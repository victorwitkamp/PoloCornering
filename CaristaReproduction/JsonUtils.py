from __future__ import annotations

import json
from typing import cast

from .Types import JsonObject


def json_objects_from_text(text: str) -> list[JsonObject]:
    data: object = json.loads(text)
    entries: list[object] = data if isinstance(data, list) else [data]
    objects: list[JsonObject] = []
    for entry in entries:
        if isinstance(entry, dict):
            objects.append(cast(JsonObject, entry))
    return objects