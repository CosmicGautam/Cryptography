#include <stdio.h>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the modular inverse of A under modulo M
int modInverse(int A, int M) {
	int X;
    if (gcd(A, M) > 1) {
        // Modulo inverse does not exist
        return -1;
    }
    for (X = 1; X < M; X++) {
        if (((A % M) * (X % M)) % M == 1) {
            return X;
        }
    }
    return -1;
}

int main() {
    int A ;
    int M ;
    printf("Enter the number and mod:");
    scanf("%d %d",&A ,&M);

    int result = modInverse(A, M);
    if (result == -1) {
        printf("Modular inverse does not exist.\n");
    } else {
        printf("Modular inverse of %d under modulo %d is %d\n", A, M, result);
    }

    return 0;
}
