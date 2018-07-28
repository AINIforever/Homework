#include <stdio.h>

void swap(int *x,int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(){
	int a,b;
	printf("Please input two numbers:");
	scanf("%d",&a);
	scanf("%d",&b);
	swap(&a,&b);
	printf("The two numbers swaped are:%d,%d",a,b);
	return 0;
}
