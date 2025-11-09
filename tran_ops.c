// Developer: Anu
// Responsibility: Add and display transactions

#include "fin_tracker.h"

void add_tran(f_manager *manager){
    if(manager->count >= manager->capacity){
        manager-> capacity *=2;
        manager-> trans= realloc(manager->trans, manager->capacity *sizeof(tran));
    }

    tran *t= &manager->trans[manager->count];
    t->id= manager-> count+1;

    printf("\nDate(YYYY-MM-DD): "); scanf("%s",t->date);
    printf("Description:"); getchar(); scanf("%[^\n]",t-> descr);
    printf("Amount: "); scanf("%f", &t->amt);
    printf("Type(income/expense):"); scanf("%s", t->type);
    printf("Category: "); scanf("%s", t-> category);
     manager-> count++;
     printf("Transaction added. ID: %d\n", t->id);
}

void show_tran(f_manager *manager){
    if(manager->count==0){
        printf("No transaction.\n");
        return;
    }

    printf("\naAll Transactions (%d):\n", manager->count);
    for(int q=0; q< manager-> count; q++){
        tran *t= &manager->trans[q];
        printf("ID: %d | %s | %s | %.2f | %s | %s\n", t->id, t->date, t->descr, t->amt, t->type, t->category);
        
    }

    
}