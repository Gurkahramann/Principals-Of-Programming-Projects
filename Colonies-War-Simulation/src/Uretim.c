#include "Uretim.h"
Uretim new_Uretim() {
    Uretim this;
    this.uretim = (struct Uretim*)malloc(sizeof(struct Uretim));
    this.Uret = &Uret;
    return this;
}
int Uret(struct KOLONI* koloni) {
    int producedFood = rand() % 10 + 1;
    return producedFood;
}