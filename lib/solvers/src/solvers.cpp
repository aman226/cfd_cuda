/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double rk4(double (*f)(double, double),double x_0,double y_0,double x_req,double h){
 
 int n;
 double y_req,x,y,k_1,k_2,k_3,k_4;
 n = int(float((x_req - x_0)/(h*1.0)) + 0.5);
 x = x_0;
 y = y_0;
 
 for(int j=0;j<n;j++){
 
  k_1 = h*f(x          , y);
  k_2 = h*f(x + (0.5)*h, y + (0.5)*k_1);
  k_3 = h*f(x + (0.5)*h, y + (0.5)*k_2);
  k_4 = h*f(x +       h, y +       k_3);
  
  y_req = y + (k_1 + 2*k_2 + 2*k_3 + k_4)/6.0;
  
  x = x + h;
  y = y_req;
 }
 
 return y_req;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double rk4_fehlberg(double (*f)(double, double),double x_0,double y_0,double x_req,double h){
 int n;
 double y_req,x,y,k_1,k_2,k_3,k_4,k_5;
 n = int(float((x_req - x_0)/(h*1.0)) + 0.5);
 x = x_0;
 y = y_0;
 
 for(int j=0;j<n;j++){ 
  k_1 = h*f(x              , y);
  k_2 = h*f(x + (   h)/4.0 , y +       (k_1/4.0));
  k_3 = h*f(x + ( 3*h)/8.0 , y +    ((3*k_1)       +    (9*k_2))/32.0);
  k_4 = h*f(x + (12*h)/13.0, y + ((1932*k_1)       - (7200*k_2) + (7296*k_3))/2197.0);
  k_5 = h*f(x + (   h)     , y +   (439*k_1)/216.0 -     8*k_2  + (3680*k_3)/513.0     - (845*k_4)/4104.0);
  
  y_req = y + (25*k_1)/216.0 + (1408*k_3)/2565.0 +(2197*k_4)/4101.0 - k_5/5.0;

  x = x + h;
  y = y_req;
 }

 return y_req;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double rk5_fehlberg(double (*f)(double, double),double x_0,double y_0,double x_req,double h){
 int n;
 double y_req,x,y,k_1,k_2,k_3,k_4,k_5,k_6;
 n = int(float((x_req - x_0)/(h*1.0)) + 0.5);
 x = x_0;
 y = y_0;
 
 for(int j=0;j<n;j++){ 
  k_1 = h*f(x              , y);
  k_2 = h*f(x + (   h)/4.0 , y +       (k_1/4.0));
  k_3 = h*f(x + ( 3*h)/8.0 , y +    ((3*k_1)       +    (9*k_2))/32.0);
  k_4 = h*f(x + (12*h)/13.0, y + ((1932*k_1)       - (7200*k_2) + (7296*k_3))/2197.0);
  k_5 = h*f(x + (   h)     , y +   (439*k_1)/216.0 -     8*k_2  + (3680*k_3)/513.0     - (845*k_4)/4104.0);
  k_6 = h*f(x + (   h)/2.0 , y -     (8*k_1)/27.0  +     2*k_2  - (3544*k_3)/2565.0    + (1859*k_4)/4104.0  - (11*k_5)/40);

  y_req = y + (16*k_1)/135.0 + (6656*k_3)/12825.0 +(28561*k_4)/56430.0 - (k_5*9)/50.0 + (2*k_6)/55.0;
  x = x + h;
  y = y_req;
 }

 return y_req;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
