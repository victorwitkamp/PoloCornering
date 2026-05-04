// Export direct references to selected Carista native setting key strings without decompilation.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

public class ExportCaristaSettingRefsOnly extends GhidraScript {
    private static final long GHIDRA_IMAGE_BASE_DELTA = 0x10000L;

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

        ReferenceManager referenceManager = currentProgram.getReferenceManager();
        File outFile = new File(outputDir, "setting_string_refs_only.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("# Carista Setting String References Only");
            writer.println();
            writer.println("No decompilation is attempted in this export.");
            writer.println();

            for (Target target : targets) {
                Address stringAddress = toAddr(target.elfAddress + GHIDRA_IMAGE_BASE_DELTA);
                writer.println("## `" + target.key + "`");
                writer.println();
                writer.println("- ELF address: `0x" + String.format("%08X", target.elfAddress) + "`");
                writer.println("- Ghidra address: `" + stringAddress + "`");

                ReferenceIterator refs = referenceManager.getReferencesTo(stringAddress);
                int count = 0;
                while (refs.hasNext()) {
                    Reference ref = refs.next();
                    count++;
                    Address from = ref.getFromAddress();
                    Function fn = currentProgram.getFunctionManager().getFunctionContaining(from);
                    Instruction instruction = currentProgram.getListing().getInstructionContaining(from);
                    writer.println(
                        "  - `" + from + "` from `" + (fn == null ? "<none>" : fn.getName()) + "`"
                        + " context `" + (instruction == null ? "<none>" : instruction.toString()) + "`"
                    );
                }
                writer.println("- Direct references: `" + count + "`");
                writer.println();
            }
        }
    }
}
