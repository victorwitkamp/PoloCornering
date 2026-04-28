from __future__ import annotations

from typing import TypeVar

from .Result import Result


T = TypeVar("T")


def Communicator_runCommand(result: Result[T]) -> Result[T]:
    return result