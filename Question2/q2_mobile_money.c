#include <stdio.h>

int main() {
    int choice;
    float balance = 50000.0; // Starting balance
    float amount;
    int successful_deposits = 0;
    int successful_withdrawals = 0;

    while (1) {
        printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        
        // Handle input validation safely
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Try again.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }

        if (choice == 5) {
            printf("System terminated.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Transaction rejected: Invalid amount.\n");
                    continue; // goes back to menu immediately
                }
                balance += amount;
                successful_deposits++;
                printf("Deposit successful.\n");
                printf("Current balance: %.0f RWF\n", balance);
                break;
            case 2:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Transaction rejected: Invalid amount.\n");
                    continue;
                }
                if (amount > balance) {
                    printf("Transaction rejected: Insufficient balance.\n");
                    continue;
                }
                balance -= amount;
                successful_withdrawals++;
                printf("Withdrawal successful.\n");
                printf("Current balance: %.0f RWF\n", balance);
                break;
            case 3:
                printf("Current balance: %.0f RWF\n", balance);
                break;
            case 4:
                printf("--- Transaction Summary ---\n");
                printf("Successful deposits: %d\n", successful_deposits);
                printf("Successful withdrawals: %d\n", successful_withdrawals);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}