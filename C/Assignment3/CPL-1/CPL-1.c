#include <stdio.h>


void rank_by_select(int *list, int size){
	int i;
		for(i=0; i<size-1; i++){
			int index = i;
			int j;
			for(j=i+1; j<size; j++){
				if(list[index] > list[j]){
					int temp = list[index];
					list[index] = list[j];
					list[j] = temp;
				}
			}
		}
		int k;
		for(k=0; k<size; k++){
			printf("%d,",list[k]);
		}
}

void rank_by_bubbling(int *list,int size){
	int i;
	for(i=0; i<size-1; i++){
		int j;
		for(j=0; j<size-1-i; j++){
			if(list[j]>list[j+1]){
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	int k;
	for(k=0;k<size;k++){
		printf("%d,",list[k]);
	}
	
}
int main(){
	printf("Please input 10 int numbers:\n");
	int list[10];
	int j;
	for (j=0; j<10; j++){
		scanf("%d",&list[j]);
	}
	printf("The number ranked by selected are:");
	rank_by_select(list,10);
	printf("\n");
	printf("The number ranked by bubbling are:");
	rank_by_bubbling(list,10);
	
	return 0;
} 
