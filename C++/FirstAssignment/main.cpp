#include <iostream>
#include "Complex.h"
#include <math.h>
using namespace std;

int main(){
	Complex a,b,sum;
	double real1,real2,image1,image2;
	cout << "Please input real of a:" << endl;
	cin >> real1;
	cout << "Please input image of a:" << endl;
	cin >> image1;
	cout << "Please input real of b:" << endl;
	cin >> real2;
	cout << "Please input image of b:" << endl;
	cin >> image2;
	a.setValue(real1,image1);
	b.setValue(real2,image2);
	cout << "The value of complex a is :";
	a.displayMessage();
	cout << "The value of complex b is :";
	b.displayMessage();
	sum.addValue(real1,image1);
	sum.addValue(real2,image2);
	a.multiply(real2,image2);
	cout << "a + b =" << endl;
	sum.displayMessage();
	cout << "a * b =" << endl;
	a.displayMessage();
	return 0;
}

