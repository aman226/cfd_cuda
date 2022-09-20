#include "iomanip"
#include "fstream"



void linear1D_convection_model(double (*u)(double), int n, double x_in, double x_fin, double y_in, double y_fin, int time, double c, double timestep){
    //std::ofstream logger;
    //logger.open ("data.txt");

    double* u_x_i;
    
    float delta_x = (x_fin - x_in)/n;
    int step = time/timestep;
    
    u_x_i = new double(n+1);
    u_x_i[0] = y_in;
    u_x_i[n] = y_fin;
    
    //logger<<u_x_i[0]<<" "<<x_in<<"\n";
    for(int i=1;i<n;i++){
     u_x_i[i] = u(x_in + (delta_x*(i)));
     //logger<<u_x_i[i]<<" "<<x_in + (delta_x*(i))<<"\n";
    }
    //logger<<u_x_i[n]<<" "<<x_fin<<"\n";

    for(int _step=0; _step<step; _step++){
        //logger<<u_x_i[0]<<" "<<x_in<<"\n";
        for(int i=1;i<n;i++){
            u_x_i[i] = u_x_i[i] - c*(timestep/delta_x)*(u_x_i[i] - u_x_i[i-1]);
            //logger<<u_x_i[i]<<" "<<x_in + (delta_x*(i))<<"\n";
        }     
        //logger<<u_x_i[n]<<" "<<x_fin<<"\n";   
    }
}

void inviscid_burgers_model(double (*u)(double), int n, double x_in, double x_fin, double y_in, double y_fin, int time, double timestep){
    std::ofstream logger;
    logger.open ("data.txt");

    double* u_x_i;
    
    float delta_x = (x_fin - x_in)/n;
    int step = time/timestep;
    
    u_x_i = new double(n+1);
    u_x_i[0] = y_in;
    u_x_i[n] = y_fin;
    
    logger<<u_x_i[0]<<" "<<x_in<<"\n";
    for(int i=1;i<n;i++){
     u_x_i[i] = u(x_in + (delta_x*(i)));
     logger<<u_x_i[i]<<" "<<x_in + (delta_x*(i))<<"\n";
    }
    logger<<u_x_i[n]<<" "<<x_fin<<"\n";

    for(int _step=0; _step<step; _step++){
        logger<<u_x_i[0]<<" "<<x_in<<"\n";
        for(int i=1;i<n;i++){
            u_x_i[i] = u_x_i[i] - u_x_i[i]*(timestep/delta_x)*(u_x_i[i] - u_x_i[i-1]);
            logger<<u_x_i[i]<<" "<<x_in + (delta_x*(i))<<"\n";
        }     
        logger<<u_x_i[n]<<" "<<x_fin<<"\n";   
    }
    logger.close();    
}