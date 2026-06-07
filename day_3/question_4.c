#include <stdio.h>

int main() {
    int Firstnumber, Secondnumber, a, b, temp, gcd, lcm;
    
    printf("Enter two integers: ");
    scanf("%d %d", &Firstnumber, &Secondnumber);

    a = Firstnumber;
    b = Secondnumber;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a; 

    lcm = (Firstnumber / gcd) * Secondnumber; 

    printf("The LCM of %d and %d is: %d\n", Firstnumber, Secondnumber, lcm);

    return 0;
}