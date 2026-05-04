// Export focused instruction windows around selected Carista native addresses.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;

public class ExportCaristaInstructionWindows extends GhidraScript {
    private static class Target {
        final String label;
        final long address;

        Target(String label, long address) {
            this.label = label;
            this.address = address;
        }
    }

    private final Target[] targets = new Target[] {
        new Target("cornering_fogs_left_ref_1", 0x01082988L),
        new Target("cornering_fogs_left_ref_2", 0x01082A4AL),
        new Target("cornering_fogs_right_ref_1", 0x01082B78L),
        new Target("cornering_fogs_right_ref_2", 0x01082C34L),
        new Target("cornering_fogs_base_ref", 0x01082764L),
        new Target("cornering_fogs_experimental_ref", 0x010828BAL),
        new Target("coming_home_req_rls_ref", 0x0107671AL),
        new Target("coming_home_master_ref", 0x01076860L),
        new Target("coming_home_mode_ref", 0x01076AB4L),
        new Target("coming_leaving_home_output_ref_1", 0x010775EEL),
        new Target("coming_home_via_low_beams_ref", 0x010776D8L),
        new Target("coming_home_via_fogs_ref", 0x01077C50L),
        new Target("coming_home_duration_ref", 0x0107813EL),
        new Target("leaving_home_req_rls_ref", 0x0107879AL),
        new Target("leaving_home_duration_ref", 0x01078C66L),
        new Target("coming_leaving_home_output_ref_2", 0x01079282L),
        new Target("drl_via_fogs_ref_1", 0x0107AA66L),
        new Target("drl_via_fogs_ref_2", 0x0107ABF4L),
        new Target("assist_dr_lights_ref", 0x0108252CL),
        new Target("turn_off_fogs_with_high_beam_ref_1", 0x0107F15AL),
        new Target("turn_off_fogs_with_high_beam_ref_2", 0x0107F26CL),
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputDir = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
        if (!outputDir.exists() && !outputDir.mkdirs()) {
            throw new IllegalStateException("Could not create output directory: " + outputDir);
        }

        Listing listing = currentProgram.getListing();
        for (Target target : targets) {
            exportWindow(outputDir, listing, target);
        }
    }

    private void exportWindow(File outputDir, Listing listing, Target target) throws Exception {
        Address center = toAddr(target.address);
        Instruction instruction = listing.getInstructionContaining(center);
        if (instruction == null) {
            instruction = listing.getInstructionAt(center);
        }

        File outFile = new File(outputDir, target.label + "_" + String.format("%08X", target.address) + ".txt");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("# " + target.label);
            writer.println("Target address: " + center);
            Function function = currentProgram.getFunctionManager().getFunctionContaining(center);
            writer.println("Function: " + (function == null ? "<none>" : function.getName() + " @ " + function.getEntryPoint()));
            writer.println();

            if (instruction == null) {
                writer.println("No instruction at target.");
                return;
            }

            Instruction start = instruction;
            for (int i = 0; i < 90 && start.getPrevious() != null; i++) {
                start = start.getPrevious();
            }

            Instruction current = start;
            for (int i = 0; i < 190 && current != null; i++) {
                writer.print(current.getAddress());
                writer.print(current.getAddress().equals(instruction.getAddress()) ? "  =>  " : "      ");
                writer.print(current.toString());
                writeReferences(writer, current);
                writeScalars(writer, current);
                writer.println();
                current = current.getNext();
            }
        }
        println("Exported " + outFile.getAbsolutePath());
    }

    private void writeReferences(PrintWriter writer, Instruction instruction) {
        Reference[] references = instruction.getReferencesFrom();
        if (references.length == 0) {
            return;
        }
        writer.print("  ; refs:");
        for (Reference reference : references) {
            writer.print(" ");
            writer.print(reference.getReferenceType().getName());
            writer.print("->");
            writer.print(reference.getToAddress());
            Data data = currentProgram.getListing().getDataAt(reference.getToAddress());
            if (data != null) {
                writer.print("[");
                writer.print(data.getDataType().getName());
                writer.print("=");
                writer.print(data.getValue());
                writer.print("]");
            }
        }
    }

    private void writeScalars(PrintWriter writer, Instruction instruction) {
        Object[] objects = instruction.getOpObjects(0);
        boolean wroteHeader = false;
        for (Object object : objects) {
            if (object instanceof Scalar) {
                if (!wroteHeader) {
                    writer.print("  ; scalars:");
                    wroteHeader = true;
                }
                writer.print(" 0x");
                writer.print(Long.toHexString(((Scalar)object).getUnsignedValue()).toUpperCase());
            }
        }
    }
}
