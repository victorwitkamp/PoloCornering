from __future__ import annotations

import argparse
import json
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence


@dataclass(frozen=True)
class Kwp21Block:
    index: int
    code: int
    a: int
    b: int

    @property
    def raw(self) -> str:
        return f"{self.code:02X}{self.a:02X}{self.b:02X}"

    @property
    def decoded(self) -> str:
        if self.code == 6:
            return f"{0.001 * self.a * self.b:.3f} V"
        if self.code == 7:
            return f"{0.01 * self.a * self.b:.2f} km/h"
        if self.code == 36:
            return f"{self.b * 10 + self.a * 2560} km"
        if self.code == 37:
            return f"raw37 a={self.a} b={self.b}"
        if self.code == 54:
            return f"{self.a * 256 + self.b} count"
        return f"code{self.code} a={self.a} b={self.b}"


def _load_payloads(path: Path) -> dict[str, str]:
    data = json.loads(path.read_text(encoding="utf-8"))
    payloads: dict[str, str] = {}
    for observation in data.get("observations", []):
        command = observation.get("command")
        payload = observation.get("payload")
        if isinstance(command, str) and isinstance(payload, str):
            payloads[command.upper()] = payload.upper()
    return payloads


def _decode_blocks(payload: str) -> tuple[Kwp21Block, ...]:
    data = bytes.fromhex(payload)
    if len(data) < 2 or data[0] != 0x61:
        return ()
    body = data[2:]
    return tuple(
        Kwp21Block(index=index, code=body[offset], a=body[offset + 1], b=body[offset + 2])
        for index, offset in enumerate(range(0, len(body) - 2, 3), start=1)
    )


def _byte_diffs(a: str, b: str) -> list[str]:
    left = bytes.fromhex(a)
    right = bytes.fromhex(b)
    diffs = [
        f"byte {index:02d}: {old:02X}->{new:02X} xor={old ^ new:02X}"
        for index, (old, new) in enumerate(zip(left, right))
        if old != new
    ]
    if len(left) != len(right):
        diffs.append(f"length {len(left)}->{len(right)}")
    return diffs


def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Compare saved KWP service-21 measuring-value logs.")
    parser.add_argument("logs", nargs="+", type=Path)
    args = parser.parse_args(argv)

    captures = [(path.stem, _load_payloads(path)) for path in args.logs]
    if len(captures) < 2:
        raise SystemExit("provide at least two saved monitor logs")

    baseline_name, baseline = captures[0]
    commands = sorted(set().union(*(payloads.keys() for _name, payloads in captures)))
    for command in commands:
        values = [(name, payloads.get(command)) for name, payloads in captures]
        present_values = [value for _name, value in values if value is not None]
        if len(set(present_values)) <= 1:
            continue

        print(f"{command}: changed")
        base_payload = baseline.get(command)
        for name, payload in values:
            print(f"  {name}: {payload or '(missing)'}")
            if payload:
                for block in _decode_blocks(payload):
                    print(
                        f"    block {block.index}: "
                        f"{block.raw} code=0x{block.code:02X}/dec{block.code} -> {block.decoded}"
                    )
            if base_payload and payload and name != baseline_name:
                for diff in _byte_diffs(base_payload, payload):
                    print(f"    {baseline_name}->{name}: {diff}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
