;
; Candidate-only LCode file for VW Polo 6R / PQ25 BCM unit 09.
;
; Target controller confirmed by supplied working coding:
; Part #: 6R0937087K
; Component: BCM PQ25 H+4
; Software version: 0254
;
; This is not an extracted Ross-Tech 6R0-937-08x CLB conversion.
; It only contains the byte/bit candidates that match the current
; PQ25 research and the supplied long-coding string where cornering
; lights were known to work again.
;
; Zero-based byte numbering, matching VCDS/LCode conventions.
;
;---------------------------------------------------
;
; long coding
;
;---------------------------------------------------
;
;
; Higher-confidence bits.
LC,12,6,[high] Base fog-light cornering function
LC,21,2,[high] Turn-signal-triggered cornering assist
;
; Medium-confidence bits and groups.
LC,13,6,[medium] Coming/Leaving Home fog-vs-low-beam selector (docs disagree with Carista UI)
LC,13,0,[medium] Parking-light behavior group member
LC,13,1,[medium] Parking-light behavior group member
LC,13,3,[medium] Parking-light behavior group member
LC,21,7,[medium] Fog-related capability/install bit; exact meaning uncertain
LC,22,5,[medium] Probable ADL-related bit
;
