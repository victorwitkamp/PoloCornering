from __future__ import annotations

from datetime import date, datetime, timezone

from .Types import HexString


def parse_iso_date(value: str | None) -> date:
    if not value:
        return datetime.now(timezone.utc).date()
    return date.fromisoformat(value)


def carista_date_payload(value: date | None = None) -> HexString:
    value = value or datetime.now(timezone.utc).date()
    return f"{value.year % 100:02d}{value.month:02d}{value.day:02d}"