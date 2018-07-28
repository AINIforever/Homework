#include <stdio.h>
int count=1;
void fun(char c){
	
	if(c>'_'){
		count = -1;
		
		if(c>'a'){
			printf("%c",c);
			c = c+32*count;
			fun(c-1);
			count = (-1)*count;
			c = c+32*count;
			printf("%c",c);
		}
		if(c=='a'){
			printf("%c",c);
			count = (-1)*count;
			c = c+32*count;
		}
	}
	else if(c<'_'){
		count = 1;
		
		if(c>'A'){
			printf("%c",c);
			c = c+32*count;
			fun(c-1);
			count = (-1)*count;
			c = c+32*count;
			printf("%c",c);
		}
		if(c=='A'){
			printf("%c",c);
			count = (-1)*count;
			c = c+32*count;
		}
	}
	
	
}

int main(){
	printf("Please input a character:");
	char c = getchar();
	fun(c); 
	return 0;
}
