#include "BTaktik.h"
#include "Taktik.h"
TaktikB* new_BTaktik() {
    TaktikB* taktikB = malloc(sizeof(TaktikB));
    taktikB->base.Savas = &B_Savas;
    return taktikB;
}
int B_Savas() {
    // A taktiği için savaş fonksiyonunu burada tanımlayın
    // 0-1000 arası rastgele bir değer döndürün
    return rand() % 1001;
}