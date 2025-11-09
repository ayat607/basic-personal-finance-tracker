// Developer: Ayat
// Responsibility: File saving and loading

#include "fin_tracker.h"

void init_manager(f_manager *manager){
    manager->trans= malloc(init_capacity *sizeof(tran));
    manager->count=0;
    manager->capacity=init_capacity;
}

void free_manager(f_manager *manager){
    free(manager->trans);
}

void save_data(f_manager *manager, const char *filename){
    FILE *file= fopen(filename, "wb");
    if(!file){
        printf("Error creating file.\n");
        return;
    }

    fwrite(&manager->count, sizeof(int),1,file);
    fwrite(manager-> trans, sizeof(tran),manager->count,file);
    fclose(file);
    printf("Data saved. Transactions: %d\n", manager->count);
}

void load_data(f_manager *manager, const char *filename){
    FILE *file= fopen(filename, "rb");
    if(!file){
        printf("No existing data file.\n");
        return;
    }

    int count;
    fread(&count, sizeof(int),1,file);

    if( count> manager->capacity){
        manager->trans= realloc(manager->trans, count *sizeof(tran));
        manager->capacity= count;
    }

    fread(manager-> trans, sizeof(tran), count,file);
    manager->count= count;
    fclose(file);
    printf("Data loaded. Transactions: %d\n",count);
}


