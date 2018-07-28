#include <iostream>
#include "displayInBinary.h"
using namespace std;

void displayInBinary(void *data,int len){
	char *p = (char*)data;
	char arr[len];
	for(int i=0; i<len; i++){
		arr[i] = *p;
		p++;
	}	
	for(int j=len-1; j>-1; j--){
		binaryOut(arr[j]);
	}
	cout << '\n';	
}

void binaryOut(char c){
	unsigned char tmp = 0x80;
	for(int i=0;i<8;i++){
		if(c&tmp)
			cout << 1;
		else
			cout << 0;
		tmp >>= 1;
	}
}
