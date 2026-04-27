# Car Scanner VW Polo Coding Backup Extraction Report

Date prepared: 2026-04-16

This document describes how coding/adaptation backup data was found and extracted from a Car Scanner ELM OBD2 Android backup for a Volkswagen Polo. It is intended as context for a separate troubleshooting session.

## Executive Summary

The Car Scanner app package is `com.ovz.carscanner`.

The important backup file is:

```text
C:\Users\victo\Downloads\2026-04-14 17-26-52\phone_extract\coding.bak
```

It contains 27 coding-history backup records for this vehicle:

```text
VIN: WVWZZZ6RZCY230414
Car profile: Volkswagen MQB, PQ26: TSI/TFSI EA211 1.0L/1.2L/1.4L/1.5L
Adapter: BT Carista [88:1B:99:68:41:8D]
```

The most important extracted long-coding style entries are:

| Unit | Request header | Response header | Password | Address | Value hex |
|---|---:|---:|---:|---:|---|
| `01` | `7E0` | `7E8` | `27971` | `0600` | `001100D6202400080000` |
| `17` | `714` | `77E` | `20103` | `0600` | `140801` |

In the extracted data, Car Scanner stores backup values in the `OldData` field. `NewData` is blank because these records are backup snapshots, not before/after change records.

## Files Produced

Extracted outputs:

```text
C:\Users\victo\Downloads\2026-04-14 17-26-52\phone_extract\coding_extracted_summary.txt
C:\Users\victo\Downloads\2026-04-14 17-26-52\phone_extract\coding_extracted.csv
C:\Users\victo\Downloads\2026-04-14 17-26-52\phone_extract\coding_extracted.json
C:\Users\victo\Downloads\2026-04-14 17-26-52\phone_extract\coding.decoded.bson
```

Source/input files:

```text
C:\Users\victo\Downloads\2026-04-14 17-26-52\phone_extract\coding.bak
C:\Users\victo\Downloads\2026-04-14 17-26-52\phone_extract\2026-04-14 17-21-34.brc
```

Hashes:

```text
SHA256  D4E429896AB3D1D38906AA2BAF30A92DC7D3EECF10115C426E2BE937F9CC85EE  coding.bak
SHA256  11B989E921D5D2A632B4B358686030EF9986D873F42E0130644C5898BE64AA12  coding.decoded.bson
SHA256  487E502D440A547C799F8851DC87C39EC25AD60C02D8A7E9C338D87CC4C9E85B  coding_extracted.json
SHA256  E2B89EC4BF401897CD9E42F10B9DCD6EDFF9F14214FF8A8D16C14A467CFDF6DA  2026-04-14 17-21-34.brc
```

## How The Data Was Captured

The original backup directory was:

```text
C:\Users\victo\Downloads\2026-04-14 17-26-52
```

It contained Android app-backup style paths:

```text
data\user\0\com.ovz.carscanner\files\coding.bak
data\user\0\com.ovz.carscanner\cache\drivecyclesv2.db.bak
storage\emulated\0\Android\data\com.ovz.carscanner\files\records\2026-04-14 16-57-55.brc
```

The phone was also connected to the PC as:

```text
Deze pc\S22 van Victor\Internal storage
```

The live phone storage contained:

```text
Internal storage\Android\data\com.ovz.carscanner\files\coding.bak
Internal storage\Android\data\com.ovz.carscanner\files\records\2026-04-14 16-57-55.brc
Internal storage\Android\data\com.ovz.carscanner\files\records\2026-04-14 17-21-34.brc
```

The phone copy of `coding.bak` matched the backup copy exactly by SHA256.

The first `.brc` file was empty. The second `.brc` file contained useful readable metadata:

```text
Header: CARSCANNERRECORD
VIN: WVWZZZ6RZCY230414
Car name: My car
Profile: Volkswagen MQB, PQ26: TSI/TFSI EA211 1.0L/1.2L/1.4L/1.5L
Adapter: BT Carista [88:1B:99:68:41:8D]
Record timestamp: 2026-04-14 17:21:34.929408
```

## How The Format Was Identified

The raw `coding.bak` file was not plain text and was not SQLite. It had high entropy but was not encrypted in the cryptographic sense.

