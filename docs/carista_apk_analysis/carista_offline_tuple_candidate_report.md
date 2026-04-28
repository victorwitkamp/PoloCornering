# Carista Offline Tuple Candidate Analysis

Date: 2026-04-27

This is a no-phone, no-Gadget static analysis pass over the reacquired Carista ARMv7 native library.
It proves where the final `3B9A` tuple fields come from, then checks whether those fields exist for the actual `6R0937087K` evidence in this workspace.

## Source

```text
C:\Users\victo\Downloads\PoloCornering\carista_apk_analysis\reacquire_20260424\carista_9.8.2.xapk!config.armeabi_v7a.apk!lib/armeabi-v7a/libCarista.so
```

## Static Function Findings

| Symbol | Address | Size | Finding |
|---|---:|---:|---|
| `_ZNK23GetVagCanEcuInfoCommand10getRequestEv` | `0x00CF8230` | 20 | ECU-info request literal resolves to 1A9B; this is the command whose positive 5A9B response carries the rawAddress4/coding selector fields. |
| `_ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x00CF8654` | 888 | ECU-info parser strips the positive response prefix, reads rawAddress4 at payload offset 0x0c, coding selector at 0x10, optional tail at 0x11, and the stored 6-byte coding value at 0x14. |
| `_ZNK21WriteVagCodingCommand10getRequestEv` | `0x00D032BC` | 300 | Request builder serializes 3B9A + 6-byte value + 4-byte rawAddress4 + coding-type-dependent suffix. |
| `_ZN17OperationDelegate13getRawAddressEhP3Ecut` | `0x012327D4` | 24 | Generic formatter returns low32=(ecu_address << 16) | raw_short and carries setting/raw type in the second return register. |
| `_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE` | `0x012620EC` | 204 | VAG setting address path returns Ecu* plus a raw-address word; setting types 9/5 and 4 use special branches, ordinary long-coding settings use the base coding-address path. |
| `_ZN20VagOperationDelegate19getCodingRawAddressEP3Ecut` | `0x0125BE08` | 492 | VAG coding raw-address path queries ECU-info metadata, distinguishes coding families 2/3, and can fall back to alternate formatting paths. |
| `_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x01263CEC` | 324 | Writer receives Ecu* + raw-address word + value vector, normalizes non-type-2 coding to type 3, has a sentinel type-5 path, then builds WriteVagCodingCommand. |

## Embedded VAGCAN20 Simulator Profiles

Carista carries canned VAGCAN20 responses in `libCarista.so`. These are not this exact car, but they reveal the metadata shape Carista expects.

### Profile 2

Identity: `1A9B=Z.1K0937049S  .704..........Bordnetz-SG 1.0 H30 ; 1A91=Z..1K0937049S *.063.26.; 22F187=.".; 22F191=.".; 22F197=.".`

Notes: has positive 1A9B ECU-info coding metadata; has KWP-style 1A9A long-coding sample; has 31B80000 compact coding-address list

Coding source:

```text
1A9A -> 5A9A000000000000B03730341012EC8F8F2600041800001400001400000000FF
```

`31B80000` coding-address shorts:

```text
0103 0104 0106 0108 0102 0107
```

Positive `1A9B` ECU-info coding metadata:

| Field | Value |
|---|---|
| Part number payload | `1K0937049S` |
| RawAddress4 | `B0373034` |
| Coding selector byte | `10` |
| Carista coding type | `3` |
| Tail | `<empty>` |
| Stored value6 | `000000000000` |
| Writer suffix | `0301FF` |

### Profile 6

Identity: `1A9B=...; 22F187=b..5C0937087E ; 22F191=b..5C0937087A ; 22F197=b..BCM25 JLB H3 `

Notes: has direct UDS-style 220600 coding sample; has 31B80000 compact coding-address list

Coding source:

```text
220600 -> 6206007B994BB808AB0B0000382000240884CD00C2502E60000000300000000000
```

`31B80000` coding-address shorts:

```text
0106 0102 0103 0107 0108 0114
```

## Tuple Proof Result

The important correction from this pass is that `31B80000` is not the parser that fills the final `WriteVagCodingCommand` rawAddress4 vector. It is an ECU-list/coding-address-short query. The final tuple metadata comes from positive `1A9B` / `5A9B` ECU-info parsing.

The static proof now supports these field origins:

```text
3B9A prefix        -> WriteVagCodingCommand::getRequest literal
6-byte value       -> writer input value vector; for this car, derived from the two 6-byte coding chunks
4-byte rawAddress4 -> positive 1A9B payload[0x0c:0x10] after stripping 5A9B
coding selector    -> positive 1A9B payload[0x10]
type-2/type-4 tail -> positive 1A9B payload[0x11:0x14] when that selector branch is used
type-3 suffix      -> 0301FF when the selector is 0x10 / coding type 3 with empty tail
```

The embedded 1K0937049S-style simulator proves the parser with real bytes: `5A9B...` decodes to rawAddress4 `B0373034`, selector `10`, coding type `3`, empty tail, and suffix `0301FF`. That is proof of Carista's tuple construction, not proof that `6R0937087K` uses the same rawAddress4.

For the actual Polo BCM evidence in this workspace, only the value vectors are proven:

| Label | Proven value6 | Complete tuple status |
|---|---:|---|
| `base-fog` | `6C680ED000C8` | incomplete: missing actual positive-1A9B rawAddress4/coding selector/tail |
| `turn-signal` | `412F60A60000` | incomplete: missing actual positive-1A9B rawAddress4/coding selector/tail |

The earlier `31B8`-derived full requests are therefore retained only as rejected proof attempts:

| Label | Value6 | Raw short | RawAddress4 hypothesis | Coding type | Request | Status |
|---|---:|---:|---:|---:|---|---|
| `base-fog` | `6C680ED000C8` | `0106` | `00000106` | 3 | `3B9A6C680ED000C8000001060301FF` | unproven |
| `turn-signal` | `412F60A60000` | `0106` | `00000106` | 3 | `3B9A412F60A60000000001060301FF` | unproven |
| `base-fog` | `6C680ED000C8` | `0106` | `00200106` | 3 | `3B9A6C680ED000C8002001060301FF` | unproven |
| `turn-signal` | `412F60A60000` | `0106` | `00200106` | 3 | `3B9A412F60A60000002001060301FF` | unproven |

## Current Boundary

The deeper static pass proves the tuple parser and rejects `31B8 short -> rawAddress4` as a sufficient proof chain. The actual `6R0937087K` complete tuple cannot be proven from the current offline evidence because the workspace does not contain a positive `1A9B` / `5A9B` ECU-info response for that ECU.

Still not proven offline:

```text
actual 6R0937087K rawAddress4 from positive 1A9B payload[0x0c:0x10]
actual 6R0937087K coding selector from positive 1A9B payload[0x10]
actual tail if the selector is a type-2/type-4 branch
whether both byte-12 and byte-21 chunks share the same rawAddress4/tail
required live precondition/session before 3B9A is accepted
```

So do not execute the `00200106` / `00000106` requests. The next non-phone proof step is a read-only in-car capture of a positive `1A9B`; once that exists, the tuple bytes can be filled deterministically from the offsets above.

