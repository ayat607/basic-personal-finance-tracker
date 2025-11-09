#ifndef fin_tracker
#define fin_tracker

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define init_capacity 10    // initial point for tran. of arr

typedef struct Transaction{
    int id;
    char date[11];
    char descr[100];
    float amt;
    char type[10];
    char category[30];
} tran;

typedef struct{
    tran *trans;
    int count;
    int capacity;
}f_manager;

void init_manager(f_manager *manager);
void free_manager(f_manager *manager);
void add_tran(f_manager *manager);
void show_tran(f_manager *manager);
void search_cat(f_manager *manager, const char *search_category);
void monthly_report(f_manager *manager, const char *month);
void save_data(f_manager *manager, const char *filename);
void load_data(f_manager *manager, const char *filename);

#endif
