#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not prime
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }

    return 1; // Prime
}

int main() {
    int num1, num2, num3;

    // Input and check 1
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    if (isPrime(num1)) {
        printf("%d is prime.\n", num1);
    } else {
        printf("%d is not prime.\n", num1);
    }

    // Input and check 2
    printf("\nEnter another integer: ");
    scanf("%d", &num2);

    if (isPrime(num2)) {
        printf("%d is prime.\n", num2);
    } else {
        printf("%d is not prime.\n", num2);
    }

    // Input and check 3
    printf("\nEnter one more integer: ");
    scanf("%d", &num3);

    if (isPrime(num3)) {
        printf("%d is prime.\n", num3);
    } else {
        printf("%d is not prime.\n", num3);
    }

    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
