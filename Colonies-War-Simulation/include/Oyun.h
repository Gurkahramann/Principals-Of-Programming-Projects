#ifndef OYUN_H
#define OYUN_H

#include "Koloni.h"
void simulate_turn(KoloniNode *head);
int remaining_colonies(KoloniNode *head);
void free_colony_list(KoloniNode *head);
void print_colony_list(KoloniNode *head);
int checkColonies(KoloniNode* head);
void apply_battle_results(KoloniNode *attacker, KoloniNode *defender, int result);
#endif
