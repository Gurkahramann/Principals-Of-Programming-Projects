#include "ATaktik.h"
#include "Taktik.h"
TaktikA* new_ATaktik() {
    TaktikA* taktikA = malloc(sizeof(TaktikA));
    taktikA->base.Savas = &A_Savas;
    return taktikA;
}
int A_Savas() {
    // A taktiği için savaş fonksiyonunu burada tanımlayın
    // 0-1000 arası rastgele bir değer döndürün
    return rand() % 1001;
}
