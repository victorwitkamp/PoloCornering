from __future__ import annotations

from dataclasses import dataclass
from typing import Any


@dataclass(frozen=True)
class CanSignal:
    name: str
    start: int
    length: int
    factor: float = 1.0
    offset: float = 0.0
    unit: str = ""


@dataclass(frozen=True)
class CanMessage:
    header: str
    name: str
    source: str
    relevance: str
    signals: tuple[CanSignal, ...]


PQ25_LIGHT_CONTEXT_HEADERS = ("390", "392", "0D0", "0C2", "1A0", "288", "320", "470")
RAW_HEADER_PRESETS: dict[str, tuple[str, ...]] = {
    "pq25_light_context": PQ25_LIGHT_CONTEXT_HEADERS,
    "light_context": PQ25_LIGHT_CONTEXT_HEADERS,
    "tp20": ("300", "338"),
}

PQ25_CAN_MESSAGES: dict[str, CanMessage] = {
    "390": CanMessage(
        header="390",
        name="Gate_Komf_1",
        source="openDBC vw_pq.dbc",
        relevance="BCM comfort/lamp state: reverse, blinkers, low/high beam, front fog, brake light",
        signals=(
            CanSignal("GK1_RueckfahrSch", 17, 1),
            CanSignal("GK1_Rueckfahr", 28, 1),
            CanSignal("GK1_Blinker_li", 34, 1),
            CanSignal("GK1_Blinker_re", 35, 1),
            CanSignal("GK1_LS1_Fernlicht", 37, 1),
            CanSignal("GK1_Abblendlicht", 48, 1),
            CanSignal("GK1_Fernlicht", 49, 1),
            CanSignal("GK1_Blink_Autob", 54, 1),
            CanSignal("GK1_Warnblk_Status", 55, 1),
            CanSignal("GK1_Nebel_ein", 58, 1),
            CanSignal("GK1_Bremslicht", 59, 1),
        ),
    ),
    "392": CanMessage(
        header="392",
        name="Gate_Komf_2",
        source="openDBC vw_pq.dbc",
        relevance="BCM comfort/lamp companion state: indicator telltales, light sensor, rear fog",
        signals=(
            CanSignal("GK2_Sta_LSM", 0, 1),
            CanSignal("GK2_Sta_Lichtsensor", 1, 1),
            CanSignal("GK2_Sta_Licht1", 2, 1),
            CanSignal("GK2_Blk_L_Kontrolle", 11, 1),
            CanSignal("GK2_Blk_R_Kontrolle", 12, 1),
            CanSignal("GK2_AFL_Schalter", 29, 1),
            CanSignal("GK2_Nebelschluss", 30, 1),
        ),
    ),
    "0D0": CanMessage(
        header="0D0",
        name="Lenkhilfe_3",
        source="openDBC vw_pq.dbc",
        relevance="EPS steering angle and driver torque; cornering logic may gate on steering angle",
        signals=(
            CanSignal("LH3_LM", 16, 10),
            CanSignal("LH3_LMSign", 26, 1),
            CanSignal("LH3_LMValid", 27, 1),
            CanSignal("LH3_BLW", 32, 12, 0.15),
            CanSignal("LH3_BLWSign", 44, 1),
            CanSignal("LH3_BLWValid", 45, 1),
        ),
    ),
    "0C2": CanMessage(
        header="0C2",
        name="Lenkwinkel_1",
        source="openDBC vw_pq.dbc",
        relevance="Steering wheel angle/rate broadcast; independent cross-check for steering state",
        signals=(
            CanSignal("LW1_LRW", 0, 15, 0.04375),
            CanSignal("LW1_LRW_Sign", 15, 1),
            CanSignal("LW1_Lenk_Gesch", 16, 15, 0.04375),
            CanSignal("LW1_Gesch_Sign", 31, 1),
            CanSignal("LW1_Status", 41, 2),
        ),
    ),
    "1A0": CanMessage(
        header="1A0",
        name="Bremse_1",
        source="openDBC vw_pq.dbc",
        relevance="ABS vehicle speed and brake-light switch context",
        signals=(
            CanSignal("BR1_Lichtschalt", 11, 1),
            CanSignal("BR1_StaDruckschw", 12, 1),
            CanSignal("BR1_Rad_kmh", 17, 15, 0.01, unit="km/h"),
            CanSignal("BR1_ESPASR_passive", 61, 1),
        ),
    ),
    "288": CanMessage(
        header="288",
        name="Motor_2",
        source="openDBC vw_pq.dbc",
        relevance="Engine brake switch and cruise state context",
        signals=(
            CanSignal("MO2_BLS", 16, 1),
            CanSignal("MO2_BTS", 17, 1),
            CanSignal("MO2_Sta_GRA", 22, 2),
        ),
    ),
    "320": CanMessage(
        header="320",
        name="Kombi_1",
        source="openDBC vw_pq.dbc",
        relevance="Instrument-cluster indicator telltales and displayed speed",
        signals=(
            CanSignal("Blinker_links_4_1", 44, 1),
            CanSignal("Blinker_rechts_4_1", 45, 1),
            CanSignal("Angezeigte_Geschwindigkeit", 46, 10, 0.32, unit="km/h"),
        ),
    ),
    "470": CanMessage(
        header="470",
        name="BSG_Kombi",
        source="openDBC vw_pq.dbc",
        relevance="BCM-to-cluster lamp/telltale status including reverse and turn indicators",
        signals=(
            CanSignal("Blinker_links_Kontrollampe", 0, 1),
            CanSignal("Blinker_rechts_Kontrollampe", 1, 1),
            CanSignal("Warnblink_Mode", 3, 1),
            CanSignal("Rueckfahrlicht", 5, 1),
            CanSignal("Unterspannung", 15, 1),
        ),
    ),
}


