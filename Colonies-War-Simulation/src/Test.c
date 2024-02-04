#include <stdio.h>
#include "Koloni.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "Oyun.h"
#include "Taktik.h"
#include "ATaktik.h"
#include "BTaktik.h"
int main() {
    int numbers[1024];
    int count = 0;
    TaktikA* taktikA=new_ATaktik();
    TaktikB* taktikB=new_BTaktik();
    srand(time(NULL));
    // Klavyeden girişi al
    KoloniNode *head = NULL;
    printf("Sayilari girin (her sayinin arasinda bir adet bosluk birakin): ");
    char input[1024];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " ");
    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    KoloniNode* koloniList = NULL;
    for (int i = 0; i < count; i++) {
        int number = numbers[i];  
    if (rand() % 2 == 0) {
        
       insertToList(&koloniList, number,(Taktik*)taktikA);
    } 
    else 
    {
        insertToList(&koloniList, number,(Taktik*)taktikB);
    }
        
    }
    int turn = 1;
    while (true) {
        printf("Tur %d\n", turn);
        print_colony_list(koloniList);
        simulate_turn(koloniList);
        turn++; 
        if(checkColonies(koloniList)<=1) break;
    }
    if(checkColonies(koloniList)==1)
    {
        printf("Tur %d\n", turn);
    print_colony_list(koloniList);
    }
    else
    {
        printf("Tur %d\n", turn);
        printf("Hicbir koloni hayatta kalamadi!\n");
        print_colony_list(koloniList);
    }


    // // Son kalan koloni
    // KoloniNode* lastColony = koloniList;
    // if (lastColony != NULL) {
    //     printf("Son kalan koloni:\n");
    //     printf("%c\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", lastColony->Koloni->symbol, lastColony->Koloni->population, lastColony->Koloni->food_stock, lastColony->Koloni->wins, lastColony->Koloni->losses);
    // }

    free_colony_list(koloniList);
    return 0;
}



