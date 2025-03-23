#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute (base^expo) % mod efficiently
int power(int base, int expo, int mod) {
    int result = 1;
    base = base % mod; // Ensure base is within mod
    while (expo > 0) {
        if (expo & 1) // If expo is odd
            result = (result * base) % mod;
        base = (base * base) % mod; // Square the base
        expo = expo >> 1; // Divide expo by 2
    }
    return result;
}

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Extended Euclidean Algorithm to find modular inverse
int modInverse(int e, int phi) {
    int m0 = phi, t, q;
    int x0 = 0, x1 = 1;

    if (phi == 1)
        return 0;

    while (e > 1) {
        q = e / phi; // Quotient
        t = phi;

        phi = e % phi; // Remainder
        e = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) // Make x1 positive
        x1 += m0;

    return x1;
}

// Function to generate RSA keys
void generateKeys(int *e, int *d, int *n) {
    int p,q;
	printf("Enter two prime numbers:");
	scanf("%d%d",&p,&q);
    *n = p * q; // Compute n
    int phi = (p - 1) * (q - 1); // Compute phi(n)

    // Choose e such that 1 < e < phi(n) and gcd(e, phi(n)) == 1
    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1)
            break;
    }

    // Compute d as the modular inverse of e modulo phi(n)
    *d = modInverse(*e, phi);

    if (*d == -1) {
        printf("Error: Modular inverse does not exist.\n");
        exit(1);
    }
}

// Function to encrypt a message
int encrypt(int m, int e, int n) {
    return power(m, e, n);
}

// Function to decrypt a message
int decrypt(int c, int d, int n) {
    return power(c, d, n);
}

int main() {
    int e, d, n;

    // Generate RSA keys
    generateKeys(&e, &d, &n);

    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);

    // Message to encrypt
    int M ;
    printf("Enter Original Message:");
    scanf("%d",&M);

    // Encrypt the message
    int C = encrypt(M, e, n);
    printf("Encrypted Message: %d\n", C);

    // Decrypt the message
    int decrypted = decrypt(C, d, n);
    printf("Decrypted Message: %d\n", decrypted);
	printf("\nName:Cosmic Gautam\tRoll no.:07");
    return 0;
}
