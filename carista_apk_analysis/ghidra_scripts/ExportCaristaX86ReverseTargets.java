// Export Play 9.8.3 x86 decompilation for current VAG ECU-info/submodule reverse targets.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.component.DecompilerUtils;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

public class ExportCaristaX86ReverseTargets extends GhidraScript {
    private static class FunctionTarget {
        final String label;
        final long address;
        final int size;
        final int timeoutSeconds;
        final String reason;

        FunctionTarget(String label, long address, int size, int timeoutSeconds, String reason) {
            this.label = label;
            this.address = address;
            this.size = size;
            this.timeoutSeconds = timeoutSeconds;
            this.reason = reason;
        }
    }

    private final FunctionTarget[] functionTargets = new FunctionTarget[] {
        new FunctionTarget("GetVagCanEcuInfoCommand_ctor", 0x00c389e0L, 66, 120,
            "command object constructor for VAG CAN ECU-info command"),
        new FunctionTarget("GetVagCanEcuInfoCommand_getRequest", 0x00c38a90L, 49, 120,
            "builds the recovered 1A9B ECU-info request"),
        new FunctionTarget("GetVagCanEcuInfoCommand_processPayloads", 0x00c38ad0L, 1317, 240,
            "multi-response ECU-info parser that builds the VagEcuInfo +0x10 submodule vector"),
        new FunctionTarget("GetVagCanEcuInfoCommand_processEcuInfo", 0x00c39240L, 2741, 240,
            "single-payload ECU-info parser for part/info string, coding type, rawAddress4, tail, initial coding, and optional suffix text"),
        new FunctionTarget("MultiResponseCommand_VagEcuInfoWithCoding_processResponses", 0x00c39e60L, 297, 180,
            "generic multi-response command wrapper used by GetVagCanEcuInfoCommand"),
        new FunctionTarget("GetSubmoduleIdsOverUdsCommand_ctor", 0x00c4e900L, 72, 120,
            "UDS submodule-ID command constructor"),
        new FunctionTarget("GetSubmoduleIdsOverUdsCommand_processPayload", 0x00c4e9b0L, 1129, 240,
            "UDS submodule-ID payload parser"),
        new FunctionTarget("GetSubmoduleIdsOverUdsCommand_addSubmodulesIdsToResult", 0x00c4ee20L, 353, 180,
            "helper that appends recovered submodule IDs to a result vector"),
        new FunctionTarget("GetVagUdsSubmoduleIdsCommand_ctor", 0x00c51e40L, 72, 120,
            "alternate VAG UDS submodule-ID command constructor"),
        new FunctionTarget("GetVagUdsSubmoduleIdsCommand_processPayload", 0x00c51ef0L, 748, 240,
            "alternate VAG UDS submodule-ID payload parser"),
        new FunctionTarget("VagEcuInfo_merge", 0x013c9310L, 386, 180,
            "shared_ptr<VagEcuInfo> merge helper"),
        new FunctionTarget("VagEcuInfo_ctor_short", 0x013c94a0L, 263, 180,
            "short VagEcuInfo constructor overload"),
        new FunctionTarget("VagEcuInfo_ctor_full", 0x013c95b0L, 305, 180,
            "full VagEcuInfo constructor overload that stores the submodule vector at +0x10/+0x14"),
        new FunctionTarget("VagEcuInfo_destructor", 0x013c96f0L, 458, 180,
            "VagEcuInfo destructor, useful for field/refcount layout"),
        new FunctionTarget("VagEcuInfo_equals", 0x013c98f0L, 1012, 240,
            "VagEcuInfo equality comparison, useful for field layout"),
        new FunctionTarget("VagEcuInfo_getInfo", 0x013c9ef0L, 794, 240,
            "native VagEcuInfo::getInfo accessor for the value used by whitelist availability matching"),
        new FunctionTarget("VagEcuInfo_getCapabilities", 0x013ca210L, 21, 120,
            "native VagEcuInfo capability accessor"),
        new FunctionTarget("VagEcuInfo_containsAll", 0x013ca230L, 131, 120,
            "native VagEcuInfo capability-mask helper"),
        new FunctionTarget("VagEcuInfo_getWorkshopCodeForWriting", 0x013ca2c0L, 1258, 240,
            "workshop-code construction used by UDS write sequences"),
        new FunctionTarget("VagEcuInfo_cloneWith", 0x013ca9f0L, 240, 180,
            "VagEcuInfo cloneWith(CodingType) overload"),
        new FunctionTarget("VagEcuInfoWithCoding_ctor_short", 0x013cb670L, 499, 180,
            "short VagEcuInfoWithCoding constructor overload"),
        new FunctionTarget("VagEcuInfoWithCoding_ctor_full", 0x013cb870L, 126, 120,
            "full VagEcuInfoWithCoding constructor overload"),
        new FunctionTarget("VagEcuInfoWithCoding_getInfo", 0x013cb980L, 1848, 240,
            "VagEcuInfoWithCoding::getInfo accessor with coding metadata"),
        new FunctionTarget("VagEcuInfoWithCoding_equals", 0x013cc0c0L, 805, 240,
            "VagEcuInfoWithCoding equality comparison, useful for field layout"),
        new FunctionTarget("VagOperationDelegate_getVagSettingAvailabilityForEcu", 0x016b4180L, 1342, 240,
            "availability router that calls VagSetting::isSubmodule before AvailBy handling"),
        new FunctionTarget("VagOperationDelegate_readVagUdsSubmoduleValue", 0x016b9dc0L, 421, 180,
            "raw read path for UDS submodule settings"),
        new FunctionTarget("VagOperationDelegate_updateEcuInfo", 0x016c4b50L, 477, 180,
            "updates cached VagEcuInfo from command results"),
        new FunctionTarget("VagOperationDelegate_validateVagCanEcuInfo", 0x016c5b00L, 725, 180,
            "validates VAG CAN ECU-info results"),
        new FunctionTarget("VagOperationDelegate_readVagEcuInfoWithUdsCommands", 0x016c5de0L, 9993, 360,
            "large UDS ECU-info read orchestration around submodule commands"),
        new FunctionTarget("VagOperationDelegate_getVagSettingAvailabilityForSubmodule", 0x016c97d0L, 311, 180,
            "recovered submodule availability helper that scans VagEcuInfo +0x10"),
    };

