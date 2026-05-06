from __future__ import annotations

from typing import Literal, TypeAlias


HexString: TypeAlias = str
JsonObject: TypeAlias = dict[str, object]
BitAction: TypeAlias = Literal["set", "clear"]
BitState: TypeAlias = Literal["set", "clear"]
CorneringFixKey: TypeAlias = Literal["base-fog", "turn-signal"]
RawValueType: TypeAlias = Literal[0, 1, 7, 8]
VagCanSettingsConstructorStatus: TypeAlias = Literal[
    "write_blocked_read_rejected",
    "constructor_partial",
    "constructor_multi_path_recovered_coding_raw_address_unresolved",
    "constructor_multi_path_runtime_branch_unresolved",
    "recovered_non_vag_ford_setting",
    "refs_only_unresolved",
    "catalog_only_unresolved",
]
VagCanSettingsConstructorKind: TypeAlias = Literal[
    "VagUdsAdaptationSetting",
    "VagUdsCodingSetting",
    "VagCanLongCodingSetting",
    "FullByteVagCanShortAdaptationSetting",
    "FordUdsSetting",
    "FordCodingSetting",
    "mixed",
    "unknown",
]
GateName: TypeAlias = Literal[
    "read_long_coding",
    "map_supported_settings_for_car",
    "build_uds_write_plan",
    "model_vag_can_adaptation_routine_builders",
    "block_055c_055d_type7_writes",
]
GateStatus: TypeAlias = Literal["pass", "block"]
SettingStatus: TypeAlias = Literal["already_enabled", "pending_enable"]
UdsDid: TypeAlias = int
