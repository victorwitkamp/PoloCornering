from __future__ import annotations

import re

from .Types import CorneringFixKey, HexString


HEX_RE = re.compile(r"^[0-9A-F]+$", re.IGNORECASE)

CODING_TYPE_LOOKUP: dict[int, HexString] = {
    0: "00",
    1: "10",
    2: "10",
    3: "03",
    4: "10",
    5: "10",
}

CORNERING_FIXES: dict[CorneringFixKey, tuple[int, int, str]] = {
    "base-fog": (12, 6, "Base fog-light cornering function"),
    "turn-signal": (21, 2, "Turn-signal-triggered cornering assist"),
    "drl-via-fogs": (23, 2, "DRL via fogs (car_setting_drl_via_fogs, byte 23 bit 2, offset=0x17 mask=0x04)"),
}

PQ25_SUPPORTED_SETTING_DEFINITIONS: tuple[tuple[str, str, CorneringFixKey], ...] = (
    (
        "car_setting_cornering_lights_via_fogs",
        "Cornering lights using fog lights",
        "base-fog",
    ),
    (
        "car_setting_cornering_lights_with_turn_signals",
        "Turn on cornering lights when turn signal is on",
        "turn-signal",
    ),
)

CARISTA_DATE_WRITE_DID = 0xF199
CARISTA_WORKSHOP_CODE_WRITE_DID = 0xF198
CARISTA_WORKSHOP_CODE_READ_DID = 0xF1A5
CARISTA_LONG_CODING_DID = 0x0600
CARISTA_INSTRUMENT_CLUSTER_NEEDLE_SWEEP_RAW_ADDRESS = 0x22A2
CARISTA_LEFT_FOG_CORNERING_RAW_ADDRESS = 0x055C
CARISTA_RIGHT_FOG_CORNERING_RAW_ADDRESS = 0x055D
CARISTA_FULL_BYTE_ADAPTATION_MASK = "FF"
