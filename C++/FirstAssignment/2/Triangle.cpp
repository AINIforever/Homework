#include<iostream>
#include<math.h>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(){
	a = 1;
	b = 1;
	c = 1;
}
Triangle::Triangle(double para_a,double para_b,double para_c){
	a = para_a;
	b = para_b;
	c = para_c;
}
double Triangle::Area(){
	double S;
	double p = (a+b+c)/2;
	S = sqrt(p*(p-a)*(p-b)*(p-c));
	return S;
}

bool operator>(Triangle x,Triangle y){
    return (x.Area() > y.Area());
}
