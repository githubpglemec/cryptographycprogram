#include <stdio.h>
#include <string.h>

void shift_cipher(char text[], int shift) {
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            // Encrypt uppercase letters
            if (isupper(text[i])) {
                text[i] = (text[i] + shift - 'A') % 26 + 'A';
            }
            // Encrypt lowercase letters
            else {
                text[i] = (text[i] + shift - 'a') % 26 + 'a';
            }
        }
    }
}

int main() {
    char plaintext[100];
    int shift_value;

    // Input
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift_value);

    // Remove newline character from fgets
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Encryption
    shift_cipher(plaintext, shift_value);

    // Output
    printf("Encrypted: %s\n", plaintext);

    // Your name and roll number
    printf("Name: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
