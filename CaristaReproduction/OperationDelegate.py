from __future__ import annotations

from dataclasses import dataclass
from typing import Generic, TypeVar

from .Result import Result


T = TypeVar("T")


@dataclass(frozen=True)
class OperationDelegate(Generic[T]):
    command_name: str

    def runCommand(self, result: Result[T]) -> Result[T]:
        return result


def OperationDelegate_runCommand(result: Result[T]) -> Result[T]:
    return result