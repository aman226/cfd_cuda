#ifndef _NUM_METHODS_HPP
#define _NUM_METHODS_HPP
double derivative_calculator(double (*f)(double), double x, double h);
double newton_raphson(double (*f)(double),double x_in,double tol);
double euler_forward_diff(double (*f)(double), double x, double h);
double euler_backward_diff(double (*f)(double), double x, double h);
double euler_midpoint(double (*f)(double), double x, double h);
#endif
