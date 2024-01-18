//cipher
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Vigenère encryption
void vigenereEncrypt(char *text, char *key) {
    int textLength = strlen(text);
    int keyLength = strlen(key);
    char encrypted[textLength];

    for (int i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            encrypted[i] = ((text[i] - base + key[i % keyLength] - 'A') % 26) + base;
        } else {
            encrypted[i] = text[i]; // Keep non-alphabet characters unchanged
        }
    }

    printf("Encrypted Text: %s\n", encrypted);
}

// Function to perform Vigenère decryption
void vigenereDecrypt(char *text, char *key) {
    int textLength = strlen(text);
    int keyLength = strlen(key);
    char decrypted[textLength];

    for (int i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            decrypted[i] = ((text[i] - base - (key[i % keyLength] - 'A') + 26) % 26) + base;
        } else {
            decrypted[i] = text[i]; // Keep non-alphabet characters unchanged
        }
    }

    printf("Decrypted Text: %s\n", decrypted);
}

int main() {
    char text[50];
    char key[50];

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%s", key);

    vigenereEncrypt(text, key);
    vigenereDecrypt(text, key);

    return 0;
}
