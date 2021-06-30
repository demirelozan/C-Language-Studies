#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double f(double x);

float Secant(double (*f)(double), double eps, double xk, double xk1);


double f(double x)
{
	return (pow(x,2) * fabs(sin(sqrt(x))) - 10);
}
int main()
{
	double eps = 0.001;
	double x1 = 1;
	double x2 = 2;  
	
	
/*	printf("Enter the initial1 (x1):");
    scanf("%lf",&x1);
    printf("Enter the initial2 (x2):");
    scanf("%lf",&x2);
    printf("Enter the desired accuracy: \n");
    scanf("%lf",&eps);
*/ 
    
    
	
	float sec;
	sec = Secant(f,eps,x1,x2); 
	printf("\n Root is: %lf",sec);
	
	return 0;	
}

float Secant(double (*f)(double), double eps, double xk, double xk1)
{
	double err, xk2;
	do {
	xk2 = xk1 - (f(xk1)*(xk1 - xk) / (f(xk1)- f (xk)));

	xk=xk1;
	xk1=xk2;
	}
	while(fabs(f(xk2))>eps);
	return xk2;
}
