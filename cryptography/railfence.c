#include <stdio.h>
#include <string.h>

void railfence_cipher(char text[], int key) {
    int len = strlen(text);
    char encrypted[len];
    int r = key;
    int c = len / key;

    if (len % key != 0) {
        c++;
    }

    char matrix[r][c];

    int k = 0;

    // Fill the matrix with characters from the text
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (k < len) {
                matrix[i][j] = text[k++];
            } else {
                matrix[i][j] = 'X'; // Padding with 'X' if needed
            }
        }
    }

    // Read the matrix in a zigzag pattern to get the encrypted text
    k = 0;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (matrix[i][j] != 'X') {
                encrypted[k++] = matrix[i][j];
            }
        }
    }

    encrypted[k] = '\0'; // Null-terminate the encrypted text

    // Print the encrypted text
    printf("Encrypted: %s\n", encrypted);
}

int main() {
    char plaintext[100];
    int key;

    // Input and encryption 1
    printf("Enter the first plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove the newline character

    printf("Enter the key for the first encryption: ");
    scanf("%d", &key);
    getchar(); // Consume the newline character

    railfence_cipher(plaintext, key);

    // Input and encryption 2
    printf("\nEnter the second plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove the newline character

    printf("Enter the key for the second encryption: ");
    scanf("%d", &key);
    getchar(); // Consume the newline character

    railfence_cipher(plaintext, key);

    // Input and encryption 3
    printf("\nEnter the third plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove the newline character

    printf("Enter the key for the third encryption: ");
    scanf("%d", &key);
    getchar(); // Consume the newline character

    railfence_cipher(plaintext, key);

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
