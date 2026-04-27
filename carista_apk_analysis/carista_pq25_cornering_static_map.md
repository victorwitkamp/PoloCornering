# Carista PQ25 Cornering Static Map

This is an offline-only map. No phone trace was used.

## Current Coding Boundary

```text
current     3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
known-good  3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
delta       byte 12 bit 6 clear -> set; byte 21 bit 2 clear -> set
```

## Carista Resource Keys

| Key | English label | Resource id | Native string VA | Direct native xrefs |
|---|---|---:|---:|---|
| `car_setting_cornerig_lights_with_turn_signal` | Activate cornering lights with turn signal | `0x7f1407f0` | `0x006984AE` | <none found> |
| `car_setting_cornering_lights` | Cornering lights | `0x7f1407f1` | `0x008E8CBA` | <none found> |
| `car_setting_cornering_lights_activation` | Cornering lights activation | `0x7f1407f2` | `0x00BBC3CE` | <none found> |
| `car_setting_cornering_lights_via` | Cornering lights use… | `0x7f140801` | `0x00A1B890` | <none found> |
| `car_setting_cornering_lights_via_fogs` | Cornering lights (using fog lights) | `0x7f140802` | `0x00B3F397` | <none found> |
| `car_setting_cornering_lights_via_fogs_experimental` | Cornering lights (using fog lights) (experimental) | `0x7f140803` | `0x008E06F6` | <none found> |
| `car_setting_cornering_lights_via_fogs_left` | Left cornering light (using fog light) | `0x7f140804` | `0x00ADA817` | <none found> |
| `car_setting_cornering_lights_via_fogs_right` | Right cornering light (using fog light) | `0x7f140805` | `0x00ADA842` | <none found> |
| `car_setting_cornering_lights_with_turn_signals` | Turn on cornering lights when turn signal is on | `0x7f140808` | `0x00A1B8B1` | <none found> |
| `car_setting_cornering_lights_with_turn_signals_one_touch` | Turn on cornering lights when one-touch turn signal is on | `0x7f140809` | `0x0081F251` | <none found> |
| `car_setting_use_cornering_lights` | Use cornering lights… | `0x7f1411be` | `0x007FD355` | <none found> |
| `car_setting_instruction_activate_cornering_lights` | Note to enable the cornering lights, activate \"Use fog lights when…\", \"Use the left fog light as…\", and \"Use the right fog light as…\", and set all three to either \"Cornering lights\" or \"Use DRL via fog and cornering lights\". | `0x7f140ab4` | `0x0091EC04` | <none found> |
| `car_setting_instruction_requires_cornering_lights` | To use this setting, enable the cornering lights. | `0x7f140b33` | `0x00871EFC` | <none found> |

## Practical Mapping Candidates

| Carista key | BCM byte/bit | Current | Known-good | Confidence | Basis |
|---|---|---|---|---|---|
| `car_setting_cornering_lights_via_fogs` | byte 12 bit 6 | clear | set | high practical / medium static | The UI label is the exact fog-light cornering wording, and the only working/non-working coding delta for that function is byte 12 bit 6. Static native analysis has not yet recovered the concrete Setting object. |
| `car_setting_cornering_lights_via_fogs_experimental` | byte 12 bit 6 | clear | set | medium | Likely older/alternate Carista key for the same fog-light cornering function. |
| `car_setting_use_cornering_lights` | byte 12 bit 6 | clear | set | medium | High-level selector wording; may be a parent/multiple-choice setting rather than the direct bit. |
| `car_setting_cornerig_lights_with_turn_signal` | byte 21 bit 2 | clear | set | high practical / medium static | This typo-preserved key says 'Activate cornering lights with turn signal'; the known working delta for turn-signal-triggered cornering is byte 21 bit 2. |
| `car_setting_cornering_lights_with_turn_signals` | byte 21 bit 2 | clear | set | high practical / medium static | Clear newer key for the same turn-signal-triggered cornering behavior. |
| `car_setting_cornering_lights` | <not mapped> |  |  | group label | Likely category/umbrella label, not enough evidence for one direct byte/bit. |
| `car_setting_cornering_lights_via_fogs_left` | <not mapped> |  |  | unknown for this BCM | May apply to newer or per-side lamp-channel platforms; no observed distinct delta on this Polo coding. |
| `car_setting_cornering_lights_via_fogs_right` | <not mapped> |  |  | unknown for this BCM | May apply to newer or per-side lamp-channel platforms; no observed distinct delta on this Polo coding. |

## Static Boundary

The native library contains the relevant Carista resource keys, but this static pass did not find simple direct code xrefs from those keys into `VagCanSettings::getSettings`. That means the remaining exact bridge is still:

```text
resource key -> native Setting catalog entry -> insertValue value bytes -> 3B9A write tuple
```

Without a phone trace, the strongest safe conclusion is the practical byte/bit mapping above, not the exact Carista 6-byte value/raw-address write tuple.
