# Carista Android APK Analysis Notes

Purpose: extract read-only diagnostic clues from the Android Carista app for a VW Polo 6R / PQ25 BCM unit 09 cornering-light investigation.

## Acquisition

- Source checked: APKPure `com.prizmos.carista` Carista OBD2 download page.
- Downloaded bundle: `Carista_OBD2_9.8.2_APKPure.xapk`
- Package: `com.prizmos.carista`
- Version: `9.8.2` / `982099`
- XAPK SHA-256: `0973F6DD33E1B3B815F278E7301355DD754698531E06EF40C00A18F317585188`
- APKMirror was also checked, but direct binary download returned HTTP 403.
- ADB was installed locally, but the connected phone was not visible to `adb devices`; MTP did not expose an APK/APKM/XAPK file.

Extracted bundle contents were:

- `xapk_extracted/com.prizmos.carista.apk`
- `xapk_extracted/config.arm64_v8a.apk`
- `xapk_extracted/config.mdpi.apk`
- Native library of interest: `arm64_apk/lib/arm64-v8a/libCarista.so`

Those raw extracted files were deleted during cleanup after the useful findings
were summarized.

## Method

1. Extracted the XAPK with `tar.exe`.
2. Extracted the base APK and arm64 split APK.
3. Extracted printable strings from:
   - `base_apk/classes.dex`
   - `base_apk/classes2.dex`
   - `arm64_apk/lib/arm64-v8a/libCarista.so`
4. Searched for VAG, PQ25/PQ26, central electrics, TP2.0, UDS, BCM, fog, and cornering-light identifiers.

Generated evidence files were:

- `strings/libCarista_strings.txt`
- `strings/classes_dex_strings.txt`
- `strings/classes2_dex_strings.txt`
- `carista_ecu_70e_strings.txt`
- `carista_tp20_candidate_strings.txt`
- `carista_cornering_relevant_strings.txt`
- `carista_target_string_matches.txt`
- `carista_tp20_research_update.md`

The full string dumps and broad match files were deleted because they contained
mostly unrelated Android/app symbols. The retained compact evidence is:

- `carista_relevant_evidence.md`
- `carista_tp20_research_update.md`

## High-Confidence Findings

Most of Carista's vehicle diagnostic logic is in `libCarista.so`, not plain Java/Kotlin.

The native library contains Volkswagen/PQ central-electrics support, including symbols for:

- `VagCanCommunicator`
- `Tp20EcuSimulator`
- `GetVagCanEcuInfoCommand`
- `ReadVagCanShortAdaptationDataCommand`
- `ReadVagCanLongAdaptationDataCommand`
- `VagCanShortAdaptationSetting`
- `VagCanLongAdaptationSetting`
- `VagCanLongCodingSetting`
- `VagWhitelists::CENTRAL_ELEC_6R`
- `VagWhitelists::CENTRAL_ELEC_6RU`
- `VagWhitelists::CENTRAL_ELEC_6R_5C_7E_7H`
- `VagWhitelists::CENTRAL_ELEC_6R_EXCEPT_6RU`

This strongly supports the earlier conclusion that your PQ25 BCM/unit 09 path is Carista's `VAGCAN20` / TP2.0 path, not the newer UDS `70E` path.

## Native TP2.0 Disassembly Update

Additional disassembly of `VagCanCommunicator` found that Carista opens the same TP2.0 unit `20` channel we already opened live, then sends this channel parameter setup:

```text
A00194FF82FF
```

The live script has been updated to try that before the older experimental payload.

Carista's TP2.0 parser treats:

```text
A3 = keep-alive, ignored
A8 = channel disconnected
B? = ACK
9? = NACK
```

This means the recurring live `300A8` frame is a channel disconnect, not a normal empty response.

Carista's ACK helper sends `B0 | ((seq + 1) & 0x0F)`, so `B1` is the ACK for a response data frame with sequence `0`.

The exported request builders show:

```text
1A9B = ECU/component info
1A9F = ECU list/info
1A9A = long coding
```

The adaptation/routine path appears to use:

```text
31B8 + id
32B8 + id
31BA + id
31B9 + id + byte
```

Those remain blocked in our scripted runs because they start with `31` or are write-oriented.

## UDS 70E Cornering-Light Evidence

Carista contains UDS simulator responses for central electrics at `70E`. This is useful context, but your live Polo did not answer on `70E->778`, so this is likely MQB/PQ26-style data rather than your active route.

Relevant Carista simulator examples:

- `ECU 70E 220250` includes supported identifiers `055C` and `055D`.
- `ECU 70E 22055C: 62055C2038002212167F000000000000000000`
- `ECU 70E 22055D: 62055D2042002313177F000000000000000000`

