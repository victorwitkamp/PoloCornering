;
; Candidate-only LCode file for VW Polo 6R / PQ25 BCM unit 09.
;
; Target controller from live reads and supplied/reference coding:
; Part #: 6R0937087K
; Component: BCM PQ25 H+4
; Software version: 0254
;
; This is not an extracted Ross-Tech 6R0-937-08x CLB conversion.
; It only contains byte/bit candidates that match current PQ25
; research, Carista labels, and external Polo 6R long-coding labels.
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
LC,12,6,[high] Turn/Cornering Lights installed/active; Carista maps this to cornering lights using fog lights
LC,21,2,[high] Cornering/Turn Lights via Turn Signal active; Carista maps this to turn-signal-triggered cornering
;
; Medium-confidence bits and groups.
LC,13,0,[medium] Parking Lights ON only without ignition ON possible
LC,13,1,[medium] Parking Lights Function active
LC,13,3,[medium] Brake Light Activation via Body Control Module (BCM)
LC,13,5,[medium] Interior Light Enabling via Rear Lid
LC,13,6,[medium] Coming-Home/Leaving-Home variant; external labels say 0=fog lights, 1=low beam
LC,21,5,[medium] Fog Lights inactive with High Beams active
LC,21,7,[medium] Front Fog Lights with Turn Lights installed
LC,22,5,[medium] Assistant Driving Light (ADL) active
;
; Lower-confidence fog/diagnostic reference. Useful context, not a functional enable.
LC,16,5,[low] Lamp Diagnostics for Rear Fog Light(s) active
LC,19,5,[low] Lamp Diagnostics for Fog Lights and/or Cornering/Turn Lights active
;
