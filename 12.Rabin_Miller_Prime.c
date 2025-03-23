#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int power(int x, unsigned int y, int p) {
    int res = 1; // Initialize result
    x = x % p;   // Update x if it is more than or equal to p
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
int miillerTest(int d, int n) {
    int a = 2 + rand() % (n - 4);
    int x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return 1;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return 0;
        if (x == n - 1) return 1;
    }
    return 0;
}

int isPrime(int n, int k) {
	int i;
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (i = 0; i < k; i++)
        if (!miillerTest(d, n))
            return 0;

    return 1;
}
int main() {
    srand(time(0)); // Seed the random number generator
    int n,k = 4;      // Number of iterations
    printf("Enter a number to check:");
	scanf("%d",&n);    
    if (isPrime(n, k))
        printf("%d is inconclusive.", n);
    else
    	printf("%d is composite.", n);
    printf("\nName:Cosmic Gautam\tRoll no.:07");
    return 0;
}
