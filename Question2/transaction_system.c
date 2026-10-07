#include <stdio.h>

int main(void)
{
    /* Account and transaction state */
    int balance = 0;          /* current balance in RWF */
    int deposit_count = 0;   /* successful deposits */
    int withdraw_count = 0;  /* successful withdrawals */

    int choice;

    while (1) {
        printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("\n1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            /* Discard the bad input so the next prompt is clean */
            while (getchar() != '\n') {
                /* discard remaining characters on the line */
            }
            continue;
        }

        switch (choice) {
        case 1: {
            int amount;
            printf("Enter deposit amount: ");
            if (scanf("%d", &amount) != 1 || amount <= 0) {
                printf("Invalid amount. Transaction rejected.\n");
                while (getchar() != '\n') {
                    /* discard the rest of the line */
                }
                continue;
            }
            balance += amount;
            deposit_count++;
            printf("Deposit successful.\n");
            printf("Current balance: %d RWF\n", balance);
            break;
        }

        case 2: {
            int amount;
            printf("Enter withdrawal amount: ");
            if (scanf("%d", &amount) != 1 || amount <= 0) {
                printf("Invalid amount. Transaction rejected.\n");
                while (getchar() != '\n') {
                    /* discard the rest of the line */
                }
                continue;
            }
            if (amount > balance) {
                printf("Transaction rejected: Insufficient balance.\n");
                break;
            }
            balance -= amount;
            withdraw_count++;
            printf("Withdrawal successful.\n");
            printf("Current balance: %d RWF\n", balance);
            break;
        }

        case 3:
            printf("Current balance: %d RWF\n", balance);
            break;

        case 4:
            printf("Transaction Summary\n");
            printf("Successful deposits   : %d\n", deposit_count);
            printf("Successful withdrawals : %d\n", withdraw_count);
            break;

        case 5:
            printf("System terminated.\n");
            goto exit_program;

        default:
            printf("Invalid choice. Please select 1-5.\n");
            continue;
        }
    }

exit_program:
    return 0;
}
