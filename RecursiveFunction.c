#include <stdio.h>


//040190625 - Ozan Demirel

int Recursive(int);
 
int main()
{
   int input, n;
 
   printf("Enter a number for the recursive function\n");
   scanf("%d",&input);
 	
	if( input >= 1)
	{
	// sadece n degerini g�stermek yerine n dahil n e kadar olan de�erleri g�stermek istedim, for d�ng�s� bunun i�in. for d�ng�s�n� kaldirinca, g�z�ken deger sadece n. deger olur.
    	for ( n = 1 ; n <= input ; n++ )
		{
		printf("%d. of the sequence is ", n );
      	printf("%d\n", Recursive(n));
      	
   		}
		return 0;	
	}
	else
	{
		printf(" You have entered wrong value\n");
		return -1;
	}		
	  
   
}
 
int Recursive(int n)
{

    if ( n < 4)
    	return 1;
    else if ( n >= 4)
        return Recursive(n-1) + (2 * Recursive(n-2)) + ( 3 * Recursive(n-3));
    //else 
} 
