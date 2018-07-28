#include <iostream>
#include "Calculator.h"
#include <cstring>
using namespace std;

Calculator::Calculator(double a, double b, char* op){
	operand1 = a;
	operand2 = b;
	strcpy(operation, op);
}

double Calculator::doOperation(){
	if(strncmp(operation, "add", 3) == 0){
		return operand1 + operand2;
	}
	else if(strncmp(operation, "sub", 3) == 0){
		return operand1 - operand2;
	}
	else if(strncmp(operation, "mul", 3) == 0){
		return operand1 * operand2;
	}
	else if(strncmp(operation, "div", 3) == 0){
		if(operand2 == 0){
			cout << "This operation has no meaning!" << endl;
			return NULL;
		}
		return operand1 / operand2;
	}
	else{
		cout << "Please input correct operation" << endl;
		return NULL;
	}
} 
