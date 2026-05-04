// Export native references to lighting-related Carista setting keys by scanning strings by text.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
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
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

public class ExportCaristaLightSettingProbe extends GhidraScript {
    private static final long MAX_DECOMPILE_ADDRESSES = 0x30000L;
    private static final int MAX_DECOMPILE_SECONDS = 10;
    private static final int MAX_DECOMPILE_FUNCTIONS_PER_KEY = 2;

    private static final String[] TARGET_KEYS = new String[] {
        "car_setting_fog_when",
        "car_setting_left_fog_light_as",
        "car_setting_right_fog_light_as",
        "car_setting_cornering_lights",
        "car_setting_cornering_lights_activation",
        "car_setting_cornering_lights_via",
        "car_setting_cornering_lights_via_fogs",
        "car_setting_cornering_lights_via_fogs_experimental",
        "car_setting_cornering_lights_via_fogs_left",
        "car_setting_cornering_lights_via_fogs_right",
        "car_setting_cornering_lights_with_turn_signals",
        "car_setting_cornering_lights_with_turn_signals_one_touch",
        "car_setting_cornerig_lights_with_turn_signal",
        "car_setting_use_cornering_lights",
        "car_setting_drl",
        "car_setting_drl_via",
        "car_setting_drl_via_fogs",
        "car_setting_scandinavian_drl",
        "car_setting_assist_dr_lights",
        "car_setting_turn_off_drl_with_parking_brake",
        "car_setting_turn_off_drl_with_turn_signal",
        "car_setting_front_fogs_with_low_beams",
        "car_setting_pl_via_front_fog_lights",
        "car_setting_fogs_with_high_beam_restriction",
        "car_setting_turn_off_fogs_with_high_beam",
        "car_setting_turn_on_fogs_with_high_beam",
        "car_setting_coming_home",
        "car_setting_coming_home_duration",
        "car_setting_coming_home_mode",
        "car_setting_coming_home_req_rls",
        "car_setting_coming_home_via_fogs",
        "car_setting_coming_home_via_low_beams",
        "car_setting_coming_leaving_home_output",
        "car_setting_leaving_home_duration",
        "car_setting_leaving_home_req_rls",
        "car_setting_enabled_coming_home_or_leaving_home"
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputDir = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
        boolean includeDecompile = hasArg(args, "--decompile");
        if (!outputDir.exists() && !outputDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + outputDir);
        }
        File functionsDir = new File(outputDir, "functions");
        if (!functionsDir.exists() && !functionsDir.mkdirs()) {
            throw new IllegalStateException("Could not create functions directory: " + functionsDir);
        }

