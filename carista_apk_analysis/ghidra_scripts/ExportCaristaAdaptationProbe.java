// Export focused native evidence for Carista VAG adaptation/routine read/write recovery.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.component.DecompilerUtils;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryAccessException;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolType;

public class ExportCaristaAdaptationProbe extends GhidraScript {
    private static final String[] NEEDLES = new String[] {
        "StartReadVagCanRoutineCommand",
        "StopReadVagCanRoutineCommand",
        "PreReadVagCanAdaptationDataCommand",
        "ReadVagCanAdaptationDataCommand",
        "ReadVagCanShortAdaptationDataCommand",
        "ReadVagCanLongAdaptationDataCommand",
        "SetVagCanAdaptationChannelCommand",
        "WriteVagCanTemporaryAdaptationDataCommand",
        "WriteVagCanAdaptationDataCommand",
        "VagUdsAdaptationSetting",
        "FullByteVagUdsAdaptationSetting",
        "VagCanShortAdaptationSetting",
        "FullByteVagCanShortAdaptationSetting",
        "ReadValuesOperation",
        "ChangeSettingOperation",
        "VagOperationDelegate"
    };

    private static final long[] POINTER_TABLE_ANCHORS = new long[] {
        0x014ba724L,
        0x014ba77cL,
        0x014baa84L,
        0x014b5630L,
        0x014b55d8L
    };

    private static final long[] TARGET_FUNCTIONS = new long[] {
        0x012148e0L,
        0x01272840L,
        0x01272888L,
        0x012728d8L,
        0x0127293cL,
        0x01272984L,
        0x012729ccL,
        0x01273680L,
        0x012736e0L,
        0x01218650L,
        0x01280c38L,
        0x01280d70L,
        0x01280ec0L,
        0x0128105cL,
        0x01281194L,
        0x012812ccL,
        0x012818d4L,
        0x01281a34L
    };

    private static final long[] BYTE_LITERAL_ADDRESSES = new long[] {
        0x00ab28b1L,
        0x00b93cf1L,
        0x00c4a6a3L,
        0x00805157L,
        0x007481ebL
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputDir = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
        if (!outputDir.exists() && !outputDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + outputDir);
        }

        SymbolTable symbolTable = currentProgram.getSymbolTable();
        FunctionManager functionManager = currentProgram.getFunctionManager();
        Set<Function> functionsToExport = new LinkedHashSet<>();

        try (PrintWriter writer = new PrintWriter(new FileWriter(new File(outputDir, "symbol_matches.md")))) {
            writer.println("# Carista Adaptation/Routine Symbol Matches");
            writer.println();
            SymbolIterator symbols = symbolTable.getAllSymbols(true);
            while (symbols.hasNext()) {
                Symbol symbol = symbols.next();
                String name = symbol.getName(true);
                if (!containsNeedle(name)) {
                    continue;
                }
                writer.println("- `" + symbol.getSymbolType() + "` `" + symbol.getAddress() + "` `" + name + "`");
                Function function = null;
                if (symbol.getSymbolType() == SymbolType.FUNCTION) {
                    function = functionManager.getFunctionAt(symbol.getAddress());
                }
                if (function == null) {
                    function = functionManager.getFunctionContaining(symbol.getAddress());
                }
                if (function != null) {
                    functionsToExport.add(function);
                }
            }
        }

        try (PrintWriter writer = new PrintWriter(new FileWriter(new File(outputDir, "pointer_tables.md")))) {
            writer.println("# Carista Pointer Table Probes");
            writer.println();
            for (long anchor : POINTER_TABLE_ANCHORS) {
                dumpPointerTable(writer, functionManager, symbolTable, anchor, -0x80, 0x260, functionsToExport);
            }
        }

        try (PrintWriter writer = new PrintWriter(new FileWriter(new File(outputDir, "byte_literals.md")))) {
            dumpByteLiterals(writer);
        }

        addTargetFunctions(functionManager, functionsToExport);

