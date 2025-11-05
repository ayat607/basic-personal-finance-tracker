#include "finance_tracker.h"
// Developer: [Member 2 Name]  
// Responsibility: Add and display transactions

void add_transaction(FinanceManager *manager) {
    if (manager->count >= manager->capacity) {
        manager->capacity *= 2;
        manager->transactions = realloc(manager->transactions, manager->capacity * sizeof(Transaction));
    }
    
    Transaction *t = &manager->transactions[manager->count];
    t->id = manager->count + 1;
    
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", t->date);
    
    printf("Description: ");
    getchar();
    fgets(t->description, 100, stdin);
    t->description[strcspn(t->description, "\n")] = 0;
    
    printf("Amount: ");
    scanf("%f", &t->amount);
    
    printf("Type (income/expense): ");
    scanf("%s", t->type);
    
    printf("Category: ");
    scanf("%s", t->category);
    
    manager->count++;
    printf("Transaction added. ID: %d\n", t->id);
}

void show_transactions(FinanceManager *manager) {
    if (manager->count == 0) {
        printf("No transactions.\n");
        return;
    }
    
    printf("\nAll Transactions (%d):\n", manager->count);
    for (int i = 0; i < manager->count; i++) {
        Transaction *t = &manager->transactions[i];
        printf("ID: %d | %s | %s | %.2f | %s | %s\n",
               t->id, t->date, t->description, t->amount, t->type, t->category);
    }
}