        DecompInterface decompiler = null;
        if (includeDecompile) {
            DecompileOptions options = DecompilerUtils.getDecompileOptions(state.getTool(), currentProgram);
            decompiler = new DecompInterface();
            decompiler.setOptions(options);
            decompiler.toggleCCode(true);
            decompiler.setSimplificationStyle("decompile");
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException("Decompiler failed to open program: " + decompiler.getLastMessage());
            }
        }

        try {
            writeReport(outputDir, functionsDir, decompiler, includeDecompile);
        }
        finally {
            if (decompiler != null) {
                decompiler.dispose();
            }
        }
    }

    private boolean hasArg(String[] args, String expected) {
        for (String arg : args) {
            if (expected.equals(arg)) {
                return true;
            }
        }
        return false;
    }

    private void writeReport(File outputDir, File functionsDir, DecompInterface decompiler, boolean includeDecompile) throws Exception {
        File report = new File(outputDir, "light_setting_string_refs.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(report))) {
            writer.println("# Carista Native Lighting Setting Probe");
            writer.println();
            writer.println("String matches are found by exact UTF-8 text plus NUL terminator, then direct Ghidra references are exported.");
            writer.println("Decompilation is skipped by default; pass --decompile after the output directory to export at most " + MAX_DECOMPILE_FUNCTIONS_PER_KEY + " functions per key with " + MAX_DECOMPILE_SECONDS + "s timeout each.");
            writer.println();
            for (String key : TARGET_KEYS) {
                exportKey(writer, functionsDir, decompiler, includeDecompile, key);
            }
        }
    }

    private void exportKey(PrintWriter writer, File functionsDir, DecompInterface decompiler, boolean includeDecompile, String key) throws Exception {
        List<Address> stringAddresses = findStringAddresses(key);
        ReferenceManager refs = currentProgram.getReferenceManager();
        Set<Function> functions = new LinkedHashSet<>();

        writer.println("## `" + key + "`");
        writer.println();
        writer.println("- String matches: `" + stringAddresses.size() + "`");
        for (Address stringAddress : stringAddresses) {
            writer.println("  - address: `" + stringAddress + "`");
            ReferenceIterator iterator = refs.getReferencesTo(stringAddress);
            int count = 0;
            while (iterator.hasNext()) {
                Reference ref = iterator.next();
                count++;
                Address from = ref.getFromAddress();
                Function function = currentProgram.getFunctionManager().getFunctionContaining(from);
                writer.println("    - ref `" + from + "` from `" + (function == null ? "<none>" : function.getName()) + "` context `" + instructionContext(from) + "`");
                if (function != null) {
                    functions.add(function);
                }
            }
            writer.println("    - direct refs: `" + count + "`");
        }
        if (stringAddresses.isEmpty()) {
            writer.println("  - no exact string match found");
        }
        writer.println("- Referencing functions: `" + functions.size() + "`");
        int exported = 0;
        for (Function function : functions) {
            writer.println("  - `" + function.getName() + " @ " + function.getEntryPoint() + "`");
            if (includeDecompile && exported < MAX_DECOMPILE_FUNCTIONS_PER_KEY) {
                exportFunction(functionsDir, decompiler, key, function);
                exported++;
            }
        }
        if (!includeDecompile && !functions.isEmpty()) {
            writer.println("  - decompilation skipped in default refs-only mode");
        }
        writer.println();
    }

    private List<Address> findStringAddresses(String key) throws Exception {
        byte[] keyBytes = key.getBytes(StandardCharsets.UTF_8);
        byte[] pattern = new byte[keyBytes.length + 1];
        System.arraycopy(keyBytes, 0, pattern, 0, keyBytes.length);
        pattern[pattern.length - 1] = 0;

        Memory memory = currentProgram.getMemory();
        List<Address> matches = new ArrayList<>();
        Address cursor = memory.getMinAddress();
        while (cursor != null && cursor.compareTo(memory.getMaxAddress()) <= 0) {
            Address found = memory.findBytes(cursor, pattern, null, true, monitor);
            if (found == null) {
                break;
            }
            matches.add(found);
            cursor = found.add(1);
        }
        return matches;
    }

    private void exportFunction(File functionsDir, DecompInterface decompiler, String key, Function function) throws Exception {
        String safeName = key + "_" + function.getEntryPoint() + "_" + function.getName().replaceAll("[^A-Za-z0-9_.-]", "_") + ".c";
        File outFile = new File(functionsDir, safeName);
        if (outFile.exists()) {
            return;
        }
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("/*");
            writer.println(" * Setting key: " + key);
            writer.println(" * Function: " + function.getName() + " @ " + function.getEntryPoint());
            writer.println(" */");
            writer.println();
            if (function.getBody().getNumAddresses() > MAX_DECOMPILE_ADDRESSES) {
                writer.println("/* decompilation skipped: function too large */");
                writer.println("/*");
                dumpInstructions(writer, function);
                writer.println(" */");
                return;
            }

            DecompileResults results = decompiler.decompileFunction(function, MAX_DECOMPILE_SECONDS, monitor);
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

    private String instructionContext(Address address) {
        Listing listing = currentProgram.getListing();
        Instruction instruction = listing.getInstructionContaining(address);
        if (instruction == null) {
            instruction = listing.getInstructionAt(address);
        }
        return instruction == null ? "<no instruction>" : instruction.toString();
    }

    private void dumpInstructions(PrintWriter writer, Function function) {
        Listing listing = currentProgram.getListing();
        Instruction instruction = listing.getInstructionAt(function.getEntryPoint());
        int count = 0;
        while (instruction != null && function.getBody().contains(instruction.getAddress()) && count < 700) {
            writer.println(" * " + instruction.getAddress() + ": " + instruction);
            instruction = instruction.getNext();
            count++;
        }
        if (instruction != null && function.getBody().contains(instruction.getAddress())) {
            writer.println(" * ... truncated ...");
        }
    }
}
