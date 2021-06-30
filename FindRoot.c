#include <math.h>
#include <stdio.h>

double Solve(double a, double b, double c);

int main() 
{
    double a, b, c;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    Solve(a,b,c);
    return 0;
} 

double Solve(double a, double b, double c)
{
	double discriminant, root1, root2;
	discriminant = b * b - 4 * a * c;

	 // If roots are real values and different from each other
    if (discriminant > 0)
	{
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("\nroot1 = %.2lf and root2 = %.2lf", root1, root2);
    }
    // If roots are real values but they are the same value(there exists 1 root)
    else if (discriminant == 0)
	{
        root1 = root2 = -b / (2 * a);
        printf("There is one root for this function, which is = %.2lf;", root1);
    }
    
    // If the roots are complex numbers
    else {
        root1 = -b / (2 * a);
        root2 = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", root1, root2, root1, root2);
    }
}
