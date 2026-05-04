// Export references to selected Carista setting-key strings.
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
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

public class ExportCaristaSettingStringRefs extends GhidraScript {
    private static final long GHIDRA_IMAGE_BASE_DELTA = 0x10000L;
    private static final long MAX_DECOMPILE_ADDRESSES = 0x20000L;

    private static class Target {
        final String key;
        final long elfAddress;

        Target(String key, long elfAddress) {
            this.key = key;
            this.elfAddress = elfAddress;
        }
    }

    private final Target[] targets = new Target[] {
        new Target("car_setting_fog_when", 0x00B58D33L),
        new Target("car_setting_left_fog_light_as", 0x007FD376L),
        new Target("car_setting_right_fog_light_as", 0x00C28F62L),
        new Target("car_setting_cornering_lights_via_fogs", 0x00B3F397L),
        new Target("car_setting_cornering_lights_via_fogs_experimental", 0x008E06F6L),
        new Target("car_setting_use_cornering_lights", 0x007FD355L),
        new Target("car_setting_cornering_lights_with_turn_signals", 0x00A1B8B1L),
        new Target("car_setting_cornerig_lights_with_turn_signal", 0x006984AEL),
        new Target("car_setting_cornering_lights_with_turn_signals_one_touch", 0x0081F251L),
        new Target("car_setting_cornering_lights_via_fogs_left", 0x00ADA817L),
        new Target("car_setting_cornering_lights_via_fogs_right", 0x00ADA842L),
        new Target("car_setting_cornering_lights_via", 0x00A1B890L),
        new Target("car_setting_cornering_lights", 0x008E8CBAL),
        new Target("car_setting_cornering_lights_activation", 0x00BBC3CEL),
        new Target("car_setting_instr_needle_sweep", 0x00B9AECCL),
        new Target("car_setting_instr_needle_sweep_method_b", 0x00B4E8C7L),
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputDir = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
        if (!outputDir.exists() && !outputDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + outputDir);
        }

        DecompileOptions options = DecompilerUtils.getDecompileOptions(state.getTool(), currentProgram);
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(options);
        decompiler.toggleCCode(true);
        decompiler.setSimplificationStyle("decompile");

        try {
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException("Decompiler failed to open program: " + decompiler.getLastMessage());
            }

            File report = new File(outputDir, "setting_string_refs.md");
            try (PrintWriter writer = new PrintWriter(new FileWriter(report))) {
                writer.println("# Carista Setting String References");
                writer.println();
                writer.println("Addresses are ELF addresses plus the known Ghidra image-base delta `0x10000`.");
                writer.println();
                for (Target target : targets) {
                    exportTarget(writer, decompiler, target, outputDir);
                }
            }
        }
        finally {
            decompiler.dispose();
        }
    }

    private void exportTarget(PrintWriter writer, DecompInterface decompiler, Target target, File outputDir)
            throws Exception {
        Address stringAddress = toAddr(target.elfAddress + GHIDRA_IMAGE_BASE_DELTA);
        ReferenceManager refs = currentProgram.getReferenceManager();
        ReferenceIterator iterator = refs.getReferencesTo(stringAddress);
        List<Reference> references = new ArrayList<>();
        while (iterator.hasNext()) {
            references.add(iterator.next());
        }

        writer.println("## `" + target.key + "`");
        writer.println();
        writer.println("- ELF address: `" + String.format("0x%08X", target.elfAddress) + "`");
        writer.println("- Ghidra address: `" + stringAddress + "`");
        writer.println("- Direct references: `" + references.size() + "`");
        writer.println();

        Set<Function> functions = new LinkedHashSet<>();
        for (Reference ref : references) {
            Address from = ref.getFromAddress();
            Function function = functionContaining(from);
            writer.println("  - `" + from + "` from `" + (function == null ? "<no function>" : function.getName()) + "`");
            writer.println("    - context: `" + instructionContext(from) + "`");
            if (function != null) {
                functions.add(function);
            }
        }
        if (references.isEmpty()) {
            writer.println("  - No direct Ghidra references found. This usually means the string is reached through a table, hash, or offset arithmetic rather than a plain pointer.");
        }
        writer.println();

        for (Function function : functions) {
            exportFunction(decompiler, outputDir, target.key, function);
        }
    }

    private Function functionContaining(Address address) {
        return currentProgram.getFunctionManager().getFunctionContaining(address);
    }

    private void exportFunction(DecompInterface decompiler, File outputDir, String key, Function function)
            throws Exception {
        String safeName = key + "_" + function.getName().replaceAll("[^A-Za-z0-9_.-]", "_") + ".c";
        File outFile = new File(outputDir, safeName);
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("/*");
            writer.println(" * Setting key: " + key);
            writer.println(" * Function: " + function.getName() + " @ " + function.getEntryPoint());
            writer.println(" */");
            writer.println();
            if (function.getBody().getNumAddresses() > MAX_DECOMPILE_ADDRESSES) {
                writer.println("/* decompilation skipped: function is too large for the targeted setting-ref export */");
                writer.println("/* use ExportCaristaSettingRefsOnly.java plus targeted address exports instead */");
                writer.println("/*");
                dumpInstructions(writer, function);
                writer.println(" */");
                return;
            }

            DecompileResults results = decompiler.decompileFunction(function, 120, monitor);
            if (results != null && results.decompileCompleted()) {
                writer.println(results.getDecompiledFunction().getC());
            }
            else {
                writer.println("/* decompilation failed */");
                writer.println("/*");
                dumpInstructions(writer, function);
                writer.println(" */");
            }
        }
    }

    private void dumpInstructions(PrintWriter writer, Function function) {
        Listing listing = currentProgram.getListing();
        Instruction instruction = listing.getInstructionAt(function.getEntryPoint());
        int count = 0;
        while (instruction != null && function.getBody().contains(instruction.getAddress()) && count < 500) {
            writer.println(" * " + instruction.getAddress() + ": " + instruction);
            instruction = instruction.getNext();
            count++;
        }
        if (instruction != null && function.getBody().contains(instruction.getAddress())) {
            writer.println(" * ... truncated ...");
        }
    }

    private String instructionContext(Address address) {
        Listing listing = currentProgram.getListing();
        Instruction instruction = listing.getInstructionContaining(address);
        if (instruction == null) {
            instruction = listing.getInstructionAt(address);
        }
        return instruction == null ? "<no instruction>" : instruction.toString();
    }
}
