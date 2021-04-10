#include <stdio.h>
#include <stdlib.h>


//Su an sokaga cikabiliyo muyum acaba

float saat;
int yas;

int main()
{
	printf("Yasin kac dostum? %d \n");
	scanf("%d", &yas);
	
	printf("Saat kac acep %f \n");
	scanf("%f", &saat);
	
	if(yas <20)
	{

		if( !(saat < 14.00) && !(saat > 18.00) )
		
		{
			printf("Hadi yine iyisin cikabilirsin \n");
			return 0;
		}
		
		else
		{
			printf("Otur oturdugun yerde \n");
			return 0;
		}
		
		
	
	}	
	else if(yas>20 && yas<65)
	{
			printf("Hadi yine iyisin cikabilirsin \n");
			return 0;
	}
	else if(yas> 65)
	{
		if( !(saat < 10.00) && !(saat > 14.00) )
		
		{
		printf("Hadi yine iyisin cikabilirsin \n");
		return 0;
		}
	}
	
}
