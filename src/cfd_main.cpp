#include "cfd_main_version.h"
#include "iostream"
#include "solvers.hpp"
#include "numMethods.hpp"
#include "models.hpp"
#include "cmath"
#include "iomanip"
#include "cstring"


double f(double,double);
double g(double,double);
double m(double x);
double u_t_0(double x);
double assign1(double x,double K=1.0,double U_naut=1.0);
double compute_assign1();

int main(int argc, char *argv[]){ 
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(NULL);
 std::cout << "Welcome to AeroCFD - Version " << cfd_main_VERSION_MAJOR << "." << cfd_main_VERSION_MINOR << "\n\n";
 //linear1D_convection_model(&u_t_0,u_x_i,100,0,2,1,1,1,1,0.001);
 inviscid_burgers_model(&u_t_0,100,0,2,1,1,1,0.001);

/*
 if(argc > 1){
  if(!strcmp(argv[1],"rk4"))
   std::cout<<std::setprecision(9)<<rk4(&f,0,1,0.1,0.1)<<"\n";
  if(!strcmp(argv[1],"rk4f"))
   std::cout<<std::setprecision(9)<<rk4_fehlberg(&f,0,1,0.1,0.1)<<"\n";
  if(!strcmp(argv[1],"rk5f"))
   std::cout<<std::setprecision(9)<<rk5_fehlberg(&f,0,1,0.1,0.1)<<"\n";
 }
 std::cout<<newton_raphson(&m,-1,0.001);
*/


 return 0;
}


double f(double x, double y){
 return x*x*x*exp(-2*x) - 2*y;
}

double g(double x, double y){
 return 1 + y*y;
}

double m(double x){
 return x*x - 5*x + 6;
}

double u_t_0(double x){
  
  if(x<=0 && x>=2){
    std::cout << "Error! Out of Domain";
    exit(0); 
  }

  else if(x >= 0.5 && x<=1)
    return 2;
  
  else
    return 1;
}

double assign1(double x,double K=1.0,double U_naut=1.0){
  return U_naut*sin(K*x);
}