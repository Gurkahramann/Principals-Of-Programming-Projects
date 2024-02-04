#include "Taktik.h"

Taktik *new_Taktik(int (*Savas)(struct KOLONI *, struct KOLONI *)) {
    Taktik *this = (Taktik *)malloc(sizeof(Taktik));
    this->Savas = Savas;
    return this;
}

