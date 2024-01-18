#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

void generateKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int k, flag = 0, *dicty;

    // Create a dictionary to check for repeated characters
    dicty = (int *)calloc(26, sizeof(int));

    for (k = 0; k < strlen(key); k++) {
        if (key[k] != 'J') {
            if (dicty[key[k] - 65] == 0) {
                keyMatrix[flag / 5][flag % 5] = key[k];
                dicty[key[k] - 65] = 1;
                flag++;
            }
        }
    }

    // Fill the remaining cells with the alphabet
    for (k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            keyMatrix[flag / 5][flag % 5] = (char)(k + 65);
            flag++;
        }
    }

    free(dicty);
}

void playfair_cipher(char message[], char keyMatrix[SIZE][SIZE]) {
    int i, j, k = 0, len = strlen(message);

    for (k = 0; k < len; k += 2) {
        // Find the coordinates of each digraph
        int row1, col1, row2, col2;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (message[k] == keyMatrix[i][j]) {
                    row1 = i;
                    col1 = j;
                }
                if (message[k + 1] == keyMatrix[i][j]) {
                    row2 = i;
                    col2 = j;
                }
            }
        }

        // Apply the rules of the Playfair Cipher
        if (row1 == row2) {
            message[k] = keyMatrix[row1][(col1 + 1) % SIZE];
            message[k + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            message[k] = keyMatrix[(row1 + 1) % SIZE][col1];
            message[k + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            message[k] = keyMatrix[row1][col2];
            message[k + 1] = keyMatrix[row2][col1];
        }
    }
}

int main() {
    char key[100], message[100];
    char keyMatrix[SIZE][SIZE];

    // Input
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // remove the newline character

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // remove the newline character

    // Generate key matrix
    generateKeyMatrix(key, keyMatrix);

    // Encryption
    playfair_cipher(message, keyMatrix);

    // Output
    printf("Encrypted: %s\n", message);

    // Additional inputs for three different words
    char input2[100], input3[100];
    printf("Enter another message: ");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = '\0';
    playfair_cipher(input2, keyMatrix);
    printf("Encrypted: %s\n", input2);

    printf("Enter one more message: ");
    fgets(input3, sizeof(input3), stdin);
    input3[strcspn(input3, "\n")] = '\0';
    playfair_cipher(input3, keyMatrix);
    printf("Encrypted: %s\n", input3);

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
