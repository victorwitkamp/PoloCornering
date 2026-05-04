from __future__ import annotations

from dataclasses import dataclass

from .Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from .VagCoding import bit_state, chunk_value6, derive_value6
from .Constants import CORNERING_FIXES, PQ25_SUPPORTED_SETTING_DEFINITIONS
from .Models.Pq25SettingDefinition import Pq25SettingDefinition
from .Models.Pq25SupportedSetting import Pq25SupportedSetting
from .Types import HexString, VagCanSettingsConstructorKind, VagCanSettingsConstructorStatus


@dataclass(frozen=True)
class VagCanSettingsChoice:
    key: str
    requested_value: HexString | None
    evidence: str


@dataclass(frozen=True)
class VagCanSettingsSettingRecovery:
    key: str
    label: str
    ecu: str
    native_function: str
    reference_address: str
    instruction_window: str | None
    constructor_kind: VagCanSettingsConstructorKind
    constructor_status: VagCanSettingsConstructorStatus
    native_helper: str | None
    raw_address: int | None
    value_offset: int | None
    value_mask: HexString | None
    immediate_value: int | None
    immediate_index: int | None
    choices: tuple[VagCanSettingsChoice, ...]
    read_method: str
    write_method: str
    next_re_step: str
    evidence: tuple[str, ...]


@dataclass(frozen=True)
class VagCanSettingsNativeHelper:
    callsite: str
    target: str
    family: str


@dataclass(frozen=True)
class VagCanSettingsNativeSetting:
    key: str
    string_ref: str
    helpers: tuple[VagCanSettingsNativeHelper, ...]
    recovered_shape: tuple[str, ...]
    read_candidate_dids: tuple[int, ...]
    safety_note: str


@dataclass(frozen=True)
class VagCanSettingsReadOnlyCandidate:
    did: int
    key: str
    purpose: str
    status: str

    @property
    def request(self) -> HexString:
        return ReadDataByIdentifierCommand_getRequest(self.did)


VAG_CAN_SETTINGS_GET_SETTINGS_SYMBOL = "_ZN14VagCanSettings11getSettingsEv"
VAG_CAN_SETTINGS_GET_SETTINGS_ADDRESS = "0x012a20c0"
VAG_CAN_SETTINGS_GET_SETTINGS_EBX_BASE = "0x01a35618"


