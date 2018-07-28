#include <stdio.h>

int main(){
	int a[10];
	int i,j;
	
	printf("Please input 10 numbers:\n");
	for(i=0; i<10; i++){
		scanf("%d",&a[i]);
	}
	int max = a[0];
	int min = a[0];
	for(j=0; j<10; j++){
		
		if(a[j]>max){
			max = a[j];
		}
		if(a[j]<min){
			min = a[j];
		}
	}
	printf("The maximun and minmun value are:%d,%d",max,min);
	return 0;
}