To identify the format, the Car Scanner Android APK was inspected. The APK is a .NET MAUI/Xamarin Android app. Its managed C# assemblies were stored inside:

```text
lib/arm64-v8a/libassemblies.arm64-v8a.blob.so
```

That file uses the .NET Android assembly-store format. The managed assembly `CarScannerMaui.dll` was extracted and decompiled.

The relevant class found was:

```text
CarScannerMaui.Coding.CodingLogItem
```

Its `SaveLogItems` and `LoadLogItems` logic shows that `coding.bak` is:

1. A list of `CodingLogItem` objects.
2. Serialized as BSON using `Newtonsoft.Json.Bson.BsonWriter`.
3. Wrapped by a simple custom stream transform called `ShiftStream2`.

Relevant decompiled logic, simplified:

```csharp
using FileStream fileStream = File.Open(FileSystemHelper.GetLocalFilePath("coding.bak"), FileMode.Create);
using ShiftStream2 shiftStream = new ShiftStream2(fileStream);
using BsonWriter bsonWriter = new BsonWriter(shiftStream);
new JsonSerializer().Serialize(bsonWriter, items);
```

And for loading:

```csharp
using Stream stream = File.Open(localFilePath, FileMode.Open);
using ShiftStream2 stream2 = new ShiftStream2(stream);
using BsonReader bsonReader = new BsonReader(stream2);
bsonReader.ReadRootValueAsArray = true;
List<CodingLogItem> list = new JsonSerializer().Deserialize<List<CodingLogItem>>(bsonReader);
```

## Decoding Method

The app's `ShiftStream2` read transform is:

```csharp
private byte ShiftReadByte(byte b, long position)
{
    if (position % 2 == 0L)
    {
        b -= 88;
        b -= (byte)position;
    }
    else
    {
        b += 69;
        b += (byte)position;
    }
    return b;
}
```

Equivalent Python:

```python
from pathlib import Path
from bson import BSON
import json

src = Path("coding.bak")
raw = bytearray(src.read_bytes())

for i, x in enumerate(raw):
    if i % 2 == 0:
        raw[i] = (x - 88 - (i & 0xff)) & 0xff
    else:
        raw[i] = (x + 69 + (i & 0xff)) & 0xff

Path("coding.decoded.bson").write_bytes(raw)

doc = BSON(bytes(raw)).decode()

# Newtonsoft BSON root array appears as a document with numeric string keys.
items = [doc[k] for k in sorted(doc.keys(), key=lambda x: int(x))]

Path("coding_extracted.json").write_text(
    json.dumps(items, indent=2, ensure_ascii=False, default=str),
    encoding="utf-8",
)
```

Python package used for BSON parsing:

```text
pymongo
```

## Extracted Data

Interpretation of columns:

| Column | Meaning |
|---|---|
| Unit | ECU/control-unit number from Car Scanner title |
| Address | Diagnostic/adaptation identifier logged by Car Scanner |
| Req | CAN request header |
| Resp | CAN response header |
| Password | Security access code Car Scanner stored for that unit |
| ValueHex | Raw bytes read from ECU, stored by Car Scanner as `OldData` |

Timestamp values are .NET ticks stored by Car Scanner. They were converted to local date/time without a timezone flag.

### Unit 01

Likely engine ECU based on CAN header `7E0`/`7E8`.

| Date/time | Address | Req | Resp | Password | ValueHex |
|---|---:|---:|---:|---:|---|
| 2026-04-14 16:59:19 | `04FC` | `7E0` | `7E8` | `27971` | `000000` |
| 2026-04-14 16:59:19 | `04FE` | `7E0` | `7E8` | `27971` | `000000` |
| 2026-04-14 16:59:17 | `0600` | `7E0` | `7E8` | `27971` | `001100D6202400080000` |
| 2026-04-14 16:59:17 | `0902` | `7E0` | `7E8` | `27971` | `00` |
| 2026-04-14 16:59:18 | `0903` | `7E0` | `7E8` | `27971` | `09C4` |
| 2026-04-14 16:59:18 | `0904` | `7E0` | `7E8` | `27971` | `09C4` |
| 2026-04-14 16:59:18 | `090D` | `7E0` | `7E8` | `27971` | `00` |
| 2026-04-14 16:59:18 | `090E` | `7E0` | `7E8` | `27971` | `0000` |
| 2026-04-14 16:59:19 | `0927` | `7E0` | `7E8` | `27971` | `00` |
| 2026-04-14 16:59:19 | `0937` | `7E0` | `7E8` | `27971` | `00` |