Inference:

- `055C` is a left-side light adaptation/coding record.
- `055D` is a right-side light adaptation/coding record.
- The values `16` and `17` appear in the sample payloads and match the earlier hypothesis that these encode left/right cornering-light functions on newer UDS BCMs.
- This explains why probing `22055C` and `22055D` was a reasonable test, but the live car returning no data means we need the PQ25 TP2.0 path.

## PQ25 / TP2.0 VAGCAN20 Evidence

Carista's native strings contain simulator data for `ECU VAGCAN20`, matching the TP2.0 unit address `20` that we already opened successfully on the car.

Important simulator examples:

- `ECU VAGCAN20 1A9B: 5A9B314B30393337303439532020B037303410000000000000000000426F72646E65747A2D534720312E302048333020`
- `ECU VAGCAN20 1A91: 5A910D314B3039333730343953202A04303633033236FF`
- `ECU VAGCAN20 1A9A: 5A9A000000000000B03730341012EC8F8F2600041800001400001400000000FF`
- `ECU VAGCAN20 1A86: 5A860F3030303030303031313032373039204256422D39303632322E30392E303430304833303030303037303431343031FF`

Another `VAGCAN20` profile also shows UDS-style reads over the same VAG CAN abstraction:

- `ECU VAGCAN20 220600: 6206007B994BB808AB0B0000382000240884CD00C2502E60000000300000000000`
- `ECU VAGCAN20 220601: 6206011E`
- `ECU VAGCAN20 220606: 620606001800038000`
- `ECU VAGCAN20 22F187: 62F1873543303933373038374520`
- `ECU VAGCAN20 22F191: 62F1913543303933373038374120`
- `ECU VAGCAN20 22F197: 62F19742434D3235204A4C4220483320`
- `ECU VAGCAN20 22F1A3: 62F1A3483636`
- `ECU VAGCAN20 22F1A5: 62F1A5000000000042`
- `ECU VAGCAN20 22F1AA: 62F1AA4A35313920`
- `ECU VAGCAN20 22F1DF: 62F1DF40`

The simulator also contains short adaptation examples:

- `ECU VAGCAN20 ADAPT01: 0000`
- `ECU VAGCAN20 ADAPT14: 0001`
- `ECU VAGCAN20 ADAPT16: 0000`
- `ECU VAGCAN20 ADAPT17: 0001`
- `ECU VAGCAN20 ADAPT18: 0000`
- `ECU VAGCAN20 ADAPT19: 0000`
- `ECU VAGCAN20 ADAPT22: 001E`
- `ECU VAGCAN20 ADAPT25: 0050`
- `ECU VAGCAN20 ADAPT2B: 0003`
- `ECU VAGCAN20 ADAPT2F: 000F`
- `ECU VAGCAN20 ADAPT30: 000F`

`ADAPTxx` is a simulator label, not necessarily the raw command to send. Carista has `ReadVagCanShortAdaptationDataCommand`, so the next reverse-engineering step would be finding how it translates an adaptation channel number into the actual TP2.0/KWP request.

## Current Interpretation

Carista likely does this for PQ25 unit 09:

1. Opens TP2.0 channel to unit address `20`.
2. Establishes a diagnostic session.
3. Reads ECU identity and coding with KWP-style reads such as `1A9B`, `1A91`, `1A9A`, and `1A86`.
4. Selects one of its `CENTRAL_ELEC_6R...` whitelists from the returned part number/component data.
5. Reads short/long adaptation or coding records through `ReadVagCanShortAdaptationDataCommand` / `ReadVagCanLongAdaptationDataCommand`.
6. For newer BCM profiles, it may also try UDS-style `22xxxx` reads through the same VAG CAN abstraction.

This supports continuing the live TP2.0 sequencing experiments. The commands we tried were plausible; the failure is more likely channel/session/ACK/timing than the unit address being wrong.

## Read-Only Next Probes

Keep every attempt isolated with adapter reset and a fresh TP2.0 channel open to unit `20`.

Prioritize these read-only KWP-style reads after a positive session:

- `1A9B`
- `1A91`
- `1A9A`
- `1A86`

Then try these read-only UDS-style reads through the same TP2.0 channel:

- `220600`
- `220601`
- `220606`
- `22F187`
- `22F191`
- `22F197`
- `22F1A3`
- `22F1A5`
- `22F1AA`
- `22F1DF`

Do not send these in scripted mode:

- `27...`
- `2E...`
- `31...`
- `3B...`

Note: `31B80000` appears in the Carista simulator, but it is a routine-control command and remains blocked.
