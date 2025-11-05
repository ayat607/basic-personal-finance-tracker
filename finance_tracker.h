#ifndef FINANCE_TRACKER_H
#define FINANCE_TRACKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int id;
    char date[11];
    char description[100];
    float amount;
    char type[10];
    char category[30];
} Transaction;

typedef struct {
    Transaction *transactions;
    int count;
    int capacity;
} FinanceManager;

void init_manager(FinanceManager *manager);
void free_manager(FinanceManager *manager);
void add_transaction(FinanceManager *manager);
void show_transactions(FinanceManager *manager);
void search_category(FinanceManager *manager, const char *category);
void monthly_report(FinanceManager *manager, const char *month);
void save_data(FinanceManager *manager, const char *filename);
void load_data(FinanceManager *manager, const char *filename);

#endif