#include <stdio.h>
#include <stdlib.h>

int n;
int factofn;

int main()
{
	printf("Value of n is:\n");
	scanf("%d", &n);
	factofn = n;
	
	
	if(n < 30)
	{
		printf("n is %d \n", n);
		while(n>1)
		{
			factofn = factofn *(n-1);
			n--;
		}
		printf("The factorial of n: %d \n", factofn);
	}
}
