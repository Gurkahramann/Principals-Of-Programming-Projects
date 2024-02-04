#ifndef Koloni_H
#define Koloni_H
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include  "Taktik.h"
#include "string.h"
typedef struct Taktik Taktik;
typedef struct Uretim Uretim;
struct KOLONI {
    int data;
    int population;
    int food;
    int wins;
    int losses;
    int diff;
    char symbol;
    int food_stock; 
    Taktik *taktik;
    Uretim *uretim;
    struct KOLONI* next;
    void (*printList)(struct KOLONI*);
    void (*insertToList)(struct KOLONI*);
    void (*freeList)(struct KOLONI*);
    void (*production)(struct KOLONI*);
    int (*battle)(struct KOLONI*,struct KOLONI*);
    int (*isNumber)(const char*);
};
typedef struct KOLONI* Koloni;

struct KoloniNode {
    Koloni Koloni;
    struct KoloniNode* next;
    void (*reverseList)(struct KoloniNode**);

};

typedef struct KoloniNode KoloniNode;
Koloni new_Koloni(int data,char symbol,Taktik* taktik);
KoloniNode* createNode(int value);
int is_Number(const char* str);
void freeList(struct KOLONI* head);
void production(KoloniNode* head);
void printList(struct KOLONI* head);
void insertToList(KoloniNode** list, int value,Taktik* taktik);
int battle(KoloniNode *current_node,KoloniNode *opponent_node);
void reverseList(KoloniNode** list);
#endif