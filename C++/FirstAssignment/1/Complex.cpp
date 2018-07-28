#include<iostream>
#include<math.h>
#include "Complex.h"
using namespace std;

void Complex::setValue(double r,double i){
	real = r;
	image = i;
}

void Complex::addValue(double r,double i){//实现复数相加
 real += r;
 image += i;
}

void Complex::multiply(double r,double i){
	int real_cp = real;
	real = real_cp*r - image*i;
	image = real_cp*i + image*r;
}

void Complex::displayMessage(){
	cout << real;
	cout << "+";
	cout << image;
	cout << "i" << endl;
}
