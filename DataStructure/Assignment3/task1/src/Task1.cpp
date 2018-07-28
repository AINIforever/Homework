#include<iostream>
using namespace std;

const int SIZE = 100;


bool isInStack[2 * SIZE];
int length = 4;
int lengthTest;
int mSeq[SIZE];  

void printSeq(int in_num, int st_num, int cur) {
	if (cur<2 * length) { 
		if (in_num<length) { 
			isInStack[cur] = true;
			printSeq(in_num + 1, st_num + 1, cur + 1);
		}
		if (st_num) { 
			isInStack[cur] = false;
			printSeq(in_num, st_num - 1, cur + 1);
		}
	}
	else { 
		int outIndex = 0, outElement=1;
		for (int i = 0; i<2 * length; i++) {
			if (isInStack[i]) {
				mSeq[outIndex] = outElement;
				outElement++;
				outIndex++;
			}
			else {
				outIndex--;
				cout << mSeq[outIndex] << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	cout << "The result sequences of deafalt length 4:" << endl;
	printSeq(0, 0, 0);
	cout << "Of cause you can define your length" << endl;
	while (true) {
		cout << "Please enter the length of your sequence:(enter 0 to exit)" << endl;
		cin >> lengthTest;
		if (lengthTest == 0)
			break;
		length = lengthTest;
		printSeq(0, 0, 0);
	}
	
	system("pause");
}







