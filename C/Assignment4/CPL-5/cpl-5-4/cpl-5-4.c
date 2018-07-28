#include <stdio.h>

rev(int *a,int n)
{
	int *p,*q;
	int temp;
	p = a;
	q = a + n - 1;
	while(p < q){
		while(!((*p)%2)) p++;
		while((*q)%2) q--;
		if(p<q){
			temp = *p;
			*p = *q;
			*q = temp;
			p++;
			q--;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d,",a[i]);
	}
}
int main(){
	int list[10];
	printf("Please input 10 numbers:");
	for(int i=0;i<10;i++){
		scanf("%d",&list[i]);
	}
	printf("The list sorted is:");
	rev(list,10);
	return 0;
}