        exportFunctions(outputDir, functionsToExport);
    }

    private void addTargetFunctions(FunctionManager functionManager, Set<Function> functionsToExport) {
        for (long target : TARGET_FUNCTIONS) {
            Function function = functionManager.getFunctionAt(toAddr(target));
            if (function == null) {
                function = functionManager.getFunctionContaining(toAddr(target));
            }
            if (function != null) {
                functionsToExport.add(function);
            }
        }
    }

    private boolean containsNeedle(String value) {
        String lower = value.toLowerCase();
        for (String needle : NEEDLES) {
            if (lower.contains(needle.toLowerCase())) {
                return true;
            }
        }
        return false;
    }

    private void dumpPointerTable(
            PrintWriter writer,
            FunctionManager functionManager,
            SymbolTable symbolTable,
            long anchor,
            int before,
            int after,
            Set<Function> functionsToExport) throws MemoryAccessException {
        Memory memory = currentProgram.getMemory();
        writer.println("## Anchor `" + toAddr(anchor) + "`");
        writer.println();
        writer.println("| Offset | Address | Value | Target | Symbol |");
        writer.println("| --- | --- | --- | --- | --- |");
        for (int offset = before; offset <= after; offset += 4) {
            Address entry = toAddr(anchor + offset);
            if (!memory.contains(entry)) {
                continue;
            }
            long value = Integer.toUnsignedLong(memory.getInt(entry));
            Address target = toAddr(value & 0xfffffffeL);
            Function function = functionManager.getFunctionContaining(target);
            Symbol symbol = symbolTable.getPrimarySymbol(target);
            if (function == null && symbol == null) {
                continue;
            }
            if (function != null) {
                functionsToExport.add(function);
            }
            writer.print("| `");
            writer.print(formatSignedHex(offset));
            writer.print("` | `");
            writer.print(entry);
            writer.print("` | `0x");
            writer.print(String.format("%08X", value));
            writer.print("` | `");
            writer.print(function == null ? "" : function.getName(true) + " @ " + function.getEntryPoint());
            writer.print("` | `");
            writer.print(symbol == null ? "" : symbol.getName(true));
            writer.println("` |");
        }
        writer.println();
    }

    private void exportFunctions(File outputDir, Set<Function> functions) throws Exception {
        DecompileOptions options = DecompilerUtils.getDecompileOptions(state.getTool(), currentProgram);
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(options);
        decompiler.toggleCCode(true);
        decompiler.setSimplificationStyle("decompile");
        try {
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException("Decompiler failed to open program: " + decompiler.getLastMessage());
            }
            File functionDir = new File(outputDir, "functions");
            if (!functionDir.exists() && !functionDir.mkdirs()) {
                throw new IllegalStateException("Could not create output directory: " + functionDir);
            }
            for (Function function : functions) {
                if (monitor.isCancelled()) {
                    break;
                }
                String fileName = String.format("%08X_%s.c", function.getEntryPoint().getOffset(), sanitize(function.getName()));
                File outFile = new File(functionDir, fileName);
                try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
                    writer.println("/* " + function.getName(true) + " @ " + function.getEntryPoint() + " */");
                    writer.println();
                    DecompileResults results = decompiler.decompileFunction(function, 120, monitor);
                    if (results != null && results.decompileCompleted()) {
                        writer.println(results.getDecompiledFunction().getC());
                    }
                    else {
                        writer.println("/* decompilation failed: " + decompiler.getLastMessage() + " */");
                    }
                }
            }
        }
        finally {
            decompiler.dispose();
        }
    }

    private void dumpByteLiterals(PrintWriter writer) throws MemoryAccessException {
        Memory memory = currentProgram.getMemory();
        writer.println("# Carista Byte Literal Probes");
        writer.println();
        writer.println("| Address | ASCII until NUL | Raw bytes |");
        writer.println("| --- | --- | --- |");
        for (long literal : BYTE_LITERAL_ADDRESSES) {
            Address address = toAddr(literal);
            StringBuilder ascii = new StringBuilder();
            StringBuilder raw = new StringBuilder();
            for (int index = 0; index < 16 && memory.contains(address.add(index)); index++) {
                int value = Byte.toUnsignedInt(memory.getByte(address.add(index)));
                if (raw.length() > 0) {
                    raw.append(' ');
                }
                raw.append(String.format("%02X", value));
                if (value == 0) {
                    break;
                }
                if (value >= 0x20 && value <= 0x7e) {
                    ascii.append((char)value);
                }
                else {
                    ascii.append(String.format("\\x%02X", value));
                }
            }
            writer.print("| `");
            writer.print(address);
            writer.print("` | `");
            writer.print(ascii);
            writer.print("` | `");
            writer.print(raw);
            writer.println("` |");
        }
    }

    private String sanitize(String value) {
        String sanitized = value.replaceAll("[^A-Za-z0-9_.-]", "_");
        if (sanitized.length() > 100) {
            return sanitized.substring(0, 100);
        }
        return sanitized;
    }

    private String formatSignedHex(int value) {
        if (value < 0) {
            return String.format("-0x%X", -value);
        }
        return String.format("+0x%X", value);
    }
}