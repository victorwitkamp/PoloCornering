from __future__ import annotations

from dataclasses import dataclass

from .ByteUtils import clean_hex, one_byte
from .Constants import CARISTA_LONG_CODING_DID
from .Types import HexString
from .VagSetting import VagSetting_insertValue


@dataclass(frozen=True)
class VagUdsCodingSetting:
    raw_address: int = CARISTA_LONG_CODING_DID
    setting_type: int = 8
    value_offset: int = 0
    value_mask: HexString = ""
    native_constructor: str = "VagUdsCodingSetting"
    native_source: str = "recovered from libCarista.so constructor exports"
    proof_notes: tuple[str, ...] = (
        "VagUdsCodingSetting(Ecu, vector) calls VagSetting with type 8 and raw address 0x0600.",
        "The constructor int is passed to VagSetting's offset field; the byte/vector argument is passed as the value mask vector used by VagSetting::insertValue.",
    )

    @property
    def value(self) -> HexString:
        return self.value_mask

    def insert_value(self, current_raw_value: HexString, requested_value: HexString) -> HexString:
        return VagSetting_insertValue(current_raw_value, self.value_offset, self.value_mask, requested_value)


def _validate_value_offset(value_offset: int) -> int:
    if value_offset < 0:
        raise ValueError("VagUdsCodingSetting value offset must be non-negative")
    return value_offset


def VagUdsCodingSetting_ctor_ecu_vector(value: HexString, value_offset: int = 0) -> VagUdsCodingSetting:
    return VagUdsCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=clean_hex(value, "VagUdsCodingSetting value mask"),
        native_constructor="VagUdsCodingSetting(Ecu*, StringWhitelist, int, vector<unsigned char>, key, Interpretation, AvailBy)",
    )


def VagUdsCodingSetting_ctor_ecu_byte(value: int, value_offset: int = 0) -> VagUdsCodingSetting:
    return VagUdsCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=one_byte(value, "VagUdsCodingSetting byte value mask"),
        native_constructor="VagUdsCodingSetting(Ecu*, StringWhitelist, int, unsigned char, key, Interpretation, AvailBy)",
    )


def VagUdsCodingSetting_ctor_ecu_byte_values(value: int, value_offset: int = 0) -> VagUdsCodingSetting:
    return VagUdsCodingSetting(
        value_offset=_validate_value_offset(value_offset),
        value_mask=one_byte(value, "VagUdsCodingSetting byte value mask"),
        native_constructor="VagUdsCodingSetting(Ecu*, StringWhitelist, int, unsigned char, key, Interpretation, values, AvailBy)",
    )


# ---------------------------------------------------------------------------
# Named 6R/PQ25 constructors recovered from Play 9.8.3 x86 VagCanSettings branch windows.
#
# Each function name matches the recovered native helper symbol from the
# x86_vag_lighting_branch_summary.md decompiled-helper table.
# Call sites are within VagCanSettings_getSettings @ 012a20c0.
# All 6R/PQ25 branches use VagCanEcu::CENTRAL_ELEC and
# CENTRAL_ELEC_6R_5C_7E_7H (or CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S for
# turn-signal cornering).  These values are passed at the call-site
# (VagCanSettings layer), not stored in the VagUdsCodingSetting object itself.
# ---------------------------------------------------------------------------


def VagUdsCodingSetting_cornering_fogs() -> VagUdsCodingSetting:
    """
    car_setting_cornering_lights_via_fogs — 6R/PQ25 branch.

    x86 call-site evidence:
      012d9f38: MOV byte_index = 0x0C (12)
      012d9f42: MOV mask       = 0x40
      012d9f67: PUSH CENTRAL_ELEC_6R_5C_7E_7H
      012d9f7b: CALL VagUdsCodingSetting_cornering_fogs (01358fd0 file VA / 01368fd0 Ghidra)
      interpretation: ENABLED_DISABLED

    Live status (2026-05-07):
      DID 0600 byte 12 = 0x6C => mask 0x40 SET => feature coded ENABLED.
      Physical cornering fog behavior NOT observed; live behavior ruled out as
      a standalone fix.  Coding bit is confirmed correct.
    """
    return VagUdsCodingSetting_ctor_ecu_byte(value=0x40, value_offset=12)


def VagUdsCodingSetting_cornering_fogs_experimental() -> VagUdsCodingSetting:
    """
    car_setting_cornering_lights_via_fogs_experimental — 6R/PQ25 branch.

    x86 call-site evidence:
      012da0a9: MOV byte_index = 0x15 (21)
      012da0b3: MOV mask       = 0x80
      6R/PQ25 branch uses CENTRAL_ELEC_6R_5C_7E_7H (same as base cornering setting).
      callee: VagUdsCodingSetting_cornering_fogs_experimental (0135eaf0 file VA / 0135eaf0 Ghidra)
      interpretation: ENABLED_DISABLED

    Live status (2026-05-07):
      DID 0600 byte 21 = 0xA6 => mask 0x80 SET => coded ENABLED.
    """
    return VagUdsCodingSetting_ctor_ecu_byte(value=0x80, value_offset=21)


def VagUdsCodingSetting_cornering_turn_signals() -> VagUdsCodingSetting:
    """
    car_setting_cornering_lights_with_turn_signals — 6R/PQ25 branch.

    x86 call-site evidence:
      012da718: MOV byte_index = 0x15 (21)
      012da722: MOV mask       = 0x04
      012da74d: PUSH CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S
      012da761: CALL VagUdsCodingSetting_cornering_turn_signals (0135e920 file VA / 0135e920 Ghidra)
      interpretation: YES_NO

    Live status (2026-05-07):
      DID 0600 byte 21 = 0xA6 => mask 0x04 SET => coded ENABLED.
    """
    return VagUdsCodingSetting_ctor_ecu_byte(value=0x04, value_offset=21)


