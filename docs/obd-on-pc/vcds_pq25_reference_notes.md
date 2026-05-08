# VCDS PQ25 Reference Notes

Date: 2026-04-27

## Relevant VCDS Files

The extracted VCDS release is currently here:

```text
C:\Users\victo\Downloads\VCDS-Release-26.3.0-Installer
```

The useful redirect file is:

```text
C:\Users\victo\Downloads\VCDS-Release-26.3.0-Installer\Labels\6R-09.lbl
```

It confirms that Polo 6R central electronics unit 09 controllers in the
`6R0-937-08x` family use the shared label file:

```text
6R0-937-08x-09.CLB
```

The relevant redirect line for this BCM family is:

```text
REDIRECT,6R0-937-08x-09.CLB,6R0-937-087-???   ; High+
```

This matches the investigated controller:

```text
Part:      6R0937087K
Component: BCM PQ25 H+4
Software:  0254
```

## Boundary

The actual long-coding labels for this controller are inside:

```text
C:\Users\victo\Downloads\VCDS-Release-26.3.0-Installer\Labels\6R0-937-08x-09.CLB
```

That file is a binary/encrypted VCDS CLB file, not a plaintext `LBL` file. It
cannot be parsed by simple text search, and the extracted installer does not
expose the long-coding bit labels as readable `LC,...` rows.

## Practical Result

VCDS confirms we are looking at the right PQ25 label family, but it did not add
a full offline bit map. The current project decoder therefore stays conservative:

```text
known high-confidence:
  byte 12 bit 6 = base fog-light cornering function
  byte 21 bit 2 = turn-signal-triggered cornering assist

known medium-confidence:
  byte 12 bit 0 = Scandinavian/Nordic parking lights ON with terminal 15 ON;
                  set in the latest 2026-05-08 captured coding; role impact uncertain
  byte 13 bit 6 = CH/LH fog-vs-low-beam selector, but conflicts with observed Carista UI
  byte 13 bits 0/1/3 = parking-light behavior group
  byte 21 bit 7 = fog-related capability/install bit, exact label uncertain
  byte 22 bit 5 = probable ADL-related bit

unknown:
  all other bits until proven by VCDS UI, Carista trace, or controlled coding deltas
```

For the next car read, the settings report should be treated as an evidence
view, not a complete VCDS clone.

## Fog Lamp Role Variants

Polo 6R lower front lamps are not a single universal electrical role. Current
external parts evidence shows at least these relevant variants:

```text
6R0 941 061 C / 062 C: H8, front fog + static cornering, without DRL
6R0 941 061 F / 062 F: H8, front fog + static cornering, without DRL
6R0 941 061 E / 062 E: H8 + P21W, front fog + static cornering + DRL
```

The user's one-bulb fog lamps should therefore be treated as a shared H8 output
that can serve front-fog and static-cornering roles, but not as the R-Line/GTI
two-bulb fog+DRL assembly. This makes `drl_via_fogs` and byte 12 bit 0 useful
context, but not direct proof of a correct cornering role. If the same H8 bulb
is already on as a paired front-fog/DRL/parking request, a per-side cornering
command may have no visible effect.

The 2026-05-07 live DRL-via-fogs test did not fix the visible behavior, so
`drl_via_fogs` should now be treated as behavior-disproven for this symptom. For
this one-bulb H8 car, the safest known coding is the previous expert backup:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

That is a restore target, not a proven explanation of why the H8 output is
currently being held in the wrong visible role.

Reference links:

```text
https://catalog.polo.blue/6R0941061C/
https://catalog.polo.blue/6R0941061E/
https://catalog.polo.blue/6R0941061F/
https://www.vwpolo.net/lights_and_vision_v_functions-129.html
```
