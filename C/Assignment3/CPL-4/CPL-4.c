#include <stdio.h>

int main(){
	
	char array[1000];

	printf("Please input a string:(the max length is 1000)\n");
	gets(array);
	printf("The string is:\n");
	for(int i=0; array[i] != '\0'; i++){
		printf("%c",array[i]);
	}
	
	return 0;
}
