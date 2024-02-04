#include "Oyun.h"
#include <stdio.h>
#include <stdlib.h>
void simulate_turn(KoloniNode *head)
{
    KoloniNode *current_node = head;
    while (current_node != NULL) {
        production(head);
        current_node = current_node->next;
    }
    current_node = head;

    KoloniNode *opponent_node = current_node->next;
    while (opponent_node != NULL) {
        int resultControl = battle(current_node,opponent_node);
        if (resultControl == 1) {
            // current_node kazanır
            // Attacker kazanır
            int ratio = (int)current_node->Koloni->diff / 1000;
            // opponent_node->Koloni->population -= (int)(opponent_node->Koloni->population * ratio);
            current_node->Koloni->food_stock += (int)(opponent_node->Koloni->food_stock * ratio);
            opponent_node->Koloni->food_stock -= (int)(opponent_node->Koloni->food_stock * ratio);
            if (opponent_node->Koloni->population <= 0) {
                opponent_node->Koloni->population = 0;
            }
        } else if (resultControl == 2) {
            // Defender kazanır
            int ratio = (int)opponent_node->Koloni->diff / 1000;
            // current_node->Koloni->population -= (int)(current_node->Koloni->population * ratio);
            opponent_node->Koloni->food_stock += (int)(opponent_node->Koloni->food_stock * ratio);
            current_node->Koloni->food_stock -= (int)(current_node->Koloni->food_stock * ratio);
            // if (current_node->Koloni->population < 0) {
            //     current_node->Koloni->population = 0;
            // }   
        }

        opponent_node = opponent_node->next;
    }
    current_node = current_node->next;

    
}
int checkColonies(KoloniNode* head) {
    KoloniNode* current = head;
    int count = 0;
    
    while (current != NULL) {
        
        if (current->Koloni->population > 0 && current->Koloni->food_stock > 0) {
            count++;
        }
        
        current = current->next;
    }
    
    return count;
}

int remaining_colonies(KoloniNode *head) {
    int count = 0;
    KoloniNode *current_node = head;

    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }
  
    return count;
}
void print_colony_list(KoloniNode *head) {
    KoloniNode *current = head;
    printf("Koloni   Populasyon   Yemek Stogu    Kazanma   Kaybetme\n");
    while (current != NULL) {
        if (current->Koloni->population <= 0 || current->Koloni->food_stock<= 0) {
            
            printf("%c\t     --\t        --\t        --\t  --\n",current->Koloni->symbol);
        } 
        else 
        {
            printf("%-9c%-14d%-15d%-12d%d\n", current->Koloni->symbol, current->Koloni->population, current->Koloni->food_stock, current->Koloni->wins, current->Koloni->losses);
        }
        current=current->next;
    }
}
void free_colony_list(KoloniNode *head) {
    KoloniNode *current_node = head;
    KoloniNode *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node->Koloni->taktik);
        free(current_node->Koloni->production);
        free(current_node->Koloni);
        free(current_node);
        current_node = next_node;
    }
}