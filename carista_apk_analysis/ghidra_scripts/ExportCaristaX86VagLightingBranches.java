// Export Play 9.8.3 x86 VAG lighting/cornering branch evidence.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.component.DecompilerUtils;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.Symbol;

public class ExportCaristaX86VagLightingBranches extends GhidraScript {
    private static final long RECOVERED_X86_EBX_BASE = 0x01A35618L;

    private static class BranchTarget {
        final String label;
        final long address;
        final String key;
        final String recoveredShape;

        BranchTarget(String label, long address, String key, String recoveredShape) {
            this.label = label;
            this.address = address;
            this.key = key;
            this.recoveredShape = recoveredShape;
        }
    }

    private static class FunctionTarget {
        final String label;
        final long address;
        final String reason;

        FunctionTarget(String label, long address, String reason) {
            this.label = label;
            this.address = address;
            this.reason = reason;
        }
    }

    private static class ResolvedValue {
        final String kind;
        final long recoveredAddress;
        final String text;

        ResolvedValue(String kind, long recoveredAddress, String text) {
            this.kind = kind;
            this.recoveredAddress = recoveredAddress;
            this.text = text;
        }
    }

    private static class AnalysisState {
        final Map<String, ResolvedValue> registers = new HashMap<>();
        final Map<Long, ResolvedValue> locals = new HashMap<>();
    }

    private final BranchTarget[] branchTargets = new BranchTarget[] {
        new BranchTarget("coming_home_via_fogs", 0x012C929BL, "car_setting_coming_home_via_fogs",
            "lighting output branch cluster; x86 direct branch observed as non-6R/B8-style until availability is recovered"),
        new BranchTarget("drl_via_fogs", 0x012CDE7BL, "car_setting_drl_via_fogs",
            "official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x17 mask 0x04"),
        new BranchTarget("turn_off_fogs_with_high_beam", 0x012D4DB5L, "car_setting_turn_off_fogs_with_high_beam",
            "official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x15 mask 0x20"),
        new BranchTarget("fog_lights_on_reverse_d1d", 0x012D62E6L, "car_setting_fog_lights_on_reverse",
            "DID/raw address 0x0D1D branch family guarded by MK7/6C/MQB/MK8/gateway whitelists, not recovered 6R/PQ25 whitelists"),
        new BranchTarget("cornering_lights_via_fogs", 0x012D9ED4L, "car_setting_cornering_lights_via_fogs",
            "official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x0C mask 0x40"),
        new BranchTarget("cornering_lights_via_fogs_experimental", 0x012DA0BDL, "car_setting_cornering_lights_via_fogs_experimental",
            "official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x15 mask 0x80"),
        new BranchTarget("cornering_lights_via_fogs_left", 0x012DA210L, "car_setting_cornering_lights_via_fogs_left",
            "same-key x86 branches use MQB/MK8 or gateway/MEB guards; nearby immediates include 0x055C offset 5 mask 0xFF"),
        new BranchTarget("cornering_lights_via_fogs_right", 0x012DA55FL, "car_setting_cornering_lights_via_fogs_right",
            "same-key x86 branches use MQB/MK8 or gateway/MEB guards; nearby immediates include 0x055D offset 5 mask 0xFF"),
        new BranchTarget("cornering_lights_with_turn_signals", 0x012DA72CL, "car_setting_cornering_lights_with_turn_signals",
            "official x86 explicit turn-signal 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S, DID 0600 byte 0x15 mask 0x04"),
        new BranchTarget("cornering_lights_activation_d1d", 0x012DA8BDL, "car_setting_cornering_lights_activation",
            "DID/raw address 0x0D1D activation branch family guarded by MK7/6C/MQB/B8 whitelists/access codes, not recovered 6R/PQ25 whitelists"),
        new BranchTarget("cornering_lights_min_activation_speed_d1d", 0x012DAF54L, "car_setting_cornering_lights_min_activation_speed",
            "DID/raw address 0x0D1D offset 3 mask 0xFF branch family guarded by MK7/MQB/gateway-style guards"),
        new BranchTarget("cornering_lights_max_activation_speed_d1d", 0x012DB176L, "car_setting_cornering_lights_max_activation_speed",
            "DID/raw address 0x0D1D offset 4 mask 0xFF branch family guarded by MK7/MQB/gateway-style guards"),
    };

