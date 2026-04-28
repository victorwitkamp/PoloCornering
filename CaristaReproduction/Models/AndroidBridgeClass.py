from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class AndroidBridgeMethod:
    name: str
    descriptor: str
    access_flags: str = ""
    is_native: bool = False


@dataclass(frozen=True)
class AndroidBridgeClass:
    descriptor: str
    java_name: str
    dex_file: str
    methods: tuple[AndroidBridgeMethod, ...]
