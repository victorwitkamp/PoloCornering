from __future__ import annotations

from typing import TypeVar

from .Result import Result


T = TypeVar("T")


CONNECTION_MANAGER_RUN_COMMAND_RECOVERED_FLOW = (
    "ConnectionManager::runCommand<EmptyModel> first calls the connection/listener state slot at vtable offset 0x14.",
    "When that slot returns false, it runs ConnectionManager::internalRunCommand<EmptyModel> and extracts the command result from the broadcast map.",
    "When that slot returns true, it calls vtable offset 0x18 with the Command shared_ptr and EmptyModel typeinfo, then wraps the returned Result<Model> as Result<EmptyModel>.",
    "This recovered branch is the app-side handoff before Communicator::runCommand owns ECU communication, retry, timeout, and response processing.",
)


def ConnectionManager_runCommand(result: Result[T]) -> Result[T]:
    return result