#include <stdio.h>


int main(){
	int num;
	
	printf("Please enter a three-digit number:");
	scanf("%d",&num);
	printf("It's unit, ten, humdred are:%d,%d,%d",num%10,(num/10)%10,num/100);
	return 0;
	
}