### Unit 17

Likely instrument cluster/dashboard based on unit number `17` and CAN header `714`/`77E`.

| Date/time | Address | Req | Resp | Password | ValueHex |
|---|---:|---:|---:|---:|---|
| 2026-04-14 17:01:55 | `0600` | `714` | `77E` | `20103` | `140801` |
| 2026-04-14 17:01:59 | `0919` | `714` | `77E` | `20103` | `03` |
| 2026-04-14 17:01:55 | `2203` | `714` | `77E` | `20103` | `48C2` |
| 2026-04-14 17:01:56 | `2232` | `714` | `77E` | `20103` | `00` |
| 2026-04-14 17:01:56 | `2233` | `714` | `77E` | `20103` | `01` |
| 2026-04-14 17:01:56 | `2234` | `714` | `77E` | `20103` | `64` |
| 2026-04-14 17:01:56 | `2238` | `714` | `77E` | `20103` | `11` |
| 2026-04-14 17:01:56 | `2239` | `714` | `77E` | `20103` | `02` |
| 2026-04-14 17:01:57 | `2243` | `714` | `77E` | `20103` | `000D` |
| 2026-04-14 17:01:57 | `2244` | `714` | `77E` | `20103` | `0022` |
| 2026-04-14 17:01:58 | `2248` | `714` | `77E` | `20103` | `01` |
| 2026-04-14 17:01:58 | `224A` | `714` | `77E` | `20103` | `0000` |
| 2026-04-14 17:01:58 | `224B` | `714` | `77E` | `20103` | `001F` |
| 2026-04-14 17:01:59 | `228A` | `714` | `77E` | `20103` | `0008` |
| 2026-04-14 17:01:56 | `2292` | `714` | `77E` | `20103` | `0FFF` |
| 2026-04-14 17:01:59 | `22A0` | `714` | `77E` | `20103` | `0096` |
| 2026-04-14 17:01:59 | `22A1` | `714` | `77E` | `20103` | `0174` |

## Important Limitations

This is not a full VCDS/ODIS auto-scan. It is only what Car Scanner saved in `coding.bak`.

Only units `01` and `17` appear in this backup file. If the app attempted "all units backup", the result here still only contains 27 logged records.

The values are raw hexadecimal bytes. This report does not decode every adaptation channel into a human-readable label. Car Scanner internally knows some labels, but `coding.bak` stores the backup record title mostly as "Backup copy of unit XX $ADDRESS" and does not include full label names for each address.

For backups, `OldData` means "the value read from the car at backup time." It does not necessarily mean "old value before a change."

## Prompt-Ready Summary For Another ChatGPT Session

I have a VW Polo / VW profile from Car Scanner ELM OBD2. The Car Scanner backup file `coding.bak` was decoded. It was BSON wrapped in Car Scanner's `ShiftStream2` transform, not real encryption. The decoded file contains 27 backup entries for VIN `WVWZZZ6RZCY230414`.

Car profile metadata from a `.brc` record:

```text
VIN: WVWZZZ6RZCY230414
Profile: Volkswagen MQB, PQ26: TSI/TFSI EA211 1.0L/1.2L/1.4L/1.5L
Adapter: BT Carista [88:1B:99:68:41:8D]
```

Extracted coding/adaptation backup values:

```text
Unit 01, request 7E0, response 7E8, password 27971:
04FC = 000000
04FE = 000000
0600 = 001100D6202400080000
0902 = 00
0903 = 09C4
0904 = 09C4
090D = 00
090E = 0000
0927 = 00
0937 = 00

Unit 17, request 714, response 77E, password 20103:
0600 = 140801
0919 = 03
2203 = 48C2
2232 = 00
2233 = 01
2234 = 64
2238 = 11
2239 = 02
2243 = 000D
2244 = 0022
2248 = 01
224A = 0000
224B = 001F
228A = 0008
2292 = 0FFF
22A0 = 0096
22A1 = 0174
```

In this data, values are raw `OldData` backup values from Car Scanner. `NewData` is blank because this was a backup snapshot.
