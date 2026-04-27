# Carista Cornering Capture Procedure

Purpose: capture the real Carista cornering-light setting write so the next
adapter-only write is no longer guessed.

## What This Solves

The current raw Python writer still does not know Carista's exact structured
write tuple for PQ25 cornering lights.

What the new trace should recover from one real Carista setting change:

```text
- SettingRef name key / event string
- SettingRef nativeId
- native Setting* pointer used by changeSettingInternal
- insertValue output bytes
- getSettingRawAddress raw uint64 key
- WriteVagCodingCommand constructor value bytes
- 4-byte raw-address vector
- coding type
- trailing tail bytes
```

Once those are captured for the real cornering setting, the Python write path
can be shaped to match Carista instead of sending blind full-coding guesses.

## Prerequisites

You need all of these at the same time:

```text
- Carista app installed on the Android phone
- phone connected to the car with the Carista adapter
- USB debugging enabled on the phone
- either a rooted `frida-server` path or a patched Carista build that loads Frida Gadget
- USB connection from the phone to this PC when using `adb` port-forwarding to Gadget
```

Quick checks on the PC:

```powershell
.
\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action check
```

For a Gadget-based build forwarded to localhost:

```powershell
adb forward tcp:27042 tcp:27042
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action check -FridaHost 127.0.0.1:27042
```

This wrapper does two things:

```text
- tries to find adb.exe in common Android SDK locations and prints adb devices if available
- uses the local frida Python package directly to check either USB-device visibility or a remote Gadget listener and package visibility
```

If the check reports `device_unavailable`, do not proceed until Frida
connectivity works. The trace depends on live Java and native hooks inside the
Carista app.

## Start The Trace

From the workspace root:

```powershell
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action trace
```

For a Gadget-based build forwarded to localhost:

```powershell
adb forward tcp:27042 tcp:27042
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action trace -FridaHost 127.0.0.1:27042
```

If Carista is not already open, omit `--attach` and let Frida spawn it:

```powershell
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action trace -Spawn
```

Expected early output:

```text
status ... ChangeSettingOperation constructor hook installed
status ... libCarista hooks installed
status ... trace_active
```

Do not continue if those hook-install messages are missing.

## What To Toggle In Carista

Stay focused. Do not browse many unrelated settings.

Best order:

```text
1. Connect to the BCM / lighting customizations section.
2. Open only cornering-light related settings.
3. Toggle one setting at a time.
4. After each toggle, wait for Carista to finish the write.
5. Prefer the most direct candidates first:
   - Cornering lights
   - Cornering lights activation
   - Activate cornering lights with turn signal
   - Cornering lights (using fog lights)
   - Left cornering light (using fog light)
   - Right cornering light (using fog light)
   - Turn on cornering lights when turn signal is on
```

Relevant Carista resource keys already confirmed offline:

```text
car_setting_cornering_lights
car_setting_cornering_lights_activation
car_setting_cornerig_lights_with_turn_signal
car_setting_cornering_lights_via_fogs
car_setting_cornering_lights_via_fogs_left
car_setting_cornering_lights_via_fogs_right
car_setting_cornering_lights_with_turn_signals
```

The trace hook is designed to surface those names if the app actually uses them
for this BCM whitelist.

## Stop And Summarize

After one or a small number of focused toggles, stop the trace with `Ctrl+C`.

Then summarize it:

```powershell
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action summarize
```

If nothing cornering-related appears, inspect everything captured:

```powershell
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action summarize -All
```

## Success Criteria

The trace is good enough when one setting block shows all of these together:

```text
nameResId or eventString for the actual cornering setting
requested value bytes
rawKey (uint64)
WriteVagCodingCommand ctor value
4-byte raw address
codingType
tail bytes
```

That is the tuple needed to stop guessing.

## Immediate Follow-Up After A Good Trace

Once a good cornering capture exists:

```text
1. Freeze that trace file and summary in the workspace.
2. Compare the captured ctor value against the two missing long-coding bits.
3. Patch the Python writer to build the same structured Carista request.
4. Dry-run the reconstructed command first.
5. Only then attempt an adapter-only write.
```

## Current Honest Boundary

Without this live Carista trace, the shortest scripted write is still only a
guess. The existing facts remain:

```text
- direct 2E0600 + full coding is parsed but rejected with 7F2E22
- 1089 + did-0600 causes immediate A8 disconnect
- simple 3B9A + full coding is obsolete and did not produce a useful reply
```

So the fastest path with only the Carista adapter is not another guessed write.
It is one traced Carista toggle that yields the exact builder inputs.