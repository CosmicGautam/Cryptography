#include <stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int phi(unsigned int n)
{
	int i;
    unsigned int result = 1;
    for (i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("phi(%d) = %d\n", n, phi(n));
    printf("\nName: Cosmic Gautam \nRoll no.:07");
    return 0;
}

