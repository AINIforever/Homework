#ifndef TRIANGLE_H
#define TRIANGLE_H

class Complex{
	private: double real,image;
	
public:
   void setValue(double r,double i);
   void addValue(double r,double i); // a=a+b 
   void multiply(double r,double i); // a=a*b
   void displayMessage();
};

#endif
