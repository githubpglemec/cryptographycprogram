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

int main() {
    int num1, num2, num3;

    // Input and calculation 1
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Calculate and print GCD
    int result1 = gcd(num1, num2);
    printf("GCD of %d and %d is: %d\n", num1, num2, result1);

    // Input and calculation 2
    printf("\nEnter the third integer: ");
    scanf("%d", &num3);

    // Calculate and print GCD
    int result2 = gcd(result1, num3);
    printf("GCD of previous result and %d is: %d\n", num3, result2);

    // Input and calculation 3
    int num4, num5;
    printf("\nEnter another integer: ");
    scanf("%d", &num4);

    printf("Enter one more integer: ");
    scanf("%d", &num5);

    // Calculate and print GCD
    int result3 = gcd(num4, num5);
    printf("GCD of %d and %d is: %d\n", num4, num5, result3);

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
