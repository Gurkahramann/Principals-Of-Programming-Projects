#ifndef Taktik_H
#define Taktik_H

#include <stdlib.h>
#include "Koloni.h"

typedef struct Taktik {
    int (*Savas)(struct KOLONI* attacker, struct KOLONI* defender);
} Taktik;

Taktik *new_Taktik(int (*Savas)(struct KOLONI*, struct KOLONI*));

#endif

