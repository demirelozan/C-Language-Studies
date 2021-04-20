#include <stdio.h>
#include <stdlib.h>


//Answer of the first question in Homework
// 040190625 - Ozan Demirel
int main()
{
	int i = 0;
	
	float input[20], sumOfTotal = 0.0, average;
	float minimumValue;
    float maximumValue; 
	 
	 while(i < 20)
	 {

	 	printf("%d. Enter a number: ", i + 1);
        scanf("%f", &input[i]);
        
        minimumValue = input[0];
        sumOfTotal += input[i];
         
		average = sumOfTotal / (i + 1);
    
		     
        if(input[i] > maximumValue)
        {
        	maximumValue = input[i];
		}
		if(input[i] < minimumValue)
        {
        	minimumValue = input[i];
		}
		
		printf("Average = %.2f, Maximum Value = %.2f, Minimum Value = %.2f \n", average, maximumValue, minimumValue);
		i++;
	}
		
    	return 0;
}
