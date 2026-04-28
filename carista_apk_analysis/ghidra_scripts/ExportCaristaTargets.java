// Export decompiled pseudocode for Carista native functions relevant to VAG CAN tuple recovery.
//@category Carista

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
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
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;

public class ExportCaristaTargets extends GhidraScript {
    private static final long GHIDRA_IMAGE_BASE_DELTA = 0x10000L;
    private static final int MAX_REFERENCES_PER_FUNCTION = 120;

    private static class Target {
        final String label;
        final String elfAddress;
        final int size;
        final String symbol;

        Target(String label, String elfAddress, int size, String symbol) {
            this.label = label;
            this.elfAddress = elfAddress;
            this.size = size;
            this.symbol = symbol;
        }
    }

    private final Target[] targets = new Target[] {
        new Target("JNI_ChangeSettingOperation_initNative", "00CB645C", 520,
            "Java_com_prizmos_carista_library_operation_ChangeSettingOperation_initNative"),
        new Target("JNI_ChangeSettingOperation_native_ctor_helper", "00CB674C", 64,
            "local helper called by ChangeSettingOperation_initNative"),
        new Target("JNI_CheckSettingsOperation_initNative", "00CB93C8", 460,
            "Java_com_prizmos_carista_library_operation_CheckSettingsOperation_initNative"),
        new Target("JNI_CheckSettingsOperation_native_ctor_helper", "00CB9594", 52,
            "local helper called by CheckSettingsOperation_initNative"),
        new Target("JNI_GetEcuInfoOperation_initNative", "00CBB01C", 472,
            "Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_initNative"),
        new Target("JNI_GetEcuInfoOperation_native_ctor_helper", "00CBB1F4", 60,
            "local helper called by GetEcuInfoOperation_initNative"),
        new Target("JNI_GetEcuInfoOperation_getCodingRawAddress", "00CBB40C", 340,
            "Java_com_prizmos_carista_library_operation_GetEcuInfoOperation_getCodingRawAddress"),
        new Target("JNI_ReadValuesOperation_getAvailableItems", "00CBDB9C", 1164,
            "Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems"),
        new Target("JNI_ReadValuesOperation_available_items_bridge_helper", "00CBE028", 52,
            "local helper called by ReadValuesOperation_getAvailableItems"),
        new Target("JNI_ReadValuesOperation_getSettingValue", "00CBE1DC", 416,
            "Java_com_prizmos_carista_library_operation_ReadValuesOperation_getSettingValue"),
        new Target("JNI_SettingCategory_valuesNative", "00CC1254", 568,
            "Java_com_prizmos_carista_library_model_SettingCategory_valuesNative"),
        new Target("JNI_SettingRef_getEcu", "00CC1E64", 368,
            "Java_com_prizmos_carista_library_model_SettingRef_getEcu"),
        new Target("JNI_SettingRef_getNameResIdNative", "00CC1FD4", 372,
            "Java_com_prizmos_carista_library_model_SettingRef_getNameResIdNative"),
        new Target("JNI_SettingRef_getInstruction", "00CC2298", 396,
            "Java_com_prizmos_carista_library_model_SettingRef_getInstruction"),
        new Target("JNI_SettingRef_toEventStringNative", "00CC2424", 396,
            "Java_com_prizmos_carista_library_model_SettingRef_toEventStringNative"),
        new Target("JNI_SettingRef_getInterpretation", "00CC25B0", 408,
            "Java_com_prizmos_carista_library_model_SettingRef_getInterpretation"),
        new Target("GetVagCanEcuInfoCommand_getRequest", "00CF8230", 20,
            "_ZNK23GetVagCanEcuInfoCommand10getRequestEv"),
        new Target("GetVagCanEcuInfoCommand_processPayloads", "00CF8244", 444,
            "_ZNK23GetVagCanEcuInfoCommand15processPayloadsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE"),
        new Target("GetVagCanEcuInfoCommand_processEcuInfo", "00CF8654", 888,
            "_ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"),
        new Target("WriteVagCodingCommand_ctor", "00D03048", 552,
            "_ZN21WriteVagCodingCommandC1EP3EcuRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEERKNS2_10shared_ptrIS7_EEN10VagEcuInfo10CodingTypeESC_"),
        new Target("WriteVagCodingCommand_getRequest", "00D032BC", 300,
            "_ZNK21WriteVagCodingCommand10getRequestEv"),
        new Target("VagOperationDelegate_getCodingRawAddress", "0125BE08", 492,
            "_ZN20VagOperationDelegate19getCodingRawAddressEP3Ecut"),
        new Target("VagOperationDelegate_readEcuInfo", "0125F2F0", 444,
            "_ZN20VagOperationDelegate11readEcuInfoEP3Ecu"),
        new Target("VagOperationDelegate_writeRawValue", "01261140", 704,
            "_ZN20VagOperationDelegate13writeRawValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE"),
        new Target("VagOperationDelegate_getSettingRawAddress", "012620EC", 204,
            "_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE"),
        new Target("VagOperationDelegate_writeVagCanCodingValue", "01263CEC", 324,
            "_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"),
        new Target("VagOperationDelegate_writeVagUdsValue_byKey", "0126379C", 68,
            "_ZN20VagOperationDelegate16writeVagUdsValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"),
        new Target("VagOperationDelegate_writeVagUdsValue_byEcuDid", "012637E0", 1060,
            "_ZN20VagOperationDelegate16writeVagUdsValueEP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEE"),
        new Target("WriteDataByIdentifierCommand_ctor", "00CF8034", 68,
            "_ZN28WriteDataByIdentifierCommandC1EP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEj"),
        new Target("WriteDataByIdentifierCommand_getRequest", "00CF80B4", 120,
            "_ZNK28WriteDataByIdentifierCommand10getRequestEv"),
        new Target("WriteDataByIdentifierCommand_processPayload", "00CF812C", 10,
            "_ZNK28WriteDataByIdentifierCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"),
        new Target("BaseCommand_extractPayloads", "00CCE52C", 276,
            "_ZNK11BaseCommand15extractPayloadsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE"),
        new Target("BaseCommand_filterOutErrors", "00CCE640", 156,
            "_ZN11BaseCommand15filterOutErrorsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE"),
        new Target("BaseCommand_removeEcho", "00CCE858", 264,
            "_ZNK11BaseCommand10removeEchoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"),
        new Target("BaseCommand_extractState", "00CCEA40", 236,
            "_ZN11BaseCommand12extractStateERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"),
        new Target("BaseCommand_isPositiveResponse", "00CCE9C0", 30,
            "_ZN11BaseCommand18isPositiveResponseERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_j"),
        new Target("BaseCommand_isPositiveUSDTResponse", "00CCEB7C", 140,
            "_ZN11BaseCommand22isPositiveUSDTResponseERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_j"),
        new Target("ReadDataByIdentifierCommand_Bytes_getRequest", "00CD5234", 116,
            "_ZNK27ReadDataByIdentifierCommandI10BytesModelE10getRequestEv"),
        new Target("GetVagUdsEcuWorkshopCodeCommand_ctor", "00D0505C", 56,
            "_ZN31GetVagUdsEcuWorkshopCodeCommandC1EP3Ecu"),
        new Target("GetVagUdsEcuWorkshopCodeCommand_processPayload", "00D050AC", 104,
            "_ZNK31GetVagUdsEcuWorkshopCodeCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE"),
        new Target("VagUdsCodingSetting_ctor_type_keyed", "0117A3A8", 124,
            "_ZN19VagUdsCodingSettingC1ERKNSt6__ndk110shared_ptrI15StringWhitelistEEN10VagSetting4TypeEP3EcutiRKNS0_6vectorIhNS0_9allocatorIhEEEEPKcRKNS1_I14InterpretationEENS6_7AvailByE"),
        new Target("VagUdsCodingSetting_ctor_ecu_vector", "0117A424", 140,
            "_ZN19VagUdsCodingSettingC1EP3EcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEiRKNS2_6vectorIhNS2_9allocatorIhEEEEPKcRKNS3_I14InterpretationEEN10VagSetting7AvailByE"),
        new Target("VagUdsCodingSetting_ctor_ecu_byte", "0117A4FC", 124,
            "_ZN19VagUdsCodingSettingC1EP3EcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEihPKcRKNS3_I14InterpretationEEN10VagSetting7AvailByE"),
        new Target("VagUdsCodingSetting_ctor_ecu_byte_values", "0117A578", 128,
            "_ZN19VagUdsCodingSettingC1EP3EcuRKNSt6__ndk110shared_ptrI15StringWhitelistEEihPKcRKNS3_I14InterpretationEERKNS3_IKNS2_6vectorIyNS2_9allocatorIyEEEEEEN10VagSetting7AvailByE"),
        new Target("VagSetting_insertValue", "0113B246", 22,
            "_ZNK10VagSetting11insertValueERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEES6_"),
        new Target("VagSetting_ctor", "0113B1EC", 80,
            "_ZN10VagSettingC1ERKNSt6__ndk110shared_ptrI15StringWhitelistEENS_4TypeEP3EcutiRKNS0_6vectorIhNS0_9allocatorIhEEEEPKcRKNS1_I14InterpretationEERKNS1_IKNS9_IyNSA_IyEEEEEEN7Setting11ConsistencyENS_7AvailByE"),
        new Target("Setting_ctor", "00D48AB0", 1052,
            "_ZN7SettingC1EhP3EcutiRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEPKcRKNS2_10shared_ptrI14InterpretationEERKNSB_IKNS3_IyNS4_IyEEEEEENS_11ConsistencyEy"),
        new Target("VagEcuInfo_getWorkshopCodeForWriting", "0110CD38", 692,
            "_ZN10VagEcuInfo25getWorkshopCodeForWritingEv"),
        new Target("VagOperationDelegate_makeWriteDataByIdentifier_date_or_wsc", "01263C04", 60,
            "local helper used by writeVagUdsValue for DATE/WORKSHOP_CODE DIDs"),
        new Target("VagOperationDelegate_makeReadDataByIdentifier", "01263C40", 60,
            "local helper used by writeVagUdsValue optional read-back"),
        new Target("VagOperationDelegate_makeRawCommand", "01263C7C", 52,
            "local helper used by writeVagUdsValue optional raw command"),
        new Target("VagOperationDelegate_makeWriteDataByIdentifier_target", "01263CB0", 60,
            "local helper used by writeVagUdsValue for final target DID"),
        new Target("VagOperationDelegate_readEcuInfoCached", "01266BD0", 500,
            "_ZN20VagOperationDelegate17readEcuInfoCachedEP3Ecujj"),
        new Target("VagOperationDelegate_readVagCanEcuInfo", "01266E30", 620,
            "_ZN20VagOperationDelegate17readVagCanEcuInfoEP9VagCanEcu"),
        new Target("Result_EmptyModel_isFatalFail", "011D620E", 8,
            "_ZNK6ResultI10EmptyModelvE11isFatalFailEv"),
        new Target("Result_EmptyModel_isFail", "011D63BA", 8,
            "_ZNK6ResultI10EmptyModelvE6isFailEv"),
        new Target("Result_EmptyModel_isIn", "011DDD30", 12,
            "_ZNK6ResultI10EmptyModelvE4isInERKN5State3SetE"),
        new Target("State_isFatalError", "00D2785C", 32,
            "_ZN5State12isFatalErrorEi"),
        new Target("State_isError", "00D27858", 4,
            "_ZN5State7isErrorEi"),
        new Target("State_Set_fatalError", "00D2787C", 184,
            "_ZN5State3Set10fatalErrorEv"),
        new Target("State_Set_obd2RequestNotSupported", "00D27A60", 164,
            "_ZN5State3Set23obd2RequestNotSupportedEv"),
        new Target("State_Set_obd2NegativeResponse", "00D279A8", 160,
            "_ZN5State3Set20obd2NegativeResponseEv"),
        new Target("OperationDelegate_runCommand_EmptyModel", "011D3F74", 160,
            "_ZN17OperationDelegate10runCommandI10EmptyModelEE6ResultIT_vERKNSt6__ndk110shared_ptrI7CommandIS3_EEERKNS6_I8ProgressEE"),
        new Target("ConnectionManager_runCommand_EmptyModel", "011DBC98", 240,
            "_ZN17ConnectionManager10runCommandI10EmptyModelEE6ResultIT_vERKNSt6__ndk110shared_ptrI7CommandIS3_EEERKNS6_IN5State21OnStateUpdateListenerEEE"),
        new Target("Communicator_runCommand_EmptyModel", "011DC844", 2072,
            "_ZN12Communicator10runCommandI10EmptyModelEE6ResultIT_vERKNSt6__ndk110shared_ptrI7CommandIS3_EEERKNS6_I10StatisticsEE"),
        new Target("SingleResponseCommand_EmptyModel_processResponses", "00CD1078", 148,
            "_ZNK21SingleResponseCommandI10EmptyModelE16processResponsesERKNSt6__ndk16vectorINS3_IhNS2_9allocatorIhEEEENS4_IS6_EEEE"),
        new Target("BroadcastCommandResult_EmptyModel_extractCommandResult", "011DC234", 132,
            "_ZNK22BroadcastCommandResultI10EmptyModelE20extractCommandResultEP3Ecu"),
        new Target("Communicator_internalExecuteCommand_EmptyModel", "011DD384", 520,
            "_ZN12Communicator22internalExecuteCommandI10EmptyModelEE22BroadcastCommandResultIT_ERKNSt6__ndk110shared_ptrI7CommandIS3_EEEjb"),
        new Target("VagCanCommunicator_postInitialize", "00D1759C", 192,
            "_ZN18VagCanCommunicator14postInitializeEv"),
        new Target("VagCanCommunicator_establishEcuComm", "00D1765C", 1036,
            "_ZN18VagCanCommunicator16establishEcuCommEP3Ecu"),
        new Target("VagCanCommunicator_sendDisconnect", "00D17D4C", 140,
            "_ZN18VagCanCommunicator14sendDisconnectEv"),
        new Target("VagCanCommunicator_closeEcuComm", "00D17DD8", 34,
            "_ZN18VagCanCommunicator12closeEcuCommEv"),
        new Target("VagCanCommunicator_readResponses", "00D182A8", 1532,
            "_ZN18VagCanCommunicator13readResponsesEv"),
        new Target("VagCanCommunicator_receive", "00D188A4", 84,
            "_ZN18VagCanCommunicator7receiveEv"),
        new Target("VagCanCommunicator_receiveMore", "00D1898C", 128,
            "_ZN18VagCanCommunicator11receiveMoreEv"),
        new Target("VagCanCommunicator_isOldSeqNum", "00D18A0C", 20,
            "_ZN18VagCanCommunicator11isOldSeqNumEhh"),
        new Target("VagCanCommunicator_incrementSeqNum", "00D18A46", 8,
            "_ZN18VagCanCommunicator15incrementSeqNumEh"),
        new Target("VagCanCommunicator_sendNack", "00D18A4E", 10,
            "_ZN18VagCanCommunicator8sendNackEh"),
        new Target("VagCanCommunicator_sendAck_seq", "00D18A94", 14,
            "_ZN18VagCanCommunicator7sendAckEhb"),
        new Target("VagCanCommunicator_sendAck_opcode", "00D18AD8", 192,
            "_ZN18VagCanCommunicator7sendAckENS_6OpCodeEhb"),
        new Target("VagCanCommunicator_getTimeoutSpec", "00D18BD8", 188,
            "_ZN18VagCanCommunicator14getTimeoutSpecEv"),
        new Target("VagCanCommunicator_getSeqNum", "00D18DB0", 18,
            "_ZN18VagCanCommunicator9getSeqNumEv"),
        new Target("VagCanPacket_isData", "00D173E8", 34,
            "_ZN18VagCanCommunicator12VagCanPacket6isDataEv"),
        new Target("VagCanPacket_ctor_fields", "00D172E4", 44,
            "_ZN18VagCanCommunicator12VagCanPacketC1EtNS_6OpCodeEhRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEE"),
        new Target("VagCanCommunicator_parsePacket", "00D17A68", 620,
            "_ZN18VagCanCommunicator11parsePacketERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEb"),
        new Target("VagCanPacket_toRawBytesForSending", "00D1740C", 180,
            "_ZN18VagCanCommunicator12VagCanPacket20toRawBytesForSendingEv")
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File outputDir = args.length > 0 ? new File(args[0]) : askDirectory("Output directory", "Export");
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

            for (Target target : targets) {
                if (monitor.isCancelled()) {
                    break;
                }
                exportTarget(decompiler, target, outputDir, indexLines);
            }
        }
        finally {
            decompiler.dispose();
        }

