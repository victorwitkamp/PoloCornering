from __future__ import annotations

import argparse
import json
from dataclasses import asdict, dataclass
from io import BytesIO
from pathlib import Path
from zipfile import ZipFile

try:
    from loguru import logger

    logger.disable("androguard")
except Exception:
    pass

from androguard.core.dex import DEX


ROOT = Path(__file__).resolve().parent
XAPK_PATH = ROOT / "reacquire_20260424" / "carista_9.8.2.xapk"
EXTRACT_ROOT = ROOT / "extracted" / "android"
BASE_APK_NAME = "com.prizmos.carista.apk"
ARM_SPLIT_APK_NAME = "config.armeabi_v7a.apk"
ARM_LIB_ENTRY = "lib/armeabi-v7a/libCarista.so"

TARGET_DESCRIPTORS = {
    "Lcom/prizmos/carista/library/model/Setting;",
    "Lcom/prizmos/carista/library/model/SettingRef;",
    "Lcom/prizmos/carista/library/model/SettingCategory;",
    "Lcom/prizmos/carista/library/model/Ecu;",
    "Lcom/prizmos/carista/library/model/Interpretation;",
    "Lcom/prizmos/carista/library/operation/ReadValuesOperation;",
    "Lcom/prizmos/carista/library/operation/ChangeSettingOperation;",
    "Lcom/prizmos/carista/library/operation/CheckSettingsOperation;",
    "Lcom/prizmos/carista/library/operation/GetEcuInfoOperation;",
}

INTERESTING_METHODS = {
    "<init>",
    "getAvailableItems",
    "getSettingValue",
    "initNative",
    "valuesNative",
    "getValues",
    "getNativeId",
    "getEcu",
    "getInstruction",
    "getInterpretation",
    "getNameResId",
    "getNameResIdNative",
    "toEventString",
    "toEventStringNative",
    "isObd2",
    "isObd2Native",
    "getCodingRawAddress",
    "getAdaptationRawAddress",
    "supportsSingleCoding",
    "supportsMultiCoding",
    "supportsAdaptation",
    "supportsDiagnostics",
    "isValueInterpretedAsDecimal",
    "equals",
    "hashCode",
}


@dataclass(frozen=True)
class ExtractedArtifact:
    label: str
    path: str
    size: int


@dataclass(frozen=True)
class BridgeMethod:
    name: str
    descriptor: str
    access_flags: str
    native: bool


@dataclass(frozen=True)
class BridgeClass:
    dex_file: str
    descriptor: str
    java_name: str
    methods: list[BridgeMethod]


def descriptor_to_java_name(descriptor: str) -> str:
    if descriptor.startswith("L") and descriptor.endswith(";"):
        return descriptor[1:-1].replace("/", ".")
    return descriptor


def write_bytes(path: Path, data: bytes) -> ExtractedArtifact:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)
    return ExtractedArtifact(path.name, str(path.relative_to(ROOT.parent)), len(data))


def extract_android_inputs(xapk_path: Path = XAPK_PATH, extract_root: Path = EXTRACT_ROOT) -> list[ExtractedArtifact]:
    artifacts: list[ExtractedArtifact] = []
    with ZipFile(xapk_path) as xapk:
        base_apk = xapk.read(BASE_APK_NAME)
        artifacts.append(write_bytes(extract_root / BASE_APK_NAME, base_apk))

        arm_split = xapk.read(ARM_SPLIT_APK_NAME)
        artifacts.append(write_bytes(extract_root / ARM_SPLIT_APK_NAME, arm_split))

        with ZipFile(BytesIO(base_apk)) as apk:
            for entry in apk.infolist():
                if entry.filename.startswith("classes") and entry.filename.endswith(".dex"):
                    artifacts.append(write_bytes(extract_root / "dex" / entry.filename, apk.read(entry.filename)))

        with ZipFile(BytesIO(arm_split)) as apk:
            artifacts.append(write_bytes(extract_root / ARM_LIB_ENTRY, apk.read(ARM_LIB_ENTRY)))

    return artifacts


