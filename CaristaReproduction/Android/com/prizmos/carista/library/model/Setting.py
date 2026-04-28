from __future__ import annotations

from dataclasses import dataclass

from .Ecu import Ecu
from .Interpretation import Interpretation


@dataclass(frozen=True)
class Setting:
    ecu: Ecu | None = None
    instruction: str | None = None
    interpretation: Interpretation | None = None
    name_res_id: str | None = None
    event_string: str | None = None
    legal_disclaimer_required: bool | None = None