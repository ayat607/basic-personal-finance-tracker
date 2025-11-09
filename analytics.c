// Developer: Ayat
// Responsibility: Search and reports

#include "fin_tracker.h"

void search_cat(f_manager *manager, const char *category){
    printf("Transacton in category '%s':\n", category);
    int found=0;

    for(int q=0; q< manager->count; q++){
        tran *t= &manager->trans[q];
        if( strcmp(t->category,category)==0){
            printf("ID: %d | %s | %s | %.2f\n", t->id, t->date, t->descr, t->amt);

            found=1;
        }
    }

    if(!found){
        printf("No transactions found.\n");
    }
}

void monthly_report(f_manager *manager, const char *month){
    float income=0, expense=0;

    for(int q=0; q<manager->count; q++){
        tran *t= &manager->trans[q];

        char trans_month[8];
        strncpy(trans_month, t->date,7);
        trans_month[7]= '\0';

        if(strcmp(trans_month, month)==0){
            if (strcmp(t->type, "income")==0){
                income += t->amt; } 
            else{
                expense += t->amt;
            }
         }
    }


printf("Monthly Report %s:\n", month);
printf("Total Income: %.2f\n", income);
printf("Total Expense: %.2f\n", expense);
printf("Net Savings: %.2f\n", income - expense);

}