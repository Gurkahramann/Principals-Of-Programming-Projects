#include "AUretim.h"
#include "Uretim.h"
#include "stdlib.h"
Uretim *new_AUretim(void) {
    Uretim *this = (Uretim *)malloc(sizeof(Uretim));
     this->Uret = &AUret_strategy; // AUretim için üretim stratejisini ayarla
    return this;
}
int AUret_strategy(Uretim *this) {
    return rand() % 10 + 1; // 1 ile 10 arasında rastgele bir sayı döndür
}