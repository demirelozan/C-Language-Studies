#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
	float radius;
	float area;
	float perimeter;
	
	printf("Enter the radius: \n");
	scanf("%f", &radius);
	
	area = radius * radius * PI;
		printf("The area is: %f", area);
	
	perimeter = 2 * radius;
		printf("The perimeter is: %f", perimeter);
	
	return 0;
}
