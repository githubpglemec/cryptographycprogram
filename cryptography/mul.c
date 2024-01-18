#include <stdio.h>

// Function to check if a is the multiplicative inverse of b
int isMultiplicativeInverse(int a, int b, int mod) {
    int result = (a * b) % mod;
    return result == 1;
}

int main() {
    int num1, num2;

    // Input and check 1
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    if (isMultiplicativeInverse(num1, num2, 26)) {
        printf("%d is the multiplicative inverse of %d.\n", num1, num2);
    } else {
        printf("%d is not the multiplicative inverse of %d.\n", num1, num2);
    }

    // Input and check 2
    int num3, num4;
    printf("\nEnter another integer: ");
    scanf("%d", &num3);

    printf("Enter one more integer: ");
    scanf("%d", &num4);

    if (isMultiplicativeInverse(num3, num4, 100)) {
        printf("%d is the multiplicative inverse of %d.\n", num3, num4);
    } else {
        printf("%d is not the multiplicative inverse of %d.\n", num3, num4);
    }

    // Input and check 3
    int num5, num6;
    printf("\nEnter another integer: ");
    scanf("%d", &num5);

    printf("Enter one more integer: ");
    scanf("%d", &num6);

    if (isMultiplicativeInverse(num5, num6, 15)) {
        printf("%d is the multiplicative inverse of %d.\n", num5, num6);
    } else {
        printf("%d is not the multiplicative inverse of %d.\n", num5, num6);
    }

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
