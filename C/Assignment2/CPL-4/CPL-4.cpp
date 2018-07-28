#include "stdio.h" 
#define PI 3.14159265358979323846
float sinx(float); 
int main() {
   float x;
   printf("Please input x:\n");
   scanf("%f",&x);
   while(x>2*PI){
   	x = x-2*PI;
   }
   while(x<-2*PI){
   	x = x+2*PI; 
   }   
   printf("sin(%.6f)=%.14lf\n",x,sinx(x)); 
   return 0;
}  
	float sinx(float x) {
    int i=1,s=1;   
	float xn,fac,sinx=0;   
	fac=1;xn=x;   
	do{    
		sinx+=s*xn/fac;
	    xn=xn*x*x;   
		fac=fac*(i+1)*(i+2);  
		i+=2;   
		s=-s;    
	}while (xn/fac>1e-6);
   return sinx; }