        File indexFile = new File(outputDir, "index.md");
        try (PrintWriter writer = new PrintWriter(new FileWriter(indexFile))) {
            writer.println("# Carista Ghidra target exports");
            writer.println();
            for (String line : indexLines) {
                writer.println(line);
            }
        }

        println("Wrote Carista target exports to " + outputDir.getAbsolutePath());
    }

    private void exportTarget(DecompInterface decompiler, Target target, File outputDir,
            List<String> indexLines) throws Exception {
        Address address = toGhidraAddress(target);
        String ghidraAddress = formatGhidraAddress(target);
        Function function = resolveExactFunction(target, address);
        decompiler.flushCache();

        File outputFile = new File(outputDir, target.label + "_" + ghidraAddress + ".c");
        try (PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {
            writer.println("/*");
            writer.println(" * " + target.label);
            writer.println(" * ELF symbol address: 0x" + target.elfAddress);
            writer.println(" * Ghidra address: 0x" + ghidraAddress + " (ELF + 0x10000 image delta)");
            writer.println(" * ELF symbol size: " + target.size + " bytes");
            writer.println(" * Symbol: " + target.symbol);
            writer.println(" * Program: " + currentProgram.getName());
            if (function != null) {
                writer.println(" * Resolved function: " + function.getName(true) + " @ " +
                    function.getEntryPoint());
                writer.println(" * Signature: " + function.getSignature());
                writer.println(" * Return type: " + function.getReturnType());
                writer.println(" * Function body: " + function.getBody());
                writer.println(" * Parameters:");
                for (Parameter parameter : function.getParameters()) {
                    writer.println(" *   [" + parameter.getOrdinal() + "] " +
                        parameter.getDataType() + " " + parameter.getName());
                }
                writer.println(" * Direct callers:");
                writeReferenceLines(writer, describeCallers(function));
                writer.println(" * Direct callees/references:");
                writeReferenceLines(writer, describeCallees(function));
            }
            writer.println(" */");
            writer.println();

            if (function == null) {
                writer.println("/* No function found at or containing 0x" + ghidraAddress + " */");
                indexLines.add("- `" + target.label + "` @ ELF `0x" + target.elfAddress +
                    "` / Ghidra `0x" + ghidraAddress + "`: no function found");
                println("No function found for " + target.label + " @ 0x" + ghidraAddress);
                return;
            }

            writer.println("/* Ghidra function: " + function.getName(true) + " @ " + function.getEntryPoint() + " */");
            writer.println();

            writer.println("/* First instructions after recreation:");
            byte[] bytes = new byte[Math.min(target.size, 32)];
            currentProgram.getMemory().getBytes(address, bytes);
            writer.println(" * Memory bytes: " + toHex(bytes));
            Listing listing = currentProgram.getListing();
            Instruction instruction = listing.getInstructionAt(address);
            for (int instructionCount = 0; instruction != null && instructionCount < 24; instructionCount++) {
                writer.println(" * " + instruction.getAddress() + ": " + instruction.toString());
                instruction = listing.getInstructionAfter(instruction.getAddress());
            }
            writer.println(" */");
            writer.println();

            DecompileResults results = decompiler.decompileFunction(function, 120, monitor);
            if (!results.decompileCompleted()) {
                writer.println("/* Decompile failed: " + results.getErrorMessage() + " */");
                indexLines.add("- `" + target.label + "` @ ELF `0x" + target.elfAddress +
                    "` / Ghidra `0x" + ghidraAddress + "`: decompile failed");
                println("Decompile failed for " + target.label + ": " + results.getErrorMessage());
                return;
            }

            writer.println(results.getDecompiledFunction().getC());
            indexLines.add("- `" + target.label + "` @ ELF `0x" + target.elfAddress +
                "` / Ghidra `0x" + ghidraAddress + "`: `" + outputFile.getName() + "`");
            println("Exported " + target.label + " -> " + outputFile.getName());
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

    private Address toGhidraAddress(Target target) {
        long elfAddress = Long.parseUnsignedLong(target.elfAddress, 16);
        return toAddr("0x" + Long.toHexString(elfAddress + GHIDRA_IMAGE_BASE_DELTA));
    }

    private String formatGhidraAddress(Target target) {
        long elfAddress = Long.parseUnsignedLong(target.elfAddress, 16);
        return String.format("%08X", elfAddress + GHIDRA_IMAGE_BASE_DELTA);
    }

    private Function resolveExactFunction(Target target, Address address) throws Exception {
        FunctionManager functions = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        Address end = address.add(target.size - 1);

        Function function = functions.getFunctionAt(address);
        Function containing = functions.getFunctionContaining(address);
        if (function != null) {
            println("Using exact existing function " + function.getName(true) + " @ " +
                function.getEntryPoint() + " for " + target.label + " @ " + address);
            return function;
        }
        if (containing != null) {
            println("Removing merged containing function " + containing.getName(true) + " @ " +
                containing.getEntryPoint() + " before recreating " + target.label + " @ " + address);
            removeFunction(containing);
        }

        listing.clearCodeUnits(address, end, true, monitor);

        Register tmode = currentProgram.getProgramContext().getRegister("TMode");
        if (tmode != null) {
            currentProgram.getProgramContext().setValue(tmode, address, end, BigInteger.ONE);
        }
        disassemble(address);

        function = createFunction(address, target.label);
        analyzeChanges(currentProgram);
        if (function == null) {
            function = functions.getFunctionAt(address);
        }
        if (function == null) {
            function = functions.getFunctionContaining(address);
        }
        return function;
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

    private String toHex(byte[] bytes) {
        StringBuilder builder = new StringBuilder();
        for (byte value : bytes) {
            builder.append(String.format("%02x", value & 0xff));
        }
        return builder.toString();
    }
}