def VagUdsCodingSetting_drl_via_fogs() -> VagUdsCodingSetting:
    """
    car_setting_drl_via_fogs — 6R/PQ25 branch.

    x86 call-site evidence (from drl_via_fogs_012CDE7B.md):
      012cde67: MOV byte_index = 0x17 (23)
      012cde71: MOV mask       = 0x04
      012cdea2: PUSH CENTRAL_ELEC_6R_5C_7E_7H
      012cdeb6: CALL VagUdsCodingSetting_drl_via_fogs (01361520 file VA / 01361520 Ghidra)
      callee inner-init: 01361535 MOV 0x6C -> alloc; 0136155f CALL 0x0197dcb0 (init body)
      callee shape identical to VagUdsCodingSetting_cornering_fogs; only EBP arg values differ.
      interpretation: MultipleChoiceInterpretation::YES_NO
        car_setting_no  => logical 0x00 => byte 23 bit 2 CLEAR
        car_setting_yes => logical 0x01 => byte 23 bit 2 SET (0x04 in byte)

    After construction the caller at 012cdec4-012cdece dispatches vtable[0x30/4=12] on the
    result object with (EDI=next-slot-in-array, EAX=setting-ptr).  This is the
    ref-counted push-to-collection call — not an ECU read or write.
    No inter-setting dependency recovered: VagOperationDelegate::getVagSettingAvailabilityForEcu
    evaluates each VagSetting via StringWhitelist independently.  Carista software has NO path
    that gates cornering_lights_via_fogs on drl_via_fogs or vice versa.

    READ path (fully recovered):
      UDS read : 22 0600 -> 30-byte response
      Extract  : VagSetting_extractValue(coding, offset=23, mask="04")
        ByteUtils_getLsbOffset("04") = 2  (bit 2 is the LSB of mask 0x04)
        result   = (byte_23 & 0x04) >> 2  => "00" = NO, "01" = YES
      Pre-write current:
        byte 23 = 0x00 => extractValue returns "00" => car_setting_no.
      Post-2026-05-07 current:
        byte 23 = 0x04 => extractValue returns "01" => car_setting_yes.

    WRITE path (same guarded 2E0600 sequence proven on this BCM):
      Modify   : VagSetting_insertValue(coding, offset=23, mask="04", requested="01")
        ByteUtils_getLsbOffset("04") = 2
        shifted  = 0x01 << 2 = 0x04
        result   : byte 23 = (0x00 & ~0x04) | 0x04 = 0x04
      Sequence :
        2E F199 YYMMDD
        22 F1A5 -> workshop-code inline read
        2E F198 workshop-code-payload
        2E 0600 3AB82B9F08A10000003008006C680ED000C8412F60A60004200000000000
        22 0600 -> verify byte 23 == 04

    Target coding (enable DRL via fogs, all other bits unchanged):
      current : 3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
      target  : 3AB82B9F08A10000003008006C680ED000C8412F60A60004200000000000
      delta   : byte 23 0x00 -> 0x04

    Former BCM firmware hypothesis, now behavior-disproven standalone:
      The BCM (6R0937087K) appears to drive fog outputs as a single paired
      'front fog channel' regardless of the cornering coding bits being set.
      Physical observation: fogs activate together as a steady low-beam-linked
      pair; no per-side cornering response to indicator inputs.

      Hypothesis tested: the DRL-via-fogs bit (byte 23 bit 2) might instruct the BCM
      firmware to re-assign the fog hardware outputs from the 'front fog channel'
      (single paired path, no individual addressing) to the 'DRL channel'
      (per-side addressing, capable of left/right independent activation).

      Live outcome: the 2026-05-07 write set byte 23 bit 2 and persisted, but
      the fog behavior stayed unchanged. This bit is therefore not the missing
      standalone fix. Keep it as mapped evidence, not as an active target.

    Live status (2026-05-07):
      DID 0600 byte 23 = 0x04 => mask 0x04 SET => DRL via fogs ENABLED.
      Physical behavior unchanged: steady paired fogs in headlight position,
      no useful left/right turn-signal-cornering ownership.
    """
    return VagUdsCodingSetting_ctor_ecu_byte(value=0x04, value_offset=23)


def VagUdsCodingSetting_turn_off_fogs_high_beam() -> VagUdsCodingSetting:
    """
    car_setting_turn_off_fogs_with_high_beam — 6R/PQ25 branch.

    x86 branch-summary evidence (from turn_off_fogs_with_high_beam_012D4DB5.md):
      Recovered shape: official x86 6R/PQ25 branch pushes CENTRAL_ELEC_6R_5C_7E_7H,
      DID 0600 byte 0x15 (21) mask 0x20.
      callee: VagUdsCodingSetting_turn_off_fogs_high_beam (0135e580 file VA / 0135e580 Ghidra)

    Live status (2026-05-07):
      DID 0600 byte 21 = 0xA6 => mask 0x20 SET => fogs-off-with-high-beam ENABLED.
      Physical observation confirms: high beam on causes front fogs to turn off.
    """
    return VagUdsCodingSetting_ctor_ecu_byte(value=0x20, value_offset=21)
