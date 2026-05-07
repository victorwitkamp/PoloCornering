from __future__ import annotations

from dataclasses import dataclass

from .Commands.ReadDataByIdentifierCommand import ReadDataByIdentifierCommand_getRequest
from .VagCoding import bit_state, chunk_value6, derive_value6, normalize_coding
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
class VagCanSettingsCurrentSettingState:
    key: str
    label: str
    byte_index: int
    bit_index: int
    state: str
    current_byte: HexString
    confidence: str
    unresolved: tuple[str, ...]


UNMODELED_CARISTA_GROUPS: tuple[str, ...] = (
    "CH/LH fog/low-beam behavior",
    "parking-light group",
    "ADL-ish byte",
)


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
            VagCanSettingsNativeHelper("0x012c8913", "0x0133fdf0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c8a1e", "0x0133fdf0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "adaptation raw/address 0x110e offset 2 field/mask 1 choices fogs=00 low_beams=01",
            "older ARM UDS coding DID 0600 byte 0x0d mask 0x40 maps fogs=00 low_beams=01",
            "older ARM UDS coding DID 0600 byte 0x11 mask 0x08 maps fogs=01 low_beams=00",
        ),
        read_candidate_dids=(0x110E,),
        safety_note="22110E returned 7F2231 live; recover the coding branch or runtime selector instead of treating this adaptation DID as a write seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_req_rls",
        string_ref="0x012c71a3 / 0x012c74e1",
        helpers=(
            VagCanSettingsNativeHelper("0x012c74fe", "0x0133b390", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S plus VagCanEcu::CENTRAL_ELEC, DID 0600 byte 0x0a mask 0x04",
            "adjacent car_setting_coming_home_menu_default_req_rls branch at 0x012c7551 is separate MK7/6C UDS adaptation raw 0x0d04 offset 0 mask 0x04",
            "older ARM same-key evidence also carries 0x0a57 adaptation, long-coding, and DID 0600 byte 0x11 mask 0x20 branches",
        ),
        read_candidate_dids=(),
        safety_note="The x86 6R branch is DID 0600 coding; 220A57 remains a rejected companion adaptation candidate, not a write seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_leaving_home_req_rls",
        string_ref="0x012ca544 / 0x012ca6e9",
        helpers=(
            VagCanSettingsNativeHelper("0x012ca6e9", "0x01340190", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S plus VagCanEcu::CENTRAL_ELEC, DID 0600 byte 0x0a mask 0x02",
            "later same-key branch at 0x012ca899 uses CENTRAL_ELEC_MK6_8X_B7 with DID 0600 byte 0x11 mask 0x40, not the 6R/PQ25 guard",
            "following car_setting_leaving_home_menu_req_rls branch is separate MK7/6C UDS adaptation raw 0x0d04 offset 2 mask 0x20",
        ),
        read_candidate_dids=(),
        safety_note="The x86 6R branch is DID 0600 coding; do not promote the adjacent menu/adaptation branches to PQ25 write seeds.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_duration",
        string_ref="0x012c9a61",
        helpers=(
            VagCanSettingsNativeHelper("0x012c9a96", "0x01360c30", "VagCanShortAdaptationSetting / VagCanEcu / NumericalInterpretation"),
            VagCanSettingsNativeHelper("0x012c9b2f", "0x01360de0", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H plus VagCanEcu::CENTRAL_ELEC, short-adaptation channel 0x2f",
            "duration choice table contains 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, and 60 second values",
            "later MQBA0 fallback uses UDS adaptation raw 0x0a57 offset 3 mask 0xff",
        ),
        read_candidate_dids=(0x0A57,),
        safety_note="For PQ25 the recovered x86 branch is VAG CAN short adaptation channel 0x2f; the 0x0A57 UDS branch is the rejected MQBA0 fallback.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_mode",
        string_ref="0x012c769d",
        helpers=(
            VagCanSettingsNativeHelper("0x012c76e6", "0x0135f420", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c77ec", "0x0135f600", "VagCanLongCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c78f2", "0x0135f7d0", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 CENTRAL_ELEC_MQBA0 UDS adaptation branch uses raw 0x0a57 offset 2 field/count 0x03 with disabled/manual/automatic choices",
            "later official x86 branches are CENTRAL_ELEC_MK5_MED_HIGH long-coding and CENTRAL_ELEC_MK6_8X_B7 UDS-coding variants",
            "no visible official x86 branch in this window is guarded by CENTRAL_ELEC_6R or CENTRAL_ELEC_6R_5C_7E_7H",
        ),
        read_candidate_dids=(0x0A57,),
        safety_note="The visible official x86 branches are MQBA0/MK5/MK6-family evidence, not a PQ25 6R write seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_trigger",
        string_ref="0x012c7ddf",
        helpers=(
            VagCanSettingsNativeHelper("0x012c7e28", "0x0135fd50", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c7f42", "0x0135ff30", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 CENTRAL_ELEC_MQBA0 UDS adaptation branch uses raw 0x0a57 offset 4 mask 0x02 with ignition-off/door-open choices",
            "later official x86 CENTRAL_ELEC_MK8 UDS adaptation branch uses raw 0x110e offset 4 mask 0x01",
            "no visible official x86 branch in this window is guarded by CENTRAL_ELEC_6R or CENTRAL_ELEC_6R_5C_7E_7H",
        ),
        read_candidate_dids=(0x0A57, 0x110E),
        safety_note="Both visible branches are non-6R and include live-rejected raw DIDs; keep as negative platform evidence.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_trigger_when_auto",
        string_ref="0x012c8449",
        helpers=(
            VagCanSettingsNativeHelper("0x012c847f", "0x013602e0", "VagUdsCodingSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 CENTRAL_ELEC_B9 UDS-coding branch uses byte/mask immediates 0x07/0x04 with ignition-off/door-open choices",
            "guard is CENTRAL_ELEC_B9 plus VagUdsEcu::CENTRAL_ELEC, not a 6R/PQ25 whitelist",
        ),
        read_candidate_dids=(),
        safety_note="This is B9-scoped UDS-coding evidence and should not be promoted to a Polo branch.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_output",
        string_ref="0x012c8569",
        helpers=(
            VagCanSettingsNativeHelper("0x012c85b2", "0x01342c30", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012c86d2", "0x01342c30", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 CENTRAL_ELEC_MQBA0 UDS adaptation branch uses raw 0x0a57 offset 4 mask 0x01 with low-beams/fogs choices",
            "later official x86 CENTRAL_ELEC_MK7_6C UDS adaptation branch uses raw 0x0d04 offset 2 mask 0x01 with the same choices",
            "no visible official x86 branch in this window is guarded by CENTRAL_ELEC_6R or CENTRAL_ELEC_6R_5C_7E_7H",
        ),
        read_candidate_dids=(0x0A57, 0x0D04),
        safety_note="The visible output branches are MQBA0/MK7_6C UDS adaptation evidence, not a recovered 6R/PQ25 selector.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_leaving_home_duration",
        string_ref="0x012cacd4",
        helpers=(
            VagCanSettingsNativeHelper("0x012cad09", "0x0133f140", "VagCanShortAdaptationSetting / VagCanEcu / NumericalInterpretation"),
            VagCanSettingsNativeHelper("0x012cad9c", "0x01361ab0", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H plus VagCanEcu::CENTRAL_ELEC, short-adaptation channel 0x30",
            "duration choice table contains 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, and 60 second values",
            "later MQBA0 fallback uses UDS adaptation raw 0x0a57 offset 5 mask 0xff",
        ),
        read_candidate_dids=(0x0A57,),
        safety_note="For PQ25 the recovered x86 branch is VAG CAN short adaptation channel 0x30; the 0x0A57 UDS branch is the rejected MQBA0 fallback.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_leaving_home_menu_req_rls",
        string_ref="0x012caaa8",
        helpers=(
            VagCanSettingsNativeHelper("0x012caaea", "0x013618d0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 CENTRAL_ELEC_MK7_6C UDS adaptation branch uses raw 0x0d04 offset 2 mask 0x20 with ENABLED_DISABLED",
            "adjacent step_1/step_2 branches are CENTRAL_ELEC_MK7_NEW UDS adaptation records on 0x0a57, including offset 7 mask 0x20 for step_2",
            "no visible official x86 branch in this window is guarded by CENTRAL_ELEC_6R or CENTRAL_ELEC_6R_5C_7E_7H",
        ),
        read_candidate_dids=(0x0D04, 0x0A57),
        safety_note="This is menu gating evidence for newer platforms, not a PQ25 6R RLS branch.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_leaving_home_duration_menu",
        string_ref="0x012cbc34",
        helpers=(
            VagCanSettingsNativeHelper("0x012cbc76", "0x013408c0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012cbcff", "0x013408c0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 CENTRAL_ELEC_MK7_NEW UDS adaptation branch uses raw 0x0a57 offset 0 mask 0x80 with ENABLED_DISABLED_INVERTED",
            "official x86 CENTRAL_ELEC_MQBA0 UDS adaptation branch uses raw 0x0a57 offset 1 mask 0x01 with ENABLED_DISABLED_INVERTED",
            "nearby car_setting_coming_leaving_home_threshold branch is B8 FullByteVagCanShortAdaptationSetting and is a different key",
        ),
        read_candidate_dids=(0x0A57,),
        safety_note="The duration-menu visibility branches are MK7_NEW/MQBA0 evidence; they do not override the 6R duration short-adaptation channels 0x2F/0x30.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_enabled_coming_home_or_leaving_home",
        string_ref="0x012d349a",
        helpers=(
            VagCanSettingsNativeHelper("0x012d3531", "0x0135cf20", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 branch uses UDS adaptation raw 0x0565 offset 5 mask 0x3f with choice value 0x1e",
            "visible guard is CENTRAL_ELEC_MK7_ALL with UDS_CENTRAL_ELEC_MK7 and VagUdsEcu::CENTRAL_ELEC",
            "this explains the reused 0x1e choice family but is not a recovered 0601 owner path",
        ),
        read_candidate_dids=(0x0565,),
        safety_note="Do not treat 0601=1E as a 2E0601 write seed; x86 ties the enum to UDS adaptation 0x0565 in a non-PQ25 branch.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_via_low_beams",
        string_ref="0x012c8a55",
        helpers=(
            VagCanSettingsNativeHelper("0x012c8a8a", "0x01358fd0", "FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 direct key branch is FullByteVagCanShortAdaptationSetting with immediate pair 0x06/0x10",
            "official x86 direct key branch is guarded by CENTRAL_ELEC_B8 plus VagCanEcu::CENTRAL_ELEC, not CENTRAL_ELEC_6R",
            "older ARM fallback evidence still shows a DID 0600 byte 0x06 mask 0x10 UDS-coding branch; treat this as build/version evidence until an x86 6R branch is found",
        ),
        read_candidate_dids=(),
        safety_note="Official x86 direct branch is B8-scoped, so it is not a PQ25 fix seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_coming_home_via_fogs",
        string_ref="0x012c929b",
        helpers=(
            VagCanSettingsNativeHelper("0x012c92d0", "0x01340190", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 direct key branch has DID 0600 byte 0x06 mask 0x20",
            "official x86 direct key branch is guarded by CENTRAL_ELEC_B8 plus VagCanEcu::CENTRAL_ELEC, not CENTRAL_ELEC_6R",
            "nearby official x86 branches for turn-signal/reverse CH/LH helpers are MK7/MQB scoped, not 6R/PQ25",
            "older ARM fallback evidence still shows a DID 0600 byte 0x06 mask 0x20 UDS-coding branch; direct adaptation candidates 0x056d/0x0550/0x0551 were live-rejected",
        ),
        read_candidate_dids=(0x056D, 0x0550, 0x0551),
        safety_note="Official x86 direct branch is B8-scoped and 22056D/220550/220551 returned 7F2231 live.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_drl_via_fogs",
        string_ref="0x012cde7b",
        helpers=(
            VagCanSettingsNativeHelper("0x012cdeb6", "0x01361520", "VagCanLongCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012cdf28", "0x01363440", "VagUdsAdaptationSetting / VagCanEcu / NumericalInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H plus VagCanEcu::CENTRAL_ELEC, byte 0x17 mask 0x04",
            "other official x86 variants are CENTRAL_ELEC_MK5_HIGH byte 0x11 mask 0x10, CENTRAL_ELEC_MK6_8X_B7 byte 0x0e mask 0x02, CENTRAL_ELEC_B8 byte 0x02 mask 0x08",
            "official x86 type-7 055C offset 6 mask FF branches are MK8 or gateway/MEB scoped, not 6R/PQ25",
        ),
        read_candidate_dids=(0x055C,),
        safety_note="The 6R/PQ25 branch is a coding-style byte/mask clue, not a cornering fix; 22055C remains known-rejected.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_turn_off_fogs_with_high_beam",
        string_ref="0x012d4db5",
        helpers=(
            VagCanSettingsNativeHelper("0x012d4dea", "0x0135e580", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012d4e65", "0x01368100", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H plus VagCanEcu::CENTRAL_ELEC, byte 0x15 mask 0x20",
            "long-coding byte 0x11 mask 0x20",
            "UDS coding DID 0600 byte 0x0e mask 0x04 and byte 0x04 mask 0x02 variants",
            "adaptation raw 0x0d01 fields 1/1; nearby adaptation raw 0x0a58",
        ),
        read_candidate_dids=(0x0D01, 0x0A58),
        safety_note="220D01/220A58 returned 7F2231 live; direct adaptation reads are negative on this BCM/session.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_fog_lights_on_reverse",
        string_ref="0x012d62e6",
        helpers=(
            VagCanSettingsNativeHelper("0x012d632e", "0x013591a0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012d63ec", "0x013691d0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "Ghidra x86 D1D branch: car_setting_fog_lights_on_reverse, raw/DID 0x0d1d, offset 0, mask 0x02, ENABLED_DISABLED choices",
            "the 0x012d632e branch pushes UDS_CENTRAL_ELEC_MK7, CENTRAL_ELEC_MK7_6C, and VagUdsEcu::CENTRAL_ELEC",
            "a later same-key D1D variant uses CENTRAL_ELEC_MK7_NEW_MQBA0 plus a CENTRAL_ELEC_MK8-derived whitelist, again with VagUdsEcu::CENTRAL_ELEC",
            "no recovered fog-on-reverse D1D branch is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S",
        ),
        read_candidate_dids=(0x0D1D,),
        safety_note="Ghidra-backed D1D evidence is MK7/6C/MQBA0/MK8 scoped, not a 6R/PQ25 read/write seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_assist_dr_lights",
        string_ref="0x012d9b78",
        helpers=(
            VagCanSettingsNativeHelper("0x012d9bad", "0x013625a0", "VagCanLongCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012d9cc0", "0x0135f600", "VagUdsAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=("official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H plus VagCanEcu::CENTRAL_ELEC, byte 0x16 mask 0x20",),
        read_candidate_dids=(),
        safety_note="Constructor family evidence only; no standalone read/write candidate from this callsite.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_via_fogs",
        string_ref="0x012d9ed4",
        helpers=(
            VagCanSettingsNativeHelper("0x012d9f09", "0x01358fd0", "FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012d9f7b", "0x01358fd0", "FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012d9ff6", "0x01358fd0", "FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012da071", "0x01358fd0", "FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch at 0x012d9f7b: CENTRAL_ELEC_6R_5C_7E_7H plus VagCanEcu::CENTRAL_ELEC, byte 0x0c mask 0x40",
            "same key also has official x86 1S byte 0x0c/mask 0x40, MK6_8X_B7 byte 0x0e/mask 0x80, and B8 byte 0x04/mask 0x01 branches",
            "current live coding has byte 0x0c mask 0x40 set, but the standalone behavior test disproved this as the missing turn-signal-cornering fix",
        ),
        read_candidate_dids=(),
        safety_note="Already behavior-disproven as a standalone fix; keep as evidence, not a retest seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_via_fogs_experimental",
        string_ref="0x012da0bd",
        helpers=(
            VagCanSettingsNativeHelper("0x012da0f2", "0x0135eaf0", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H plus VagCanEcu::CENTRAL_ELEC, byte 0x15 mask 0x80",
            "fresh engine-running coding byte 0x15 is 0xA6, so mask 0x80 is already set while turn-signal cornering behavior is absent",
        ),
        read_candidate_dids=(),
        safety_note="Already set in current coding; not a missing-fix write seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_with_turn_signals",
        string_ref="0x012da72c",
        helpers=(
            VagCanSettingsNativeHelper("0x012da761", "0x0135e920", "VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "official x86 6R/PQ25 branch: CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S plus VagCanEcu::CENTRAL_ELEC, byte 0x15 mask 0x04",
            "fresh engine-running coding byte 0x15 is 0xA6, so mask 0x04 is already set while turn-signal cornering behavior is absent",
        ),
        read_candidate_dids=(),
        safety_note="This is the explicit turn-signal-cornering key, but its recovered bit is already set on the car.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_activation",
        string_ref="0x012da8bd",
        helpers=(
            VagCanSettingsNativeHelper("0x012da906", "0x0133e9f0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012daab2", "0x0133e9f0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012dab32", "0x0135e750", "VagCanLongCodingSetting / VagCanEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "Ghidra x86 D1D branch: car_setting_cornering_lights_activation, raw/DID 0x0d1d, offset 2, mask 0x38, choice vector disabled/steering-wheel/blinker methods",
            "the first D1D helper pushes UDS_CENTRAL_ELEC_MK7, CENTRAL_ELEC_MK7_6C, and VagUdsEcu::CENTRAL_ELEC",
            "a later same-key D1D helper uses CENTRAL_ELEC_MK7_NEW_MQBA0 with VagUdsEcu::CENTRAL_ELEC",
            "the nearby non-D1D B8 long-coding variant pushes CENTRAL_ELEC_B8 with VagCanEcu::CENTRAL_ELEC",
            "no recovered activation D1D branch is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S",
        ),
        read_candidate_dids=(0x0D1D,),
        safety_note="This branch explains a plausible Carista activation setting family, but all recovered D1D paths are non-6R scoped; do not use it for 2E0D1D on PQ25.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_min_activation_speed",
        string_ref="0x012daf54",
        helpers=(
            VagCanSettingsNativeHelper("0x012dae8c", "0x0136ccc0", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
            VagCanSettingsNativeHelper("0x012daf97", "0x0136cea0", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
            VagCanSettingsNativeHelper("0x012db0a5", "0x0136cea0", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
        ),
        recovered_shape=(
            "Ghidra x86 D1D branch: car_setting_cornering_lights_min_activation_speed, raw/DID 0x0d1d, offset 3, mask 0xff, Unit::KM_H numeric interpretation",
            "nearby same-key D1D variant uses offset 2 mask 0xff under CENTRAL_ELEC_MK7_NEW_MQBA0",
            "observed guards are CENTRAL_ELEC_MK7_ALL, CENTRAL_ELEC_MK7_6C, and CENTRAL_ELEC_MK7_NEW_MQBA0 with VagUdsEcu::CENTRAL_ELEC",
            "no recovered min-speed D1D branch is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S",
        ),
        read_candidate_dids=(0x0D1D,),
        safety_note="Non-6R D1D numerical setting evidence only; not a PQ25 write/read seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_max_activation_speed",
        string_ref="0x012db176",
        helpers=(
            VagCanSettingsNativeHelper("0x012db1bf", "0x0136cea0", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
            VagCanSettingsNativeHelper("0x012db2f6", "0x0136d080", "VagUdsAdaptationSetting / VagUdsEcu / NumericalInterpretation"),
        ),
        recovered_shape=(
            "Ghidra x86 D1D branch: car_setting_cornering_lights_max_activation_speed, raw/DID 0x0d1d, offset 4, mask 0xff, Unit::KM_H numeric interpretation",
            "nearby same-key D1D variant uses offset 3 mask 0xff under CENTRAL_ELEC_MK7_NEW_MQBA0/MK8-derived guards",
            "observed guards are CENTRAL_ELEC_MK7_6C and CENTRAL_ELEC_MK7_NEW_MQBA0/MK8-derived with VagUdsEcu::CENTRAL_ELEC",
            "no recovered max-speed D1D branch is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S",
        ),
        read_candidate_dids=(0x0D1D,),
        safety_note="Non-6R D1D numerical setting evidence only; not a PQ25 write/read seed.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_via_fogs_left",
        string_ref="0x012da210",
        helpers=(
            VagCanSettingsNativeHelper("0x012da25a", "0x0136c910", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012da39a", "0x01356f90", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("01082988 -> 010B90CC", "010E44E8", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation / allowed-values vector"),
            VagCanSettingsNativeHelper("01082A4A -> 010B5620", "010D2BD0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "raw/DID 0x055c", "offset 5", "mask 0xff", "choices off=00 on=16 coming/leaving=1e",
            "official x86 first helper derives its whitelist from CENTRAL_ELEC_MQB_ALL plus CENTRAL_ELEC_MK8",
            "official x86 second helper uses UDS_CAN_GATEWAY_MEB plus CAN_GATEWAY",
            "older ARM first type-7 branch uses CENTRAL_ELEC plus CENTRAL_ELEC_MQB_ALL/CENTRAL_ELEC_MK8-derived whitelist",
            "older ARM MQB/MK8 whitelist setup is paired with part patterns 5Q0937084* and 6C093708*, not 6R0937087K",
            "older ARM second type-7 branch uses CAN_GATEWAY plus UDS_CAN_GATEWAY_MEB",
            "no recovered per-side 055C branch is guarded by CENTRAL_ELEC_6R / CENTRAL_ELEC_6R_5C_7E_7H / CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S",
        ),
        read_candidate_dids=(0x055C,),
        safety_note="22055C already returned 7F2231 live; never build a 2E055C write from static data alone.",
    ),
    VagCanSettingsNativeSetting(
        key="car_setting_cornering_lights_via_fogs_right",
        string_ref="0x012da55f",
        helpers=(
            VagCanSettingsNativeHelper("0x012da5a9", "0x01368690", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("0x012da6e9", "0x0136caf0", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
            VagCanSettingsNativeHelper("01082B78 -> 010B8574", "010E0DE8", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation / allowed-values vector"),
            VagCanSettingsNativeHelper("01082C34 -> 010B9120", "010E466C", "VagUdsAdaptationSetting / VagUdsEcu / MultipleChoiceInterpretation"),
        ),
        recovered_shape=(
            "raw/DID 0x055d", "offset 5", "mask 0xff", "choices off=00 on=17 coming/leaving=1e",
            "official x86 first helper derives its whitelist from CENTRAL_ELEC_MQB_ALL plus CENTRAL_ELEC_MK8",
            "official x86 second helper uses UDS_CAN_GATEWAY_MEB plus CAN_GATEWAY",
            "older ARM first type-7 branch uses CENTRAL_ELEC plus CENTRAL_ELEC_MQB_ALL/CENTRAL_ELEC_MK8-derived whitelist",
            "older ARM MQB/MK8 whitelist setup is paired with part patterns 5Q0937084* and 6C093708*, not 6R0937087K",
            "older ARM second type-7 branch uses CAN_GATEWAY plus UDS_CAN_GATEWAY_MEB",
            "no recovered per-side 055D branch is guarded by CENTRAL_ELEC_6R / CENTRAL_ELEC_6R_5C_7E_7H / CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S",
        ),
        read_candidate_dids=(0x055D,),
        safety_note="22055D already returned 7F2231 live; never build a 2E055D write from static data alone.",
    ),
)


VAG_CAN_SETTINGS_READ_ONLY_CANDIDATES: tuple[VagCanSettingsReadOnlyCandidate, ...] = (
    VagCanSettingsReadOnlyCandidate(0x110E, "car_setting_coming_leaving_home_output", "Coming/leaving-home output selector adaptation/coding candidate; live direct read rejected", "live_rejected_7F2231"),
    VagCanSettingsReadOnlyCandidate(0x056D, "car_setting_coming_home_via_fogs", "Coming-home via fogs nearby UDS adaptation candidate; live direct read rejected", "live_rejected_7F2231"),
    VagCanSettingsReadOnlyCandidate(0x0550, "car_setting_coming_home_via_fogs", "Coming-home via fogs nearby raw channel candidate; live direct read rejected", "live_rejected_7F2231"),
    VagCanSettingsReadOnlyCandidate(0x0551, "car_setting_coming_home_via_fogs", "Coming-home via fogs nearby raw channel candidate; live direct read rejected", "live_rejected_7F2231"),
    VagCanSettingsReadOnlyCandidate(0x0D01, "car_setting_turn_off_fogs_with_high_beam", "Turn-off-fogs-with-high-beam UDS adaptation candidate; live direct read rejected", "live_rejected_7F2231"),
    VagCanSettingsReadOnlyCandidate(0x0A58, "car_setting_turn_off_fogs_with_high_beam", "Turn-off-fogs-with-high-beam nearby UDS adaptation candidate; live direct read rejected", "live_rejected_7F2231"),
    VagCanSettingsReadOnlyCandidate(0x0A57, "car_setting_coming_home_req_rls", "Shared coming/leaving-home UDS adaptation branch candidate; live direct read rejected", "live_rejected_7F2231"),
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


YES_NO_SINGLETON_EVIDENCE = (
    "MultipleChoiceInterpretation::YES_NO at 014f1fd8 is initialized by static init 00D54B34: "
    "car_setting_yes has compact requested value 01 and car_setting_no has compact requested value 00."
)
ENABLED_DISABLED_SINGLETON_EVIDENCE = (
    "MultipleChoiceInterpretation::ENABLED_DISABLED at 014f1ff0 is initialized by static init 00D54B34: "
    "car_setting_enabled has compact requested value 01 and car_setting_disabled has compact requested value 00."
)


def _yes_no_choices(evidence: str) -> tuple[VagCanSettingsChoice, ...]:
    return (
        _choice("car_setting_no", "00", f"{evidence} {YES_NO_SINGLETON_EVIDENCE}"),
        _choice("car_setting_yes", "01", f"{evidence} {YES_NO_SINGLETON_EVIDENCE}"),
    )


def _enabled_disabled_choices(evidence: str) -> tuple[VagCanSettingsChoice, ...]:
    return (
        _choice("car_setting_disabled", "00", f"{evidence} {ENABLED_DISABLED_SINGLETON_EVIDENCE}"),
        _choice("car_setting_enabled", "01", f"{evidence} {ENABLED_DISABLED_SINGLETON_EVIDENCE}"),
    )


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


def VagCanSettings_pq25CurrentSettingStates(coding: HexString) -> tuple[VagCanSettingsCurrentSettingState, ...]:
    normalized = normalize_coding(coding)
    data = bytes.fromhex(normalized)
    states: list[VagCanSettingsCurrentSettingState] = []
    for definition in VagCanSettings_getPq25SettingDefinitions():
        states.append(
            VagCanSettingsCurrentSettingState(
                key=definition.key,
                label=definition.label,
                byte_index=definition.byte_index,
                bit_index=definition.bit_index,
                state=bit_state(normalized, definition.byte_index, definition.bit_index),
                current_byte=f"{data[definition.byte_index]:02X}",
                confidence=definition.confidence,
                unresolved=definition.unresolved,
            )
        )
    return tuple(states)


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
            native_helper="official x86: 0x012da25a -> 0x0136c910 -> PLT 0x0197e2f0 VagUdsAdaptationSetting; 0x012da39a -> 0x01356f90 -> PLT 0x0197d6f0 VagUdsAdaptationSetting. Older ARM: 01082988 -> 010B90CC -> 010E44E8 VagUdsAdaptationSetting and 01082A4A -> 010B5620 -> 010D2BD0 VagUdsAdaptationSetting; readVagUdsValue -> ReadRawDataByIdentifierCommand applies to the 055C type-7 branches",
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
                "Direct x86 ELF audit resolves 0x0136c910 through PLT entry 0x0197e2f0 to shared_ptr_emplace<VagUdsAdaptationSetting, VagUdsEcu, StringWhitelist, ..., MultipleChoiceInterpretation>.",
                "Direct x86 ELF audit resolves adjacent helper 0x01356f90 through PLT entry 0x0197d6f0 to shared_ptr_emplace<VagUdsAdaptationSetting, VagUdsEcu, StringWhitelist, ..., MultipleChoiceInterpretation>.",
                "The x86 helper path at 0x012da25a obtains its whitelist through GOT [EBX-0x2AA4] relocation _ZN13VagWhitelists20CENTRAL_ELEC_MQB_ALLE and passes GOT [EBX-0x2C9C] relocation _ZN13VagWhitelists16CENTRAL_ELEC_MK8E through the whitelist vtable slot +0x14.",
                "The second x86 helper at 0x012da39a pushes GOT-derived _ZN13VagWhitelists19UDS_CAN_GATEWAY_MEBE from [EBX-0x2C94] and _ZN9VagUdsEcu11CAN_GATEWAYE from [EBX-0x5DF4], despite carrying the left fog-role key.",
                "The older ARM 01082988 type-7 branch has the same CENTRAL_ELEC plus MQB/MK8-derived whitelist argument shape: cornering_fogs_left_ref_1_01082988.txt loads VagUdsEcu::CENTRAL_ELEC from 014f7ad8 and derives a whitelist from CENTRAL_ELEC_MQB_ALL (014f706c) with CENTRAL_ELEC_MK8 (014f701c).",
                "The same older ARM per-side region loads part-number patterns 5Q0937084* and 6C093708*, but no 6R0937087K / 6R0-937-08x pattern was recovered for the 055C path.",
                "The older ARM 01082A4A type-7 branch is gateway-shaped: cornering_fogs_left_ref_2_01082A4A.txt loads VagWhitelists::UDS_CAN_GATEWAY_MEB from 014f6c0c and VagUdsEcu::CAN_GATEWAY from 014f7a7c.",
                "Older ARM windows prove both left variants allocate VagUdsAdaptationSetting: 01082988 -> 010B90CC -> 010E44E8 and 01082A4A -> 010B5620 -> 010D2BD0.",
                "Native constructor uses raw address 055C, value offset 5, mask FF.",
                "No recovered per-side 055C branch is currently guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S.",
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
            constructor_kind="mixed",
            constructor_status="write_blocked_read_rejected",
            native_helper="official x86: 0x012da5a9 -> 0x01368690 -> PLT 0x0197e0a0 VagUdsAdaptationSetting; 0x012da6e9 -> 0x0136caf0 -> PLT 0x0197e300 VagUdsAdaptationSetting. Older ARM: 01082B78 -> 010B8574 -> 010E0DE8 VagUdsAdaptationSetting and 01082C34 -> 010B9120 -> 010E466C VagUdsAdaptationSetting; readVagUdsValue -> ReadRawDataByIdentifierCommand applies to the 055D type-7 branches",
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
                "Direct x86 ELF audit resolves 0x01368690 through PLT entry 0x0197e0a0 to shared_ptr_emplace<VagUdsAdaptationSetting, VagUdsEcu, StringWhitelist, ..., MultipleChoiceInterpretation>.",
                "Direct x86 ELF audit resolves adjacent helper 0x0136caf0 through PLT entry 0x0197e300 to shared_ptr_emplace<VagUdsAdaptationSetting, VagUdsEcu, StringWhitelist, ..., MultipleChoiceInterpretation>.",
                "The x86 helper path at 0x012da5a9 uses the same GOT [EBX-0x2AA4] CENTRAL_ELEC_MQB_ALL plus [EBX-0x2C9C] CENTRAL_ELEC_MK8 whitelist derivation as the left-side first helper.",
                "The second right-side x86 gateway-shaped path at 0x012da6e9 pushes GOT-derived _ZN13VagWhitelists19UDS_CAN_GATEWAY_MEBE from [EBX-0x2C94] and _ZN9VagUdsEcu11CAN_GATEWAYE from [EBX-0x5DF4].",
                "The older ARM 01082B78 type-7 branch has the same CENTRAL_ELEC plus MQB/MK8-derived whitelist argument shape: cornering_fogs_right_ref_1_01082B78.txt follows the same 014f706c/014f701c derivation and loads VagUdsEcu::CENTRAL_ELEC from 014f7ad8.",
                "The same older ARM per-side region loads part-number patterns 5Q0937084* and 6C093708*, but no 6R0937087K / 6R0-937-08x pattern was recovered for the 055D path.",
                "The older ARM 01082C34 type-7 branch is gateway-shaped: cornering_fogs_right_ref_2_01082C34.txt loads VagWhitelists::UDS_CAN_GATEWAY_MEB from 014f6c0c and VagUdsEcu::CAN_GATEWAY from 014f7a7c.",
                "Older ARM windows prove both right variants allocate VagUdsAdaptationSetting: 01082B78 -> 010B8574 -> 010E0DE8 and 01082C34 -> 010B9120 -> 010E466C.",
                "Native constructor uses raw address 055D, value offset 5, mask FF.",
                "No recovered per-side 055D branch is currently guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S.",
                "Type 7 dispatch goes through UDS raw DID read/write helpers.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_via_fogs",
            label="Cornering lights using fog lights",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012d9ed4 / 0x012d9f7b (Play 9.8.3 x86)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md",
            constructor_kind="FullByteVagCanShortAdaptationSetting",
            constructor_status="constructor_partial",
            native_helper=(
                "official x86 same-key branches: 0x012d9f09, 0x012d9f7b, 0x012d9ff6, and 0x012da071 all call 0x01358fd0 "
                "FullByteVagCanShortAdaptationSetting; the 0x012d9f7b branch is guarded by CENTRAL_ELEC_6R_5C_7E_7H"
            ),
            raw_address=None,
            value_offset=0x0C,
            value_mask="40",
            immediate_value=0x40,
            immediate_index=0x0C,
            choices=_enabled_disabled_choices(
                "Official x86 0x012d9f7b branch passes MultipleChoiceInterpretation::ENABLED_DISABLED into the 6R/PQ25 byte 0x0c mask 0x40 branch."
            ),
            read_method="Official x86 branch is FullByteVagCanShortAdaptationSetting; live DID 0600 writes changed the same byte/mask but did not fix the symptom.",
            write_method="Do not retest as a standalone write; this byte/mask is already behavior-disproven for the missing turn-signal cornering behavior.",
            next_re_step="Keep this as a ruled-out prerequisite bit and focus on branches not already set/behavior-disproven.",
            evidence=(
                "Official x86 0x012d9ed4 loads car_setting_cornering_lights_via_fogs.",
                "Official x86 0x012d9f7b pushes CENTRAL_ELEC_6R_5C_7E_7H, VagCanEcu::CENTRAL_ELEC, immediate pair byte 0x0c/mask 0x40, and ENABLED_DISABLED.",
                "The same key also has official x86 1S byte 0x0c/mask 0x40, MK6_8X_B7 byte 0x0e/mask 0x80, and B8 byte 0x04/mask 0x01 branches.",
                "Current live coding has byte 0x0c mask 0x40 set, but physical testing still showed no turn-signal-triggered cornering.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_via_fogs_experimental",
            label="Cornering lights using fog lights (experimental)",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012da0bd / 0x012da0f2 (Play 9.8.3 x86)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md",
            constructor_kind="VagUdsCodingSetting",
            constructor_status="constructor_partial",
            native_helper="official x86 0x012da0f2 -> 0x0135eaf0 VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation",
            raw_address=None,
            value_offset=0x15,
            value_mask="80",
            immediate_value=0x80,
            immediate_index=0x15,
            choices=_yes_no_choices(
                "Official x86 0x012da0f2 branch passes MultipleChoiceInterpretation::YES_NO into the 6R/PQ25 byte 0x15 mask 0x80 branch."
            ),
            read_method="Coding-style byte 0x15 mask 0x80 branch; no separate direct DID candidate recovered.",
            write_method="Do not write: fresh engine-running coding byte 0x15 is 0xA6, so mask 0x80 is already set.",
            next_re_step="Treat as already-enabled negative evidence for this symptom unless runtime Carista UI proves otherwise.",
            evidence=(
                "Official x86 0x012da0bd loads car_setting_cornering_lights_via_fogs_experimental.",
                "Official x86 0x012da0f2 pushes CENTRAL_ELEC_6R_5C_7E_7H, VagCanEcu::CENTRAL_ELEC, byte 0x15, mask 0x80, and YES_NO.",
                "Fresh engine-running coding byte 0x15 is 0xA6, so this bit is already set while turn-signal cornering behavior is absent.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_with_turn_signals",
            label="Turn on cornering lights when turn signal is on",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x012da72c / 0x012da761 (Play 9.8.3 x86)",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md",
            constructor_kind="VagUdsCodingSetting",
            constructor_status="constructor_partial",
            native_helper="official x86 0x012da761 -> 0x0135e920 VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation",
            raw_address=None,
            value_offset=0x15,
            value_mask="04",
            immediate_value=0x04,
            immediate_index=0x15,
            choices=_yes_no_choices(
                "Official x86 0x012da761 branch passes MultipleChoiceInterpretation::YES_NO into the explicit turn-signal-cornering byte 0x15 mask 0x04 branch."
            ),
            read_method="Coding-style byte 0x15 mask 0x04 branch; no separate direct DID candidate recovered.",
            write_method="Do not write: fresh engine-running coding byte 0x15 is 0xA6, so mask 0x04 is already set.",
            next_re_step="This explicit turn-signal key is already enabled in current coding; look for prerequisite/output-role branches instead of toggling it again.",
            evidence=(
                "Official x86 0x012da72c loads car_setting_cornering_lights_with_turn_signals before the 0x012da761 helper call.",
                "Official x86 0x012da761 pushes CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S, VagCanEcu::CENTRAL_ELEC, byte 0x15, mask 0x04, and YES_NO.",
                "Fresh engine-running coding byte 0x15 is 0xA6, so this bit is already set while turn-signal cornering behavior is absent.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_fog_lights_on_reverse",
            label="Fog lights on reverse",
            ecu="non-6R VAG central electrics D1D branch family",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86 Ghidra export",
            reference_address="0x012d62e6 / 0x012d632e / 0x012d63ec (Play 9.8.3 x86)",
            instruction_window="carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting/branches/fog_lights_on_reverse_d1d_012D62E6.md",
            constructor_kind="VagUdsAdaptationSetting",
            constructor_status="constructor_partial",
            native_helper="official x86 D1D branches call 0x013591a0 and 0x013691d0 VagUdsAdaptationSetting helpers",
            raw_address=0x0D1D,
            value_offset=0,
            value_mask="02",
            immediate_value=0x02,
            immediate_index=0,
            choices=_enabled_disabled_choices(
                "Official x86 0x012d632e branch passes MultipleChoiceInterpretation::ENABLED_DISABLED into the D1D offset 0 mask 0x02 branch."
            ),
            read_method="D1D UDS adaptation-style branch; recovered guards are MK7/6C/MQBA0/MK8, not 6R/PQ25.",
            write_method="Blocked: no recovered 6R/PQ25 guard and no positive 220D1D payload; never build 2E0D1D from this branch for the Polo.",
            next_re_step="Use this as negative platform-scope evidence while continuing to search for 6R/PQ25-owned branches.",
            evidence=(
                "Ghidra export fog_lights_on_reverse_d1d_012D62E6 shows car_setting_fog_lights_on_reverse at 0x012d62e6.",
                "The 0x012d632e helper call passes raw/DID 0x0d1d, offset 0, mask 0x02, UDS_CENTRAL_ELEC_MK7, CENTRAL_ELEC_MK7_6C, VagUdsEcu::CENTRAL_ELEC, and ENABLED_DISABLED.",
                "The later same-key 0x012d63ec helper path uses CENTRAL_ELEC_MK7_NEW_MQBA0 plus a CENTRAL_ELEC_MK8-derived whitelist with VagUdsEcu::CENTRAL_ELEC.",
                "No recovered fog-on-reverse D1D branch in the Ghidra x86 window is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_activation",
            label="Cornering lights activation method",
            ecu="non-6R VAG central electrics D1D branch family",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86 Ghidra export",
            reference_address="0x012da8bd / 0x012da906 / 0x012daab2 / 0x012dab32 (Play 9.8.3 x86)",
            instruction_window="carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting/branches/cornering_lights_activation_d1d_012DA8BD.md",
            constructor_kind="mixed",
            constructor_status="constructor_partial",
            native_helper="official x86 D1D paths call 0x0133e9f0 VagUdsAdaptationSetting; nearby non-D1D B8 path calls 0x0135e750 VagCanLongCodingSetting",
            raw_address=0x0D1D,
            value_offset=2,
            value_mask="38",
            immediate_value=0x38,
            immediate_index=2,
            choices=(
                _choice("car_setting_disabled", "00", "D1D activation choice vector"),
                _choice("car_setting_steering_wheel_method_a", "01", "D1D activation choice vector"),
                _choice("car_setting_steering_wheel_and_blinker_method_a", "02", "D1D activation choice vector"),
                _choice("car_setting_steering_wheel_method_b", "03", "D1D activation choice vector"),
                _choice("car_setting_steering_wheel_and_blinker_method_b", "04", "D1D activation choice vector"),
                _choice("car_setting_not_defined", "06", "D1D activation choice vector"),
            ),
            read_method="D1D UDS adaptation-style branch; recovered D1D guards are MK7/6C/MQBA0, not 6R/PQ25.",
            write_method="Blocked: no recovered 6R/PQ25 guard and no positive 220D1D payload; never build 2E0D1D from this branch for the Polo.",
            next_re_step="Keep as platform-negative evidence; do not confuse this with the already-set 6R DID 0600 byte 0x15 mask 0x04 turn-signal key.",
            evidence=(
                "Ghidra export cornering_lights_activation_d1d_012DA8BD shows car_setting_cornering_lights_activation at 0x012da8bd.",
                "The 0x012da906 helper call passes raw/DID 0x0d1d, offset 2, mask 0x38, UDS_CENTRAL_ELEC_MK7, CENTRAL_ELEC_MK7_6C, and VagUdsEcu::CENTRAL_ELEC.",
                "The later 0x012daab2 same-key D1D helper uses CENTRAL_ELEC_MK7_NEW_MQBA0 with VagUdsEcu::CENTRAL_ELEC.",
                "The nearby 0x012dab32 path is a B8 long-coding variant guarded by CENTRAL_ELEC_B8 plus VagCanEcu::CENTRAL_ELEC, not a D1D 6R path.",
                "No recovered activation D1D branch in the Ghidra x86 window is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_min_activation_speed",
            label="Cornering lights minimum activation speed",
            ecu="non-6R VAG central electrics D1D branch family",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86 Ghidra export",
            reference_address="0x012daf54 / 0x012daf97 / 0x012db0a5 (Play 9.8.3 x86)",
            instruction_window="carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting/branches/cornering_lights_min_activation_speed_d1d_012DAF54.md",
            constructor_kind="VagUdsAdaptationSetting",
            constructor_status="constructor_partial",
            native_helper="official x86 D1D numerical helpers call 0x0136ccc0 and 0x0136cea0 VagUdsAdaptationSetting paths",
            raw_address=0x0D1D,
            value_offset=3,
            value_mask="FF",
            immediate_value=0xFF,
            immediate_index=3,
            choices=(),
            read_method="D1D UDS adaptation-style numerical branch with Unit::KM_H; guards are MK7/MK7_6C/MK7_NEW_MQBA0, not 6R/PQ25.",
            write_method="Blocked: no recovered 6R/PQ25 guard and no positive 220D1D payload; never build 2E0D1D from this branch for the Polo.",
            next_re_step="Treat the D1D speed settings as non-PQ25 evidence unless a recovered 6R guard appears.",
            evidence=(
                "Ghidra export cornering_lights_min_activation_speed_d1d_012DAF54 shows the key at 0x012daf54.",
                "The primary observed raw tuple is raw/DID 0x0d1d, offset 3, mask 0xff with Unit::KM_H numerical interpretation.",
                "Observed guards include CENTRAL_ELEC_MK7_ALL, CENTRAL_ELEC_MK7_6C, and CENTRAL_ELEC_MK7_NEW_MQBA0 with VagUdsEcu::CENTRAL_ELEC.",
                "No recovered min-speed D1D branch in the Ghidra x86 window is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_max_activation_speed",
            label="Cornering lights maximum activation speed",
            ecu="non-6R VAG central electrics D1D branch family",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86 Ghidra export",
            reference_address="0x012db176 / 0x012db1bf / 0x012db2f6 (Play 9.8.3 x86)",
            instruction_window="carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting/branches/cornering_lights_max_activation_speed_d1d_012DB176.md",
            constructor_kind="VagUdsAdaptationSetting",
            constructor_status="constructor_partial",
            native_helper="official x86 D1D numerical helpers call 0x0136cea0 and 0x0136d080 VagUdsAdaptationSetting paths",
            raw_address=0x0D1D,
            value_offset=4,
            value_mask="FF",
            immediate_value=0xFF,
            immediate_index=4,
            choices=(),
            read_method="D1D UDS adaptation-style numerical branch with Unit::KM_H; guards are MK7_6C/MK7_NEW_MQBA0/MK8-derived, not 6R/PQ25.",
            write_method="Blocked: no recovered 6R/PQ25 guard and no positive 220D1D payload; never build 2E0D1D from this branch for the Polo.",
            next_re_step="Treat the D1D speed settings as non-PQ25 evidence unless a recovered 6R guard appears.",
            evidence=(
                "Ghidra export cornering_lights_max_activation_speed_d1d_012DB176 shows the key at 0x012db176.",
                "The primary observed raw tuple is raw/DID 0x0d1d, offset 4, mask 0xff with Unit::KM_H numerical interpretation.",
                "Observed guards include CENTRAL_ELEC_MK7_6C and CENTRAL_ELEC_MK7_NEW_MQBA0/MK8-derived whitelists with VagUdsEcu::CENTRAL_ELEC.",
                "No recovered max-speed D1D branch in the Ghidra x86 window is guarded by CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_req_rls",
            label="Coming-home requires rain/light sensor",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86; FUN_0105f6c0 older ARM",
            reference_address="0x012c71a3 / 0x012c74fe 6R/PQ25 reused key branch (Play 9.8.3 x86); 0107671A / 01076772 / 010767E0 / 01076964",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; coming_home_req_rls_ref_0107671A.txt; coming_home_master_ref_01076860.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper=(
                "official x86 0x012c74fe -> 0x0133b390 VagUdsCodingSetting guarded by CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S; "
                "010B6B3C -> 010D8FE4 VagUdsAdaptationSetting; "
                "010B6B90 -> 010D917C VagCanLongCodingSetting; "
                "010B0D5C -> 010BC860 VagUdsCodingSetting; "
                "010B19D0 -> 010C0708 VagUdsCodingSetting"
            ),
            raw_address=0x0A57,
            value_offset=2,
            value_mask="04",
            immediate_value=0x04,
            immediate_index=0x0A,
            choices=_enabled_disabled_choices(
                "Official x86 0x012c74fe and coming_home_req_rls_ref_0107671A pass MultipleChoiceInterpretation::ENABLED_DISABLED (014f1ff0) into the recovered adaptation, long-coding, and UDS-coding constructor calls."
            ),
            read_method="Official x86 6R/PQ25 branch reads DID 0600 byte 0x0A mask 0x04; 220A57 is the rejected adaptation branch; older UDS coding/long-coding variants are also present.",
            write_method="Do not write from this recovery until runtime branch selection and requested-choice encoding are known.",
            next_re_step="Recover requested-choice packing for the x86 6R/PQ25 DID 0600 byte 0x0A mask 0x04 branch before considering any write.",
            evidence=(
                "Official x86 0x012c74cf loads VagWhitelists::CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S and 0x012c74f0 pushes VagCanEcu::CENTRAL_ELEC before the reused car_setting_coming_home_req_rls branch.",
                "Official x86 0x012c74af/0x012c74b9 set DID 0600 byte/mask pair 0x0A/0x04 before 0x012c74fe calls 0x0133b390, which the pyelftools helper resolver classifies as VagUdsCodingSetting.",
                "The immediate fields on this recovery intentionally prefer the official x86 6R/PQ25 branch over the older same-key 0x11/0x20 branch.",
                "The following direct car_setting_coming_home_menu_default_req_rls branch at 0x012c7551 is separate MK7/6C UDS adaptation evidence: raw/address 0x0D04, offset 0, mask/value field 0x04, not a 6R/PQ25 branch.",
                "Instruction window shows raw address 0A57, offset 2, mask/value field 04 before one req-RLS constructor.",
                "target_010B6B3C.c calls 010D8FE4, which constructs VagUdsAdaptationSetting.",
                "target_010B6B90.c calls 010D917C, which constructs VagCanLongCodingSetting.",
                "target_010B0D5C.c calls 010BC860, which constructs VagUdsCodingSetting.",
                "The same key appears again through 010B19D0 -> 010C0708, another VagUdsCodingSetting helper.",
                "coming_home_req_rls_ref_0107671A shows UDS coding immediate pairs 20/11 and 04/0A for these helpers.",
                "VagUdsCodingSetting(Ecu, int, byte/vector) hardcodes raw address 0x0600 and type 8, mapping those pairs to DID 0600 byte/mask fields.",
                ENABLED_DISABLED_SINGLETON_EVIDENCE,
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
            immediate_value=0x02,
            immediate_index=0x06,
            choices=_enabled_disabled_choices(
                "coming_home_master_ref_01076860 passes MultipleChoiceInterpretation::ENABLED_DISABLED (014f1ff0) into all recovered coming_home constructor calls."
            ),
            read_method="220A57 is the rejected adaptation branch; UDS coding variants read DID 0600 byte 0x06 mask 0x02 and byte 0x07 mask 0x01.",
            write_method="Do not write from this recovery until runtime branch selection and requested-choice encoding are known.",
            next_re_step="Runtime-select the active coming_home branch for this BCM and map requested choices onto the DID 0600 byte/mask variants.",
            evidence=(
                "Instruction window shows raw address 0A57, offset 4, mask/value field 40 before one coming_home constructor.",
                "target_010B6BDC.c calls 010D92EC, which constructs VagUdsAdaptationSetting.",
                "target_010B2040.c calls 010C2700, which constructs VagUdsCodingSetting.",
                "target_010B3AF0.c calls 010CA958, which constructs VagUdsCodingSetting.",
                "coming_home_master_ref_01076860 shows UDS coding immediate pairs 02/06 and 01/07 for the two coding helpers.",
                "VagUdsCodingSetting(Ecu, int, byte/vector) hardcodes raw address 0x0600 and type 8, mapping those pairs to DID 0600 byte/mask fields.",
                ENABLED_DISABLED_SINGLETON_EVIDENCE,
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_mode",
            label="Coming-home mode",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86; FUN_0105f6c0 older ARM",
            reference_address="0x012c769d / 0x012c76e6 / 0x012c77ec / 0x012c78f2 (Play 9.8.3 x86); 01076AB4 / 01076B5E / 01076BF4",
            instruction_window="x86 dump 0x012c7460..0x012c7940; coming_home_mode_ref_01076AB4.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper="official x86 0x012c76e6 -> 0x0135f420 VagUdsAdaptationSetting guarded by CENTRAL_ELEC_MQBA0; 0x012c77ec -> 0x0135f600 VagCanLongCodingSetting guarded by CENTRAL_ELEC_MK5_MED_HIGH; 0x012c78f2 -> 0x0135f7d0 VagUdsCodingSetting guarded by CENTRAL_ELEC_MK6_8X_B7; older ARM 010B6C30 -> 010D9484 VagUdsAdaptationSetting; 010B6C84 -> 010D9608 VagCanLongCodingSetting",
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
            read_method="Official x86 visible branches are MQBA0/MK5/MK6-family, not 6R/PQ25; 220A57 adaptation candidate at offset 2 returned 7F2231 live; a long-coding variant is also present.",
            write_method="Do not write from this recovery until runtime branch selection and positive read/packing evidence are known.",
            next_re_step="Treat official x86 visible mode branches as non-6R until a CENTRAL_ELEC_6R guard or runtime availability record proves otherwise.",
            evidence=(
                "Official x86 0x012c75c5..0x012c76e6 builds car_setting_coming_home_mode as raw 0x0A57 offset 2 field/count 0x03 under CENTRAL_ELEC_MQBA0 and VagUdsEcu::CENTRAL_ELEC.",
                "Official x86 0x012c77ec builds a same-key long-coding branch under CENTRAL_ELEC_MK5_MED_HIGH, and 0x012c78f2 builds a UDS-coding branch under CENTRAL_ELEC_MK6_8X_B7.",
                "No visible official x86 coming_home_mode branch in this window uses CENTRAL_ELEC_6R, CENTRAL_ELEC_6R_5C_7E_7H, or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S.",
                "Instruction window shows raw address 0A57, offset/count 2/3 and disabled/manual/automatic choices.",
                "target_010B6C30.c calls 010D9484, which constructs VagUdsAdaptationSetting.",
                "target_010B6C84.c calls 010D9608, which constructs VagCanLongCodingSetting.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_coming_home_duration",
            label="Coming-home duration",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86; FUN_0105f6c0 older ARM",
            reference_address="0x012c9a61 / 0x012c9a96 (Play 9.8.3 x86); 0107813E / nearby duration variants",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; coming_home_duration_ref_0107813E.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper=(
                "official x86 0x012c9a96 -> 0x01360c30 VagCanShortAdaptationSetting channel 0x2f guarded by CENTRAL_ELEC_6R_5C_7E_7H; "
                "official x86 0x012c9b2f -> 0x01360de0 VagUdsAdaptationSetting raw 0x0a57 offset 3 mask 0xff MQBA0 fallback; "
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
                _choice("car_setting_time_25sec", "19", "0A57 duration table."),
                _choice("car_setting_time_30sec", "1E", "0A57 duration table."),
                _choice("car_setting_time_35sec", "23", "0A57 duration table."),
                _choice("car_setting_time_40sec", "28", "0A57 duration table."),
                _choice("car_setting_time_45sec", "2D", "0A57 duration table."),
                _choice("car_setting_time_50sec", "32", "0A57 duration table."),
                _choice("car_setting_time_55sec", "37", "0A57 duration table."),
                _choice("car_setting_time_60sec", "3C", "0A57 duration table."),
            ),
            read_method="Official x86 6R/PQ25 branch is VAG short-adaptation channel 0x2F; the 220A57 UDS-adaptation duration variant is an MQBA0 fallback and direct 220A57 returned 7F2231 live.",
            write_method="Do not write from this recovery until runtime branch selection proves which adaptation path applies.",
            next_re_step="Decode the exact VagCanShortAdaptationSetting request/response packing for channel 0x2F before any live adaptation write plan.",
            evidence=(
                "Official x86 0x012c9a82 pushes CENTRAL_ELEC_6R_5C_7E_7H and 0x012c9a88 pushes VagCanEcu::CENTRAL_ELEC before 0x012c9a96 calls 0x01360c30, resolved as VagCanShortAdaptationSetting.",
                "Official x86 0x012c9861 sets short-adaptation channel 0x2F for the coming-home duration branch.",
                "Official x86 fallback after the short-adaptation branch uses raw/address 0x0A57, offset 3, mask 0xFF and helper 0x01360de0, resolved as VagUdsAdaptationSetting.",
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
            native_helper="official x86 direct: 0x012c8913 and 0x012c8a1e -> 0x0133fdf0 VagUdsAdaptationSetting helpers guarded by CENTRAL_ELEC_MK8 or UDS_CAN_GATEWAY_MEB; older ARM: 0x010B1930 -> 0x010C0418 VagUdsAdaptationSetting and 0x010B4218 -> 0x010CCBC8 VagUdsCodingSetting",
            raw_address=0x110E,
            value_offset=2,
            value_mask="01",
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_fogs", None, "Branch-specific encoding: 110E adaptation and DID 0600 byte 0D/mask 40 tables store fogs=00, but the DID 0600 byte 11/mask 08 table stores fogs=01."),
                _choice("car_setting_low_beams", None, "Branch-specific encoding: 110E adaptation and DID 0600 byte 0D/mask 40 tables store low_beams=01, but the DID 0600 byte 11/mask 08 table stores low_beams=00."),
            ),
            read_method="22110E is the rejected official x86 adaptation path; older ARM UDS coding alternatives show DID 0600 byte/mask pairs 0x0D/0x40 and 0x11/0x08.",
            write_method="Do not write either path until branch selection and requested-choice encoding are known.",
            next_re_step="Do not treat the official x86 direct branches as PQ25-selected; recover whether a separate 6R branch exists or whether this visible selector is absent for 6R0937087K.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012c88d0; first visible helper call targets 0x0133fdf0, resolved by the pyelftools helper resolver as VagUdsAdaptationSetting.",
                "Official x86 0x012c8913 pushes VagUdsEcu::CENTRAL_ELEC, CENTRAL_ELEC_MK8, raw/address 0x110e, offset 2, field 1, and the coming_leaving_home_output key.",
                "Official x86 0x012c8a1e pushes VagUdsEcu::CAN_GATEWAY, UDS_CAN_GATEWAY_MEB, raw/address 0x110e, offset 2, field 1, and the same key.",
                "No official x86 direct coming_leaving_home_output branch is currently guarded by CENTRAL_ELEC_6R or CENTRAL_ELEC_6R_5C_7E_7H.",
                "Official static candidate DID 0x110E has offset 2 / field 1, but live 22110E returned 7F2231, so this is not a write seed.",
                "Instruction window shows raw address 110E, value offset 2, mask/value field 1 near the key.",
                "Ghidra export target_010B1930.c calls 0x010C0418.",
                "Ghidra export target_010C0418.c constructs VagUdsAdaptationSetting.",
                "Second-path instruction window stores coding pairs 40/0D and 08/11 before calling 0x010B4218.",
                "For the 40/0D coding variant, coming_leaving_home_output_ref_2_01079282 stores car_setting_fogs with compact value 00 and car_setting_low_beams with compact value 01.",
                "For the 08/11 coding variant, the same instruction window stores car_setting_fogs with compact value 01 and car_setting_low_beams with compact value 00.",
                "The older 110E adaptation branch stores car_setting_fogs with compact value 00 and car_setting_low_beams with compact value 01.",
                "Instruction window coming_leaving_home_output_ref_2_01079282 calls 0x010B4218 at 01079296 and 0107932A.",
                "target_010B4218.c calls 0x010CCBC8.",
                "target_010CCBC8.c constructs VagUdsCodingSetting.",
                "VagUdsCodingSetting(Ecu, int, byte/vector) hardcodes raw address 0x0600 and type 8, so those pairs are DID 0600 byte/mask variants rather than separate raw DIDs.",
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
            native_helper="official x86 direct key: 0x012c8a8a -> 0x01358fd0 FullByteVagCanShortAdaptationSetting / VagCanEcu / MultipleChoiceInterpretation guarded by CENTRAL_ELEC_B8; older ARM fallback: 0x010B5A98 -> 0x010D4140 VagUdsCodingSetting",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=0x10,
            immediate_index=0x06,
            choices=_yes_no_choices(
                "coming_home_via_low_beams_ref_010776D8 passes MultipleChoiceInterpretation::YES_NO (014f1fd8) into the DID 0600 byte 06/mask 10 UDS-coding branch."
            ),
            read_method="Official x86 direct key is B8-scoped FullByteVagCanShortAdaptationSetting; older ARM fallback evidence has DID 0600 byte 0x06 mask 0x10.",
            write_method="Do not write from this setting recovery until runtime branch selection and requested-choice encoding are known.",
            next_re_step="Do not treat this as PQ25-selected unless an x86 6R whitelist branch or a licensed runtime availability record proves it.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012c8a55; first visible helper call targets 0x01358fd0.",
                "Official x86 0x012c8a8a pushes CENTRAL_ELEC_B8, VagCanEcu::CENTRAL_ELEC, immediate pair byte 0x06/mask 0x10, and YES_NO.",
                "No official x86 direct branch for this key is currently guarded by CENTRAL_ELEC_6R or CENTRAL_ELEC_6R_5C_7E_7H.",
                "Ghidra export target_010B5A98.c calls 0x010D4140.",
                "Ghidra export target_010D4140.c constructs VagUdsCodingSetting.",
                "Older ARM VagUdsCodingSetting(Ecu, int, byte/vector) evidence maps the immediate pair to DID 0600 byte 0x06 mask 0x10.",
                YES_NO_SINGLETON_EVIDENCE,
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
            native_helper="official x86 direct key: 0x012c92d0 -> 0x01340190 VagUdsCodingSetting / VagCanEcu / MultipleChoiceInterpretation guarded by CENTRAL_ELEC_B8; older ARM fallback: 0x010B19D0 -> 0x010C0708 VagUdsCodingSetting",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=0x20,
            immediate_index=0x06,
            choices=_yes_no_choices(
                "coming_home_via_fogs_ref_01077C50 passes MultipleChoiceInterpretation::YES_NO (014f1fd8) into the DID 0600 byte 06/mask 20 UDS-coding branch."
            ),
            read_method="Official x86 direct key is B8-scoped VagUdsCodingSetting at DID 0600 byte 0x06 mask 0x20; older ARM fallback evidence has the same byte/mask; direct adaptation candidates returned 7F2231.",
            write_method="Do not write from this setting recovery until runtime branch selection and requested-choice encoding are known.",
            next_re_step="Do not treat this as PQ25-selected unless an x86 6R whitelist branch or a licensed runtime availability record proves it.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012c929b; first visible helper call targets 0x01340190.",
                "Official x86 0x012c92d0 pushes CENTRAL_ELEC_B8, VagCanEcu::CENTRAL_ELEC, immediate pair byte 0x06/mask 0x20, and YES_NO before calling 0x01340190, resolved as VagUdsCodingSetting.",
                "No official x86 direct branch for this key is currently guarded by CENTRAL_ELEC_6R or CENTRAL_ELEC_6R_5C_7E_7H.",
                "Official static read-only candidates include 22056D plus nearby 220550/220551; all returned 7F2231 live.",
                "Ghidra export target_010B19D0.c calls 0x010C0708.",
                "Ghidra export target_010C0708.c constructs VagUdsCodingSetting.",
                "Older ARM VagUdsCodingSetting(Ecu, int, byte/vector) evidence maps the immediate pair to DID 0600 byte 0x06 mask 0x20.",
                YES_NO_SINGLETON_EVIDENCE,
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_leaving_home_req_rls",
            label="Leaving-home requires rain/light sensor",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86; FUN_0105f6c0 older ARM",
            reference_address="0x012ca544 / 0x012ca6e9 6R/PQ25 branch (Play 9.8.3 x86); 0107879A / 01078896",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; leaving_home_req_rls_ref_0107879A.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper="official x86 0x012ca6e9 -> 0x01340190 VagUdsCodingSetting guarded by CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S; 010B7184 -> 010DAD6C VagCanLongCodingSetting; 010B19D0 -> 010C0708 VagUdsCodingSetting",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=0x02,
            immediate_index=0x0A,
            choices=_enabled_disabled_choices(
                "leaving_home_req_rls_ref_0107879A passes MultipleChoiceInterpretation::ENABLED_DISABLED (014f1ff0) into the long-coding and DID 0600 UDS-coding branches."
            ),
            read_method="Official x86 6R/PQ25 branch reads DID 0600 byte 0x0A mask 0x02; older long-coding byte 0x00 mask 0x20 and non-6R byte 0x11 mask 0x40 variants are also visible.",
            write_method="Do not write from this recovery until runtime branch selection and requested-choice encoding are known.",
            next_re_step="Recover requested-choice packing for the x86 6R/PQ25 DID 0600 byte 0x0A mask 0x02 branch before considering any write.",
            evidence=(
                "Official x86 0x012ca6a1/0x012ca6ab set DID 0600 byte/mask pair 0x0A/0x02 before 0x012ca6e9 calls 0x01340190, resolved as VagUdsCodingSetting.",
                "Official x86 0x012ca6d5 pushes CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S and 0x012ca6db pushes VagCanEcu::CENTRAL_ELEC for the 6R/PQ25 branch.",
                "A later x86 branch at 0x012ca899 uses CENTRAL_ELEC_MK6_8X_B7 and DID 0600 byte/mask 0x11/0x40, not the 6R/PQ25 guard.",
                "The following car_setting_leaving_home_menu_req_rls branch is separate MK7/6C UDS adaptation evidence: raw/address 0x0D04, offset 2, mask/value field 0x20.",
                "Instruction window shows leaving_home_req_rls refs at 0107879A and 01078896.",
                "target_010B7184.c calls 010DAD6C, which constructs VagCanLongCodingSetting.",
                "Second visible path reuses 010B19D0 -> 010C0708, which constructs VagUdsCodingSetting.",
                "leaving_home_req_rls_ref_0107879A shows long-coding pair 20/00 and UDS coding pair 02/0A for this key family.",
                "VagUdsCodingSetting(Ecu, int, byte/vector) hardcodes raw address 0x0600 and type 8, mapping the UDS pair to DID 0600 byte 0x0A mask 0x02.",
                ENABLED_DISABLED_SINGLETON_EVIDENCE,
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
            immediate_value=0x04,
            immediate_index=0x06,
            choices=_enabled_disabled_choices(
                "leaving_home_req_rls_ref_0107879A passes MultipleChoiceInterpretation::ENABLED_DISABLED (014f1ff0) into both recovered leaving_home UDS-coding branches."
            ),
            read_method="UDS coding variants read DID 0600 byte 0x06 mask 0x04 and byte 0x07 mask 0x08.",
            write_method="Do not write from this setting recovery until runtime branch selection and requested-choice encoding are known.",
            next_re_step="Resolve which leaving_home UDS coding helper applies and how requested choices map onto the DID 0600 byte/mask variants.",
            evidence=(
                "Instruction window shows leaving_home refs through two UDS coding helpers.",
                "target_010B71D0.c calls 010DAEDC, which constructs VagUdsCodingSetting.",
                "target_010B0C78.c calls 010BC404, which constructs VagUdsCodingSetting.",
                "leaving_home_req_rls_ref_0107879A shows immediate pairs 04/06 and 08/07 before the leaving_home helper calls.",
                "VagUdsCodingSetting(Ecu, int, byte/vector) hardcodes raw address 0x0600 and type 8, mapping those pairs to DID 0600 byte/mask fields.",
                ENABLED_DISABLED_SINGLETON_EVIDENCE,
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_leaving_home_duration",
            label="Leaving-home duration",
            ecu="PQ25 BCM / unit 09",
            native_function="_ZN14VagCanSettings11getSettingsEv / official Play 9.8.3 x86; FUN_0105f6c0 older ARM",
            reference_address="0x012cacd4 / 0x012cad09 (Play 9.8.3 x86); 01078C66 / nearby duration variants",
            instruction_window="docs/carista_apk_analysis/play_9_8_3_x86_vag_static_reverse_update.md; leaving_home_duration_ref_01078C66.txt; coming_leaving_home_output_ref_2_01079282.txt",
            constructor_kind="mixed",
            constructor_status="constructor_multi_path_runtime_branch_unresolved",
            native_helper=(
                "official x86 0x012cad09 -> 0x0133f140 VagCanShortAdaptationSetting channel 0x30 guarded by CENTRAL_ELEC_6R_5C_7E_7H; "
                "official x86 0x012cad9c -> 0x01361ab0 VagUdsAdaptationSetting raw 0x0a57 offset 5 mask 0xff MQBA0 fallback; "
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
                _choice("car_setting_time_25sec", "19", "0A57 duration table."),
                _choice("car_setting_time_30sec", "1E", "0A57 duration table."),
                _choice("car_setting_time_35sec", "23", "0A57 duration table."),
                _choice("car_setting_time_40sec", "28", "0A57 duration table."),
                _choice("car_setting_time_45sec", "2D", "0A57 duration table."),
                _choice("car_setting_time_50sec", "32", "0A57 duration table."),
                _choice("car_setting_time_55sec", "37", "0A57 duration table."),
                _choice("car_setting_time_60sec", "3C", "0A57 duration table."),
            ),
            read_method="Official x86 6R/PQ25 branch is VAG short-adaptation channel 0x30; the 220A57 UDS-adaptation duration variant is an MQBA0 fallback and direct 220A57 returned 7F2231 live.",
            write_method="Do not write from this recovery until runtime branch selection proves which adaptation path applies.",
            next_re_step="Decode the exact VagCanShortAdaptationSetting request/response packing for channel 0x30 before any live adaptation write plan.",
            evidence=(
                "Official x86 0x012cacf5 pushes CENTRAL_ELEC_6R_5C_7E_7H and 0x012cacfb pushes VagCanEcu::CENTRAL_ELEC before 0x012cad09 calls 0x0133f140, resolved as VagCanShortAdaptationSetting.",
                "Official x86 0x012cac68 sets short-adaptation channel 0x30 for the leaving-home duration branch.",
                "Official x86 fallback after the short-adaptation branch uses raw/address 0x0A57, offset 5, mask 0xFF and helper 0x01361ab0, resolved as VagUdsAdaptationSetting.",
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
                "official x86 6R/PQ25: 0x012cdeb6 -> 0x01361520 VagCanLongCodingSetting guarded by CENTRAL_ELEC_6R_5C_7E_7H byte 0x17/mask 0x04; "
                "official x86 non-6R variants include 0x012cdf28 -> 0x01363440 and additional MK5/MK6/B8 coding branches; "
                "010B71D0 -> 010DAEDC VagUdsCodingSetting; "
                "010B7764 -> 010DC980 VagCanLongCodingSetting; "
                "010B1980 -> 010C0590 VagUdsAdaptationSetting"
            ),
            raw_address=0x055C,
            value_offset=6,
            value_mask="FF",
            immediate_value=0x04,
            immediate_index=0x17,
            choices=(
                _choice("car_setting_no", "00", "Official x86 6R/PQ25 coding branch uses MultipleChoiceInterpretation::YES_NO."),
                _choice("car_setting_yes", "01", "Official x86 6R/PQ25 coding branch uses MultipleChoiceInterpretation::YES_NO."),
                _choice("car_setting_disabled", "00", "055C adaptation choice table in drl_via_fogs_ref_2."),
                _choice("car_setting_enabled", "14", "055C adaptation choice table in drl_via_fogs_ref_2."),
            ),
            read_method=(
                "The x86 6R/PQ25 branch is coding-style byte 0x17 mask 0x04. "
                "Read: 22 0600 -> 30-byte response; "
                "VagSetting_extractValue(coding, offset=23, mask='04') -> '00' (DISABLED) or '01' (ENABLED). "
                "ByteUtils_getLsbOffset('04')=2; result=(byte_23 & 0x04) >> 2. "
                "Current live BCM: byte 23 = 0x00 => extractValue returns '00' => car_setting_no = DISABLED. "
                "The 22055C adaptation candidate at offset 6 returned 7F2231 live and is blocked."
            ),
            write_method=(
                "ACTIONABLE pending live correlation test. "
                "The 6R/PQ25 branch targets DID 0600 byte 23 mask 0x04 via the same guarded 2E0600 write sequence "
                "proven on this BCM for the cornering bits. "
                "Modify: VagSetting_insertValue(coding, offset=23, mask='04', requested='01') => byte 23 = 0x04. "
                "Target coding: 3AB82B9F08A10000003008006C680ED000C8412F60A60004200000000000 (byte 23: 0x00->0x04). "
                "Write sequence: 2EF199 YYMMDD -> 22F1A5 -> 2EF198 workshop-code -> 2E0600 [30 bytes] -> 22 0600 verify. "
                "Do not write until the live correlation test (read-only before/after) confirms whether Carista "
                "or VCDS shows this setting as a separately togglable item on this BCM."
            ),
            next_re_step=(
                "TOP PRIORITY live hypothesis: DRL-via-fogs (byte 23 bit 2) may enable per-side fog output routing "
                "in the BCM firmware, which is the prerequisite for cornering-via-fogs to produce individual left/right "
                "activation. This is the ONLY recovered CENTRAL_ELEC_6R_5C_7E_7H bit not set in the current BCM. "
                "Recommended test: (1) read-only correlation pass — check if Carista app or VCDS shows drl_via_fogs "
                "as an available separately-togglable setting for this BCM; (2) if available, capture before/after "
                "220600 delta to confirm the byte/mask; (3) then perform the guarded 2E0600 write with the "
                "computed target coding and test cornering fog behaviour."
            ),
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012cde7b.",
                "Official x86 0x012cdeb6 pushes CENTRAL_ELEC_6R_5C_7E_7H, VagCanEcu::CENTRAL_ELEC, byte 0x17, mask 0x04, and YES_NO.",
                "Official x86 non-6R variants include CENTRAL_ELEC_MK5_HIGH byte 0x11/mask 0x10, CENTRAL_ELEC_MK6_8X_B7 byte 0x0e/mask 0x02, CENTRAL_ELEC_B8 byte 0x02/mask 0x08, plus MK8/gateway 055C adaptation branches.",
                "Refs-only probe finds six FUN_0105f6c0 references for this exact key.",
                "The DID 0600 and long-coding variants pass MultipleChoiceInterpretation::YES_NO (014f1fd8), whose static init maps car_setting_no=00 and car_setting_yes=01.",
                "Two 010B1980 calls construct VagUdsAdaptationSetting via 010C0590.",
                "The 055C adaptation table stores raw address 055C, offset 6, mask FF, disabled 00, enabled 14.",
                "Deep RE (2026-05-08): callee VagUdsCodingSetting_drl_via_fogs at 01361520 allocates 0x6C bytes (same size as all other VagUdsCodingSetting helpers) and calls inner-init 0x0197dcb0 with args (self, byte_ptr=23, mask_ptr=0x04, whitelist=CENTRAL_ELEC_6R_5C_7E_7H, ecu=CENTRAL_ELEC, key, YES_NO). Shape is byte-for-byte identical to the other 6R coding constructors.",
                "Deep RE (2026-05-08): after construction, caller dispatches vtable[12] (slot +0x30) on the result object to push it into the settings collection. This is a lifetime/collection management call, NOT an ECU read or write. Carista software has no inter-setting dependency between drl_via_fogs and cornering_lights_via_fogs.",
                "Deep RE (2026-05-08): VagOperationDelegate::getVagSettingAvailabilityForEcu (016b4180) evaluates each VagSetting independently via StringWhitelist::itemMatches. The CENTRAL_ELEC_6R_5C_7E_7H whitelist matches 6R0937087K, so drl_via_fogs IS available for this BCM. No code path gates cornering availability on drl_via_fogs state.",
                "BCM firmware hypothesis (not Carista software): DRL-via-fogs bit (byte 23, bit 2) may instruct the BCM to assign fog hardware outputs to the per-side DRL control channel instead of the paired front-fog channel. Without it, both fog relays/transistors share a single driver path with no individual addressing, making cornering (which requires per-side control) physically impossible regardless of the coding bits. Physical observation (fogs as steady paired output, no turn-signal response) matches the paired-channel model.",
                "This is the only CENTRAL_ELEC_6R_5C_7E_7H DID 0600 coding bit not set in the current live BCM. All other cornering-relevant 6R bits (byte 12 bit 6, byte 21 bits 2/5/7) are already set and were behaviour-disproven as standalone fixes on 2026-05-05.",
                YES_NO_SINGLETON_EVIDENCE,
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
                "official x86 6R/PQ25: 0x012d4dea -> 0x0135e580 VagUdsCodingSetting guarded by CENTRAL_ELEC_6R_5C_7E_7H byte 0x15/mask 0x20; "
                "0x012d4e65 -> 0x01368100 VagUdsCodingSetting-neighborhood; "
                "010B69C0 -> 010D88A0 VagUdsCodingSetting; "
                "010B8480 -> 010E0970 VagCanLongCodingSetting; "
                "010B7F38 -> 010DEE9C VagUdsAdaptationSetting"
            ),
            raw_address=0x0D01,
            value_offset=1,
            value_mask="01",
            immediate_value=0x20,
            immediate_index=0x15,
            choices=_yes_no_choices(
                "turn_off_fogs_with_high_beam_ref_1_0107F15A and ref_2_0107F26C pass MultipleChoiceInterpretation::YES_NO (014f1fd8) into the recovered UDS-coding, long-coding, and adaptation branches."
            ),
            read_method="The x86 6R/PQ25 branch is coding-style byte 0x15 mask 0x20; 220D01/220A58 adaptation variants returned 7F2231 live.",
            write_method="Do not write from this recovery; fresh engine-running coding byte 0x15 has mask 0x20 set and the physical high-beam shutoff behavior is already present.",
            next_re_step="Treat byte 0x15 mask 0x20 as a selected Carista branch but not a likely missing turn-signal-cornering fix.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012d4db5; helper calls target 0x0135e580 and 0x01368100.",
                "Official x86 0x012d4dea pushes CENTRAL_ELEC_6R_5C_7E_7H, VagCanEcu::CENTRAL_ELEC, byte 0x15, mask 0x20, and YES_NO.",
                "Official static read-only candidates include 220D01 and nearby 220A58; both returned 7F2231 live.",
                "Refs-only probe finds six FUN_0105f6c0 references plus app getSettings refs for this key.",
                "Instruction windows show UDS coding variants with immediate pairs 20/15, 04/0E, 02/04, and 01/0F; the first three are in the front-fog window and 01/0F sits at the boundary before the rear-fog key.",
                "Instruction window shows a long-coding variant with immediate pair 20/11.",
                "The recovered front-fog branches pass MultipleChoiceInterpretation::YES_NO (014f1fd8), whose static init maps car_setting_no=00 and car_setting_yes=01.",
                "VagUdsCodingSetting(Ecu, int, byte/vector) hardcodes raw address 0x0600 and type 8, so UDS coding immediate pairs map to DID 0600 byte/mask fields.",
                "Instruction windows show UDS adaptation variants at raw addresses 0D01 and 0A58 through 010B7F38 -> 010DEE9C.",
                "For the first adaptation variant, the window stores raw address 0D01 with adjacent 1/1 fields before constructing VagUdsAdaptationSetting.",
                YES_NO_SINGLETON_EVIDENCE,
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
            native_helper="official x86 6R/PQ25: 0x012d9bad -> 0x013625a0 VagCanLongCodingSetting guarded by CENTRAL_ELEC_6R_5C_7E_7H byte 0x16/mask 0x20; 0x012d9cc0 -> 0x0135f600 non-6R cornering_lights branch; older ARM 010B74A0 -> 010DBC4C VagUdsCodingSetting",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=0x20,
            immediate_index=0x16,
            choices=_enabled_disabled_choices(
                "assist_dr_lights_ref_0108252C passes MultipleChoiceInterpretation::ENABLED_DISABLED (014f1ff0) into the recovered DID 0600 byte 16/mask 20 UDS-coding branch."
            ),
            read_method="The x86 6R/PQ25 branch is coding-style byte 0x16 mask 0x20.",
            write_method="Use only full-coding guarded writes if intentionally tested; do not infer this from byte 22 bit 5 alone.",
            next_re_step="Lower priority for the fog-cornering symptom; current live coding has byte 0x16 mask 0x20 clear.",
            evidence=(
                "Official Play 9.8.3 x86 string ref is 0x012d9b78.",
                "Official x86 0x012d9bad pushes CENTRAL_ELEC_6R_5C_7E_7H, VagCanEcu::CENTRAL_ELEC, byte 0x16, mask 0x20, and ENABLED_DISABLED.",
                "Official x86 0x012d9cc0 is the nearby non-6R car_setting_cornering_lights branch, guarded by CENTRAL_ELEC_MK5_MED_30.",
                "Refs-only probe finds a direct FUN_0105f6c0 ref.",
                "Instruction window stores immediate pair 20/16 before car_setting_assist_dr_lights.",
                "010B74A0 calls 010DBC4C, which constructs VagUdsCodingSetting.",
                "Older ARM VagUdsCodingSetting(Ecu, int, byte/vector) evidence maps the immediate pair to DID 0600 byte 0x16 mask 0x20.",
                ENABLED_DISABLED_SINGLETON_EVIDENCE,
                "PQ25 catalog byte 22 bit 5 remains an external candidate, not native proof.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_fog_when",
            label="Use fog lights when",
            ecu="Ford setting zone, not PQ25 BCM / unit 09",
            native_function="_ZN12FordSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x00e72b62 string ref; 0x00e72bc1 constructor call",
            instruction_window="one-off x86 Capstone/ELF sweep, 2026-05-06",
            constructor_kind="FordCodingSetting",
            constructor_status="recovered_non_vag_ford_setting",
            native_helper="0x00e72bc1 -> 0x00ee30b0 -> shared_ptr_emplace<FordCodingSetting, ..., RA21_Kc, MultipleChoiceInterpretation>",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_use_cornering_lights", None, "Official x86 FordSettings window loads this as a Ford choice label at 0x00e72ab3 before constructing car_setting_fog_when."),
            ),
            read_method="Recovered direct constructor is FordCodingSetting only; no VAG/PQ25 setting object or read method recovered for this label.",
            write_method="Do not write on VW/PQ25 from this key. The recovered direct path is Ford-only.",
            next_re_step="Look for a VW/PQ25 equivalent through VAG keys or ReadValuesOperation objects, not this direct resource key.",
            evidence=(
                "Official Play 9.8.3 x86 string for car_setting_fog_when is referenced at 0x00e72b62 inside _ZN12FordSettings11getSettingsEv.",
                "The constructor call at 0x00e72bc1 targets 0x00ee30b0, whose symbol is shared_ptr_emplace<FordCodingSetting, ..., RA21_Kc, MultipleChoiceInterpretation>.",
                "No official x86 reference to this exact key was found inside _ZN14VagCanSettings11getSettingsEv.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_left_fog_light_as",
            label="Use the left fog light as",
            ecu="Ford setting zone, not PQ25 BCM / unit 09",
            native_function="_ZN12FordSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x00e73135 string ref; 0x00e73194 constructor call",
            instruction_window="one-off x86 Capstone/ELF sweep, 2026-05-06",
            constructor_kind="FordUdsSetting",
            constructor_status="recovered_non_vag_ford_setting",
            native_helper="0x00e73194 -> 0x00ee03b0 -> shared_ptr_emplace<FordUdsSetting, ..., RA45_Kc, MultipleChoiceInterpretation>",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_cornerig_lights_with_turn_signal", None, "Official x86 FordSettings window loads this typo-preserved label at 0x00e73334 as a Ford choice-table item for the left-fog setting."),
            ),
            read_method="Recovered direct constructor is FordUdsSetting only; no VAG/PQ25 setting object or read method recovered for this label.",
            write_method="Do not write on VW/PQ25 from this key. The recovered direct path is Ford-only.",
            next_re_step="If VW/PQ25 exposes an equivalent left-fog role, it must be through a different VAG key, sub-object, or ReadValuesOperation value path.",
            evidence=(
                "Official Play 9.8.3 x86 string for car_setting_left_fog_light_as is referenced at 0x00e73135 inside _ZN12FordSettings11getSettingsEv.",
                "The constructor call at 0x00e73194 targets 0x00ee03b0, whose symbol is shared_ptr_emplace<FordUdsSetting, ..., RA45_Kc, MultipleChoiceInterpretation>.",
                "No official x86 reference to this exact key was found inside _ZN14VagCanSettings11getSettingsEv.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_right_fog_light_as",
            label="Use the right fog light as",
            ecu="Ford setting zone, not PQ25 BCM / unit 09",
            native_function="_ZN12FordSettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x00e7376f string ref; 0x00e737ce constructor call",
            instruction_window="one-off x86 Capstone/ELF sweep, 2026-05-06",
            constructor_kind="FordUdsSetting",
            constructor_status="recovered_non_vag_ford_setting",
            native_helper="0x00e737ce -> 0x00ee59f0 -> shared_ptr_emplace<FordUdsSetting, ..., RA33_Kc, NumericalInterpretation>",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Recovered direct constructor is FordUdsSetting only; no VAG/PQ25 setting object or read method recovered for this label.",
            write_method="Do not write on VW/PQ25 from this key. The recovered direct path is Ford-only.",
            next_re_step="If VW/PQ25 exposes an equivalent right-fog role, it must be through a different VAG key, sub-object, or ReadValuesOperation value path.",
            evidence=(
                "Official Play 9.8.3 x86 string for car_setting_right_fog_light_as is referenced at 0x00e7376f inside _ZN12FordSettings11getSettingsEv.",
                "The constructor call at 0x00e737ce targets 0x00ee59f0, whose symbol is shared_ptr_emplace<FordUdsSetting, ..., RA33_Kc, NumericalInterpretation>.",
                "No official x86 reference to this exact key was found inside _ZN14VagCanSettings11getSettingsEv.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_cornering_lights_with_turn_signals_one_touch",
            label="Turn on cornering lights when one-touch turn signal is on",
            ecu="BMW E setting zone, not PQ25 BCM / unit 09",
            native_function="_ZN12BmwESettings11getSettingsEv / official Play 9.8.3 x86",
            reference_address="0x00d39204 string ref; 0x00d39240 / 0x00d392ba constructor calls",
            instruction_window="one-off x86 Capstone/ELF sweep, 2026-05-06",
            constructor_kind="BmwESetting",
            constructor_status="recovered_non_vag_bmw_setting",
            native_helper="0x00d39240 and 0x00d392ba -> 0x00d7eec0 -> shared_ptr_emplace<BmwESetting, ..., RA25_Kc, MultipleChoiceInterpretation>",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Recovered direct constructor is BmwESetting only; no VAG/PQ25 setting object or read method recovered for this label.",
            write_method="Do not write on VW/PQ25 from this key. The recovered direct path is BMW-only.",
            next_re_step="Treat the one-touch turn-signal resource as non-PQ25 until a separate VAG constructor path is recovered.",
            evidence=(
                "Official Play 9.8.3 x86 string for car_setting_cornering_lights_with_turn_signals_one_touch is referenced at 0x00d39204 inside _ZN12BmwESettings11getSettingsEv.",
                "The constructor calls at 0x00d39240 and 0x00d392ba target 0x00d7eec0, whose symbol is shared_ptr_emplace<BmwESetting, ..., RA25_Kc, MultipleChoiceInterpretation>.",
                "No official x86 reference to this exact key was found inside _ZN14VagCanSettings11getSettingsEv.",
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
            ecu="Ford setting zone, not PQ25 BCM / unit 09",
            native_function="FUN_00E314FE / older ARM Ford lighting setting constructor zone",
            reference_address="00E4BCFA direct string ref; string at 00A5D168",
            instruction_window="carista_apk_analysis/ghidra_instruction_windows/front_fogs_with_low_beams_ref_00E4BCFA.txt",
            constructor_kind="FordUdsSetting",
            constructor_status="recovered_non_vag_ford_setting",
            native_helper="00E82930 -> 00E8FBE4 -> shared_ptr_emplace<FordUdsSetting, ... RA22_Kc, MultipleChoiceInterpretation>",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(
                _choice("car_setting_low_beams", None, "Instruction window passes car_setting_low_beams into the FordUdsSetting constructor block at 00E4BD5C."),
            ),
            read_method="Recovered direct constructor is FordUdsSetting only; no VAG/PQ25 DID, raw address, or long-coding path was found.",
            write_method="Do not write on VW/PQ25 from this key. The recovered read/write path is Ford-only.",
            next_re_step="Find the VAG/PQ25 equivalent through ReadValuesOperation availability/value objects or another VAG key; the direct key is not the VW implementation.",
            evidence=(
                "Carista catalog contains the resource key.",
                "Refs-only probe found this exact key only in FUN_00E314FE, not in FUN_0105F6C0.",
                "Focused instruction window stores car_setting_front_fogs_with_low_beams at 00E4BCFA into the setting table and then calls 00E82930.",
                "00E82930 is a thin wrapper around 00E8FBE4.",
                "target_00E8FBE4.c constructs shared_ptr_emplace<FordUdsSetting, ..., RA22_Kc, MultipleChoiceInterpretation>.",
                "The same window uses car_setting_low_beams as a choice label at 00E4BD5C.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_fogs_with_high_beam_restriction",
            label="Fog lights with high beam restriction",
            ecu="Ford setting zone, not PQ25 BCM / unit 09",
            native_function="FUN_00E314FE / older ARM Ford lighting setting constructor zone",
            reference_address="00E4DE8A direct string ref; string at 0076A97E",
            instruction_window="carista_apk_analysis/ghidra_instruction_windows/fogs_with_high_beam_restriction_ref_00E4DE8A.txt",
            constructor_kind="FordCodingSetting",
            constructor_status="recovered_non_vag_ford_setting",
            native_helper="00E820A8 -> 00E8D43C -> shared_ptr_emplace<FordCodingSetting, ... RA28_Kc, MultipleChoiceInterpretation>",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Recovered direct constructor is FordCodingSetting only; use car_setting_turn_off_fogs_with_high_beam for the VAG/PQ25 high-beam fog lead.",
            write_method="Do not write on VW/PQ25 from this key. The recovered direct path is Ford-only.",
            next_re_step="Keep the VAG-side high-beam lead on car_setting_turn_off_fogs_with_high_beam, whose mixed VAG constructors are recovered separately.",
            evidence=(
                "Carista catalog contains a high-beam fog restriction key relevant to the observed high-beam test.",
                "Refs-only probe found this exact key only in FUN_00E314FE, not in FUN_0105F6C0.",
                "Focused instruction window stores car_setting_fogs_with_high_beam_restriction at 00E4DE8A inside a Ford fog_lights_mode choice table.",
                "00E820A8 is a thin wrapper around 00E8D43C.",
                "target_00E8D43C.c constructs shared_ptr_emplace<FordCodingSetting, ..., RA28_Kc, MultipleChoiceInterpretation>.",
            ),
        ),
        VagCanSettingsSettingRecovery(
            key="car_setting_turn_on_fogs_with_high_beam",
            label="Turn on fogs with high beam",
            ecu="Ford setting zone, not PQ25 BCM / unit 09",
            native_function="FUN_00E314FE / older ARM Ford lighting setting constructor zone",
            reference_address="00E4DE9A direct string ref; string at 00A5D1BA",
            instruction_window="carista_apk_analysis/ghidra_instruction_windows/turn_on_fogs_with_high_beam_ref_00E4DE9A.txt",
            constructor_kind="FordCodingSetting",
            constructor_status="recovered_non_vag_ford_setting",
            native_helper="00E820A8 -> 00E8D43C -> shared_ptr_emplace<FordCodingSetting, ... RA28_Kc, MultipleChoiceInterpretation>",
            raw_address=None,
            value_offset=None,
            value_mask=None,
            immediate_value=None,
            immediate_index=None,
            choices=(),
            read_method="Recovered direct constructor is FordCodingSetting only; no VAG/PQ25 read method was recovered for this key.",
            write_method="Do not write on VW/PQ25 from this key. The recovered direct path is Ford-only.",
            next_re_step="Search VAG/PQ25 settings by VAG constructor paths, not by this Ford high-beam key.",
            evidence=(
                "Carista catalog contains a high-beam fog setting key relevant to the observed high-beam test.",
                "Refs-only probe found this exact key only in FUN_00E314FE, not in FUN_0105F6C0.",
                "Focused instruction window stores car_setting_turn_on_fogs_with_high_beam at 00E4DE9A inside the same Ford fog_lights_mode choice table.",
                "00E820A8 is a thin wrapper around 00E8D43C.",
                "target_00E8D43C.c constructs shared_ptr_emplace<FordCodingSetting, ..., RA28_Kc, MultipleChoiceInterpretation>.",
            ),
        ),
    )


class VagCanSettings:
    getPq25SettingDefinitions = staticmethod(VagCanSettings_getPq25SettingDefinitions)
    getPq25SupportedSettings = staticmethod(VagCanSettings_getPq25SupportedSettings)
    pq25CurrentSettingStates = staticmethod(VagCanSettings_pq25CurrentSettingStates)
    getPq25SettingRecoveries = staticmethod(VagCanSettings_getPq25SettingRecoveries)