def scan_bridge_classes(dex_dir: Path = EXTRACT_ROOT / "dex") -> list[BridgeClass]:
    classes: list[BridgeClass] = []
    for dex_path in sorted(dex_dir.glob("classes*.dex")):
        dex = DEX(dex_path.read_bytes())
        for target in sorted(TARGET_DESCRIPTORS):
            dex_class = dex.get_class(target)
            if dex_class is None:
                continue
            methods: list[BridgeMethod] = []
            for method in dex_class.get_methods():
                name = method.get_name()
                if name in INTERESTING_METHODS or name.endswith("Native"):
                    access_flags = method.get_access_flags_string()
                    methods.append(
                        BridgeMethod(
                            name=name,
                            descriptor=method.get_descriptor(),
                            access_flags=access_flags,
                            native="native" in access_flags.split(),
                        )
                    )
            classes.append(
                BridgeClass(
                    dex_file=dex_path.name,
                    descriptor=target,
                    java_name=descriptor_to_java_name(target),
                    methods=methods,
                )
            )
    return classes


def render_report(artifacts: list[ExtractedArtifact], bridge_classes: list[BridgeClass]) -> str:
    lines = [
        "# Carista Android Ghidra Inputs And Bridge Scan",
        "",
        "This report is generated from the Carista 9.8.2 XAPK without running the app or using a phone.",
        "",
        "## Extracted Inputs",
        "",
        "| Artifact | Path | Size |",
        "|---|---|---:|",
    ]
    for artifact in artifacts:
        lines.append(f"| {artifact.label} | `{artifact.path}` | {artifact.size} |")

    lines.extend(
        [
            "",
            "## Bridge Classes",
            "",
            "These descriptors are the Java-side package/folder structure to use when connecting the DEX model to the native `libCarista.so` model.",
            "",
        ]
    )
    for item in bridge_classes:
        lines.extend(
            [
                f"### {item.java_name}",
                "",
                f"- DEX: `{item.dex_file}`",
                f"- Descriptor: `{item.descriptor}`",
                "- Interesting methods:",
            ]
        )
        for method in item.methods:
            suffix = " [native declaration]" if method.native else ""
            lines.append(f"  - `{method.name}{method.descriptor}` ({method.access_flags}){suffix}")
        lines.append("")

    lines.extend(
        [
            "## Ghidra Workflow Note",
            "",
            "The base APK contains both `classes.dex` and `classes2.dex`. For the richest Ghidra DEX output, import the APK from Code Browser, decline immediate analysis, set External Program associations for every `classes*.dex`, confirm both listings are open, then run Analyze All Open.",
            "",
            "Native Java methods such as `initNative`, `getSettingValue`, and `getAvailableItems` are declarations in the DEX. Ghidra can show their call sites, but the implementation is in `libCarista.so` and must be followed through the native exports.",
            "",
        ]
    )
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description="Extract Carista APK/DEX inputs and report Java/native bridge descriptors.")
    parser.add_argument("--xapk", type=Path, default=XAPK_PATH)
    parser.add_argument("--extract-root", type=Path, default=EXTRACT_ROOT)
    parser.add_argument("--output", type=Path, default=ROOT / "carista_android_bridge_report.md")
    parser.add_argument("--json-output", type=Path, default=ROOT / "carista_android_bridge_report.json")
    args = parser.parse_args()

    artifacts = extract_android_inputs(args.xapk, args.extract_root)
    bridge_classes = scan_bridge_classes(args.extract_root / "dex")

    args.output.write_text(render_report(artifacts, bridge_classes), encoding="utf-8")
    args.json_output.write_text(
        json.dumps(
            {
                "artifacts": [asdict(item) for item in artifacts],
                "bridge_classes": [asdict(item) for item in bridge_classes],
            },
            indent=2,
            sort_keys=True,
        )
        + "\n",
        encoding="utf-8",
    )
    print(f"Wrote {len(bridge_classes)} bridge classes to {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
