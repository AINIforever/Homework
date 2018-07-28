#include<iostream>
#include<math.h>
#include "Triangle.h"
using namespace std;

int main(){
	double a1, b1, c1;
	double a2, b2, c2;
	cout << "Please input three sides of the first triangle x:(Numbers are separated by space.)" << endl;
	cin >> a1 >> b1 >> c1;
	cout << "Please input three sides of the second triangle y:(Numbers are separated by space.)" << endl;
	cin >> a2 >> b2 >> c2;
	Triangle x = Triangle(a1, b1, c1);
	Triangle y = Triangle(a2, b2, c2);
	cout << "The area of first triangle x is:" << x.Area() << endl;
	cout << "The area of second triangle y is:" << y.Area() << endl;
	cout << "And the lager object is:";
	if(x>y){
		cout << "x" << endl;
	}
	else{
		cout << "y" << endl;
	}
	
	return 0;
}
