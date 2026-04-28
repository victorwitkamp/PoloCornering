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