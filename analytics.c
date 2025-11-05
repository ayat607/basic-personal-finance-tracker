// Developer: [Member 3 Name]
// Responsibility: Search and reports

#include "finance_tracker.h"

void search_category(FinanceManager *manager, const char *category) {
    printf("Transactions in category '%s':\n", category);
    int found = 0;
    
    for (int i = 0; i < manager->count; i++) {
        Transaction *t = &manager->transactions[i];
        if (strcmp(t->category, category) == 0) {
            printf("ID: %d | %s | %s | %.2f\n",
                   t->id, t->date, t->description, t->amount);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No transactions found.\n");
    }
}

void monthly_report(FinanceManager *manager, const char *month) {
    float income = 0, expense = 0;
    
    for (int i = 0; i < manager->count; i++) {
        Transaction *t = &manager->transactions[i];
        
        char trans_month[8];
        strncpy(trans_month, t->date, 7);
        trans_month[7] = '\0';
        
        if (strcmp(trans_month, month) == 0) {
            if (strcmp(t->type, "income") == 0) {
                income += t->amount;
            } else {
                expense += t->amount;
            }
        }
    }
    
    printf("Monthly Report %s:\n", month);
    printf("Total Income: %.2f\n", income);
    printf("Total Expense: %.2f\n", expense);
    printf("Net Savings: %.2f\n", income - expense);
}