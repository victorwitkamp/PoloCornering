from __future__ import annotations

from typing import TypeVar

from .Result import Result
from .State import State


T = TypeVar("T")


COMMUNICATOR_RUN_COMMAND_ATTEMPTS = 4
COMMUNICATOR_RETRY_DELAY_MS = 300
COMMUNICATOR_NO_DATA_STATE = -0x0B
COMMUNICATOR_CAN_ERROR_STATE = -0x2E
COMMUNICATOR_RESPONSE_PENDING_STATE = State.RESPONSE_PENDING
COMMUNICATOR_RETRY_COMMAND_STATES_SYMBOL = "RETRY_COMMAND_STATES"

COMMUNICATOR_RUN_COMMAND_RECOVERED_FLOW = (
    "Communicator::runCommand<EmptyModel> initializes the communicator when the initialized byte is clear.",
    "It executes up to four attempts while the result is in the native RETRY_COMMAND_STATES set.",
    "Retry attempts after the first log NO DATA or ECU busy and sleep 300 ms before resending.",
    "Before each send it ensures ECU communication is established with establishEcuCommWithStats unless the cached ECU/channel is still valid.",
    "If the previous result is RESPONSE_PENDING, it computes the next command timeout from TimeoutSpec and logs the adaptive retry timeout.",
    "It calls Communicator::internalExecuteCommand<EmptyModel>, extracts the command result, then decides whether to continue from RETRY_COMMAND_STATES.",
    "Two consecutive -0x0B no-data results stop the retry loop.",
    "State -0x2E is tracked as a CAN error; native analytics distinguish final CAN-error failure from retry success after a CAN error.",
)
COMMUNICATOR_INTERNAL_EXECUTE_COMMAND_RECOVERED_FLOW = (
    "Communicator::internalExecuteCommand<EmptyModel> obtains the request bytes from the Command and sends them through the communicator.",
    "If the send state is an error, it logs the failed request hex and returns that state.",
    "It reads response packets, validates status-1 payloads with ByteUtils::isValidHexString, and throws IllegalStateException on invalid hex.",
    "It checks Communicator::isEcuDeadlock; on deadlock it forces bus reinit and returns -0x32.",
    "It extracts the first non-positive response error with default -0x0B, filters responses to status 1, and returns that error if no positive payload remains.",
    "Positive payloads are passed into Communicator::processResponses<EmptyModel>.",
)


def Communicator_runCommand(result: Result[T]) -> Result[T]:
    return result