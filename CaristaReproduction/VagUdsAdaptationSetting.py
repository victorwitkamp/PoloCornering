from __future__ import annotations

from dataclasses import dataclass
from typing import Literal

from .Constants import (
    CARISTA_FULL_BYTE_ADAPTATION_MASK,
    CARISTA_INSTRUMENT_CLUSTER_NEEDLE_SWEEP_RAW_ADDRESS,
    CARISTA_LEFT_FOG_CORNERING_RAW_ADDRESS,
    CARISTA_RIGHT_FOG_CORNERING_RAW_ADDRESS,
)
from .Types import HexString, RawValueType
from .VagSetting import VagSetting_insertValue


VagUdsEcuName = Literal["BCM", "INSTRUMENT_CLUSTER"]


@dataclass(frozen=True)
class VagUdsAdaptationChoice:
    key: str
    value: int

    @property
    def requested_value(self) -> HexString:
        return f"{self.value:02X}"


@dataclass(frozen=True)
class VagUdsAdaptationSetting:
    ecu: VagUdsEcuName
    raw_address: int
    value_offset: int
    value_mask: HexString
    key: str
    setting_type: RawValueType = 7
    native_constructor: str = "VagUdsAdaptationSetting"
    native_source: str = "recovered from libCarista.so constructor/string references"
    choices: tuple[VagUdsAdaptationChoice, ...] = ()
    proof_notes: tuple[str, ...] = ()

    def requested_value_for_choice(self, choice_key: str) -> HexString:
        for choice in self.choices:
            if choice.key == choice_key:
                return choice.requested_value
        known = ", ".join(choice.key for choice in self.choices) or "<none recovered>"
        raise ValueError(f"Unknown choice {choice_key!r} for {self.key}; known choices: {known}")

    def insert_choice(self, current_raw_value: HexString, choice_key: str) -> HexString:
        return VagSetting_insertValue(
            current_raw_value,
            self.value_offset,
            self.value_mask,
            self.requested_value_for_choice(choice_key),
        )


CORNERING_LIGHTS_VIA_FOGS_LEFT_CHOICES = (
    VagUdsAdaptationChoice("car_setting_off", 0x00),
    VagUdsAdaptationChoice("car_setting_on", 0x16),
    VagUdsAdaptationChoice("car_setting_enabled_coming_home_or_leaving_home", 0x1E),
)


CORNERING_LIGHTS_VIA_FOGS_RIGHT_CHOICES = (
    VagUdsAdaptationChoice("car_setting_off", 0x00),
    VagUdsAdaptationChoice("car_setting_on", 0x17),
    VagUdsAdaptationChoice("car_setting_enabled_coming_home_or_leaving_home", 0x1E),
)


def FullByteVagUdsAdaptationSetting_ctor(
    *,
    ecu: VagUdsEcuName,
    raw_address: int,
    key: str,
) -> VagUdsAdaptationSetting:
    return VagUdsAdaptationSetting(
        ecu=ecu,
        raw_address=raw_address,
        value_offset=0,
        value_mask=CARISTA_FULL_BYTE_ADAPTATION_MASK,
        key=key,
        native_constructor="FullByteVagUdsAdaptationSetting -> VagUdsAdaptationSetting",
        native_source="typeinfo and constructor references recovered from libCarista.so",
        proof_notes=(
            "FullByteVagUdsAdaptationSetting uses offset 0 and mask FF.",
            "Treat raw address as read-only until a positive 22<DID> read proves the payload on this ECU.",
        ),
    )


def car_setting_instr_needle_sweep() -> VagUdsAdaptationSetting:
    return FullByteVagUdsAdaptationSetting_ctor(
        ecu="INSTRUMENT_CLUSTER",
        raw_address=CARISTA_INSTRUMENT_CLUSTER_NEEDLE_SWEEP_RAW_ADDRESS,
        key="car_setting_instr_needle_sweep",
    )


def car_setting_instr_needle_sweep_method_b() -> VagUdsAdaptationSetting:
    return FullByteVagUdsAdaptationSetting_ctor(
        ecu="INSTRUMENT_CLUSTER",
        raw_address=CARISTA_INSTRUMENT_CLUSTER_NEEDLE_SWEEP_RAW_ADDRESS,
        key="car_setting_instr_needle_sweep_method_b",
    )


def car_setting_cornering_lights_via_fogs_left() -> VagUdsAdaptationSetting:
    return VagUdsAdaptationSetting(
        ecu="BCM",
        raw_address=CARISTA_LEFT_FOG_CORNERING_RAW_ADDRESS,
        value_offset=5,
        value_mask=CARISTA_FULL_BYTE_ADAPTATION_MASK,
        key="car_setting_cornering_lights_via_fogs_left",
        native_constructor="VagUdsAdaptationSetting(VagUdsEcu, StringWhitelist, rawAddress, valueOffset, mask, key, MultipleChoiceInterpretation)",
        native_source="Older ARM instruction-window recovery plus official Play 9.8.3 x86 helper context",
        choices=CORNERING_LIGHTS_VIA_FOGS_LEFT_CHOICES,
        proof_notes=(
            "Native setting type is 7, which dispatches through readVagUdsValue / ReadRawDataByIdentifierCommand.",
            "Official Play 9.8.3 x86 ref 0x012da210 first lands on a VagCanLongCodingSetting helper, so this type-7 object is retained only as the recovered static branch.",
            "Live direct read 22055C returned 7F2231, so this is not a safe write seed on the current BCM/session.",
        ),
    )


def car_setting_cornering_lights_via_fogs_right() -> VagUdsAdaptationSetting:
    return VagUdsAdaptationSetting(
        ecu="BCM",
        raw_address=CARISTA_RIGHT_FOG_CORNERING_RAW_ADDRESS,
        value_offset=5,
        value_mask=CARISTA_FULL_BYTE_ADAPTATION_MASK,
        key="car_setting_cornering_lights_via_fogs_right",
        native_constructor="VagUdsAdaptationSetting(VagUdsEcu, StringWhitelist, rawAddress, valueOffset, mask, key, MultipleChoiceInterpretation)",
        native_source="Older ARM instruction-window recovery plus official Play 9.8.3 x86 helper context",
        choices=CORNERING_LIGHTS_VIA_FOGS_RIGHT_CHOICES,
        proof_notes=(
            "Native setting type is 7, which dispatches through readVagUdsValue / ReadRawDataByIdentifierCommand.",
            "Official Play 9.8.3 x86 ref 0x012da55f calls a VagUdsAdaptationSetting/NumericalInterpretation helper at 0x01368690.",
            "Live direct read 22055D returned 7F2231, so this is not a safe write seed on the current BCM/session.",
        ),
    )
