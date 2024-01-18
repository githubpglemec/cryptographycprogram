#include <stdio.h>
#include <string.h>

void vigenere_cipher(char text[], char key[]) {
    int text_length = strlen(text);
    int key_length = strlen(key);

    for (int i = 0, j = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            int shift = key[j % key_length] - 'A';

            if (isupper(text[i])) {
                text[i] = (text[i] + shift - 'A') % 26 + 'A';
            } else {
                text[i] = (text[i] + shift - 'a') % 26 + 'a';
            }

            j++;
        }
    }
}

int main() {
    char plaintext[100];
    char key[100];

    // Input
    printf("Enter the plaintext: ");
    gets(plaintext);
    printf("Enter the key: ");
    gets(key);

    // Encryption
    vigenere_cipher(plaintext, key);

    // Output
    printf("Encrypted: %s\n", plaintext);

    // Additional inputs for three different words
    char input2[100], input3[100];
    printf("Enter another plaintext: ");
    gets(input2);
    printf("Enter another key: ");
    gets(key);
    vigenere_cipher(input2, key);
    printf("Encrypted: %s\n", input2);

    printf("Enter one more plaintext: ");
    gets(input3);
    printf("Enter one more key: ");
    gets(key);
    vigenere_cipher(input3, key);
    printf("Encrypted: %s\n", input3);

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
