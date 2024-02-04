#ifndef ATAKTIK_H
#define ATAKTIK_H

#include "Taktik.h"

typedef struct {
    Taktik base; // Taktik yapısını kalıtım alır
} TaktikA;

TaktikA* new_ATaktik();
int A_Savas();
#endif