#include<stdio.h>
#include<conio.h>
int main()
{
	 int num1, num2, gcd, i;
	 printf("Enter two numbers:");
	 scanf("%d%d", &num1, &num2);
	 for(i=1;i<=num1;i++)
	 {
	  if(num1%i==0 && num2%i==0)
	  {
	   gcd = i;
	  }
	 }
	 if(gcd == 1)
	 {
	  printf("%d and %d are CO-PRIME NUMBERS.", num1, num2);
	 }
	 else
	 {
	  printf("%d and %d are NOT CO-PRIME NUMBERS.", num1, num2);
	 }
	 printf("\nName:Cosmic Gautam\tRoll no.:07");
	 return(0);
}

