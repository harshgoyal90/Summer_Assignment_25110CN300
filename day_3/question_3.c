 #include <stdio.h>

int main() {
    int num1, num2;
    int Temp1, Temp2, Remainder;

    // Taking the input from user
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

    Temp1 = num1;
    Temp2 = num2;

    while (Temp2 != 0) {
        Remainder = Temp1 % Temp2;
        Temp1 = Temp2;
        Temp2 = Remainder;
    }

    printf("The GCD of %d and %d is: %d\n", num1, num2, Temp1);

    return 0;
}

