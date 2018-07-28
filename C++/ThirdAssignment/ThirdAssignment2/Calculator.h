#ifndef Calculator_h
#define Calculator_h

class Calculator{
	double operand1,operand2;
	char operation[3] = {0};
	
public:
	Calculator(double,double,char*);
	double doOperation();
};

#endif
