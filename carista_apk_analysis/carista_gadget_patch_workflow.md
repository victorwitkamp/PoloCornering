# Carista Gadget Patch Workflow

Purpose: build a patched Carista split set that loads Frida Gadget through the
existing `armeabi-v7a` native library path, so live setting-write traces are
possible on the stock Samsung phone without root or `frida-server`.

## Why This Path

The reacquired Carista bundle already gives us a stable native injection point:

```text
- xapk_unpacked/config.armeabi_v7a.apk is the only ABI split in the bundle
- libCarista.so is ARM / ELF32 and already loaded by the app
- LIEF can successfully add a new DT_NEEDED entry to libCarista.so
- APK Editor Studio installed usable Android tools locally:
  - tools/apksigner.jar
  - tools/zipalign.exe
```

That means we do not need a full smali or manifest rebuild just to load Gadget.
We can patch `libCarista.so` itself so Android loads `libgadget.so` alongside
it.

## Inputs

You need the Android ARM Frida Gadget asset that matches the local Frida major
version. For the current setup that is:

```text
frida-gadget-17.9.1-android-arm.so.xz
```

Place it anywhere in the workspace or give the builder the full path.

## Build The Patched Split Set

From the workspace root:

```powershell
.venv\Scripts\python.exe .\carista_apk_analysis\build_carista_gadget_apks.py --gadget .\downloads\frida-gadget-17.9.1-android-arm.so.xz
```

What the builder does:

```text
1. Decompresses the Gadget asset if needed.
2. Patches libCarista.so to add DT_NEEDED for libgadget.so.
3. Rewrites config.armeabi_v7a.apk with:
   - patched libCarista.so
   - libgadget.so
   - libgadget.config.so
4. Rewrites the base and hdpi split APKs without the stale original signature metadata.
5. zipaligns all three APKs.
6. Generates a local debug keystore if one does not exist yet.
7. Signs all three APKs with the same local certificate.
8. Writes:
   - gadget_patch_out/signed/*.apk
   - gadget_patch_out/install_patched_carista.ps1
   - gadget_patch_out/patch_summary.json
```

The default Gadget config is:

```json
{
  "interaction": {
    "type": "listen",
    "address": "127.0.0.1",
    "port": 27042,
    "on_port_conflict": "fail",
    "on_load": "wait"
  }
}
```

If you want the app to continue immediately instead of waiting for the trace
client, add:

```powershell
--on-load resume
```

## Install On The Phone

Because the APKs are re-signed locally, Android will treat them as a different
signing identity from the Play-installed Carista app.

That means the normal installation path is:

```text
1. Uninstall the store-signed Carista app from the phone.
2. Install the generated split set with adb install-multiple.
```

The builder writes a helper script for that:

```powershell
powershell -ExecutionPolicy Bypass -File .\carista_apk_analysis\gadget_patch_out\install_patched_carista.ps1 -UninstallFirst
```

Important consequence:

```text
- uninstalling Carista will also remove its local app data on the phone
```

## Run The Trace Through Gadget

After the patched build is installed:

```powershell
adb forward tcp:27042 tcp:27042
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action trace -FridaHost 127.0.0.1:27042
```

Then toggle only the cornering-light settings inside Carista and summarize the
capture the same way as before:

```powershell
.\carista_apk_analysis\run_carista_cornering_capture.ps1 -Action summarize
```

## Current Expected Behavior

If the patched APK is installed correctly but the Carista native path has not
loaded yet, the host-side `check` may not see a process immediately.

Once `libCarista.so` is loaded by the app, the forwarded Gadget listener should
be reachable on `127.0.0.1:27042`, and the trace tooling can attach through the
new `-FridaHost` path instead of waiting on a rooted `frida-server`.