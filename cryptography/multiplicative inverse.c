#include <stdio.h>

// Function to calculate the GCD
int gcdExtended(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to calculate the multiplicative inverse
int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);

    if (g != 1) {
        // Inverse doesn't exist
        return -1;
    } else {
        // Making x positive
        return (x % m + m) % m;
    }
}

int main() {
    int num1, num2, num3;

    // Input and calculation 1
    printf("Enter the integer: ");
    scanf("%d", &num1);

    int inverse1 = modInverse(num1, 26);

    if (inverse1 == -1) {
        printf("Multiplicative inverse does not exist for %d.\n", num1);
    } else {
        printf("Multiplicative inverse of %d (mod 26) is: %d\n", num1, inverse1);
    }

    // Input and calculation 2
    printf("\nEnter another integer: ");
    scanf("%d", &num2);

    int inverse2 = modInverse(num2, 100);

    if (inverse2 == -1) {
        printf("Multiplicative inverse does not exist for %d.\n", num2);
    } else {
        printf("Multiplicative inverse of %d (mod 100) is: %d\n", num2, inverse2);
    }

    // Input and calculation 3
    printf("\nEnter one more integer: ");
    scanf("%d", &num3);

    int inverse3 = modInverse(num3, 15);

    if (inverse3 == -1) {
        printf("Multiplicative inverse does not exist for %d.\n", num3);
    } else {
        printf("Multiplicative inverse of %d (mod 15) is: %d\n", num3, inverse3);
    }

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
