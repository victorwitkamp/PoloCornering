from __future__ import annotations

import re
from pathlib import Path

from ..ByteUtils import ascii_from_hex, clean_hex
from ..JsonUtils import json_objects_from_text
from ..Models.VagEcuInfoWithCoding import VagEcuInfoWithCoding
from ..Result import Result
from ..State import State
from ..Types import HexString
from .WriteVagCodingCommand import WriteVagCodingCommand_suffix


class GetVagCanEcuInfoCommand:
    def getRequest(self) -> HexString:
        return GetVagCanEcuInfoCommand_getRequest()

    @staticmethod
    def processEcuInfo(response: HexString) -> VagEcuInfoWithCoding | None:
        return GetVagCanEcuInfoCommand_processEcuInfo(response)

    @staticmethod
    def processPayloads(payloads: list[HexString]) -> Result[VagEcuInfoWithCoding]:
        return GetVagCanEcuInfoCommand_processPayloads(payloads)


def GetVagCanEcuInfoCommand_getRequest() -> HexString:
    return "1A9B"


def GetVagCanEcuInfoCommand_processEcuInfo(response: HexString) -> VagEcuInfoWithCoding | None:
    response = clean_hex(response, "1A9B response")
    if not response.startswith("5A9B"):
        return None
    payload = bytes.fromhex(response)[2:]
    if len(payload) < 0x1A:
        return None

    selector = payload[0x10]
    tail = ""
    if selector == 0x03:
        coding_type = 2
        tail = payload[0x11:0x14].hex().upper()
    elif selector == 0x10:
        coding_type = 3
    elif 0x21 <= selector <= 0x2F:
        coding_type = 4
        tail = payload[0x11:0x14].hex().upper()
    else:
        coding_type = 1

    suffix = ""
    if coding_type >= 2:
        suffix = WriteVagCodingCommand_suffix(coding_type, tail)

    return VagEcuInfoWithCoding(
        response=response,
        stripped_payload=payload.hex().upper(),
        part_number=ascii_from_hex(payload[:12].hex()).strip().strip("\x00"),
        raw_address4=payload[0x0C:0x10].hex().upper(),
        coding_type_selector=f"{selector:02X}",
        coding_type=coding_type,
        tail=tail,
        initial_value6=payload[0x14:0x1A].hex().upper(),
        suffix=suffix,
    )


def GetVagCanEcuInfoCommand_processPayloads(payloads: list[HexString]) -> Result[VagEcuInfoWithCoding]:
    decoded: list[VagEcuInfoWithCoding] = []
    for payload in payloads:
        metadata = GetVagCanEcuInfoCommand_processEcuInfo(payload)
        if metadata is not None:
            decoded.append(metadata)
    if not decoded:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    main = decoded[0]
    if main.coding_type not in {1, 2, 3} and len(decoded) == 1:
        return Result.fail(State.EMPTY_OR_INVALID_RESPONSE)
    return Result.done(
        VagEcuInfoWithCoding(
            response=main.response,
            stripped_payload=main.stripped_payload,
            part_number=main.part_number,
            raw_address4=main.raw_address4,
            coding_type_selector=main.coding_type_selector,
            coding_type=main.coding_type,
            tail=main.tail,
            initial_value6=main.initial_value6,
            suffix=main.suffix,
            submodule_payloads=tuple(item.stripped_payload for item in decoded[1:]),
        )
    )


decode_positive_1a9b_metadata = GetVagCanEcuInfoCommand_processEcuInfo


def read_first_positive_ecu_info(paths: list[Path]) -> VagEcuInfoWithCoding | None:
    for path in paths:
        if not path.exists():
            continue
        text = path.read_text(encoding="utf-8")
        if path.suffix.lower() == ".json":
            for entry in json_objects_from_text(text):
                read_result = entry.get("read_result")
                if isinstance(read_result, str):
                    try:
                        metadata = GetVagCanEcuInfoCommand_processEcuInfo(read_result)
                    except ValueError:
                        metadata = None
                    if metadata:
                        return metadata
            continue
        for token in re.split(r"\s+", text):
            try:
                metadata = GetVagCanEcuInfoCommand_processEcuInfo(token)
            except ValueError:
                metadata = None
            if metadata:
                return metadata
    return None