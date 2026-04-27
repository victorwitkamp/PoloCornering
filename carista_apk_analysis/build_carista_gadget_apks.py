from __future__ import annotations

import argparse
import json
import lzma
import shutil
import subprocess
import sys
from pathlib import Path
from zipfile import ZIP_DEFLATED, ZIP_STORED, ZipFile, ZipInfo

import lief


SCRIPT_ROOT = Path(__file__).resolve().parent
REACQUIRE_ROOT = SCRIPT_ROOT / "reacquire_20260424"
XAPK_DIR = REACQUIRE_ROOT / "xapk_unpacked"
DEFAULT_BASE_APK = XAPK_DIR / "com.prizmos.carista.apk"
DEFAULT_ARM_SPLIT_APK = XAPK_DIR / "config.armeabi_v7a.apk"
DEFAULT_HDPI_SPLIT_APK = XAPK_DIR / "config.hdpi.apk"
DEFAULT_CARISTA_LIB = (
    REACQUIRE_ROOT / "split_armv7_unpacked" / "lib" / "armeabi-v7a" / "libCarista.so"
)
DEFAULT_OUTPUT_DIR = SCRIPT_ROOT / "gadget_patch_out"
DEFAULT_TOOL_ROOT = Path(r"C:\Program Files (x86)\APK Editor Studio\tools")
DEFAULT_ZIPALIGN = DEFAULT_TOOL_ROOT / "zipalign.exe"
DEFAULT_APKSIGNER = DEFAULT_TOOL_ROOT / "apksigner.jar"
DEFAULT_GADGET_NAME = "libgadget.so"
DEFAULT_GADGET_HOST = "127.0.0.1"
DEFAULT_GADGET_PORT = 27042
DEFAULT_GADGET_ON_LOAD = "wait"
DEFAULT_PACKAGE_NAME = "com.prizmos.carista"
DEFAULT_KEYSTORE = SCRIPT_ROOT / "keys" / "carista-gadget-debug.jks"
DEFAULT_KEY_ALIAS = "carista-gadget"
DEFAULT_STOREPASS = "android"
DEFAULT_KEYPASS = "android"
DEFAULT_DNAME = "CN=Carista Gadget, OU=Local, O=Local, L=Local, S=Local, C=US"


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Build a re-signed Carista split set that loads Frida Gadget from the "
            "existing armeabi-v7a native split."
        )
    )
    parser.add_argument(
        "--gadget",
        type=Path,
        required=True,
        help=(
            "Path to Frida Gadget for Android ARM. The file may be the raw .so or "
            "the downloaded .xz asset."
        ),
    )
    parser.add_argument(
        "--base-apk",
        type=Path,
        default=DEFAULT_BASE_APK,
        help=f"Base APK to copy and re-sign (default: {DEFAULT_BASE_APK})",
    )
    parser.add_argument(
        "--arm-split-apk",
        type=Path,
        default=DEFAULT_ARM_SPLIT_APK,
        help=f"ARMv7 split APK to patch and re-sign (default: {DEFAULT_ARM_SPLIT_APK})",
    )
    parser.add_argument(
        "--hdpi-split-apk",
        type=Path,
        default=DEFAULT_HDPI_SPLIT_APK,
        help=f"Display-density split APK to copy and re-sign (default: {DEFAULT_HDPI_SPLIT_APK})",
    )
    parser.add_argument(
        "--carista-lib",
        type=Path,
        default=DEFAULT_CARISTA_LIB,
        help=f"Extracted libCarista.so to patch with a DT_NEEDED entry (default: {DEFAULT_CARISTA_LIB})",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=DEFAULT_OUTPUT_DIR,
        help=f"Output directory for unsigned, aligned, and signed APKs (default: {DEFAULT_OUTPUT_DIR})",
    )
    parser.add_argument(
        "--gadget-name",
        default=DEFAULT_GADGET_NAME,
        help=(
            "Library filename to use inside the split APK. Use a neutral name like "
            f"{DEFAULT_GADGET_NAME} to avoid obvious Frida naming."
        ),
    )
    parser.add_argument(
        "--listen-address",
        default=DEFAULT_GADGET_HOST,
        help=f"Frida Gadget listen address (default: {DEFAULT_GADGET_HOST})",
    )
    parser.add_argument(
        "--listen-port",
        type=int,
        default=DEFAULT_GADGET_PORT,
        help=f"Frida Gadget listen port (default: {DEFAULT_GADGET_PORT})",
    )
    parser.add_argument(
        "--on-load",
        choices=("wait", "resume"),
        default=DEFAULT_GADGET_ON_LOAD,
        help=(
            "Frida Gadget on-load behavior. 'wait' blocks until a controller attaches; "
            "'resume' lets the app continue immediately."
        ),
    )
    parser.add_argument(
        "--package-name",
        default=DEFAULT_PACKAGE_NAME,
        help=f"Package name used in the generated install helper (default: {DEFAULT_PACKAGE_NAME})",
    )
    parser.add_argument(
        "--keystore",
        type=Path,
        default=DEFAULT_KEYSTORE,
        help=f"Signing keystore path. Created if missing (default: {DEFAULT_KEYSTORE})",
    )
    parser.add_argument(
        "--key-alias",
        default=DEFAULT_KEY_ALIAS,
        help=f"Signing key alias (default: {DEFAULT_KEY_ALIAS})",
    )
    parser.add_argument(
        "--storepass",
        default=DEFAULT_STOREPASS,
        help="Keystore password.",
    )
    parser.add_argument(
        "--keypass",
        default=DEFAULT_KEYPASS,
        help="Key password.",
    )
    parser.add_argument(
        "--key-dname",
        default=DEFAULT_DNAME,
        help=f"Distinguished name used when generating a keystore (default: {DEFAULT_DNAME})",
    )
    parser.add_argument(
        "--java",
        default=shutil.which("java") or "java",
        help="Java executable used to run apksigner.jar.",
    )
    parser.add_argument(
        "--keytool",
        default=shutil.which("keytool") or "keytool",
        help="keytool executable used to create a keystore if missing.",
    )
    parser.add_argument(
        "--zipalign",
        type=Path,
        default=DEFAULT_ZIPALIGN,
        help=f"zipalign executable path (default: {DEFAULT_ZIPALIGN})",
    )
    parser.add_argument(
        "--apksigner",
        type=Path,
        default=DEFAULT_APKSIGNER,
        help=f"apksigner jar path (default: {DEFAULT_APKSIGNER})",
    )
    return parser


