#include <stdio.h>

// Function to perform Caesar Cipher encryption
void caesar_cipher(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] + shift - 'a') % 26 + 'a';
        }
    }
}

int main() {
    char plaintext[100];
    int shift_value;
    char key[100];

    // First encryption
    printf("Enter the first plaintext: ");
    gets(plaintext);
    printf("Enter the shift value for the first encryption: ");
    scanf("%d", &shift_value);
    getchar();
    printf("Enter the key for the first encryption: ");
    gets(key);
    caesar_cipher(plaintext, shift_value);
    printf("Encrypted (1): %s\n", plaintext);

    // Second encryption
    printf("\nEnter the second plaintext: ");
    gets(plaintext);
    printf("Enter the shift value for the second encryption: ");
    scanf("%d", &shift_value);
    getchar();
    printf("Enter the key for the second encryption: ");
    gets(key);
    caesar_cipher(plaintext, shift_value);
    printf("Encrypted (2): %s\n", plaintext);

    // Third encryption
    printf("\nEnter the third plaintext: ");
    gets(plaintext);
    printf("Enter the shift value for the third encryption: ");
    scanf("%d", &shift_value);
    getchar();
    printf("Enter the key for the third encryption: ");
    gets(key);
    caesar_cipher(plaintext, shift_value);
    printf("Encrypted (3): %s\n", plaintext);

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}
