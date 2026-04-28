from __future__ import annotations

from dataclasses import dataclass
from typing import Iterable


class State:
    DONE = 1
    UNKNOWN_ERROR = -1
    EMPTY_OR_INVALID_RESPONSE = -6
    RESPONSE_PENDING = -17
    OBD2_BUSY_REPEAT_REQUEST = -22
    OBD2_REQUEST_SEQUENCE_ERROR = -31
    OBD2_REQUEST_OUT_OF_RANGE = -32
    OBD2_SECURITY_ACCESS_DENIED = -33
    OBD2_CONDITIONS_NOT_CORRECT = -34
    OBD2_SUBFUNCTION_NOT_SUPPORTED_IN_ACTIVE_SESSION = -35
    OBD2_INVALID_KEY = -36
    OBD2_GENERAL_REJECT = -38
    OBD2_SERVICE_NOT_SUPPORTED = -39
    OBD2_SUBFUNCTION_NOT_SUPPORTED = -40
    OBD2_UPLOAD_DOWNLOAD_NOT_ACCEPTED = -41
    OBD2_INCORRECT_MESSAGE_LENGTH_OR_FORMAT = -43
    OBD2_RESPONSE_TOO_LONG = -45
    OBD2_REQUIRED_TIME_DELAY_NOT_EXPIRED = -48
    OBD2_EXCEEDED_NUMBER_OF_ATTEMPTS = -49
    TRANSPORT_LAYER_ERROR = -51
    CANCELED = -1000
    TARGET_WRITE_RECOVERY_ERROR = -42

    @dataclass(frozen=True)
    class Set:
        states: frozenset[int]

        def contains(self, state: int) -> bool:
            return state in self.states

        @classmethod
        def from_values(cls, values: Iterable[int]) -> State.Set:
            return cls(frozenset(values))

        @staticmethod
        def fatalError() -> State.Set:
            return State.Set.from_values((-12, -1, -7, -4, -16, State.TRANSPORT_LAYER_ERROR, State.CANCELED))

        @staticmethod
        def obd2RequestNotSupported() -> State.Set:
            return State.Set.from_values(
                (
                    State.OBD2_GENERAL_REJECT,
                    State.OBD2_SERVICE_NOT_SUPPORTED,
                    State.OBD2_SUBFUNCTION_NOT_SUPPORTED,
                )
            )

        @staticmethod
        def obd2NegativeResponse() -> State.Set:
            return State.Set.from_values(OBD2_NEGATIVE_RESPONSE_STATES)

    @staticmethod
    def isError(state: int) -> bool:
        return state < 0

    @staticmethod
    def isFatalError(state: int) -> bool:
        return State.Set.fatalError().contains(state)


OBD2_NEGATIVE_RESPONSE_STATES = frozenset(
    (
        State.RESPONSE_PENDING,
        State.OBD2_BUSY_REPEAT_REQUEST,
        State.OBD2_REQUEST_SEQUENCE_ERROR,
        State.OBD2_REQUEST_OUT_OF_RANGE,
        State.OBD2_SECURITY_ACCESS_DENIED,
        State.OBD2_CONDITIONS_NOT_CORRECT,
        State.OBD2_SUBFUNCTION_NOT_SUPPORTED_IN_ACTIVE_SESSION,
        State.OBD2_INVALID_KEY,
        State.OBD2_GENERAL_REJECT,
        State.OBD2_SERVICE_NOT_SUPPORTED,
        State.OBD2_SUBFUNCTION_NOT_SUPPORTED,
        State.OBD2_UPLOAD_DOWNLOAD_NOT_ACCEPTED,
        State.OBD2_INCORRECT_MESSAGE_LENGTH_OR_FORMAT,
        State.OBD2_RESPONSE_TOO_LONG,
        State.OBD2_REQUIRED_TIME_DELAY_NOT_EXPIRED,
        State.OBD2_EXCEEDED_NUMBER_OF_ATTEMPTS,
        -10,
        -29,
        -30,
    )
)


def State_isError(state: int) -> bool:
    return State.isError(state)


def State_isFatalError(state: int) -> bool:
    return State.isFatalError(state)