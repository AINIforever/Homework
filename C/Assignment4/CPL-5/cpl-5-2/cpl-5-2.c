#include <stdio.h>

//void insert(int arr[], int num){
//	
//	printf("%d\n",length);
//	
//}

int main(){
	int arr[] = {1,10,20,30,40,50,60,70,80,90};
	int num,i;
	int length = sizeof(arr)/sizeof(arr[0]);
	printf("This is the arr:");
	printf("\n%d\n",length);
	for(i=0;i<length;i++){
		printf("%d,",arr[i]);
	}
	printf("\nPlease input your number:\n");
	scanf("%d",&num);
	printf("The new array is:");
	
	int arr1[length+1],x;
	for(i=0;i<length+1; i++){
			if(num<arr[0]){
				arr1[0] = num;
				arr1[i+1] = arr[i];
			}
			else if(num>arr[i]){
				arr1[i] = arr[i];
				arr1[i+1] = num;
			}
			else if(num<arr[i]){
				arr1[i+1] = arr[i];
			}
			printf("%d,",arr1[i]);
		}
	
	
	return 0;
}
