// Export decompiled pseudocode for Carista DEX Java/native bridge functions.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.component.DecompilerUtils;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;

public class ExportCaristaAndroidBridge extends GhidraScript {
    private static final String[] CLASS_TOKENS = new String[] {
        "com::prizmos::carista::library::model::Ecu::",
        "com::prizmos::carista::library::model::Interpretation::",
        "com::prizmos::carista::library::model::Setting::",
        "com::prizmos::carista::library::model::SettingRef::",
        "com::prizmos::carista::library::model::SettingCategory::",
        "com::prizmos::carista::library::operation::ReadValuesOperation::",
        "com::prizmos::carista::library::operation::ChangeSettingOperation::",
        "com::prizmos::carista::library::operation::CheckSettingsOperation::",
        "com::prizmos::carista::library::operation::GetEcuInfoOperation::"
    };

    private static final int MAX_REFERENCES_PER_FUNCTION = 80;

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputRoot = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
        File outputDir = new File(outputRoot, sanitize(currentProgram.getName()));
        if (!outputDir.exists() && !outputDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + outputDir);
        }
        cleanOutputDirectory(outputDir);

        DecompileOptions options = DecompilerUtils.getDecompileOptions(state.getTool(), currentProgram);
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(options);
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        decompiler.setSimplificationStyle("decompile");

        List<String> indexLines = new ArrayList<>();
        try {
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException("Decompiler failed to open program: " + decompiler.getLastMessage());
            }
            FunctionManager functions = currentProgram.getFunctionManager();
            for (Function function : functions.getFunctions(true)) {
                if (monitor.isCancelled()) {
                    break;
                }
                if (isBridgeTarget(function)) {
                    exportFunction(decompiler, function, outputDir, indexLines);
                }
            }
        }
        finally {
            decompiler.dispose();
        }

        File indexFile = new File(outputDir, "index.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(indexFile))) {
            writer.println("# Carista Android bridge exports for " + currentProgram.getName());
            writer.println();
            if (indexLines.isEmpty()) {
                writer.println("No matching bridge functions found in this program.");
            }
            else {
                for (String line : indexLines) {
                    writer.println(line);
                }
            }
        }

        println("Wrote Carista Android bridge exports to " + outputDir.getAbsolutePath());
    }

    private boolean isBridgeTarget(Function function) {
        String fullName = function.getName(true);
        boolean classMatch = false;
        for (String token : CLASS_TOKENS) {
            if (fullName.contains(token)) {
                classMatch = true;
                break;
            }
        }
        return classMatch;
    }

    private void exportFunction(DecompInterface decompiler, Function function, File outputDir,
            List<String> indexLines) throws Exception {
        String fileName = sanitize(function.getName(true)) + "_" + function.getEntryPoint() + ".c";
        List<String> callers = describeCallers(function);
        List<String> callees = describeCallees(function);

        File outputFile = new File(outputDir, fileName);
        try (PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {
            writer.println("/*");
            writer.println(" * Program: " + currentProgram.getName());
            writer.println(" * Function: " + function.getName(true));
            writer.println(" * Signature: " + function.getSignature());
            writer.println(" * Return type: " + function.getReturnType());
            writer.println(" * Entry: " + function.getEntryPoint());
            writer.println(" * Body: " + function.getBody());
            writer.println(" * Parameters:");
            for (Parameter parameter : function.getParameters()) {
                writer.println(" *   [" + parameter.getOrdinal() + "] " + parameter.getDataType() +
                    " " + parameter.getName());
            }
            writer.println(" * Direct callers:");
            writeReferenceLines(writer, callers);
            writer.println(" * Direct callees/references:");
            writeReferenceLines(writer, callees);
            writer.println(" */");
            writer.println();

            DecompileResults results = decompiler.decompileFunction(function, 120, monitor);
            if (!results.decompileCompleted()) {
                writer.println("/* Decompile failed: " + results.getErrorMessage() + " */");
                indexLines.add("- `" + function.getName(true) + "`: decompile failed");
                return;
            }
            writer.println(results.getDecompiledFunction().getC());
            indexLines.add("- `" + function.getName(true) + "`: `" + outputFile.getName() +
                "`; callers=" + callers.size() + "; callees/refs=" + callees.size());
        }
    }

    private List<String> describeCallers(Function function) {
        ReferenceManager references = currentProgram.getReferenceManager();
        FunctionManager functions = currentProgram.getFunctionManager();
        Set<String> lines = new LinkedHashSet<>();
        for (Reference reference : references.getReferencesTo(function.getEntryPoint())) {
            Function caller = functions.getFunctionContaining(reference.getFromAddress());
            String callerName = caller == null ? "<no function>" : caller.getName(true) +
                " @ " + caller.getEntryPoint();
            lines.add(callerName + " -> " + reference.getReferenceType() +
                " from " + reference.getFromAddress());
            if (lines.size() >= MAX_REFERENCES_PER_FUNCTION) {
                break;
            }
        }
        return new ArrayList<>(lines);
    }

    private List<String> describeCallees(Function function) {
        ReferenceManager references = currentProgram.getReferenceManager();
        FunctionManager functions = currentProgram.getFunctionManager();
        Set<String> lines = new LinkedHashSet<>();
        AddressIterator addresses = function.getBody().getAddresses(true);
        while (addresses.hasNext() && lines.size() < MAX_REFERENCES_PER_FUNCTION) {
            Address from = addresses.next();
            for (Reference reference : references.getReferencesFrom(from)) {
                Function callee = functions.getFunctionContaining(reference.getToAddress());
                String calleeName = callee == null ? reference.getToAddress().toString()
                    : callee.getName(true) + " @ " + callee.getEntryPoint();
                lines.add(reference.getReferenceType() + " " + calleeName + " from " + from);
                if (lines.size() >= MAX_REFERENCES_PER_FUNCTION) {
                    break;
                }
            }
        }
        return new ArrayList<>(lines);
    }

    private void writeReferenceLines(PrintWriter writer, List<String> lines) {
        if (lines.isEmpty()) {
            writer.println(" *   <none recorded>");
            return;
        }
        for (String line : lines) {
            writer.println(" *   " + line);
        }
    }

    private void cleanOutputDirectory(File outputDir) {
        File[] existing = outputDir.listFiles((dir, name) -> name.endsWith(".c") || name.equals("index.md"));
        if (existing == null) {
            return;
        }
        for (File file : existing) {
            if (!file.delete()) {
                println("Warning: could not delete stale export " + file.getAbsolutePath());
            }
        }
    }

    private String sanitize(String value) {
        return value.replaceAll("[^A-Za-z0-9._-]", "_");
    }
}