    private final FunctionTarget[] functionTargets = new FunctionTarget[] {
        new FunctionTarget("VagCanSettings_getSettings", 0x012A20C0L,
            "owning constructor-list function; exported as metadata and branch windows only because the function is huge"),
        new FunctionTarget("FullByteVagCanShortAdaptationSetting_cornering_fogs", 0x01358FD0L,
            "callee reached by car_setting_cornering_lights_via_fogs 6R/PQ25 branch"),
        new FunctionTarget("VagUdsCodingSetting_cornering_fogs_experimental", 0x0135EAF0L,
            "callee reached by car_setting_cornering_lights_via_fogs_experimental 6R/PQ25 branch"),
        new FunctionTarget("VagUdsCodingSetting_cornering_turn_signals", 0x0135E920L,
            "callee reached by car_setting_cornering_lights_with_turn_signals 6R/PQ25 branch"),
        new FunctionTarget("VagCanLongCodingSetting_drl_via_fogs", 0x01361520L,
            "callee reached by car_setting_drl_via_fogs 6R/PQ25 branch"),
        new FunctionTarget("VagUdsCodingSetting_turn_off_fogs_high_beam", 0x0135E580L,
            "callee reached by car_setting_turn_off_fogs_with_high_beam 6R/PQ25 branch"),
        new FunctionTarget("VagCanShortAdaptationSetting_left_fog_role", 0x0136C910L,
            "x86 left-side same-key helper using MQB/MK8-style guards"),
        new FunctionTarget("VagUdsCodingSetting_left_fog_role", 0x01356F90L,
            "x86 left-side same-key helper using gateway/MEB-style guards"),
        new FunctionTarget("VagCanLongCodingSetting_right_fog_role", 0x01368690L,
            "x86 right-side same-key helper using MQB/MK8-style guards"),
        new FunctionTarget("VagUdsAdaptationSetting_right_fog_role", 0x0136CAF0L,
            "x86 right-side same-key helper using gateway/MEB-style guards"),
        new FunctionTarget("VagUdsAdaptationSetting_fog_reverse_mk7", 0x013591A0L,
            "D1D fog-on-reverse helper reached from MK7/gateway variants"),
        new FunctionTarget("VagUdsAdaptationSetting_fog_reverse_mk7_new", 0x013691D0L,
            "D1D fog-on-reverse helper reached from MK7_NEW/MK8 variant"),
        new FunctionTarget("VagUdsAdaptationSetting_cornering_activation", 0x0133E9F0L,
            "D1D cornering activation helper reached from MK7_6C and MK7_NEW_MQBA0 variants"),
        new FunctionTarget("VagCanLongCodingSetting_cornering_activation_b8", 0x0135E750L,
            "D1D-adjacent B8 long-coding helper in the activation cluster"),
        new FunctionTarget("VagUdsAdaptationSetting_cornering_speed", 0x0136CCC0L,
            "D1D min/max activation-speed helper reached from MK7_ALL variants"),
        new FunctionTarget("VagUdsAdaptationSetting_cornering_speed_mk7_new", 0x0136CEA0L,
            "D1D min/max activation-speed helper reached from MK7_6C and MK7_NEW_MQBA0 variants"),
        new FunctionTarget("VagUdsAdaptationSetting_cornering_speed_mk8", 0x0136D080L,
            "D1D max activation-speed helper reached from MK7_NEW/MK8-derived variant"),
        new FunctionTarget("VagSetting_isSubmodule", 0x01426DD0L,
            "vtable slot +0x3C predicate target recovered from VagOperationDelegate availability routing"),
        new FunctionTarget("VagOperationDelegate_getVagSettingAvailabilityForEcu", 0x016B4180L,
            "x86 availability function that calls VagSetting::isSubmodule before normal AvailBy/StringWhitelist handling"),
        new FunctionTarget("StringWhitelist_itemMatches", 0x00CD97B0L,
            "x86 StringWhitelist::itemMatches behavior recovered from Play 9.8.3"),
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputDir = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
        if (!outputDir.exists() && !outputDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + outputDir);
        }

