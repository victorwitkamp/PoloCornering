// Export decompilation for manually selected Carista native addresses.
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
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

public class ExportCaristaAddressTargets extends GhidraScript {
    private final long[] ghidraAddresses = new long[] {
        0x00E722A0L,
        0x00E822A0L,
        0x00E71AC0L,
        0x00E81AC0L,
        0x00E729D8L,
        0x00E829D8L,
        0x010B3DECL,
        0x010B3E34L,
        0x010B208CL,
        0x010B1348L,
        0x010B1618L,
        0x010B1930L,
        0x010B1708L,  // leaving_home_duration wrapper variant
        0x010B4218L,  // second coming_leaving_home_output variant wrapper
        0x010CCBC8L,  // callee behind 010B4218; helper class type target
        0x010B19D0L,
        0x010B1980L,
        0x010B5620L,
        0x010B5280L,
        0x010B5A98L,
        0x010B69C0L,
        0x010B6B3CL,  // coming_home_req_rls wrapper variant
        0x010B6B90L,  // coming_home_req_rls wrapper variant
        0x010B6BDCL,  // coming_home master wrapper variant
        0x010B6C30L,  // coming_home_mode wrapper variant
        0x010B6A0CL,
        0x010B6A58L,
        0x010B6AA4L,
        0x010B6C84L,
        0x010B704CL,  // coming_home_duration wrapper variant
        0x010B7094L,  // coming_home_duration wrapper variant
        0x010B7134L,  // coming/leaving duration wrapper variant
        0x010B7184L,  // leaving_home_req_rls wrapper variant
        0x010B71D0L,
        0x010B7270L,  // leaving_home_duration wrapper variant
        0x010B72C4L,  // leaving_home_duration wrapper variant
        0x010B7318L,  // leaving_home_duration/menu wrapper variant
        0x010B7368L,  // leaving_home_duration/menu wrapper variant
        0x010B74A0L,
        0x010B7764L,
        0x010B7F38L,
        0x010B8434L,
        0x010B8480L,
        0x010B8574L,
        0x010B9080L,
        0x010B90CCL,
        0x010B9120L,
        0x010B9170L,
        0x010D2BD0L,
        0x010D4140L,
        0x010E0DE8L,
        0x010E44E8L,
        0x010E466CL,
        0x010E47E4L,
        0x010B0C2CL,
        0x010B0C78L,
        0x010B0CC4L,
        0x010B0D10L,
        0x010B0D5CL,
        0x010B0DA8L,
        0x010B0DF4L,
        0x010B0E40L,
        0x010B1CA0L,  // coming_home_req_rls wrapper variant
        0x010B2040L,  // coming_home master wrapper variant
        0x010B2834L,  // DRL setting wrapper variant
        0x010B28D0L,  // DRL setting wrapper variant
        0x010B3AF0L,  // coming_home master wrapper variant
        0x00E8B8B4L,
        0x00E8DD54L,
        0x00E8FEECL,
        0x00E81484L,  // helper reached near car_setting_front_fogs_with_low_beams setup
        0x00E820A8L,  // helper reached near high-beam fog mode setup
        0x00E82930L,  // helper reached by car_setting_front_fogs_with_low_beams construction
        0x00E89B58L,  // callee behind 00E81484
        0x00E8D43CL,  // callee behind 00E820A8
        0x00E8FBE4L,  // callee behind 00E82930
        0x010CB7D8L,
        0x010C2874L,
        0x010C0418L,
        0x010C0590L,
        0x010C0708L,
        0x010C149CL,  // callee behind coming_home_req_rls wrapper
        0x010C2700L,  // callee behind coming_home master wrapper
        0x010C4EECL,  // callee behind DRL wrapper
        0x010C51D8L,  // callee behind DRL wrapper
        0x010CA958L,  // callee behind coming_home master wrapper
        0x010D1A6CL,
        0x010BE824L,
        0x010D88A0L,
        0x010D8FE4L,  // callee behind coming_home_req_rls wrapper
        0x010D917CL,  // callee behind coming_home_req_rls wrapper
        0x010D92ECL,  // callee behind coming_home master wrapper
        0x010D9484L,  // callee behind coming_home_mode wrapper
        0x010D9608L,  // callee behind coming_home_mode wrapper
        0x010DA7BCL,  // callee behind coming_home_duration wrapper
        0x010DA910L,  // callee behind coming_home_duration wrapper
        0x010DAEDCL,
        0x010DABF4L,  // callee behind coming/leaving duration wrapper
        0x010DAD6CL,  // callee behind leaving_home_req_rls wrapper
        0x010DB1E8L,  // callee behind leaving_home_duration wrapper
        0x010DB380L,  // callee behind leaving_home_duration wrapper
        0x010DB504L,  // callee behind leaving_home_duration wrapper
        0x010DB67CL,  // callee behind leaving_home_duration wrapper
        0x010DBC4CL,
        0x010DC980L,
        0x010DEE9CL,
        0x010E07FCL,
        0x010E0970L,
        0x01189DDCL,
        0x01189E6CL,
        0x01189F64L,
        0x0118A010L,
        0x0118A0ACL,
        0x0118A144L,
        0x0118A188L,
        0x0118A20CL,
        0x0118A290L,
        0x010BF9DCL,  // callee behind leaving_home_duration wrapper
        0x010BCB48L,
        0x010BC1ACL,
        0x010BC404L,
        0x010BC578L,
        0x010BC6ECL,
        0x010BC860L,
        0x010BCA18L,
        0x012CD520L,  // ReadValuesOperation::getAvailableItems base slot target
        0x012CD62CL,  // ReadValuesOperation::hasSettingValue base slot target
        0x012CD694L,  // ReadValuesOperation::getSettingValue base slot target
        0x012CD820L,  // ReadValuesOperation::isItemAvailable
        0x012CDE08L,  // ReadValuesOperation::readItemAvailabilityAndValues
        0x012CEA98L,  // ReadValuesOperation::addAvailableItems
        0x012CEB94L,  // ReadValuesOperation::addAvailableItem
        0x012CEBE0L,  // ReadValuesOperation::countAndMapByPresentEcu
        0x012703D0L,  // VagOperationDelegate::getSettingAvailability
        0x01270A10L,  // VagOperationDelegate::readRawValue
        0x0127075CL,  // VagOperationDelegate::getVagSettingAvailabilityForEcu
        0x01270CF8L,  // VagOperationDelegate::readRawValuesMulti
        0x012720ECL,  // VagOperationDelegate::getSettingRawAddress
        0x0127236CL,  // VagOperationDelegate::readVagCanAdaptationValue
        0x01272A1CL,  // VagOperationDelegate::readVagUdsValue
        0x01272AD0L,  // VagOperationDelegate::readVagUdsCodingValue
        0x01272CE0L,  // VagOperationDelegate::readVagUdsSubmoduleValue
        0x01156090L,  // _INIT_138; initializes VagWhitelists globals
        0x00D5CFD4L,  // StringWhitelist::combinedItems
        0x00D5D030L,  // StringWhitelist::itemMatches
        0x00D5D330L,  // StringWhitelist::match
        0x00E2D9F4L,  // WhitelistBasedSetting<StringWhitelist>::WhitelistBasedSetting real body
        0x0140EC70L,  // WhitelistBasedSetting<StringWhitelist>::WhitelistBasedSetting
    };

