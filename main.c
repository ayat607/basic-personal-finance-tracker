// Developer: Tanu
// Responsibility: Main program and menu

#include "fin_tracker.h"

void show_menu(){
    printf("\n=== Finance Tracker Menu ===\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Search by category\n");
    printf("4. Monthly Report\n");
    printf("5. Save Data\n");
    printf("6. Load Data\n");
    printf("7. Exit\n");
    printf("Choice:");
}

int main(){
    f_manager manager;
    init_manager(&manager);

    int choice; char input[50];

    do{
        show_menu(); scanf("%d", &choice);

        switch(choice){
            case 1: add_tran(&manager); break;
            case 2: show_tran(&manager); break;
            case 3: 
                printf("Enter Category: "); scanf("%s",input);
                search_cat(&manager, input); break;
            case 4: 
                printf("Enter month(YYYY-MM): "); scanf("%s",input);
                monthly_report(&manager, input); break;
            case 5: save_data(&manager, "finance.dat"); break;
            case 6: load_data(&manager, "finance.dat"); break;
            case 7: printf("Goodbye\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while(choice !=7);

    save_data(&manager, "finance.dat");
    free_manager(&manager);
    return 0;

}

