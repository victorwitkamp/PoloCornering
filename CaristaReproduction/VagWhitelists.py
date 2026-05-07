from __future__ import annotations

from .StringWhitelist import StringWhitelist


CENTRAL_ELEC_6RU_LOW = StringWhitelist(
    ("6RU937084*", "6RU937085*", "6RU937086*"),
    (
        "Play 9.8.3 x86 init window 0x01479743..0x014797d0 builds three libc++ SSO strings before storing VagWhitelists::CENTRAL_ELEC_6RU_LOW.",
    ),
)

CENTRAL_ELEC_6RU_HIGH = StringWhitelist(
    ("6RU937087*", "6RU937088*", "6RU937089*", "6RU937090*"),
    (
        "Play 9.8.3 x86 init window 0x01479970..0x01479a15 builds four libc++ SSO strings before storing VagWhitelists::CENTRAL_ELEC_6RU_HIGH.",
    ),
)

CENTRAL_ELEC_6RU = CENTRAL_ELEC_6RU_LOW.combinedItems(CENTRAL_ELEC_6RU_HIGH)

CENTRAL_ELEC_6R_EXCEPT_6RU = StringWhitelist(
    ("6R093708*", "6R793708*"),
    (
        "Play 9.8.3 x86 init window 0x01479bf6..0x01479c92 builds 6R093708* and 6R793708* before storing VagWhitelists::CENTRAL_ELEC_6R_EXCEPT_6RU.",
    ),
)

CENTRAL_ELEC_6R = CENTRAL_ELEC_6RU.combinedItems(CENTRAL_ELEC_6R_EXCEPT_6RU)

CENTRAL_ELEC_5C = StringWhitelist(
    ("5C093708*", "5C593708*"),
    (
        "Play 9.8.3 x86 init window 0x01479e81..0x01479f23 builds 5C093708* and 5C593708* before storing VagWhitelists::CENTRAL_ELEC_5C.",
    ),
)

CENTRAL_ELEC_7H = StringWhitelist(
    ("7H093708*", "7H0937090*"),
    (
        "Play 9.8.3 x86 init window 0x01479fcc..0x0147a075 builds 7H093708* and 7H0937090* before storing VagWhitelists::CENTRAL_ELEC_7H.",
    ),
)

CENTRAL_ELEC_7E = StringWhitelist(
    ("7E093708*", "7E0937090*", "7E0937189*", "7E0937190*"),
    (
        "Play 9.8.3 x86 init window 0x0147a12c..0x0147a1d7 builds four 7E central-electrics patterns before storing VagWhitelists::CENTRAL_ELEC_7E.",
    ),
)

CENTRAL_ELEC_5C_7E_7H = CENTRAL_ELEC_5C.combinedItems(CENTRAL_ELEC_7H, CENTRAL_ELEC_7E)

CENTRAL_ELEC_6R_5C_7E_7H = CENTRAL_ELEC_6R.combinedItems(CENTRAL_ELEC_5C_7E_7H)

CENTRAL_ELEC_1S = StringWhitelist(
    ("1S0937086*", "1S0937087*", "1S0937090*"),
    (
        "Play 9.8.3 x86 init window 0x0147a632..0x0147a6b9 builds three 1S central-electrics patterns before storing VagWhitelists::CENTRAL_ELEC_1S.",
    ),
)

CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S = CENTRAL_ELEC_6R_5C_7E_7H.combinedItems(CENTRAL_ELEC_1S)