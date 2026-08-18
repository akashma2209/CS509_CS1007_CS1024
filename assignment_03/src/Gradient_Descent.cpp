#include "gradient_descent.hpp"
#include <cmath>

double calculateFunction(double coefficient[], int degree, double x)
{
    double result = 0;
    for (int i = 0; i <= degree; i++)
    {
        result = result + coefficient[i] * pow(x, i);
    }
    return result;
}

double calculateDerivative(double coefficient[], int degree, double x)
{
    double result = 0;
    for (int i = 1; i <= degree; i++)
    {
        result = result + i * coefficient[i] * pow(x, i - 1);
    }
    return result;
}

void gradientDescent(double coefficient[],int degree,double x,double learningRate,double tolerance,int maxIterations,double &finalX,double &finalFx, int &iterations,bool &converged)
{
    iterations = 0;
    converged = false;
    for (int i = 0; i < maxIterations; i++)
    {
        double derivative;
        derivative = calculateDerivative(coefficient, degree, x);
        if (fabs(derivative) <= tolerance)
        {
            converged = true;
            break;
        }
        x = x - learningRate * derivative;
        iterations++;
    }

    finalX = x;
    finalFx = calculateFunction(coefficient, degree, x);
}

//g++ -std=c++17 assignment_03\driver\driver_gradient_descent.cpp assignment_03\src\Gradient_Descent.cpp -o assignment_03\executables\gradient_descent.exe

//.\assignment_03\executables\gradient_descent.exe