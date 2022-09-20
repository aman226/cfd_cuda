#ifndef _SOLVERS_H
#define _SOLVERS_H
double rk4(double (*f)(double,double),double x_0,double y_0,double x_req,double h);
double rk5_fehlberg(double (*f)(double, double),double x_0,double y_0,double x_req,double h);
double rk4_fehlberg(double (*f)(double, double),double x_0,double y_0,double x_req,double h);
#endif
