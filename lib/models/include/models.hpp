#ifndef _MODELS_HPP
#define _MODELS_HPP
void linear1D_convection_model(double (*u)(double), int n, double x_in, double x_fin, double y_in, double y_fin, int time, double c, double timestep);
void inviscid_burgers_model(double (*u)(double), int n, double x_in, double x_fin, double y_in, double y_fin, int time, double timestep);
#endif