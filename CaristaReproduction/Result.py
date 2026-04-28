from __future__ import annotations

from dataclasses import dataclass
from typing import Generic, TypeVar

from .State import State


T = TypeVar("T")


@dataclass(frozen=True)
class Result(Generic[T]):
    state: int = State.DONE
    value: T | None = None

    @classmethod
    def done(cls, value: T | None = None) -> Result[T]:
        return cls(State.DONE, value)

    @classmethod
    def fail(cls, state: int) -> Result[T]:
        if state >= 0:
            raise ValueError("failure state must be negative")
        return cls(state, None)

    def isFail(self) -> bool:
        return State.isError(self.state)

    def isFatalFail(self) -> bool:
        return State.isFatalError(self.state)

    def isIn(self, state_set: State.Set) -> bool:
        return state_set.contains(self.state)

    def stateAs(self) -> Result[object]:
        return Result(state=self.state)


def Result_done(value: T | None = None) -> Result[T]:
    return Result.done(value)


def Result_fail(state: int) -> Result[object]:
    return Result.fail(state)