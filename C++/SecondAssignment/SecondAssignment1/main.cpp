#include <iostream>
#include "displayInBinary.h"
using namespace std;

int main(){
	int num;
	char ch;
	short sh;
	float f;
	while (true){
	
		cout << "Please  follow the prompts below to enter the number to select input data type and then start your input:" << endl;
		cout << "1--char\n2--short\n3--float\n" << endl;
		cin >> num;
	
		if(num == 1){
			cin >> ch;
			displayInBinary(&ch, sizeof(char));
			continue;
		}
		else if(num == 2){
			cin >> sh;
			displayInBinary(&sh, sizeof(short));
			continue;
		}
		else if(num == 3){
			cin >> f;
			displayInBinary(&f, sizeof(float));
			continue;
		}
		else if(num == 4){
			break;
		}
		else break;
	}
		
//	char ch1 = 'a';   //this is a test about the given examples
//	displayBinary(&ch1, sizeof(char));
//    
//    int intt = 257;
//    displayBinary(&intt, sizeof(int));
//    
//    float f = 1.0f;
//    displayBinary(&f, sizeof(float));
	return 0;
}

