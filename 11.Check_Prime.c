#include<stdio.h>
int main()
{
	int i,n,flag=0;
	printf("Enter the number to check:");
	scanf("%d",&n);
	if(n==0 || n==1)
	{
		flag=1;
	}

	for(i=2;i<=n/2;i++)
	{
		if(n%i == 0)
		{
			flag=1;
			break;
		}
	}
	
	if(flag==0)
		printf("%d is Prime.",n);
	else
		printf("%d is Composite.",n);
	printf("\nName:Cosmic Gautam\tRoll no.:07");
}
