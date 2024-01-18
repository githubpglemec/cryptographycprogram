#include <stdio.h>

// Function to calculate the Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, &x1, &y1);

    // Update x and y using results of the recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int num1, num2, num3, x, y;

    // Input and calculation 1
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Calculate Extended Euclidean Algorithm
    int gcd1 = extendedEuclidean(num1, num2, &x, &y);

    printf("GCD of %d and %d is: %d\n", num1, num2, gcd1);
    printf("Extended Euclidean Algorithm: %d * %d + %d * %d = %d\n", num1, x, num2, y, gcd1);

    // Input and calculation 2
    printf("\nEnter another integer: ");
    scanf("%d", &num3);

    // Calculate Extended Euclidean Algorithm
    int gcd2 = extendedEuclidean(gcd1, num3, &x, &y);

    printf("GCD of previous result and %d is: %d\n", num3, gcd2);
    printf("Extended Euclidean Algorithm: %d * %d + %d * %d = %d\n", gcd1, x, num3, y, gcd2);

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
