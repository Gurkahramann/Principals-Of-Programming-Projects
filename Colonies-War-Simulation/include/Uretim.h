#ifndef Uretim_H
#define Uretim_H
#include "Koloni.h"
struct Uretim {
    int (*Uret)(struct KOLONI* koloni);
    int uretim;
};
typedef struct Uretim Uretim;
int Uret(struct KOLONI* koloni);
#endif