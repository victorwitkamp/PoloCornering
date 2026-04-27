# Carista Supported Settings Map

Date: 2026-04-27

This is an offline map from the decoded Android resources and `libCarista.so` strings.
It is not a live vehicle availability dump; Carista decides actual support at runtime through native checks.

## Summary

- App resource settings: `3669`
- Also present as native strings: `3619`
- Lighting-related resource settings: `742`
- PQ25 BCM settings mapped with practical confidence: `9`

Full searchable outputs:

```text
carista_supported_settings_map.csv
carista_supported_settings_map.json
```

## Category Counts

| Category | Count |
|---|---:|
| `app_catalog` | 1636 |
| `locking` | 363 |
| `lighting_general` | 353 |
| `comfort` | 283 |
| `windows_mirrors` | 215 |
| `lighting_drl_adl` | 163 |
| `instrument_cluster` | 97 |
| `sound_chime` | 96 |
| `driver_assistance` | 93 |
| `lighting_coming_leaving_home` | 89 |
| `lighting_fog` | 67 |
| `engine_drivetrain` | 56 |
| `wipers` | 39 |
| `lighting_cornering` | 38 |
| `lighting_parking` | 32 |
| `parking_assist` | 29 |
| `service_tpms` | 20 |

## PQ25 BCM Mapped Settings

These rows are the current useful map for BCM `6R0937087K`. They identify what the setting means in the long coding, but they do not yet contain the complete Carista write tuple.

| Key | Label | PQ25 mapping | Current | Target | Value chunk | Status |
|---|---|---|---|---|---|---|
| `car_setting_assist_dr_lights` | Assistant Driving Light (ADL) | byte 22 bit 5 | clear | clear | - | mapped location only; not a pending write target |
| `car_setting_coming_home_via_fogs` | Use fog lights as coming-home lights | byte 13 bit 6 | set | set | - | mapped location only; not a pending write target |
| `car_setting_coming_home_via_low_beams` | Use low beams as coming-home lights | byte 13 bit 6 | set | set | - | mapped location only; not a pending write target |
| `car_setting_coming_leaving_home_output` | Coming/leaving-home lights use… | byte 13 bit 6 | set | set | - | mapped location only; not a pending write target |
| `car_setting_cornerig_lights_with_turn_signal` | Activate cornering lights with turn signal | byte 21 bit 2 | clear | set | `412F60A60000` | candidate value chunk known; rawAddress4/coding tail unknown |
| `car_setting_cornering_lights_via_fogs` | Cornering lights (using fog lights) | byte 12 bit 6 | clear | set | `6C680ED000C8` | candidate value chunk known; rawAddress4/coding tail unknown |
| `car_setting_cornering_lights_via_fogs_experimental` | Cornering lights (using fog lights) (experimental) | byte 12 bit 6 | clear | set | `6C680ED000C8` | candidate value chunk known; rawAddress4/coding tail unknown |
| `car_setting_cornering_lights_with_turn_signals` | Turn on cornering lights when turn signal is on | byte 21 bit 2 | clear | set | `412F60A60000` | candidate value chunk known; rawAddress4/coding tail unknown |
| `car_setting_use_cornering_lights` | Use cornering lights… | byte 12 bit 6 | clear | set | `6C680ED000C8` | candidate value chunk known; rawAddress4/coding tail unknown |

## Current Tuple Boundary

The Carista write shape is known:

```text
3B9A + 6-byte value + 4-byte rawAddress + coding-type-dependent tail
```

For the two cornering fixes, the likely 6-byte target values are:

```text
byte 12 bit 6 / base fog-cornering: 6C680ED000C8
byte 21 bit 2 / turn-signal trigger: 412F60A60000
```

Still unknown for the final write tuple:

- `raw_value_key`
- `raw_address4`
- `coding_type`
- `tail_bytes`

## Useful Search Examples

```powershell
Import-Csv .\carista_supported_settings_map.csv | Where-Object category -like 'lighting*' | Format-Table key,label,pq25_location
Import-Csv .\carista_supported_settings_map.csv | Where-Object key -like '*cornering*' | Format-Table key,label,pq25_location,target_value6
Import-Csv .\carista_supported_settings_map.csv | Where-Object native_string_found -eq 'True' | Measure-Object
```
