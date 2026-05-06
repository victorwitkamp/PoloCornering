# PoloCornering Carista Reproduction Rules

- All recovered Carista behavior, protocol, session, transport, and operation logic belongs under `CaristaReproduction/`.
- `obd-on-pc/` is only for live adapter entrypoints, PowerShell wrappers, and logs. Do not add new Carista protocol logic there.
- `CaristaReproduction/` must be a close-as-possible reproduction of recovered Carista code. Classes, methods, functions, types, modules, and operation names in this package must come from recovered Carista symbols or clearly documented recovered callsites. Do not invent package symbols such as `*Live`, `*Profile`, ad hoc transport helpers, or alternate procedure names.
- When a symbol is not recovered, record evidence/data and the uncertainty instead of creating a fake Carista-shaped symbol.
- Temporary runner scripts may be created outside `CaristaReproduction/` only to execute recovered package code against the adapter. They must stay thin, must not own Carista behavior, and must be removed after the run/session is complete.
- Keep names exactly shaped like recovered Carista native classes/functions when evidence exists, such as `ReadValuesOperation`, `VagOperationDelegate`, and `VagCanCommunicator`.
- Read-only tooling must not send services `27`, `2E`, `31`, or `3B` unless the task is explicitly a confirmed write/routine operation.