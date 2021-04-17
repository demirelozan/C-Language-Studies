#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Random number generation between the given numbers
int randInt(int min, int max);

int main()
{
int a;
srand((unsigned)time(0));

for(a=0; a<10; a++)
{
	printf("%d\n", randInt(5,12) );	
}	
}

int randInt(  min,  max)
{
	int i;
	i =  rand() % (max- min) + min;
	return i;
}
