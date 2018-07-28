#include <iostream>
#include <unistd.h>
#include <cmath>
#include "Calculator.h"
using namespace std;

int main(int argc, const char* argv[]){
	if(argc != 4){
		cout << "You must give 4 arguments!" << endl;
		return 1;
	}
	
	double op1,op2;
	char opcode[3];
	
	strcpy(opcode, argv[1]);
	op1 = atof(argv[2]);
	op2 = atof(argv[3]);
	
	Calculator one(op1,op2,opcode);
	cout << one.doOperation() << endl;
	
	return 0;
}

