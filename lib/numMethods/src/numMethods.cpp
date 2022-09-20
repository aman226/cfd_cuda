double derivative_calculator(double (*f)(double), double x, double h){
    return (f(x+h)-f(x))/h;
}

double newton_raphson(double (*f)(double),double x_in,double tol){
    static double x = x_in;
    double val = f(x);
    if(val<=tol || val == 0)
        return x;
    x = x_in - f(x_in)/derivative_calculator(f,x_in,0.00001);
    return newton_raphson(f,x,tol);
}

double euler_forward_diff(double (*f)(double), double x, double h){
    return derivative_calculator(f,x,h);
}

double euler_backward_diff(double (*f)(double), double x, double h){
    return (f(x)-f(x-h))/h;
}

double euler_midpoint(double (*f)(double), double x, double h){
    return (f(x+h/2)-f(x-h/2))/(2*h);
}

double second_order_forward_diff(double (*f)(double), double x, double h){
    return (3*f(x) - 4*f(x-h) + f(x-2*h) )/(2*h);
}

double second_order_backward_diff(double (*f)(double), double x, double h){
    return (-3*f(x) + 4*f(x+h) - f(x+2*h) )/(2*h);
}

double fourth_order_central_diff(double (*f)(double), double x, double h){
    return (-f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h) )/(12*h);
}

double s2_second_order_central_diff(double (*f)(double), double x, double h){
    return (f(x+h) - 2*f(x) + f(x - h))/(h*h);
}
