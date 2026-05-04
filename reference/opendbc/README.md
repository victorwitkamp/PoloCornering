# openDBC Volkswagen PQ Reference

Downloaded on 2026-05-01 from `https://github.com/commaai/opendbc`.

Files retained here:

- `LICENSE`
- `opendbc__dbc__vw_pq.dbc`
- `opendbc__car__volkswagen__carstate.py`
- `opendbc__car__volkswagen__values.py`
- `opendbc__safety__modes__volkswagen_pq.h`

The debugging tools do not require the full openDBC package. The retained DBC
was mined into `obd-on-pc/pq25_can_reference.py` for focused raw-CAN annotation
and is also parsed directly by `obd-on-pc/dbc_signal_decoder.py` so the analyzer
can generate decoded `_raw_signal_deltas.csv` reports.

Most important light-debug hit: `vw_pq.dbc` message `Gate_Komf_1` at CAN header
`390` includes `GK1_Blinker_li`, `GK1_Blinker_re`, `GK1_Abblendlicht`,
`GK1_Fernlicht`, `GK1_Nebel_ein`, `GK1_Rueckfahr`, and `GK1_Bremslicht`.