    private final String[] symbolNeedles = new String[] {
        "GetVagCanEcuInfoCommand",
        "GetSubmoduleIdsOverUdsCommand",
        "GetVagUdsSubmoduleIdsCommand",
        "VagEcuInfo",
        "readVagUdsSubmoduleValue",
        "getVagSettingAvailabilityForSubmodule"
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputDir = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
        if (!outputDir.exists() && !outputDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + outputDir);
        }
        File functionDir = new File(outputDir, "functions");
        if (!functionDir.exists() && !functionDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + functionDir);
        }

        exportSummary(outputDir);
        exportSymbolMatches(outputDir);
        exportFunctions(functionDir);
    }

    private void exportSummary(File outputDir) throws Exception {
        File outFile = new File(outputDir, "x86_reverse_targets_summary.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("# Play 9.8.3 x86 Reverse Target Export");
            writer.println();
            writer.println("Program: `" + currentProgram.getName() + "`");
            writer.println("Image base: `" + currentProgram.getImageBase() + "`");
            writer.println("Recovered x86 VA mapping: `Ghidra address - image base`");
            writer.println();
            writer.println("| Label | Recovered VA | Size | Reason | Function |");
            writer.println("|---|---:|---:|---|---|");
            for (FunctionTarget target : functionTargets) {
                Address address = toProgramAddress(target.address);
                Function function = currentProgram.getFunctionManager().getFunctionContaining(address);
                writer.println("| `" + target.label + "` | `" + recoveredAddress(target.address) + "` | `" + target.size + "` | " + target.reason + " | `" + functionLabel(function) + "` |");
            }
        }
        println("Exported " + outFile.getAbsolutePath());
    }

    private void exportSymbolMatches(File outputDir) throws Exception {
        File outFile = new File(outputDir, "symbol_matches.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("# Symbol Matches");
            writer.println();
            SymbolIterator symbols = currentProgram.getSymbolTable().getAllSymbols(true);
            while (symbols.hasNext()) {
                Symbol symbol = symbols.next();
                String name = symbol.getName(true);
                for (String needle : symbolNeedles) {
                    if (name.contains(needle)) {
                        writer.println("- `" + formatRecoveredAddress(symbol.getAddress()) + "` `" + symbol.getSymbolType() + "` `" + name.replace("`", "'") + "`");
                        break;
                    }
                }
            }
        }
        println("Exported " + outFile.getAbsolutePath());
    }

    private void exportFunctions(File outputDir) throws Exception {
        DecompileOptions options = DecompilerUtils.getDecompileOptions(state.getTool(), currentProgram);
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(options);
        decompiler.toggleCCode(true);
        decompiler.setSimplificationStyle("decompile");

        try {
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException("Decompiler failed to open program: " + decompiler.getLastMessage());
            }
            for (FunctionTarget target : functionTargets) {
                exportFunction(outputDir, decompiler, target);
            }
        }
        finally {
            decompiler.dispose();
        }
    }

    private void exportFunction(File outputDir, DecompInterface decompiler, FunctionTarget target) throws Exception {
        Address address = toProgramAddress(target.address);
        ensureDisassembled(address);
        Function function = currentProgram.getFunctionManager().getFunctionContaining(address);
        if (function == null) {
            try {
                function = createFunction(address, target.label);
            }
            catch (Exception exception) {
                function = currentProgram.getFunctionManager().getFunctionContaining(address);
            }
        }

        File outFile = new File(outputDir, target.label + "_" + String.format("%08X", target.address) + ".c");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("/* Target " + target.label + " @ " + recoveredAddress(target.address) + " (Ghidra " + address + ") */");
            writer.println("/* Size: " + target.size + " bytes */");
            writer.println("/* Reason: " + target.reason + " */");
            writer.println("/* Function: " + functionLabel(function) + " */");
            writer.println();
            writer.println("/* Symbols at target:");
            writeSymbolsAt(writer, address);
            writer.println(" */");
            writer.println();

            if (function == null) {
                writer.println("/* no containing function; bounded instruction preview follows */");
                writeInstructionPreviewFrom(writer, address, Math.max(40, Math.min(500, target.size / 2)));
                return;
            }

            DecompileResults results = decompiler.decompileFunction(function, target.timeoutSeconds, monitor);
            if (results != null && results.decompileCompleted()) {
                writer.println(results.getDecompiledFunction().getC());
            }
            else {
                writer.println("/* decompilation failed: " + decompiler.getLastMessage() + " */");
            }
            writer.println();
            writer.println("/* Entry instruction preview:");
            writeFunctionInstructionPreview(writer, function, Math.max(80, Math.min(700, target.size / 2)));
            writer.println(" */");
        }
        println("Exported " + outFile.getAbsolutePath());
    }

    private void ensureDisassembled(Address address) {
        if (currentProgram.getListing().getInstructionContaining(address) != null) {
            return;
        }
        try {
            disassemble(address);
        }
        catch (Exception exception) {
            println("Could not disassemble at " + address + ": " + exception.getMessage());
        }
    }

    private void writeFunctionInstructionPreview(PrintWriter writer, Function function, int maxInstructions) {
        Listing listing = currentProgram.getListing();
        AddressSetView body = function.getBody();
        Instruction instruction = listing.getInstructionAt(function.getEntryPoint());
        int count = 0;
        while (instruction != null && body.contains(instruction.getAddress()) && count < maxInstructions) {
            writeInstructionLine(writer, instruction);
            instruction = instruction.getNext();
            count++;
        }
    }

    private void writeInstructionPreviewFrom(PrintWriter writer, Address startAddress, int maxInstructions) {
        Listing listing = currentProgram.getListing();
        Instruction instruction = listing.getInstructionContaining(startAddress);
        if (instruction == null) {
            instruction = listing.getInstructionAt(startAddress);
        }
        int count = 0;
        while (instruction != null && count < maxInstructions) {
            writeInstructionLine(writer, instruction);
            instruction = instruction.getNext();
            count++;
        }
    }

    private void writeInstructionLine(PrintWriter writer, Instruction instruction) {
        writer.print(" * ");
        writer.print(formatRecoveredAddress(instruction.getAddress()));
        writer.print(": ");
        writer.print(instruction.toString().replace("`", "'"));
        writeInlineReferences(writer, instruction);
        writeScalars(writer, instruction);
        writer.println();
    }

    private void writeInlineReferences(PrintWriter writer, Instruction instruction) {
        Reference[] references = instruction.getReferencesFrom();
        if (references.length == 0) {
            return;
        }
        writer.print(" refs:");
        for (Reference reference : references) {
            Address toAddress = reference.getToAddress();
            writer.print(" `");
            writer.print(reference.getReferenceType().getName());
            writer.print(" -> ");
            writer.print(formatRecoveredAddress(toAddress));
            writer.print("`");

            Symbol primarySymbol = currentProgram.getSymbolTable().getPrimarySymbol(toAddress);
            if (primarySymbol != null) {
                writer.print(" `sym=");
                writer.print(primarySymbol.getName(true).replace("`", "'"));
                writer.print("`");
            }
            Data data = currentProgram.getListing().getDataAt(toAddress);
            if (data != null && data.getValue() != null) {
                writer.print(" `data=");
                writer.print(data.getValue().toString().replace("`", "'"));
                writer.print("`");
            }
        }
    }

    private void writeScalars(PrintWriter writer, Instruction instruction) {
        boolean wroteHeader = false;
        for (int operandIndex = 0; operandIndex < instruction.getNumOperands(); operandIndex++) {
            Object[] objects = instruction.getOpObjects(operandIndex);
            for (Object object : objects) {
                if (object instanceof Scalar) {
                    if (!wroteHeader) {
                        writer.print(" scalars:");
                        wroteHeader = true;
                    }
                    writer.print(" `0x");
                    writer.print(Long.toHexString(((Scalar)object).getUnsignedValue()).toUpperCase());
                    writer.print("`");
                }
            }
        }
    }

    private void writeSymbolsAt(PrintWriter writer, Address address) {
        Symbol[] symbols = currentProgram.getSymbolTable().getSymbols(address);
        if (symbols.length == 0) {
            writer.println(" * <none>");
            return;
        }
        for (Symbol symbol : symbols) {
            writer.println(" * " + symbol.getSymbolType() + " " + symbol.getName(true).replace("`", "'"));
        }
    }

    private Address toProgramAddress(long recoveredAddress) {
        return toAddr(recoveredAddress + currentProgram.getImageBase().getOffset());
    }

    private String recoveredAddress(long recoveredAddress) {
        return String.format("%08x", recoveredAddress);
    }

    private String formatRecoveredAddress(Address address) {
        if (address == null || !address.isMemoryAddress()) {
            return String.valueOf(address);
        }
        long recovered = address.getOffset() - currentProgram.getImageBase().getOffset();
        if (recovered < 0) {
            return address.toString();
        }
        return recoveredAddress(recovered);
    }

    private String functionLabel(Function function) {
        if (function == null) {
            return "<none>";
        }
        return function.getName(true).replace("`", "'") + " @ " + formatRecoveredAddress(function.getEntryPoint());
    }
}