def require_file(path: Path, label: str) -> Path:
    resolved = path.resolve()
    if not resolved.is_file():
        raise FileNotFoundError(f"{label} not found: {resolved}")
    return resolved


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def run_command(arguments: list[str | Path], *, label: str) -> None:
    command = [str(argument) for argument in arguments]
    print(f"[{label}] {' '.join(command)}")
    completed = subprocess.run(command, check=False, text=True, capture_output=True)
    if completed.stdout:
        print(completed.stdout.rstrip())
    if completed.stderr:
        print(completed.stderr.rstrip(), file=sys.stderr)
    if completed.returncode != 0:
        raise RuntimeError(f"{label} failed with exit code {completed.returncode}")


def clone_zip_info(info: ZipInfo, *, filename: str | None = None, compress_type: int | None = None) -> ZipInfo:
    cloned = ZipInfo(filename or info.filename, date_time=info.date_time)
    cloned.comment = info.comment
    cloned.extra = info.extra
    cloned.create_system = info.create_system
    cloned.create_version = info.create_version
    cloned.extract_version = info.extract_version
    cloned.flag_bits = info.flag_bits
    cloned.volume = info.volume
    cloned.internal_attr = info.internal_attr
    cloned.external_attr = info.external_attr
    cloned.compress_type = info.compress_type if compress_type is None else compress_type
    return cloned


def load_gadget_bytes(path: Path) -> bytes:
    raw = path.read_bytes()
    if path.suffix.lower() == ".xz":
        return lzma.decompress(raw)
    return raw