    private final long[] dataAddresses = new long[] {
        0x00AD5A21L,  // StringWhitelist wildcard token used by itemMatches
        0x014F6FA4L,  // VagWhitelists::CENTRAL_ELEC_6RU_LOW
        0x014F6FACL,  // VagWhitelists::CENTRAL_ELEC_6RU_HIGH
        0x014F6FB4L,  // VagWhitelists::CENTRAL_ELEC_6RU
        0x014F6FBCL,  // VagWhitelists::CENTRAL_ELEC_6R_EXCEPT_6RU
        0x014F6FC4L,  // VagWhitelists::CENTRAL_ELEC_6R
        0x014F6FECL,  // VagWhitelists::CENTRAL_ELEC_6R_5C_7E_7H
        0x014F7004L,  // VagWhitelists::CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S
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
            for (long rawAddress : ghidraAddresses) {
                Address address = toAddr(rawAddress);
                Function function = currentProgram.getFunctionManager().getFunctionContaining(address);
                File outFile = new File(outputDir, String.format("target_%08X.c", rawAddress));
                try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
                    writer.println("/* Target address " + address + " */");
                    if (function == null) {
                        writer.println("/* no containing function */");
                        continue;
                    }
                    writer.println("/* Function " + function.getName() + " @ " + function.getEntryPoint() + " */");
                    writer.println();
                    if (rawAddress == 0x0140EC70L) {
                        writer.println("/* Instruction flow for whitelist constructor target:");
                        Listing listing = currentProgram.getListing();
                        Instruction instruction = listing.getInstructionAt(function.getEntryPoint());
                        int count = 0;
                        while (instruction != null && function.getBody().contains(instruction.getAddress()) && count < 80) {
                            writer.print(" * ");
                            writer.print(instruction.getAddress());
                            writer.print(": ");
                            writer.print(instruction);
                            Address[] flows = instruction.getFlows();
                            if (flows.length > 0) {
                                writer.print(" ->");
                                for (Address flow : flows) {
                                    writer.print(" ");
                                    writer.print(flow);
                                }
                            }
                            writer.println();
                            instruction = instruction.getNext();
                            count++;
                        }
                        writer.println(" */");
                        writer.println();
                    }
                    DecompileResults results = decompiler.decompileFunction(function, 120, monitor);
                    if (results != null && results.decompileCompleted()) {
                        writer.println(results.getDecompiledFunction().getC());
                    }
                    else {
                        writer.println("/* decompilation failed */");
                        writer.println("/*");
                        Listing listing = currentProgram.getListing();
                        Instruction instruction = listing.getInstructionAt(function.getEntryPoint());
                        int count = 0;
                        while (instruction != null && function.getBody().contains(instruction.getAddress()) && count < 500) {
                            writer.println(" * " + instruction.getAddress() + ": " + instruction);
                            instruction = instruction.getNext();
                            count++;
                        }
                        writer.println(" */");
                    }
                }
            }
            exportDataTargets(outputDir);
            exportWhitelistSymbols(outputDir);
        }
        finally {
            decompiler.dispose();
        }
    }

    private void exportWhitelistSymbols(File outputDir) throws Exception {
        File outFile = new File(outputDir, "whitelist_symbols.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
            writer.println("# Whitelist Symbol Matches");
            writer.println();
            SymbolIterator symbols = currentProgram.getSymbolTable().getAllSymbols(true);
            while (symbols.hasNext()) {
                Symbol symbol = symbols.next();
                String name = symbol.getName(true);
                if (name.contains("StringWhitelist") || name.contains("VagWhitelists")) {
                    writer.println("- `" + symbol.getAddress() + "` `" + symbol.getSymbolType() + "` `" + name + "`");
                }
            }
        }
    }

    private void exportDataTargets(File outputDir) throws Exception {
        ReferenceManager references = currentProgram.getReferenceManager();
        Listing listing = currentProgram.getListing();
        for (long rawAddress : dataAddresses) {
            Address address = toAddr(rawAddress);
            File outFile = new File(outputDir, String.format("data_%08X.md", rawAddress));
            try (PrintWriter writer = new PrintWriter(new FileWriter(outFile))) {
                writer.println("# Data Target `" + address + "`");
                writer.println();
                writer.println("## Symbols");
                Symbol[] symbols = currentProgram.getSymbolTable().getSymbols(address);
                boolean wroteSymbol = false;
                for (Symbol symbol : symbols) {
                    writer.println("- `" + symbol.getSymbolType() + "` `" + symbol.getName(true) + "`");
                    wroteSymbol = true;
                }
                if (!wroteSymbol) {
                    writer.println("- <none>");
                }
                writer.println();

                writer.println("## Memory Bytes");
                byte[] bytes = new byte[64];
                try {
                    currentProgram.getMemory().getBytes(address, bytes);
                    writer.println("`" + toHex(bytes) + "`");
                }
                catch (Exception exception) {
                    writer.println("<unreadable: " + exception.getClass().getSimpleName() + ": " + exception.getMessage() + ">");
                }
                writer.println();

                writer.println("## Direct References To This Address");
                boolean wroteRef = false;
                for (Reference reference : references.getReferencesTo(address)) {
                    Function function = currentProgram.getFunctionManager().getFunctionContaining(reference.getFromAddress());
                    writer.println("- `" + reference.getReferenceType() + "` from `" + reference.getFromAddress() + "` in `" +
                        (function == null ? "<no function>" : function.getName(true) + " @ " + function.getEntryPoint()) + "`");
                    wroteRef = true;
                }
                if (!wroteRef) {
                    writer.println("- <none>");
                }
                writer.println();

                writer.println("## Instructions At Direct Reference Sites");
                wroteRef = false;
                for (Reference reference : references.getReferencesTo(address)) {
                    Instruction instruction = listing.getInstructionAt(reference.getFromAddress());
                    if (instruction != null) {
                        writer.println("- `" + instruction.getAddress() + "`: `" + instruction + "`");
                        wroteRef = true;
                    }
                }
                if (!wroteRef) {
                    writer.println("- <none>");
                }
                writer.println();

                writer.println("## Local Instruction Windows");
                wroteRef = false;
                for (Reference reference : references.getReferencesTo(address)) {
                    Instruction center = listing.getInstructionAt(reference.getFromAddress());
                    if (center == null) {
                        continue;
                    }
                    writer.println("### Around `" + center.getAddress() + "`");
                    Instruction instruction = center;
                    for (int count = 0; count < 12 && instruction.getPrevious() != null; count++) {
                        instruction = instruction.getPrevious();
                    }
                    for (int count = 0; count < 38 && instruction != null; count++) {
                        writer.print("- `" + instruction.getAddress() + "`: `" + instruction + "`");
                        Reference[] refsFromInstruction = references.getReferencesFrom(instruction.getAddress());
                        if (refsFromInstruction.length > 0) {
                            writer.print(" refs:");
                            for (Reference refsFrom : refsFromInstruction) {
                                writer.print(" `" + refsFrom.getReferenceType() + " -> " + refsFrom.getToAddress() + "`");
                            }
                        }
                        writer.println();
                        instruction = instruction.getNext();
                    }
                    wroteRef = true;
                }
                if (!wroteRef) {
                    writer.println("- <none>");
                }
            }
        }
    }

    private String toHex(byte[] bytes) {
        StringBuilder builder = new StringBuilder();
        for (byte value : bytes) {
            builder.append(String.format("%02x", value & 0xff));
        }
        return builder.toString();
    }
}
