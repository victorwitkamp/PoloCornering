from __future__ import annotations

from typing import Literal, TypeAlias


HexString: TypeAlias = str
JsonObject: TypeAlias = dict[str, object]
BitAction: TypeAlias = Literal["set", "clear"]
BitState: TypeAlias = Literal["set", "clear"]
CorneringFixKey: TypeAlias = Literal["base-fog", "turn-signal"]
GateName: TypeAlias = Literal[
    "read_long_coding",
    "map_supported_settings_for_car",
    "get_vag_can_ecu_info",
    "build_write_tuples",
]
GateStatus: TypeAlias = Literal["pass", "block"]
SettingStatus: TypeAlias = Literal["already_enabled", "pending_enable"]
TupleStatus: TypeAlias = Literal["blocked_missing_5A9B_metadata", "ready_for_review"]
UdsDid: TypeAlias = int