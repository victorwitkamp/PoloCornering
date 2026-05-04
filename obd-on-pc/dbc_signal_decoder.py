from __future__ import annotations

import re
from collections import OrderedDict
from dataclasses import dataclass
from pathlib import Path


WORKSPACE_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_VW_PQ_DBC = WORKSPACE_ROOT / "reference" / "opendbc" / "opendbc__dbc__vw_pq.dbc"

MESSAGE_RE = re.compile(r"^BO_\s+(\d+)\s+(\S+):\s+(\d+)\s+(\S+)")
SIGNAL_RE = re.compile(
    r'^\s*SG_\s+([A-Za-z0-9_]+)(?:\s+[mM]\d*)?\s*:\s*'
    r'(\d+)\|(\d+)@([01])([+-])\s+'
    r'\(([+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?),'
    r'([+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?)\)\s+'
    r'\[[^\]]*\]\s+"([^"]*)"'
)


@dataclass(frozen=True)
class DbcDecodedSignal:
    name: str
    raw: int
    value: float
    text: str
    unit: str

    @property
    def text_with_unit(self) -> str:
        return f"{self.text}{self.unit}" if self.unit else self.text


@dataclass(frozen=True)
class DbcSignal:
    name: str
    start: int
    length: int
    endian: str
    signed: bool
    factor: float
    offset: float
    unit: str

    @property
    def is_supported(self) -> bool:
        return self.endian == "1"

    def decode(self, data: bytes) -> DbcDecodedSignal | None:
        if not self.is_supported or self.length <= 0 or self.start < 0:
            return None
        if self.start + self.length > len(data) * 8:
            return None
        raw_int = int.from_bytes(data, "little")
        raw_value = (raw_int >> self.start) & ((1 << self.length) - 1)
        if self.signed and raw_value & (1 << (self.length - 1)):
            raw_value -= 1 << self.length
        value = raw_value * self.factor + self.offset
        return DbcDecodedSignal(self.name, raw_value, value, format_number(value), self.unit)


@dataclass(frozen=True)
class DbcMessage:
    header: str
    decimal_id: int
    name: str
    length: int
    sender: str
    signals: tuple[DbcSignal, ...]

    def decode(self, payload: object) -> OrderedDict[str, DbcDecodedSignal]:
        payload_text = str(payload or "").strip().replace(" ", "")
        if not payload_text or len(payload_text) % 2:
            return OrderedDict()
        try:
            data = bytes.fromhex(payload_text)
        except ValueError:
            return OrderedDict()

        decoded: OrderedDict[str, DbcDecodedSignal] = OrderedDict()
        for signal in self.signals:
            decoded_signal = signal.decode(data)
            if decoded_signal is not None:
                decoded[signal.name] = decoded_signal
        return decoded


class DbcDatabase:
    def __init__(self, messages: dict[str, DbcMessage], source: Path | None = None) -> None:
        self.messages = messages
        self.source = source

    @classmethod
    def from_file(cls, path: Path) -> "DbcDatabase":
        messages: dict[str, DbcMessage] = {}
        current_id: str | None = None
        current_decimal_id = 0
        current_name = ""
        current_length = 0
        current_sender = ""
        current_signals: list[DbcSignal] = []

        def flush_current() -> None:
            nonlocal current_id, current_decimal_id, current_name, current_length, current_sender, current_signals
            if current_id is None:
                return
            messages[current_id] = DbcMessage(
                header=current_id,
                decimal_id=current_decimal_id,
                name=current_name,
                length=current_length,
                sender=current_sender,
                signals=tuple(current_signals),
            )
            current_id = None
            current_decimal_id = 0
            current_name = ""
            current_length = 0
            current_sender = ""
            current_signals = []

        for raw_line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            message_match = MESSAGE_RE.match(raw_line)
            if message_match:
                flush_current()
                current_decimal_id = int(message_match.group(1))
                current_id = normalize_header(f"{current_decimal_id:X}")
                current_name = message_match.group(2)
                current_length = int(message_match.group(3))
                current_sender = message_match.group(4)
                continue

            if current_id is None:
                continue
            signal_match = SIGNAL_RE.match(raw_line)
            if not signal_match:
                continue
            current_signals.append(
                DbcSignal(
                    name=signal_match.group(1),
                    start=int(signal_match.group(2)),
                    length=int(signal_match.group(3)),
                    endian=signal_match.group(4),
                    signed=signal_match.group(5) == "-",
                    factor=float(signal_match.group(6)),
                    offset=float(signal_match.group(7)),
                    unit=signal_match.group(8),
                )
            )
        flush_current()
        return cls(messages, source=path)

    @classmethod
    def empty(cls) -> "DbcDatabase":
        return cls({})

    def message(self, header: object) -> DbcMessage | None:
        return self.messages.get(normalize_header(header))

    def message_name(self, header: object) -> str:
        message = self.message(header)
        return message.name if message else ""

    def signal_names(self, header: object) -> str:
        message = self.message(header)
        if not message:
            return ""
        return ",".join(signal.name for signal in message.signals if signal.is_supported)

    def decode(self, header: object, payload: object) -> OrderedDict[str, DbcDecodedSignal]:
        message = self.message(header)
        if not message:
            return OrderedDict()
        return message.decode(payload)

    def decoded_summary(self, header: object, payload: object, limit: int = 16) -> str:
        decoded = self.decode(header, payload)
        parts = [f"{name}={signal.text_with_unit}" for name, signal in list(decoded.items())[:limit]]
        if len(decoded) > limit:
            parts.append(f"... {len(decoded) - limit} more")
        return "; ".join(parts)


def normalize_header(header: object) -> str:
    value = str(header or "").strip().replace(" ", "").upper()
    if not value:
        return ""
    if len(value) <= 3:
        return value.zfill(3)
    return value


def format_number(value: float) -> str:
    if abs(value - round(value)) < 0.000001:
        return str(int(round(value)))
    return f"{value:.6f}".rstrip("0").rstrip(".")