        File branchDir = new File(outputDir, "branches");
        File functionDir = new File(outputDir, "functions");
        if (!branchDir.exists() && !branchDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + branchDir);
        }
        if (!functionDir.exists() && !functionDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + functionDir);
        }

        ensureDisassembled(toProgramAddress(0x012A20C0L));
        exportSummary(outputDir);
        for (BranchTarget target : branchTargets) {
            exportBranchWindow(branchDir, target);
        }
        exportFunctions(functionDir);
    }

    private void exportSummary(File outputDir) throws Exception {
        File outFile = new File(outputDir, "x86_vag_lighting_branch_summary.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("# Play 9.8.3 x86 VAG Lighting Branch Export");
            writer.println();
            writer.println("Program: `" + currentProgram.getName() + "`");
            writer.println("Image base: `" + currentProgram.getImageBase() + "`");
            writer.println("Recovered x86 VA mapping: `Ghidra address - image base`");
            writer.println();
            writer.println("## Branch Windows");
            writer.println();
            writer.println("| Label | Address | Setting key | Recovered shape | Function |");
            writer.println("|---|---:|---|---|---|");
            for (BranchTarget target : branchTargets) {
                Address address = toProgramAddress(target.address);
                Function function = currentProgram.getFunctionManager().getFunctionContaining(address);
                writer.println("| `" + target.label + "` | `" + recoveredAddress(target.address) + "` | `" + target.key + "` | " + target.recoveredShape + " | `" + functionLabel(function) + "` |");
            }
            writer.println();
            writer.println("## Decompiled Helper Targets");
            writer.println();
            writer.println("| Label | Address | Reason | Function |");
            writer.println("|---|---:|---|---|");
            for (FunctionTarget target : functionTargets) {
                Address address = toProgramAddress(target.address);
                Function function = currentProgram.getFunctionManager().getFunctionContaining(address);
                writer.println("| `" + target.label + "` | `" + recoveredAddress(target.address) + "` | " + target.reason + " | `" + functionLabel(function) + "` |");
            }
        }
        println("Exported " + outFile.getAbsolutePath());
    }

    private void exportBranchWindow(File outputDir, BranchTarget target) throws Exception {
        Listing listing = currentProgram.getListing();
        Address center = toProgramAddress(target.address);
        ensureDisassembled(center);
        Instruction centerInstruction = listing.getInstructionContaining(center);
        if (centerInstruction == null) {
            centerInstruction = listing.getInstructionAt(center);
        }

        File outFile = new File(outputDir, target.label + "_" + String.format("%08X", target.address) + ".md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("# " + target.label);
            writer.println();
            writer.println("Target address: `" + recoveredAddress(target.address) + "` (Ghidra `" + center + "`)");
            writer.println("Setting key: `" + target.key + "`");
            writer.println("Recovered shape: " + target.recoveredShape);
            Function function = currentProgram.getFunctionManager().getFunctionContaining(center);
            writer.println("Function: `" + functionLabel(function) + "`");
            writer.println();
            writer.println("## Symbols At Target");
            writeSymbolsAt(writer, center);
            writer.println();
            writer.println("## Instruction Window");
            writer.println();
            if (centerInstruction == null) {
                writer.println("No instruction at target.");
                return;
            }
            Instruction start = centerInstruction;
            for (int count = 0; count < 90 && start.getPrevious() != null; count++) {
                start = start.getPrevious();
            }
            Instruction instruction = start;
            AnalysisState analysisState = analysisStateBefore(start.getAddress());
            for (int count = 0; count < 210 && instruction != null; count++) {
                writeInstruction(writer, instruction, instruction.getAddress().equals(centerInstruction.getAddress()), analysisState);
                updateAnalysisState(analysisState, instruction);
                instruction = instruction.getNext();
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

        Set<Address> exportedEntries = new HashSet<>();
        try {
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException("Decompiler failed to open program: " + decompiler.getLastMessage());
            }
            for (FunctionTarget target : functionTargets) {
                Address address = toProgramAddress(target.address);
                ensureDisassembled(address);
                Function function = currentProgram.getFunctionManager().getFunctionContaining(address);
                boolean functionWasPresent = function != null;
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
                    writer.println("/* Reason: " + target.reason + " */");
                    writer.println("/* Function: " + functionLabel(function) + " */");
                    writer.println();
                    if (function == null) {
                        writer.println("/* no containing function */");
                        continue;
                    }
                    if (exportedEntries.contains(function.getEntryPoint())) {
                        writer.println("/* function already exported for another target entry: " + formatRecoveredAddress(function.getEntryPoint()) + " */");
                    }
                    else if (target.label.equals("VagCanSettings_getSettings")) {
                        writer.println("/* huge function; branch-local instruction windows are exported under branches/ */");
                        writeFunctionInstructionPreview(writer, function, 180);
                        exportedEntries.add(function.getEntryPoint());
                    }
                    else if (!functionWasPresent) {
                        writer.println("/* no-analysis import had no function boundary here; exported bounded Ghidra instruction preview instead of an unreliable decompile */");
                        writeFunctionInstructionPreview(writer, function, 180);
                        exportedEntries.add(function.getEntryPoint());
                    }
                    else {
                        DecompileResults results = decompiler.decompileFunction(function, 180, monitor);
                        if (results != null && results.decompileCompleted()) {
                            writer.println(results.getDecompiledFunction().getC());
                        }
                        else {
                            writer.println("/* decompilation failed: " + decompiler.getLastMessage() + " */");
                            writeFunctionInstructionPreview(writer, function, 500);
                        }
                        exportedEntries.add(function.getEntryPoint());
                    }
                    writer.println();
                    writer.println("/* References from entry-window instructions:");
                    writeFunctionInstructionPreview(writer, function, 80);
                    writer.println(" */");
                }
                println("Exported " + outFile.getAbsolutePath());
            }
        }
        finally {
            decompiler.dispose();
        }
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
            writer.print(" * ");
            writer.print(formatRecoveredAddress(instruction.getAddress()));
            writer.print(": ");
            writer.print(instruction);
            writeInlineReferences(writer, instruction);
            writeScalars(writer, instruction);
            writer.println();
            instruction = instruction.getNext();
            count++;
        }
    }

    private void writeInstruction(PrintWriter writer, Instruction instruction, boolean isCenter, AnalysisState analysisState) {
        writer.print("- `");
        writer.print(formatRecoveredAddress(instruction.getAddress()));
        writer.print(isCenter ? "` **=>** `" : "` `");
        writer.print(instruction.toString().replace("`", "'"));
        writer.print("`");
        writeInlineReferences(writer, instruction);
        writeScalars(writer, instruction);
        writeRecoveredAnnotations(writer, instruction, analysisState);
        writer.println();
    }

    private AnalysisState analysisStateBefore(Address stopAddress) {
        AnalysisState state = new AnalysisState();
        Listing listing = currentProgram.getListing();
        Instruction instruction = listing.getInstructionAt(toProgramAddress(0x012A20C0L));
        int guard = 0;
        while (instruction != null && instruction.getAddress().compareTo(stopAddress) < 0 && guard < 300000) {
            updateAnalysisState(state, instruction);
            instruction = instruction.getNext();
            guard++;
        }
        return state;
    }

    private void updateAnalysisState(AnalysisState state, Instruction instruction) {
        String mnemonic = instruction.getMnemonicString().toUpperCase();
        if (mnemonic.startsWith("CALL")) {
            clearCallerSaved(state);
            return;
        }

        String destRegister = registerOnly(instruction, 0);
        Long destLocal = localDisplacement(instruction, 0);

        if (destRegister != null) {
            ResolvedValue value = null;
            Long ebxDisplacement = displacementForBase(instruction, 1, "EBX");
            if ((mnemonic.equals("LEA") || mnemonic.equals("MOV")) && ebxDisplacement != null) {
                value = resolveRecoveredAddress(RECOVERED_X86_EBX_BASE + ebxDisplacement.longValue());
            }
            else if (mnemonic.equals("MOV")) {
                Long sourceLocal = localDisplacement(instruction, 1);
                String sourceRegister = registerOnly(instruction, 1);
                if (sourceLocal != null) {
                    value = state.locals.get(sourceLocal);
                }
                else if (sourceRegister != null) {
                    value = state.registers.get(sourceRegister);
                }
            }

            if (value != null) {
                state.registers.put(destRegister, value);
            }
            else if (!mnemonic.equals("PUSH")) {
                state.registers.remove(destRegister);
            }
        }

        if (destLocal != null && mnemonic.equals("MOV")) {
            ResolvedValue value = null;
            String sourceRegister = registerOnly(instruction, 1);
            Long ebxDisplacement = displacementForBase(instruction, 1, "EBX");
            Long sourceLocal = localDisplacement(instruction, 1);
            if (sourceRegister != null) {
                value = state.registers.get(sourceRegister);
            }
            else if (ebxDisplacement != null) {
                value = resolveRecoveredAddress(RECOVERED_X86_EBX_BASE + ebxDisplacement.longValue());
            }
            else if (sourceLocal != null) {
                value = state.locals.get(sourceLocal);
            }

            if (value != null) {
                state.locals.put(destLocal, value);
            }
        }
    }

    private void clearCallerSaved(AnalysisState state) {
        state.registers.remove("EAX");
        state.registers.remove("ECX");
        state.registers.remove("EDX");
    }

    private void writeRecoveredAnnotations(PrintWriter writer, Instruction instruction, AnalysisState state) {
        LinkedHashSet<String> annotations = new LinkedHashSet<>();
        String mnemonic = instruction.getMnemonicString().toUpperCase();
        for (int operandIndex = 0; operandIndex < instruction.getNumOperands(); operandIndex++) {
            boolean destinationWrite = operandIndex == 0 && writesFirstOperand(mnemonic);
            Long ebxDisplacement = displacementForBase(instruction, operandIndex, "EBX");
            if (ebxDisplacement != null) {
                ResolvedValue value = resolveRecoveredAddress(RECOVERED_X86_EBX_BASE + ebxDisplacement.longValue());
                annotations.add("ebx->" + describeResolvedValue(value));
            }

            Long localDisplacement = localDisplacement(instruction, operandIndex);
            if (!destinationWrite && localDisplacement != null && state.locals.containsKey(localDisplacement)) {
                annotations.add(localName(localDisplacement) + "->" + describeResolvedValue(state.locals.get(localDisplacement)));
            }

            String register = registerOnly(instruction, operandIndex);
            if (!destinationWrite && register != null && state.registers.containsKey(register)) {
                annotations.add(register + "->" + describeResolvedValue(state.registers.get(register)));
            }
        }
        if (!annotations.isEmpty()) {
            writer.print(" recovered:");
            for (String annotation : annotations) {
                writer.print(" `");
                writer.print(annotation.replace("`", "'"));
                writer.print("`");
            }
        }
    }

    private boolean writesFirstOperand(String mnemonic) {
        return mnemonic.equals("LEA") || mnemonic.equals("MOV") || mnemonic.equals("MOVSD") ||
            mnemonic.equals("XOR") || mnemonic.equals("ADD") || mnemonic.equals("SUB") ||
            mnemonic.equals("INC") || mnemonic.equals("DEC") || mnemonic.equals("POP");
    }

    private String registerOnly(Instruction instruction, int operandIndex) {
        if (operandIndex >= instruction.getNumOperands()) {
            return null;
        }
        String representation = instruction.getDefaultOperandRepresentation(operandIndex);
        if (representation == null) {
            return null;
        }
        String normalized = representation.trim().toUpperCase();
        if (!normalized.matches("EAX|EBX|ECX|EDX|ESI|EDI|EBP|ESP")) {
            return null;
        }
        Object[] objects = instruction.getOpObjects(operandIndex);
        for (Object object : objects) {
            if (object instanceof Register) {
                return ((Register)object).getName().toUpperCase();
            }
        }
        return normalized;
    }

    private Long localDisplacement(Instruction instruction, int operandIndex) {
        return displacementForBase(instruction, operandIndex, "EBP");
    }

    private Long displacementForBase(Instruction instruction, int operandIndex, String baseRegister) {
        if (operandIndex >= instruction.getNumOperands()) {
            return null;
        }
        String representation = instruction.getDefaultOperandRepresentation(operandIndex);
        if (representation == null) {
            return null;
        }
        String normalized = representation.toUpperCase();
        if (!normalized.contains("[") || !normalized.contains(baseRegister)) {
            return null;
        }
        Object[] objects = instruction.getOpObjects(operandIndex);
        for (Object object : objects) {
            if (object instanceof Scalar) {
                long unsignedValue = ((Scalar)object).getUnsignedValue() & 0xffffffffL;
                return Long.valueOf((long)(int)unsignedValue);
            }
        }
        return Long.valueOf(0L);
    }

    private ResolvedValue resolveRecoveredAddress(long recoveredAddress) {
        Address programAddress = toProgramAddress(recoveredAddress);
        String ascii = readAscii(programAddress, 128);
        if (ascii != null) {
            return new ResolvedValue("str", recoveredAddress, ascii);
        }
        String directSymbolName = bestSymbolName(programAddress);
        if (directSymbolName != null) {
            return new ResolvedValue("got", recoveredAddress, directSymbolName);
        }
        Data data = currentProgram.getListing().getDataAt(programAddress);
        if (data != null && data.getValue() != null) {
            Object value = data.getValue();
            if (value instanceof Address) {
                String pointedSymbolName = bestSymbolName((Address)value);
                if (pointedSymbolName != null) {
                    return new ResolvedValue("got", recoveredAddress, pointedSymbolName);
                }
                return new ResolvedValue("data", recoveredAddress, formatRecoveredAddress((Address)value));
            }
            return new ResolvedValue("data", recoveredAddress, value.toString());
        }
        return new ResolvedValue("addr", recoveredAddress, "");
    }

    private String bestSymbolName(Address address) {
        Symbol[] symbols = currentProgram.getSymbolTable().getSymbols(address);
        for (Symbol symbol : symbols) {
            String name = symbol.getName(true);
            if (!name.startsWith("DAT_") && !name.startsWith("LAB_") && !name.startsWith("SUB_")) {
                return name;
            }
        }
        Symbol primarySymbol = currentProgram.getSymbolTable().getPrimarySymbol(address);
        if (primarySymbol != null) {
            String name = primarySymbol.getName(true);
            if (!name.startsWith("DAT_") && !name.startsWith("LAB_") && !name.startsWith("SUB_")) {
                return name;
            }
        }
        return null;
    }

    private String describeResolvedValue(ResolvedValue value) {
        String suffix = value.text == null || value.text.isEmpty() ? "" : ":" + value.text;
        return value.kind + "=0x" + recoveredAddress(value.recoveredAddress) + suffix;
    }

    private String localName(long displacement) {
        if (displacement < 0) {
            return "local-0x" + Long.toHexString(-displacement);
        }
        return "local+0x" + Long.toHexString(displacement);
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
            String ascii = readAscii(toAddress, 96);
            if (ascii != null) {
                writer.print(" `ascii=");
                writer.print(ascii.replace("`", "'"));
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
            writer.println("- <none>");
            return;
        }
        for (Symbol symbol : symbols) {
            writer.println("- `" + symbol.getSymbolType() + "` `" + symbol.getName(true).replace("`", "'") + "`");
        }
    }

    private String readAscii(Address address, int maxLength) {
        Memory memory = currentProgram.getMemory();
        StringBuilder builder = new StringBuilder();
        try {
            for (int index = 0; index < maxLength; index++) {
                int value = memory.getByte(address.add(index)) & 0xff;
                if (value == 0) {
                    break;
                }
                if (value < 0x20 || value >= 0x7f) {
                    return null;
                }
                builder.append((char)value);
            }
        }
        catch (Exception exception) {
            return null;
        }
        return builder.length() >= 4 ? builder.toString() : null;
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