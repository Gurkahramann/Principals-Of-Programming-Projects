#ifndef BTAKTIK_H
#define BTAKTIK_H

#include "Taktik.h"
typedef struct {
    Taktik base; // Taktik yapısını kalıtım alır
} TaktikB;

TaktikB* new_BTaktik();
int B_Savas();
#endif