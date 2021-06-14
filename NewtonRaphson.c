#include <stdio.h>
#include <math.h>

#define h 0.001

double f(double);
double df(double);

int NewtonRaphson(double (*f)(double x), double (*df)(double x), double errTol, double xInit);
int main()
{
	double errTol = 0.01f;
//	printf("Enter Error Tolerance: ");
//	scanf("%f", &errTol);
	
	
	double xInit = 1;
	
	NewtonRaphson(f,df,errTol,xInit);
}

//The function
double f(double x)
{
	return (pow(x,2) * fabs(sin(sqrt(x))) - 10);
}

//Derivative of the function
double df(double x)
{
	return (f(x + h) - f(x))/h;
}

//The function, that returns the root of the given function(f(x)), using Newton-Raphson Method
int NewtonRaphson(double (*f)(double x), double (*df)(double x), double errTol, double xInit)
{
   	int iteration;
	int maximumIterations = 15;
    double k, x1;
    
    for (iteration=1; iteration<=maximumIterations; iteration++)
    {
    	
    	//using k, to write the equation only once, to simplify
        k = f(xInit)/df(xInit);
        x1 = xInit - k; 
		printf("At Iteration%3d: , x = %9.6f\n", iteration, x1);
        
		if (fabs(k) < errTol)
        {
            printf("\n\nAfter %3d iterations;\nThe Root is = %8.6f\n", iteration, x1);
            return x1;
        }
    	xInit=x1;
    }	
}


