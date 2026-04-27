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
  byte 13 bit 6 = CH/LH fog-vs-low-beam selector, but conflicts with observed Carista UI
  byte 13 bits 0/1/3 = parking-light behavior group
  byte 21 bit 7 = fog-related capability/install bit, exact label uncertain
  byte 22 bit 5 = probable ADL-related bit

unknown:
  all other bits until proven by VCDS UI, Carista trace, or controlled coding deltas
```

For the next car read, the settings report should be treated as an evidence
view, not a complete VCDS clone.
