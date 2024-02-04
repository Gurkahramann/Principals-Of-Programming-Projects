#include "BUretim.h"
#include "Uretim.h"
#include "stdlib.h"
Uretim *new_BUretim(void) {
    Uretim *this = (Uretim *)malloc(sizeof(Uretim));
     this->Uret = &BUret_strategy; // AUretim için üretim stratejisini ayarla
    return this;
}
int BUret_strategy(Uretim *this) {
    //srand(time(NULL)); // Rastgele sayı üretimi için tohum değeri ayarla
    return rand() % 10 + 1; // 1 ile 10 arasında rastgele bir sayı döndür
}