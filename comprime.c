#include <stdio.h>

// Function to calculate the GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if two numbers are coprime
int areCoprime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int num1, num2, num3;

    // Input and check 1
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    if (areCoprime(num1, num2)) {
        printf("%d and %d are coprime.\n", num1, num2);
    } else {
        printf("%d and %d are not coprime.\n", num1, num2);
    }

    // Input and check 2
    int num4, num5;
    printf("\nEnter another integer: ");
    scanf("%d", &num4);

    printf("Enter one more integer: ");
    scanf("%d", &num5);

    if (areCoprime(num4, num5)) {
        printf("%d and %d are coprime.\n", num4, num5);
    } else {
        printf("%d and %d are not coprime.\n", num4, num5);
    }

    // Input and check 3
    int num6, num7;
    printf("\nEnter another integer: ");
    scanf("%d", &num6);

    printf("Enter one more integer: ");
    scanf("%d", &num7);

    if (areCoprime(num6, num7)) {
        printf("%d and %d are coprime.\n", num6, num7);
    } else {
        printf("%d and %d are not coprime.\n", num6, num7);
    }

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