VAG_CAN_SETTINGS_NATIVE_SETTINGS: tuple[VagCanSettingsNativeSetting, ...] = (
    VagCanSettingsNativeSetting(
        key="car_setting_coming_leaving_home_output",
        string_ref="0x012c88d0",
        helpers=(
            VagCanSettingsNativeHelper("0x012c8913", "0x0133fdf0", "VagUdsCodingSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c8a1e", "0x0133fdf0", "VagUdsCodingSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=("raw/address 0x110e", "offset 2", "field/mask 1", "choices fogs=00 low_beams=01"),
        read_candidate_dids=(0x110E,),
        safety_note="Read-only 22110E candidate; do not write without positive payload and branch proof.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_via_low_beams",
        string_ref="0x012c8a55",
        helpers=(
            VagCanSettingsNativeHelper("0x012c8a8a", "0x01358fd0", "FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c8bf7", "0x013604b0", "VagUdsCodingSetting-neighborhood wrapper"),
        ),
        recovered_shape=("variant helper families recovered", "exact raw read candidate not recovered from this callsite"),
        read_candidate_dids=(),
        safety_note="Constructor family evidence only; no standalone read/write candidate from this callsite.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_via_fogs",
        string_ref="0x012c929b",
        helpers=(
            VagCanSettingsNativeHelper("0x012c92d0", "0x01340190", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c93f1", "0x01348190", "VagUdsCodingSetting-neighborhood wrapper"),
        ),
        recovered_shape=("coding-style pair 0x20/0x06", "nearby raw 0x056d offset 5 mask 0xff value 0x1e", "nearby raw 0x0550/0x0551 offset 0x0d mask 0xff"),
        read_candidate_dids=(0x056D, 0x0550, 0x0551),
        safety_note="Read-only 22056D/220550/220551 candidates; no writes without positive payload and runtime branch proof.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_drl_via_fogs",
        string_ref="0x012cde7b",
        helpers=(
            VagCanSettingsNativeHelper("0x012cdeb6", "0x01361520", "VagCanLongCodingSetting-neighborhood wrapper"),
            VagCanSettingsNativeHelper("0x012cdf28", "0x01363440", "VagUdsAdaptationSetting-neighborhood wrapper"),
        ),
        recovered_shape=("coding-style pairs 0x17/0x04, 0x11/0x10, 0x0e/0x02", "older static branch includes raw 0x055c offset 6 mask 0xff"),
        read_candidate_dids=(0x055C,),
        safety_note="22055C already returned 7F2231 live; keep as negative evidence, not a default probe.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_turn_off_fogs_with_high_beam",
        string_ref="0x012d4db5",
        helpers=(
            VagCanSettingsNativeHelper("0x012d4dea", "0x0135e580", "VagUdsCodingSetting-neighborhood wrapper"),
            VagCanSettingsNativeHelper("0x012d4e65", "0x01368100", "VagUdsCodingSetting-neighborhood wrapper"),
        ),
        recovered_shape=("coding-style pairs 0x20/0x15, 0x20/0x11, 0x04/0x0e", "adaptation raw 0x0d01 fields 1/1", "nearby adaptation raw 0x0a58"),
        read_candidate_dids=(0x0D01, 0x0A58),
        safety_note="Read-only 220D01/220A58 candidates; do not write until the runtime branch and payload are proven.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_assist_dr_lights",
        string_ref="0x012d9b78",
        helpers=(
            VagCanSettingsNativeHelper("0x012d9bad", "0x013625a0", "VagCanLongCodingSetting-neighborhood wrapper"),
            VagCanSettingsNativeHelper("0x012d9cc0", "0x0135f600", "VagUdsAdaptationSetting-neighborhood wrapper"),
        ),
        recovered_shape=("coding-style pair 0x20/0x16",),
        read_candidate_dids=(),
        safety_note="Constructor family evidence only; no standalone read/write candidate from this callsite.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_via_fogs_left",
        string_ref="0x012da210",
        helpers=(
            VagCanSettingsNativeHelper("0x012da25a", "0x0136c910", "VagCanLongCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012da39a", "0x01356f90", "VagUdsAdaptationSetting-neighborhood wrapper"),
        ),
        recovered_shape=("raw/DID 0x055c", "offset 5", "mask 0xff", "choices off=00 on=16 coming/leaving=1e"),
        read_candidate_dids=(0x055C,),
        safety_note="22055C already returned 7F2231 live; never build a 2E055C write from static data alone.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_via_fogs_right",
        string_ref="0x012da55f",
        helpers=(
            VagCanSettingsNativeHelper("0x012da5a9", "0x01368690", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
            VagCanSettingsNativeHelper("0x012da6e9", "0x0136caf0", "VagUdsAdaptationSetting-neighborhood wrapper"),
        ),
        recovered_shape=("raw/DID 0x055d", "offset 5", "mask 0xff", "choices off=00 on=17 coming/leaving=1e"),
        read_candidate_dids=(0x055D,),
        safety_note="22055D already returned 7F2231 live; never build a 2E055D write from static data alone.",
    ),
)


VAG_CAN_SETTINGS_READ_ONLY_CANDIDATES: tuple[VagCanSettingsReadOnlyCandidate, ...] = (
    VagCanSettingsReadOnlyCandidate(0x110E, "car_setting_coming_leaving_home_output", "Coming/leaving-home output selector adaptation/coding candidate", "unverified_live"),
    VagCanSettingsReadOnlyCandidate(0x056D, "car_setting_coming_home_via_fogs", "Coming-home via fogs nearby UDS adaptation candidate", "unverified_live"),
    VagCanSettingsReadOnlyCandidate(0x0550, "car_setting_coming_home_via_fogs", "Coming-home via fogs nearby raw channel candidate", "unverified_live"),
    VagCanSettingsReadOnlyCandidate(0x0551, "car_setting_coming_home_via_fogs", "Coming-home via fogs nearby raw channel candidate", "unverified_live"),
    VagCanSettingsReadOnlyCandidate(0x0D01, "car_setting_turn_off_fogs_with_high_beam", "Turn-off-fogs-with-high-beam UDS adaptation candidate", "unverified_live"),
    VagCanSettingsReadOnlyCandidate(0x0A58, "car_setting_turn_off_fogs_with_high_beam", "Turn-off-fogs-with-high-beam nearby UDS adaptation candidate", "unverified_live"),
    VagCanSettingsReadOnlyCandidate(0x055C, "car_setting_cornering_lights_via_fogs_left", "Left cornering/fog role static candidate; live direct read rejected", "live_rejected_7F2231"),
    VagCanSettingsReadOnlyCandidate(0x055D, "car_setting_cornering_lights_via_fogs_right", "Right cornering/fog role static candidate; live direct read rejected", "live_rejected_7F2231"),
)


def VagCanSettings_nativeSettingsByKey() -> dict[str, VagCanSettingsNativeSetting]:
    return {setting.key: setting for setting in VAG_CAN_SETTINGS_NATIVE_SETTINGS}


def VagCanSettings_getNativeSetting(key: str) -> VagCanSettingsNativeSetting:
    return VagCanSettings_nativeSettingsByKey()[key]


def VagCanSettings_readOnlyCandidates(include_known_rejected: bool = False) -> tuple[VagCanSettingsReadOnlyCandidate, ...]:
    if include_known_rejected:
        return VAG_CAN_SETTINGS_READ_ONLY_CANDIDATES
    return tuple(candidate for candidate in VAG_CAN_SETTINGS_READ_ONLY_CANDIDATES if not candidate.status.startswith("live_rejected"))


def VagCanSettings_readOnlyDidRequests(include_known_rejected: bool = False) -> tuple[HexString, ...]:
    return tuple(candidate.request for candidate in VagCanSettings_readOnlyCandidates(include_known_rejected))


def VagCanSettings_commandLabels(include_known_rejected: bool = True) -> dict[HexString, str]:
    return {
        candidate.request: f"VagCanSettings::getSettings Play 9.8.3 x86 {candidate.key}: {candidate.purpose}; status={candidate.status}"
        for candidate in VagCanSettings_readOnlyCandidates(include_known_rejected)
    }


def _choice(key: str, requested_value: str | None, evidence: str) -> VagCanSettingsChoice:
    return VagCanSettingsChoice(key=key, requested_value=requested_value, evidence=evidence)


def VagCanSettings_getPq25SettingDefinitions() -> tuple[Pq25SettingDefinition, ...]:
    definitions: list[Pq25SettingDefinition] = []
    for key, label, cornering_fix in PQ25_SUPPORTED_SETTING_DEFINITIONS:
        byte_index, bit_index, description = CORNERING_FIXES[cornering_fix]
        definitions.append(
            Pq25SettingDefinition(
                key=key,
                label=label,
                cornering_fix=cornering_fix,
                byte_index=byte_index,
                bit_index=bit_index,
                ecu_module="PQ25 BCM/J519 6R0937087K",
                java_bridge="ReadValuesOperation availability map returns native Setting/SettingRef bridge objects",
                native_write_path="ChangeSettingOperation -> VagOperationDelegate::writeRawValue -> UDS type-8 DID 0600 or blocked VAG-CAN 3B9A tuple path",
                confidence="known coding effect; exact native Setting catalog entry unresolved",
                evidence=(
                    description,
                    "Carista resource/native-string map contains this setting key",
                    "known-good long-coding delta changes this byte/bit",
                    "JNI bridge proves Setting + requested byte[] + ReadValuesOperation crosses into native ChangeSettingOperation",
                ),
                unresolved=(
                    "Concrete native Setting object address/nativeId is not recovered yet",
                    "ReadValuesOperation slot 0x7c/0x8c concrete runtime target is not named yet",
                ),
            )
        )
    return tuple(definitions)


def VagCanSettings_getPq25SupportedSettings(coding: HexString) -> list[Pq25SupportedSetting]:
    settings: list[Pq25SupportedSetting] = []
    for key, label, cornering_fix in PQ25_SUPPORTED_SETTING_DEFINITIONS:
        byte_index, bit_index, description = CORNERING_FIXES[cornering_fix]
        current_state = bit_state(coding, byte_index, bit_index)
        chunk_index, byte_start, current_value6 = chunk_value6(coding, byte_index)
        target = derive_value6(coding, 6, None, byte_index, bit_index, "set", description)
        settings.append(
            Pq25SupportedSetting(
                key=key,
                label=label,
                cornering_fix=cornering_fix,
                byte_index=byte_index,
                bit_index=bit_index,
                current_state=current_state,
                desired_state="set",
                chunk_index=chunk_index,
                byte_start=byte_start,
                current_value6=current_value6,
                target_value6=target.value6,
                status="already_enabled" if current_state == "set" else "pending_enable",
            )
        )
    return settings


def VagCanSettings_getPq25SettingRecoveries() -> tuple[VagCanSettingsSettingRecovery, ...]:
    return (
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_via_fogs_left",
            label="Cornering lights using left fog output",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012da210 (Play 9.8.3 x86); 01082988 / 01082A4A (older ARM windows)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; cornering_fogs_left_ref_1_01082988.txt; cornering_fogs_left_ref_2_01082A4A.txt",
            constructor_kind="mixed",
            constructor_status="write_blocked_read_rejected",
            native_helper="0x012da25a -> 0x0136c910 VagCanLongCodingSetting; 0x012da39a -> 0x01356f90 VagUdsAdaptationSetting-neighborhood; readVagUdsValue -> ReadRawDataByIdentifierCommand for the 055C type-7 branch",
            raw_address=0x055C,
            value_offset=5,
            value_mask="FF",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_off", "00", "055C choice table"),
                _choice("car_setting_on", "16", "055C choice table"),
                _choice("car_setting_enabled_coming_home_or_leaving_home", "1E", "055C choice table"),
            ),
            read_method="22055C",
            write_method="Blocked: live direct read returned 7F2231, so no raw payload seed exists for 2E055C.",
            next_re_step="Recover why Carista can expose this setting without a positive direct 22055C read, or find the required session/security precondition.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012da210 inside VagCanSettings::getSettings with EBX base 0x01a35618.",
                "Official x86 visible helper call 0x012da25a targets 0x0136c910, a VagCanLongCodingSetting wrapper; adjacent helper 0x01356f90 is a VagUdsAdaptationSetting-neighborhood wrapper.",
                "Native constructor uses raw address 055C, value offset 5, mask FF.",
                "Type 7 dispatch goes through UDS raw DID read/write helpers.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_via_fogs_right",
            label="Cornering lights using right fog output",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012da55f (Play 9.8.3 x86); 01082B78 / 01082C34 (older ARM windows)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; cornering_fogs_right_ref_1_01082B78.txt; cornering_fogs_right_ref_2_01082C34.txt",
            constructor_kind="VagUdsAdaptationSetting",
            constructor_status="write_blocked_read_rejected",
            native_helper="0x012da5a9 -> 0x01368690 VagUdsAdaptationSetting/NumericalInterpretation; 0x012da6e9 -> 0x0136caf0 VagUdsAdaptationSetting-neighborhood; readVagUdsValue -> ReadRawDataByIdentifierCommand for the 055D type-7 branch",
            raw_address=0x055D,
            value_offset=5,
            value_mask="FF",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_off", "00", "055D choice table"),
                _choice("car_setting_on", "17", "055D choice table"),
                _choice("car_setting_enabled_coming_home_or_leaving_home", "1E", "055D choice table"),
            ),
            read_method="22055D",
            write_method="Blocked: live direct read returned 7F2231, so no raw payload seed exists for 2E055D.",
            next_re_step="Recover why Carista can expose this setting without a positive direct 22055D read, or find the required session/security precondition.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012da55f inside VagCanSettings::getSettings with EBX base 0x01a35618.",
                "Official x86 helper call 0x012da5a9 targets 0x01368690, a VagUdsAdaptationSetting wrapper using NumericalInterpretation.",
                "Native constructor uses raw address 055D, value offset 5, mask FF.",
                "Type 7 dispatch goes through UDS raw DID read/write helpers.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_req_rls",
            label="Coming-home requires rain/light sensor",
            ecu="PQ25 BCM / unit 09",
            native_function="FUN_0105f6c0",
            reference_address="0107671A / 01076772 / 010767E0 / 01076964",
            instruction_window="coming_home_req_rls_ref_0107671A.txt; coming_home_master_ref_01076860.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper=(
                "010B6B3C -> 010D8FE4 VagUdsAdaptationSetting; "
                "010B6B90 -> 010D917C VagCanLongCodingSetting; "
                "010B0D5C -> 010BC860 VagUdsCodingSetting; "
                "010B19D0 -> 010C0708 VagUdsCodingSetting"
            ),
            raw_address=0x0A57,
            value_offset=2,
            value_mask="04",
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="220A57 is the adaptation-branch read candidate only; other refs are coding/long-coding variants.",
            write_method="Do not write from this recovery until runtime branch selection and positive read/packing evidence are known.",
            next_re_step="Identify which coming_home_req_rls branch is selected for 6R0937087K and test 220A57 read-only before any adaptation write.",
            evidence=(
                "Instruction window shows raw address 0A57, offset 2, mask/value field 04 before one req-RLS constructor.",
                "target_010B6B3C.c calls 010D8FE4, which constructs VagUdsAdaptationSetting.",
                "target_010B6B90.c calls 010D917C, which constructs VagCanLongCodingSetting.",
                "target_010B0D5C.c calls 010BC860, which constructs VagUdsCodingSetting.",
                "The same key appears again through 010B19D0 -> 010C0708, another VagUdsCodingSetting helper.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home",
            label="Coming-home master switch",
            ecu="PQ25 BCM / unit 09",
            native_function="FUN_0105f6c0",
            reference_address="01076860 / 010768BA / 01076910",
            instruction_window="coming_home_master_ref_01076860.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper=(
                "010B6BDC -> 010D92EC VagUdsAdaptationSetting; "
                "010B2040 -> 010C2700 VagUdsCodingSetting; "
                "010B3AF0 -> 010CA958 VagUdsCodingSetting"
            ),
            raw_address=0x0A57,
            value_offset=4,
            value_mask="40",
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="220A57 is the adaptation-branch read candidate only; the same key also has UDS coding variants.",
            write_method="Do not write from this recovery until runtime branch selection and positive read/packing evidence are known.",
            next_re_step="Runtime-select the active coming_home branch for this BCM; then prove 220A57 or exact coding packing before any write.",
            evidence=(
                "Instruction window shows raw address 0A57, offset 4, mask/value field 40 before one coming_home constructor.",
                "target_010B6BDC.c calls 010D92EC, which constructs VagUdsAdaptationSetting.",
                "target_010B2040.c calls 010C2700, which constructs VagUdsCodingSetting.",
                "target_010B3AF0.c calls 010CA958, which constructs VagUdsCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_mode",
            label="Coming-home mode",
            ecu="PQ25 BCM / unit 09",
            native_function="FUN_0105f6c0",
            reference_address="01076AB4 / 01076B5E / 01076BF4",
            instruction_window="coming_home_mode_ref_01076AB4.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper="010B6C30 -> 010D9484 VagUdsAdaptationSetting; 010B6C84 -> 010D9608 VagCanLongCodingSetting",
            raw_address=0x0A57,
            value_offset=2,
            value_mask="03",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_disabled", "00", "0A57 mode choice table in coming_home_mode_ref."),
                _choice("car_setting_coming_home_manual", "01", "0A57 mode choice table in coming_home_mode_ref."),
                _choice("car_setting_coming_home_automatic", "02", "0A57 mode choice table in coming_home_mode_ref."),
            ),
            read_method="220A57 adaptation candidate at offset 2; a long-coding variant is also present.",
            write_method="Do not write from this recovery until runtime branch selection and positive read/packing evidence are known.",
            next_re_step="Determine whether this BCM uses the 0A57 adaptation branch or the long-coding branch for coming_home_mode.",
            evidence=(
                "Instruction window shows raw address 0A57, offset/count 2/3 and disabled/manual/automatic choices.",
                "target_010B6C30.c calls 010D9484, which constructs VagUdsAdaptationSetting.",
                "target_010B6C84.c calls 010D9608, which constructs VagCanLongCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_duration",
            label="Coming-home duration",
            ecu="PQ25 BCM / unit 09",
            native_function="FUN_0105f6c0",
            reference_address="0107813E / nearby duration variants",
            instruction_window="coming_home_duration_ref_0107813E.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper=(
                "010B704C -> 010DA7BC FullByteVagCanShortAdaptationSetting; "
                "010B7094 -> 010DA910 VagUdsAdaptationSetting"
            ),
            raw_address=0x0A57,
            value_offset=3,
            value_mask="FF",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_time_10sec", "0A", "0A57 duration table."),
                _choice("car_setting_time_15sec", "0F", "0A57 duration table."),
                _choice("car_setting_time_20sec", "14", "0A57 duration table."),
                _choice("car_setting_time_30sec", "1E", "0A57 duration table."),
                _choice("car_setting_time_40sec", "28", "0A57 duration table."),
                _choice("car_setting_time_50sec", "32", "0A57 duration table."),
                _choice("car_setting_time_60sec", "3C", "0A57 duration table."),
            ),
            read_method="VAG short-adaptation and 220A57 UDS-adaptation duration variants are both present.",
            write_method="Do not write from this recovery until runtime branch selection proves which adaptation path applies.",
            next_re_step="Runtime-select whether Carista uses the short-adaptation branch or UDS 0A57 duration branch on this BCM.",
            evidence=(
                "Instruction window shows 10-60 second duration tables and one 0A57 offset 3 mask FF UDS branch.",
                "target_010B704C.c calls 010DA7BC, which constructs FullByteVagCanShortAdaptationSetting.",
                "target_010B7094.c calls 010DA910, which constructs VagUdsAdaptationSetting with NumericalInterpretation.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_leaving_home_output",
            label="Coming/leaving-home output selector",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012c88d0 (Play 9.8.3 x86); 010775EE / 01077694 / 01079282 / 01079316 (older ARM windows)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; coming_leaving_home_output_ref_1_010775EE.txt; coming_leaving_home_output_ref_2_01079282.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_recovered_coding_raw_address_unresolved",
            native_helper="0x012c8913 -> 0x0133fdf0 VagUdsCodingSetting / VagUdsEcu / MultipleChoiceInterpretation; 0x010B1930 -> 0x010C0418 -> VagUdsAdaptationSetting; 0x010B4218 -> 0x010CCBC8 -> VagUdsCodingSetting",
            raw_address=0x110E,
            value_offset=2,
            value_mask="01",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_fogs", "00", "Choice table stores 0 next to car_setting_fogs in the instruction window."),
                _choice("car_setting_low_beams", "01", "Choice table stores 1 next to car_setting_low_beams in the instruction window."),
            ),
            read_method="22110E is the native-shaped read candidate for the adaptation path only; the coding path raw address/packing remains unresolved.",
            write_method="Do not write either path until branch selection and positive read/packing evidence are known.",
            next_re_step="Resolve the VagUdsCodingSetting raw address/index packing around coming_leaving_home_output_ref_2_01079282 and identify which runtime branch applies to this BCM.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012c88d0; first visible helper call targets 0x0133fdf0.",
                "Official static candidate is read-only DID 0x110E with offset 2 / field 1; this is not a write seed yet.",
                "Instruction window shows raw address 110E, value offset 2, mask/value field 1 near the key.",
                "Ghidra export target_010B1930.c calls 0x010C0418.",
                "Ghidra export target_010C0418.c constructs VagUdsAdaptationSetting.",
                "Second-path instruction window stores coding-like immediate pairs 40/0D and 08/11 before calling 0x010B4218.",
                "Instruction window coming_leaving_home_output_ref_2_01079282 calls 0x010B4218 at 01079296 and 0107932A.",
                "target_010B4218.c calls 0x010CCBC8.",
                "target_010CCBC8.c constructs VagUdsCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_via_low_beams",
            label="Use low beams as coming-home lights",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012c8a55 (Play 9.8.3 x86); 010776D8 (older ARM window)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; coming_home_via_low_beams_ref_010776D8.txt",
            constructor_kind="mixed",
            constructor_status="constructor_partial",
            native_helper="0x012c8a8a -> 0x01358fd0 FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation; 0x012c8bf7 -> 0x013604b0 wrapper neighborhood; 0x010B5A98 -> 0x010D4140",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=0x10,
            immediate_index=0x06,
            choices=(),
            read_method="UDS coding setting path; exact DID/value packing still needs constructor proof.",
            write_method="Do not write from this setting recovery; class is known, but exact coding byte/value packing is not recovered.",
            next_re_step="Map the VagUdsCodingSetting constructor parameters from helper 0x010D4140 back to DID/byte/mask fields.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012c8a55; first visible helper call targets 0x01358fd0.",
                "Instruction window shows movs r4,#0x6 and movs r0,#0x10 before the key.",
                "Ghidra export target_010B5A98.c calls 0x010D4140.",
                "Ghidra export target_010D4140.c constructs VagUdsCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_via_fogs",
            label="Use fog lights as coming-home lights",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012c929b (Play 9.8.3 x86); 01077C50 (older ARM window)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; coming_home_via_fogs_ref_01077C50.txt",
            constructor_kind="mixed",
            constructor_status="constructor_partial",
            native_helper="0x012c92d0 -> 0x01340190 VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation; 0x012c93f1 -> 0x01348190 VagUdsCodingSetting-neighborhood; 0x010B19D0 -> 0x010C0708",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=0x20,
            immediate_index=0x06,
            choices=(),
            read_method="UDS coding setting path; exact DID/value packing still needs constructor proof.",
            write_method="Do not write from this setting recovery; class is known, but exact coding byte/value packing is not recovered.",
            next_re_step="Map the VagUdsCodingSetting constructor parameters from helper 0x010C0708 back to DID/byte/mask fields.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012c929b; first visible helper call targets 0x01340190.",
                "Official static read-only candidates include 22056D plus nearby 220550/220551; none are write seeds without live proof.",
                "Instruction window shows movs r0,#0x6, movs r1,#0x20, strd r1,r0 before the key.",
                "Ghidra export target_010B19D0.c calls 0x010C0708.",
                "Ghidra export target_010C0708.c constructs VagUdsCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_leaving_home_req_rls",
            label="Leaving-home requires rain/light sensor",
            ecu="PQ25 BCM / unit 09",
            native_function="FUN_0105f6c0",
            reference_address="0107879A / 01078896",
            instruction_window="leaving_home_req_rls_ref_0107879A.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper="010B7184 -> 010DAD6C VagCanLongCodingSetting; 010B19D0 -> 010C0708 VagUdsCodingSetting",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Coding/long-coding variants are visible; no raw adaptation DID is proven for this key yet.",
            write_method="Do not write from this recovery until exact coding packing and branch selection are known.",
            next_re_step="Map the leaving_home_req_rls immediate pairs around 0107879A/01078896 back to exact coding byte/mask fields.",
            evidence=(
                "Instruction window shows leaving_home_req_rls refs at 0107879A and 01078896.",
                "target_010B7184.c calls 010DAD6C, which constructs VagCanLongCodingSetting.",
                "Second visible path reuses 010B19D0 -> 010C0708, which constructs VagUdsCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_leaving_home",
            label="Leaving-home master switch",
            ecu="PQ25 BCM / unit 09",
            native_function="FUN_0105f6c0",
            reference_address="010787F2 / 01078848",
            instruction_window="leaving_home_req_rls_ref_0107879A.txt",
            constructor_kind="VagUdsCodingSetting",
            constructor_status="constructor_partial",
            native_helper="010B71D0 -> 010DAEDC VagUdsCodingSetting; 010B0C78 -> 010BC404 VagUdsCodingSetting",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="UDS coding setting variants; exact DID/value packing still needs constructor-field mapping.",
            write_method="Do not write from this setting recovery; class is known, but exact coding byte/value packing is not recovered.",
            next_re_step="Map the leaving_home immediate pairs around 010787F2/01078848 back to exact coding byte/mask fields.",
            evidence=(
                "Instruction window shows leaving_home refs through two UDS coding helpers.",
                "target_010B71D0.c calls 010DAEDC, which constructs VagUdsCodingSetting.",
                "target_010B0C78.c calls 010BC404, which constructs VagUdsCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_leaving_home_duration",
            label="Leaving-home duration",
            ecu="PQ25 BCM / unit 09",
            native_function="FUN_0105f6c0",
            reference_address="01078C66 / nearby duration variants",
            instruction_window="leaving_home_duration_ref_01078C66.txt; coming_leaving_home_output_ref_2_01079282.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper=(
                "010B1708 -> 010BF9DC FullByteVagCanShortAdaptationSetting; "
                "010B72C4 -> 010DB380 VagUdsAdaptationSetting; "
                "010B7318 -> 010DB504 VagUdsAdaptationSetting; "
                "010B7368 -> 010DB67C VagUdsAdaptationSetting"
            ),
            raw_address=0x0A57,
            value_offset=5,
            value_mask="FF",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_time_10sec", "0A", "0A57 duration table."),
                _choice("car_setting_time_15sec", "0F", "0A57 duration table."),
                _choice("car_setting_time_20sec", "14", "0A57 duration table."),
                _choice("car_setting_time_30sec", "1E", "0A57 duration table."),
                _choice("car_setting_time_40sec", "28", "0A57 duration table."),
                _choice("car_setting_time_50sec", "32", "0A57 duration table."),
                _choice("car_setting_time_60sec", "3C", "0A57 duration table."),
            ),
            read_method="VAG short-adaptation and 220A57 UDS-adaptation duration variants are both present.",
            write_method="Do not write from this recovery until runtime branch selection proves which adaptation path applies.",
            next_re_step="Runtime-select whether Carista uses the short-adaptation branch or UDS 0A57 duration branch on this BCM.",
            evidence=(
                "Instruction windows show 10-60 second leaving-home duration tables and one 0A57 offset 5 mask FF UDS branch.",
                "target_010B1708.c calls 010BF9DC, which constructs FullByteVagCanShortAdaptationSetting.",
                "target_010B72C4.c calls 010DB380, which constructs VagUdsAdaptationSetting with NumericalInterpretation.",
                "target_010B7318.c calls 010DB504, which constructs VagUdsAdaptationSetting with NumericalInterpretation.",
                "target_010B7368.c calls 010DB67C, which constructs VagUdsAdaptationSetting with MultipleChoiceInterpretation.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_drl_via_fogs",
            label="Use fog lights as daytime running lights",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012cde7b (Play 9.8.3 x86); 0107AA66 / 0107AAAC / 0107AB04 / 0107AB60 / 0107ABF4 / 0107AC84 (older ARM windows)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; drl_via_fogs_ref_1_0107AA66.txt; drl_via_fogs_ref_2_0107ABF4.txt",
            constructor_kind="mixed",
            constructor_status="constructor_partial",
            native_helper=(
                "0x012cdeb6 -> 0x01361520 VagCanLongCodingSetting-neighborhood; "
                "0x012cdf28 -> 0x01363440 VagUdsAdaptationSetting-neighborhood; "
                "010B71D0 -> 010DAEDC VagUdsCodingSetting; "
                "010B7764 -> 010DC980 VagCanLongCodingSetting; "
                "010B1980 -> 010C0590 VagUdsAdaptationSetting"
            ),
            raw_address=0x055C,
            value_offset=6,
            value_mask="FF",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_disabled", "00", "055C adaptation choice table in drl_via_fogs_ref_2."),
                _choice("car_setting_enabled", "14", "055C adaptation choice table in drl_via_fogs_ref_2."),
            ),
            read_method="22055C adaptation candidate at offset 6; the same key also has UDS/long-coding variants.",
            write_method="Do not write from this recovery until a positive 22055C read supplies the full raw payload.",
            next_re_step="Determine which of the six Carista variants is selected for 6R0937087K; current evidence proves multiple constructor variants, not the runtime branch.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012cde7b; helper family is mixed around long-coding and UDS adaptation wrappers.",
                "Refs-only probe finds six FUN_0105f6c0 references for this exact key.",
                "Instruction windows show UDS coding variants with immediate pairs 17/04, 0E/02, and 02/08.",
                "Instruction window shows a long-coding variant with immediate pair 11/10.",
                "Two 010B1980 calls construct VagUdsAdaptationSetting via 010C0590.",
                "The 055C adaptation table stores raw address 055C, offset 6, mask FF, disabled 00, enabled 14.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_turn_off_fogs_with_high_beam",
            label="Turn off fogs with high beam",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012d4db5 (Play 9.8.3 x86); 0107F15A / 0107F1B4 / 0107F20A / 0107F26C / 0107F2D6 / 0107F330 (older ARM windows)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; turn_off_fogs_with_high_beam_ref_1_0107F15A.txt; turn_off_fogs_with_high_beam_ref_2_0107F26C.txt",
            constructor_kind="mixed",
            constructor_status="constructor_partial",
            native_helper=(
                "0x012d4dea -> 0x0135e580 VagUdsCodingSetting-neighborhood; "
                "0x012d4e65 -> 0x01368100 VagUdsCodingSetting-neighborhood; "
                "010B69C0 -> 010D88A0 VagUdsCodingSetting; "
                "010B8480 -> 010E0970 VagCanLongCodingSetting; "
                "010B7F38 -> 010DEE9C VagUdsAdaptationSetting"
            ),
            raw_address=0x0D01,
            value_offset=1,
            value_mask="01",
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="220D01 adaptation candidate for one variant; other variants are UDS coding or long-coding settings.",
            write_method="Do not write from this recovery until the exact runtime variant and positive read payload are proven.",
            next_re_step="Runtime-select the variant for this BCM by matching availability reads; then test 220D01 read-only before any adaptation write.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012d4db5; helper calls target 0x0135e580 and 0x01368100.",
                "Official static read-only candidates include 220D01 and nearby 220A58; neither is a write seed without positive live proof.",
                "Refs-only probe finds six FUN_0105f6c0 references plus app getSettings refs for this key.",
                "Instruction windows show UDS coding variants with immediate pairs 20/15, 04/0E, 02/04, and 01/0F.",
                "Instruction window shows a long-coding variant with immediate pair 20/11.",
                "Instruction windows show UDS adaptation variants at raw addresses 0D01 and 0A58 through 010B7F38 -> 010DEE9C.",
                "For the first adaptation variant, the window stores raw address 0D01 with adjacent 1/1 fields before constructing VagUdsAdaptationSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_assist_dr_lights",
            label="Assistant Driving Light (ADL)",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012d9b78 (Play 9.8.3 x86); 0108252C (older ARM window)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; assist_dr_lights_ref_0108252C.txt",
            constructor_kind="mixed",
            constructor_status="constructor_partial",
            native_helper="0x012d9bad -> 0x013625a0 VagCanLongCodingSetting-neighborhood; 0x012d9cc0 -> 0x0135f600 VagUdsAdaptationSetting-neighborhood; 010B74A0 -> 010DBC4C VagUdsCodingSetting",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=0x20,
            immediate_index=0x16,
            choices=(),
            read_method="UDS coding setting path; exact DID/value packing still needs constructor-field mapping.",
            write_method="Use only full-coding guarded writes if intentionally tested; do not infer this from byte 22 bit 5 alone.",
            next_re_step="Map the VagUdsCodingSetting constructor parameters from 010DBC4C to the exact DID/byte/mask fields.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012d9b78; visible helpers land in mixed long-coding/adaptation wrapper neighborhoods.",
                "Refs-only probe finds a direct FUN_0105f6c0 ref.",
                "Instruction window stores immediate pair 20/16 before car_setting_assist_dr_lights.",
                "010B74A0 calls 010DBC4C, which constructs VagUdsCodingSetting.",
                "PQ25 catalog byte 22 bit 5 remains an external candidate, not native proof.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_pl_via_front_fog_lights",
            label="Use front fog lights as parking lights",
            ecu="PQ25 BCM / unit 09",
            native_function="unknown",
            reference_address="unknown",
            instruction_window=None,
            constructor_kind="unknown",
            constructor_status="catalog_only_unresolved",
            native_helper=None,
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Catalog/resource only.",
            write_method="Unknown; do not write.",
            next_re_step="Search callers outside the VAG FUN_0105f6c0 path if this setting becomes relevant; current probe found no PQ25/VAG constructor.",
            evidence=(
                "Carista catalog contains the resource key.",
                "Refs-only probe found this exact key only in getSettings @ 00D8CC4C, not in FUN_0105F6C0.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_front_fogs_with_low_beams",
            label="Activate front fog lights with low beams",
            ecu="PQ25 BCM / unit 09",
            native_function="unknown",
            reference_address="unknown",
            instruction_window=None,
            constructor_kind="unknown",
            constructor_status="catalog_only_unresolved",
            native_helper=None,
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Catalog/resource only.",
            write_method="Unknown; do not write.",
            next_re_step="Search callers outside the VAG FUN_0105f6c0 path if this setting becomes relevant; current probe found no PQ25/VAG constructor.",
            evidence=(
                "Carista catalog contains the resource key.",
                "Refs-only probe found this exact key only in FUN_00E314FE, not in FUN_0105F6C0.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_fogs_with_high_beam_restriction",
            label="Fog lights with high beam restriction",
            ecu="PQ25 BCM / unit 09",
            native_function="unknown",
            reference_address="unknown",
            instruction_window=None,
            constructor_kind="unknown",
            constructor_status="catalog_only_unresolved",
            native_helper=None,
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Catalog/resource only.",
            write_method="Unknown; do not write.",
            next_re_step="Search callers outside the VAG FUN_0105f6c0 path if this setting becomes relevant; current probe found no PQ25/VAG constructor.",
            evidence=(
                "Carista catalog contains a high-beam fog restriction key relevant to the observed high-beam test.",
                "Refs-only probe found this exact key only in FUN_00E314FE, not in FUN_0105F6C0.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_turn_on_fogs_with_high_beam",
            label="Turn on fogs with high beam",
            ecu="PQ25 BCM / unit 09",
            native_function="unknown",
            reference_address="unknown",
            instruction_window=None,
            constructor_kind="unknown",
            constructor_status="catalog_only_unresolved",
            native_helper=None,
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Catalog/resource only.",
            write_method="Unknown; do not write.",
            next_re_step="Search callers outside the VAG FUN_0105f6c0 path if this setting becomes relevant; current probe found no PQ25/VAG constructor.",
            evidence=(
                "Carista catalog contains a high-beam fog setting key relevant to the observed high-beam test.",
                "Refs-only probe found this exact key only in FUN_00E314FE, not in FUN_0105F6C0.",
            ),
        ),
    )


class VagCanSettings:
    getPq25SettingDefinitions = staticmethod(VagCanSettings_getPq25SettingDefinitions)
    getPq25SupportedSettings = staticmethod(VagCanSettings_getPq25SupportedSettings)
    getPq25SettingRecoveries = staticmethod(VagCanSettings_getPq25SettingRecoveries)
