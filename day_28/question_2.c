//    Write a program to Create bank account system

#include <stdio.h>
struct BankAccount {
    char accountHolderName[50];
    int accountNumber;
    float balance;
};

int main() {
    struct BankAccount account;

    // Input account details
    printf("Enter account holder name: ");
    scanf("%s", account.accountHolderName);

    printf("Enter account number: ");
    scanf("%d", &account.accountNumber);

    printf("Enter initial balance: ");
    scanf("%f", &account.balance);

    // Display account details
    printf("\nBank Account Details:\n");
    printf("Account Holder Name: %s\n", account.accountHolderName);
    printf("Account Number: %d\n", account.accountNumber);
    printf("Balance: %.2f\n", account.balance);

    return 0;
}