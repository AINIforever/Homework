#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle {
private:
	double a, b, c;
public:
	Triangle();
	Triangle(double, double, double);
	double Area();
	friend bool operator>(Triangle, Triangle);
};

#endif