def build_gadget_config(address: str, port: int, on_load: str) -> bytes:
    payload = {
        "interaction": {
            "type": "listen",
            "address": address,
            "port": port,
            "on_port_conflict": "fail",
            "on_load": on_load,
        }
    }
    return (json.dumps(payload, indent=2) + "\n").encode("utf-8")


def patch_carista_library(source: Path, destination: Path, gadget_name: str) -> list[str]:
    parsed = lief.parse(str(source))
    if parsed is None or not isinstance(parsed, lief.ELF.Binary):
        raise ValueError(f"failed to parse ELF binary: {source}")

    libraries = list(parsed.libraries)
    if gadget_name not in libraries:
        parsed.add_library(gadget_name)
    parsed.write(str(destination))

    reparsed = lief.parse(str(destination))
    if reparsed is None or not isinstance(reparsed, lief.ELF.Binary):
        raise ValueError(f"failed to reparse patched ELF binary: {destination}")

    patched_libraries = list(reparsed.libraries)
    if gadget_name not in patched_libraries:
        raise ValueError(f"patched ELF is missing DT_NEEDED entry for {gadget_name}")
    return patched_libraries


def should_skip_entry(filename: str) -> bool:
    return filename.startswith("META-INF/") or filename == "stamp-cert-sha256"


def rewrite_apk(
    source_apk: Path,
    destination_apk: Path,
    *,
    replacements: dict[str, tuple[bytes, int]],
) -> None:
    ensure_parent(destination_apk)
    pending = dict(replacements)
    with ZipFile(source_apk, "r") as source, ZipFile(destination_apk, "w") as destination:
        for info in source.infolist():
            if should_skip_entry(info.filename):
                continue

            if info.filename in pending:
                data, compress_type = pending.pop(info.filename)
                destination.writestr(
                    clone_zip_info(info, compress_type=compress_type),
                    data,
                )
                continue

            destination.writestr(clone_zip_info(info), source.read(info.filename))

        for filename, (data, compress_type) in pending.items():
            entry = ZipInfo(filename)
            entry.create_system = 0
            entry.compress_type = compress_type
            destination.writestr(entry, data)


def ensure_keystore(
    *,
    keytool: str,
    keystore: Path,
    alias: str,
    storepass: str,
    keypass: str,
    dname: str,
) -> None:
    if keystore.exists():
        return

    ensure_parent(keystore)
    run_command(
        [
            keytool,
            "-genkeypair",
            "-keystore",
            keystore,
            "-storepass",
            storepass,
            "-keypass",
            keypass,
            "-alias",
            alias,
            "-keyalg",
            "RSA",
            "-keysize",
            "2048",
            "-validity",
            "3650",
            "-dname",
            dname,
        ],
        label="keytool",
    )


def zipalign_apk(zipalign: Path, source_apk: Path, destination_apk: Path) -> None:
    ensure_parent(destination_apk)
    run_command(
        [zipalign, "-p", "-f", "4", source_apk, destination_apk],
        label="zipalign",
    )


def sign_apk(
    *,
    java: str,
    apksigner: Path,
    source_apk: Path,
    destination_apk: Path,
    keystore: Path,
    alias: str,
    storepass: str,
    keypass: str,
) -> None:
    ensure_parent(destination_apk)
    run_command(
        [
            java,
            "-jar",
            apksigner,
            "sign",
            "--ks",
            keystore,
            "--ks-key-alias",
            alias,
            "--ks-pass",
            f"pass:{storepass}",
            "--key-pass",
            f"pass:{keypass}",
            "--out",
            destination_apk,
            source_apk,
        ],
        label="apksigner-sign",
    )
    run_command(
        [java, "-jar", apksigner, "verify", "--print-certs", destination_apk],
        label="apksigner-verify",
    )


