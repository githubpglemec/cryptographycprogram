#include <stdio.h>
#include <math.h>
// Function to calculate (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }

    return result;
}

// Function to perform Diffie-Hellman key exchange
long long diffieHellman(long long base, long long private_key, long long prime) {
    return power(base, private_key, prime);
}

int main() {
    long long prime, base, private_key_A, private_key_B;

    // Input for prime and base
    printf("Enter the prime number (p): ");
    scanf("%lld", &prime);

    printf("Enter the base (g): ");
    scanf("%lld", &base);

    // Input for private key A
    printf("Enter the private key for person A (a): ");
    scanf("%lld", &private_key_A);

    // Calculate public key A
    long long public_key_A = diffieHellman(base, private_key_A, prime);

    // Input for private key B
    printf("Enter the private key for person B (b): ");
    scanf("%lld", &private_key_B);

    // Calculate public key B
    long long public_key_B = diffieHellman(base, private_key_B, prime);

    // Calculate shared secret
    long long secret_A = diffieHellman(public_key_B, private_key_A, prime);
    long long secret_B = diffieHellman(public_key_A, private_key_B, prime);

    // Display results
    printf("\nPublic Key A (g^a mod p): %lld\n", public_key_A);
    printf("Public Key B (g^b mod p): %lld\n", public_key_B);
    printf("\nShared Secret for A: %lld\n", secret_A);
    printf("Shared Secret for B: %lld\n", secret_B);
    printf("\nName: Hari Prasad Gyawali\n");
    printf("Roll No: 6\n");

    return 0;
}

