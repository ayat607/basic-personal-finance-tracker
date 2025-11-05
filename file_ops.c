#include "finance_tracker.h"

void init_manager(FinanceManager *manager) {
    manager->transactions = malloc(INITIAL_CAPACITY * sizeof(Transaction));
    manager->count = 0;
    manager->capacity = INITIAL_CAPACITY;
}

void free_manager(FinanceManager *manager) {
    free(manager->transactions);
}

void save_data(FinanceManager *manager, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error creating file!\n");
        return;
    }
    
    fwrite(&manager->count, sizeof(int), 1, file);
    fwrite(manager->transactions, sizeof(Transaction), manager->count, file);
    fclose(file);
    printf("Data saved. Transactions: %d\n", manager->count);
}

void load_data(FinanceManager *manager, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("No existing data file.\n");
        return;
    }
    
    int count;
    fread(&count, sizeof(int), 1, file);
    
    if (count > manager->capacity) {
        manager->transactions = realloc(manager->transactions, count * sizeof(Transaction));
        manager->capacity = count;
    }
    
    fread(manager->transactions, sizeof(Transaction), count, file);
    manager->count = count;
    fclose(file);
    printf("Data loaded. Transactions: %d\n", count);
}