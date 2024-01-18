#include <stdio.h>

// Function to calculate the Totient of a number
int totient(int n) {
    int result = 1; // Initialize result as n

    for (int i = 2; i < n; i++) {
        if (gcd(i, n) == 1) {
            result++;
        }
    }

    return result;
}

// Function to calculate the GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, num3;

    // Input and calculation 1
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Totient of %d is: %d\n", num1, totient(num1));

    // Input and calculation 2
    printf("\nEnter another integer: ");
    scanf("%d", &num2);

    printf("Totient of %d is: %d\n", num2, totient(num2));

    // Input and calculation 3
    printf("\nEnter one more integer: ");
    scanf("%d", &num3);

    printf("Totient of %d is: %d\n", num3, totient(num3));

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
