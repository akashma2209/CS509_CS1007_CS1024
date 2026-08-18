#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

double calculateFunction(double coefficient[], int degree, double x);
double calculateDerivative(double coefficient[], int degree, double x);

void gradientDescent(double coefficient[],int degree,double x,double learningRate,double tolerance,int maxIterations,double &finalX,double &finalFx,int &iterations,bool &converged);
#endif