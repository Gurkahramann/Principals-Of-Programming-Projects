#include "Koloni.h"
#include "time.h"
Koloni new_Koloni(int data, char symbol,Taktik* taktik) {
    Koloni this;
    this = (Koloni)malloc(sizeof(struct KOLONI));
    this->data = data;
    this->next = NULL;
    this->symbol = symbol;
    this->population=data;
    this->food_stock=data*data;
    this->insertToList = insertToList;
    this->isNumber = &is_Number;
    this->freeList = &freeList;
    this->printList = &printList;
    this->production=production;
    this->battle=battle;
    this->wins=0;
    this->diff=0;
    this->losses=0;
    this->taktik = taktik; // Taktik alanını başlangıçta NULL olarak ayarlayalım
    this->uretim = NULL; // Uretim alanını başlangıçta NULL olarak ayarlayalım
   
    return this;
}
int battle(KoloniNode *current_node,KoloniNode *opponent_node) {

    
    int koloni1_score=current_node->Koloni->taktik->Savas(current_node,opponent_node);//koloni1->taktik->Savas(koloni1,koloni2);
    int koloni2_score =opponent_node->Koloni->taktik->Savas(opponent_node,current_node); //koloni2->taktik->Savas(koloni2, koloni1);
    int winner=0;
    if(koloni1_score==koloni2_score)
    {
        if(current_node->Koloni->population==opponent_node->Koloni->population)
        {
            winner=(rand()%2)+1;
            if(winner==1)
            {
                current_node->Koloni->wins++;
                opponent_node->Koloni->losses++;
            }
            if(winner==2)
            {
                opponent_node->Koloni->wins++;
                current_node->Koloni->losses++;
            }
        }
        else if(current_node->Koloni->population>opponent_node->Koloni->population)
        {
            winner=1;
            current_node->Koloni->wins++;
            opponent_node->Koloni->losses++;
        }
        else
        {
            winner=2;
            opponent_node->Koloni->wins++;
            current_node->Koloni->losses++;
        }
    }else if(koloni1_score>koloni2_score)
    {
        winner=1;
        current_node->Koloni->wins++;
        opponent_node->Koloni->losses++;
        
    }
    else
    {
        winner=2;
        opponent_node->Koloni->wins++;
        current_node->Koloni->losses++;
    }
    if(winner==1)
    {
        current_node->Koloni->diff=koloni1_score-koloni2_score;
        int ratio = (int)current_node->Koloni->diff / 1000;
        opponent_node->Koloni->population -= (int)(opponent_node->Koloni->population * ratio);
        if (opponent_node->Koloni->population <= 0) {
                opponent_node->Koloni->population = 0;
            }

    }
    else if(winner==2)
    {
        opponent_node->Koloni->diff=koloni2_score-koloni1_score;
        int ratio = (int)opponent_node->Koloni->diff / 1000;
        current_node->Koloni->population -= (int)(current_node->Koloni->population * ratio);
        if (current_node->Koloni->population < 0) {
                current_node->Koloni->population = 0;
            }   
    }
    return winner;
}



KoloniNode* createNode(int value) {
    struct KoloniNode* newNode = (struct KoloniNode*)malloc(sizeof(struct KoloniNode));
    newNode->Koloni->data = value;
    newNode->Koloni->next = NULL;
    return newNode->Koloni;
}
void production(KoloniNode* head) {
    KoloniNode* koloni=head;
    Uretim* aUretim=new_AUretim();
    Uretim* bUretim=new_BUretim();

    while(koloni!=NULL)
    {
     if (rand() % 2 == 0) {
        koloni->Koloni->uretim = (Uretim*)aUretim;
    } 
    else {
         koloni->Koloni->uretim = (Uretim*)bUretim;
        }
    int producedFood = rand() % 10 + 1;
    koloni->Koloni->food_stock+= producedFood;
    koloni->Koloni->population += (int)(koloni->Koloni->population * 0.2);
    koloni->Koloni->food_stock -= koloni->Koloni->population * 2;
    koloni=koloni->next;
    }

}
void insertToList(KoloniNode** list, int value,Taktik* taktik) {
    char randomChar=(char)(32 + (rand() % 95));
    Koloni newKoloni = new_Koloni(value,randomChar,taktik);
    KoloniNode* newNode = (KoloniNode*)malloc(sizeof(KoloniNode));
    newNode->Koloni = newKoloni;
    newNode->next = *list;
    *list = newNode;
}
int is_Number(const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}
void reverseList(KoloniNode** list) {
    KoloniNode* prev = NULL;
    KoloniNode* current = *list;
    KoloniNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *list = prev;
}
void freeList(struct KOLONI* head) {
    struct KOLONI* current = head;
    while (current != NULL) {
        struct KOLONI* temp = current;
        current = current->next;
        free(temp);
    }
}
int isNumber(const char *str) {
    char *endptr;
    strtol(str, &endptr, 10);
    return (*endptr == '\0');
}
void printList(struct KOLONI* head) {
    struct KOLONI* current = head;
    if(head==NULL)  return;
        printList(current->next);
        printf("Data: %d, Symbol: %c\n", current->data, current->symbol);
}




