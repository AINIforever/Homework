#include <stdio.h>
#include <math.h>

void calculate(float a, float b, float c){
	float s = b*b - 4*a*c;
	
	if(s>0){
		s = sqrt(s);
		float x1 = (b*(-1)+s)/2*a;
		float x2 = (b*(-1)-s)/2*a;
		
		printf("The two real roots are:%f,%f\n",x1,x2);
	}
	else if(s==0){
		float x = b*(-1)/2*a;
		
		printf("The only one root is:%f\n",x);
	}
	else{
		s = sqrt((-1)*s);
		float a1 = b*(-1)/2*a;
		float a2 = s/2*a;
		printf("The two complex roots are:%f+%fi,%f-%fi",a1,a2,a1,a2);
	}
}

int main(){
	int count = 0;
	float a,b,c;
	
	while(count<3){//用来测试三种不同情况 
	printf("The form of equotion is: ax^2 + bx + c = 0\nPlease input a, b and c:");
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	
	calculate(a,b,c);
	count++; 
}
	return 0;
}
