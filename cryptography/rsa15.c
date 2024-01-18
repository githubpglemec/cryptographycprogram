#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }

    return result;
}

void generateKeys(long long p, long long q, long long* n, long long* e, long long* d) {
    *n = p * q;
    long long phi = (p - 1) * (q - 1);

    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1)
            break;
    }

    for (*d = 2; *d < phi; (*d)++) {
        if ((*d * (*e)) % phi == 1)
            break;
    }
}

long long encrypt(long long message, long long e, long long n) {
    return power(message, e, n);
}

long long decrypt(long long encryptedMessage, long long d, long long n) {
    return power(encryptedMessage, d, n);
}

int main() {
    long long p, q, n, e, d;

    for (int i = 0; i < 3; i++) {
        // Input for prime numbers p and q
        printf("\nEnter prime number p for set %d: ", i + 1);
        scanf("%lld", &p);

        printf("Enter prime number q for set %d: ", i + 1);
        scanf("%lld", &q);

        // Generate public and private keys
        generateKeys(p, q, &n, &e, &d);

        // Display public and private keys
        printf("\nPublic Key (e, n) for set %d: (%lld, %lld)\n", i + 1, e, n);
        printf("Private Key (d, n) for set %d: (%lld, %lld)\n", i + 1, d, n);

        // Input for the message to be encrypted
        long long message;
        printf("\nEnter a message to encrypt for set %d: ", i + 1);
        scanf("%lld", &message);

        // Encrypt the message
        long long encryptedMessage = encrypt(message, e, n);
        printf("Encrypted Message for set %d: %lld\n", i + 1, encryptedMessage);

        // Decrypt the message
        long long decryptedMessage = decrypt(encryptedMessage, d, n);
        printf("Decrypted Message for set %d: %lld\n", i + 1, decryptedMessage);
    }

    // Your name and roll number
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}

