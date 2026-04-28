from __future__ import annotations

from dataclasses import dataclass

from ..model.Ecu import Ecu
from .Operation import Operation


@dataclass(frozen=True)
class GetEcuInfoOperation:
    ecu: Ecu
    operation: Operation
    native_pointer: int | None = None

    def getCodingRawAddress(self, coding_address_short: int) -> int | None:
        return None

    def supportsSingleCoding(self) -> bool | None:
        return None

    def supportsMultiCoding(self) -> bool | None:
        return None