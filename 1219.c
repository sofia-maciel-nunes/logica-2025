#include <stdio.h>
    #include <math.h>
    const double PI=3.1415926535897;
    
    int main() {
    double a,b,c;
    
    while(scanf("%lf %lf %lf",&a,&b,&c)==3){
        double s = (a+b+c)/2.0;
        double area_triangle = sqrt(s*(s-a)*(s-b)*(s-c));
        
        double r = area_triangle/s;
        double R = (a*b*c)/(4.0*area_triangle);
        
        double area_incircle=PI*r*r;
        double area_circumcircle=PI*R*R;
        
        
        double amarelo = area_circumcircle-area_triangle;
        double azul = area_triangle-area_incircle;
        double vermelho = area_incircle;
        
        printf("%.4lf %.4lf %.4lf\n",amarelo,azul,vermelho);
        
    }
 
  
    return 0;
}
