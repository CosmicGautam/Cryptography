/* This program calculates the Key for two persons
using the Diffie-Hellman Key exchange algorithm */
#include <math.h>
#include <stdio.h>

// Power function to return value of a ^ b mod P
long int power(long int a,long int b,
                    long int P)
{
    if (b == 1)
        return a;

    else
        return (((long int)pow(a, b)) % P);
}

// Driver program
int main()
{
    long int P, G, x, a, y, b, ka, kb;

    // Both the persons will be agreed upon the
    // public keys G and P
    P = 13; // A prime number P is taken
    printf("The value of P : %ld\n", P);

    G = 3; // A primitive root for P, G is taken
    printf("The value of G : %ld\n\n", G);

    // Alice will choose the private key a
    a = 10; // a is the chosen private key
    printf("The private key a for Alice : %ld\n", a);
    x = power(G, a, P); // gets the generated key

    // Bob will choose the private key b
    b = 7; // b is the chosen private key
    printf("The private key b for Bob : %ld\n\n", b);
    y = power(G, b, P); // gets the generated key

    // Generating the secret key after the exchange
    // of keys
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    printf("Secret key for the Alice is : %ld\n", ka);
    printf("Secret Key for the Bob is : %ld\n", kb);
	printf("\nName:Cosmic Gautam\tRoll no.:07");
    return 0;
}

