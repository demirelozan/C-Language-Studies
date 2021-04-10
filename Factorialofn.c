#include <stdio.h>
#include <stdlib.h>

int n;
int factofn = 1;

int main()
{
	printf("Value of n is:\n");
	scanf("%d", &n);

	
	if(n < 30)
	{
		printf("n is %d \n", n);
		while(n>1)
		{
			factofn *= n--;
		
		}
		printf("The factorial of n: %d \n", factofn);
	}
}
