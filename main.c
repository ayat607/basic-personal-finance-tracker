// Developer: [Member 3 Name] 
// Responsibility: Main program and menu

#include "finance_tracker.h"

void show_menu() {
    printf("\nFinance Tracker Menu:\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Search by Category\n");
    printf("4. Monthly Report\n");
    printf("5. Save Data\n");
    printf("6. Load Data\n");
    printf("7. Exit\n");
    printf("Choice: ");
}

int main() {
    FinanceManager manager;
    init_manager(&manager);
    
    int choice;
    char input[50];
    
    do {
        show_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_transaction(&manager); break;
            case 2: show_transactions(&manager); break;
            case 3: 
                printf("Enter category: ");
                scanf("%s", input);
                search_category(&manager, input);
                break;
            case 4:
                printf("Enter month (YYYY-MM): ");
                scanf("%s", input);
                monthly_report(&manager, input);
                break;
            case 5: save_data(&manager, "finance.dat"); break;
            case 6: load_data(&manager, "finance.dat"); break;
            case 7: printf("Goodbye\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 7);
    
    save_data(&manager, "finance.dat");
    free_manager(&manager);
    return 0;
}