def write_install_helper(
    destination: Path,
    *,
    package_name: str,
    base_apk: Path,
    arm_apk: Path,
    hdpi_apk: Path,
    listen_port: int,
) -> None:
    content = f"""param(
    [switch]$UninstallFirst
)

Set-StrictMode -Version Latest
$ErrorActionPreference = \"Stop\"

function Find-Adb {{
    $command = Get-Command adb -ErrorAction SilentlyContinue
    if ($command -and $command.Source) {{
        return $command.Source
    }}

    $candidates = @(
        $(if ($env:ANDROID_SDK_ROOT) {{ Join-Path $env:ANDROID_SDK_ROOT \"platform-tools\\adb.exe\" }}),
        $(if ($env:ANDROID_HOME) {{ Join-Path $env:ANDROID_HOME \"platform-tools\\adb.exe\" }}),
        \"$env:LOCALAPPDATA\\Android\\Sdk\\platform-tools\\adb.exe\",
        \"$env:USERPROFILE\\AppData\\Local\\Android\\Sdk\\platform-tools\\adb.exe\",
        \"$env:LOCALAPPDATA\\Microsoft\\WinGet\\Packages\\Google.PlatformTools_Microsoft.Winget.Source_8wekyb3d8bbwe\\platform-tools\\adb.exe\",
        \"$env:ProgramFiles\\Android\\platform-tools\\adb.exe\",
        \"$env:ProgramFiles(x86)\\Android\\android-sdk\\platform-tools\\adb.exe\",
        \"C:\\platform-tools\\adb.exe\"
    )
    foreach ($candidate in $candidates) {{
        if ($candidate -and (Test-Path $candidate)) {{
            return $candidate
        }}
    }}
    return $null
}}

$adb = Find-Adb
if (-not $adb) {{
    throw \"adb.exe not found in PATH or common Android SDK locations. Install platform-tools first.\"
}}

function Invoke-Adb([string[]]$Arguments) {{
    & $adb @Arguments
    if ($LASTEXITCODE -ne 0) {{
        throw \"adb command failed ($LASTEXITCODE): $($Arguments -join ' ')\"
    }}
}}

$base = \"{base_apk}\"
$arm = \"{arm_apk}\"
$hdpi = \"{hdpi_apk}\"

if ($UninstallFirst) {{
    Invoke-Adb @("uninstall", "{package_name}")
}}

Invoke-Adb @("install-multiple", $base, $arm, $hdpi)
Invoke-Adb @("forward", "tcp:{listen_port}", "tcp:{listen_port}")

Write-Host \"Forwarded tcp:{listen_port} -> tcp:{listen_port}.\"
Write-Host \"Next: .\\carista_apk_analysis\\run_carista_cornering_capture.ps1 -Action trace -FridaHost 127.0.0.1:{listen_port}\"
"""
    ensure_parent(destination)
    destination.write_text(content, encoding="utf-8")


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()

    base_apk = require_file(args.base_apk, "Base APK")
    arm_split_apk = require_file(args.arm_split_apk, "ARM split APK")
    hdpi_split_apk = require_file(args.hdpi_split_apk, "HDPI split APK")
    carista_lib = require_file(args.carista_lib, "libCarista.so")
    gadget = require_file(args.gadget, "Frida Gadget")
    zipalign = require_file(args.zipalign, "zipalign")
    apksigner = require_file(args.apksigner, "apksigner")

    if not args.gadget_name.startswith("lib") or not args.gadget_name.endswith(".so"):
        parser.error("--gadget-name must start with 'lib' and end with '.so'")

    output_dir = args.output_dir.resolve()
    unsigned_dir = output_dir / "unsigned"
    aligned_dir = output_dir / "aligned"
    signed_dir = output_dir / "signed"
    work_dir = output_dir / "work"
    for directory in (unsigned_dir, aligned_dir, signed_dir, work_dir):
        directory.mkdir(parents=True, exist_ok=True)

    gadget_bytes = load_gadget_bytes(gadget)
    gadget_config_name = args.gadget_name[:-3] + ".config.so"
    gadget_config_bytes = build_gadget_config(args.listen_address, args.listen_port, args.on_load)

    patched_lib_path = work_dir / "libCarista.patched.so"
    patched_libraries = patch_carista_library(carista_lib, patched_lib_path, args.gadget_name)
    gadget_path = work_dir / args.gadget_name
    gadget_path.write_bytes(gadget_bytes)
    gadget_config_path = work_dir / gadget_config_name
    gadget_config_path.write_bytes(gadget_config_bytes)

    lib_root = "lib/armeabi-v7a/"
    arm_replacements = {
        f"{lib_root}libCarista.so": (patched_lib_path.read_bytes(), ZIP_STORED),
        f"{lib_root}{args.gadget_name}": (gadget_bytes, ZIP_STORED),
        f"{lib_root}{gadget_config_name}": (gadget_config_bytes, ZIP_STORED),
    }

    unsigned_base = unsigned_dir / base_apk.name
    unsigned_arm = unsigned_dir / arm_split_apk.name
    unsigned_hdpi = unsigned_dir / hdpi_split_apk.name
    rewrite_apk(base_apk, unsigned_base, replacements={})
    rewrite_apk(arm_split_apk, unsigned_arm, replacements=arm_replacements)
    rewrite_apk(hdpi_split_apk, unsigned_hdpi, replacements={})

    aligned_base = aligned_dir / base_apk.name
    aligned_arm = aligned_dir / arm_split_apk.name
    aligned_hdpi = aligned_dir / hdpi_split_apk.name
    zipalign_apk(zipalign, unsigned_base, aligned_base)
    zipalign_apk(zipalign, unsigned_arm, aligned_arm)
    zipalign_apk(zipalign, unsigned_hdpi, aligned_hdpi)

    ensure_keystore(
        keytool=args.keytool,
        keystore=args.keystore.resolve(),
        alias=args.key_alias,
        storepass=args.storepass,
        keypass=args.keypass,
        dname=args.key_dname,
    )

    signed_base = signed_dir / base_apk.name
    signed_arm = signed_dir / arm_split_apk.name
    signed_hdpi = signed_dir / hdpi_split_apk.name
    sign_apk(
        java=args.java,
        apksigner=apksigner,
        source_apk=aligned_base,
        destination_apk=signed_base,
        keystore=args.keystore.resolve(),
        alias=args.key_alias,
        storepass=args.storepass,
        keypass=args.keypass,
    )
    sign_apk(
        java=args.java,
        apksigner=apksigner,
        source_apk=aligned_arm,
        destination_apk=signed_arm,
        keystore=args.keystore.resolve(),
        alias=args.key_alias,
        storepass=args.storepass,
        keypass=args.keypass,
    )
    sign_apk(
        java=args.java,
        apksigner=apksigner,
        source_apk=aligned_hdpi,
        destination_apk=signed_hdpi,
        keystore=args.keystore.resolve(),
        alias=args.key_alias,
        storepass=args.storepass,
        keypass=args.keypass,
    )

    install_helper = output_dir / "install_patched_carista.ps1"
    write_install_helper(
        install_helper,
        package_name=args.package_name,
        base_apk=signed_base,
        arm_apk=signed_arm,
        hdpi_apk=signed_hdpi,
        listen_port=args.listen_port,
    )

    summary = {
        "base_apk": str(signed_base),
        "arm_split_apk": str(signed_arm),
        "hdpi_split_apk": str(signed_hdpi),
        "install_helper": str(install_helper),
        "patched_lib": str(patched_lib_path),
        "gadget_name": args.gadget_name,
        "gadget_config_name": gadget_config_name,
        "gadget_listen": f"{args.listen_address}:{args.listen_port}",
        "carista_libraries": patched_libraries,
    }
    summary_path = output_dir / "patch_summary.json"
    summary_path.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")

    print()
    print("Patched Carista split set created:")
    print(f"  base: {signed_base}")
    print(f"  arm:  {signed_arm}")
    print(f"  hdpi: {signed_hdpi}")
    print(f"  helper: {install_helper}")
    print(f"  summary: {summary_path}")
    print()
    print("Next steps:")
    print(f"  1. Uninstall the store-signed Carista app from the phone if needed.")
    print(f"  2. Run: powershell -ExecutionPolicy Bypass -File \"{install_helper}\" -UninstallFirst")
    print(
        f"  3. Trace with: .\\carista_apk_analysis\\run_carista_cornering_capture.ps1 -Action trace -FridaHost {args.listen_address}:{args.listen_port}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())