def normalize_can_header(header: object) -> str:
    value = str(header or "").strip().replace(" ", "").upper()
    if not value:
        return ""
    if len(value) <= 3:
        return value.zfill(3)
    return value


def known_message(header: object) -> CanMessage | None:
    return PQ25_CAN_MESSAGES.get(normalize_can_header(header))


def message_name(header: object) -> str:
    message = known_message(header)
    return message.name if message else ""


def message_relevance(header: object) -> str:
    message = known_message(header)
    return message.relevance if message else ""


def message_signal_names(header: object) -> str:
    message = known_message(header)
    if not message:
        return ""
    return ",".join(signal.name for signal in message.signals)


def _extract_unsigned(data: bytes, start: int, length: int) -> int | None:
    if length <= 0 or start < 0 or start + length > len(data) * 8:
        return None
    raw = int.from_bytes(data, "little")
    return (raw >> start) & ((1 << length) - 1)


def _format_value(value: float, unit: str = "") -> str:
    if abs(value - round(value)) < 0.000001:
        text = str(int(round(value)))
    else:
        text = f"{value:.3f}".rstrip("0").rstrip(".")
    return f"{text}{unit}" if unit else text


def decode_known_payload(header: object, payload: object) -> dict[str, str]:
    message = known_message(header)
    if not message:
        return {}
    payload_text = str(payload or "").strip().replace(" ", "")
    if not payload_text or len(payload_text) % 2:
        return {}
    try:
        data = bytes.fromhex(payload_text)
    except ValueError:
        return {}

    decoded: dict[str, str] = {}
    raw_values: dict[str, int] = {}
    for signal in message.signals:
        raw_value = _extract_unsigned(data, signal.start, signal.length)
        if raw_value is None:
            continue
        raw_values[signal.name] = raw_value
        scaled = raw_value * signal.factor + signal.offset
        decoded[signal.name] = _format_value(scaled, signal.unit)

    if message.header == "0D0":
        if "LH3_BLW" in raw_values and "LH3_BLWSign" in raw_values:
            sign = -1 if raw_values["LH3_BLWSign"] else 1
            decoded["LH3_steering_angle_signed_deg"] = _format_value(sign * raw_values["LH3_BLW"] * 0.15)
        if "LH3_LM" in raw_values and "LH3_LMSign" in raw_values:
            sign = -1 if raw_values["LH3_LMSign"] else 1
            decoded["LH3_torque_signed"] = _format_value(sign * raw_values["LH3_LM"])
    elif message.header == "0C2":
        if "LW1_LRW" in raw_values and "LW1_LRW_Sign" in raw_values:
            sign = -1 if raw_values["LW1_LRW_Sign"] else 1
            decoded["LW1_angle_signed_deg"] = _format_value(sign * raw_values["LW1_LRW"] * 0.04375)
        if "LW1_Lenk_Gesch" in raw_values and "LW1_Gesch_Sign" in raw_values:
            sign = -1 if raw_values["LW1_Gesch_Sign"] else 1
            decoded["LW1_rate_signed_deg_s"] = _format_value(sign * raw_values["LW1_Lenk_Gesch"] * 0.04375)
    return decoded


def decoded_summary(header: object, payload: object) -> str:
    decoded = decode_known_payload(header, payload)
    return "; ".join(f"{name}={value}" for name, value in decoded.items())


def raw_header_preset(value: object) -> tuple[str, ...] | None:
    return RAW_HEADER_PRESETS.get(str(value or "").strip().lower())


def reference_metadata() -> dict[str, Any]:
    return {
        "source": "openDBC vw_pq.dbc downloaded under reference/opendbc/ with LICENSE",
        "light_context_headers": list(PQ25_LIGHT_CONTEXT_HEADERS),
        "presets": {name: list(headers) for name, headers in RAW_HEADER_PRESETS.items()},
    }