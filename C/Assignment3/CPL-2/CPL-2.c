#include <stdio.h>

int list[10] = {1,12,34,47,55,61,78,84,90,105};

void search(int x, int y,int k){
	int m = x + (y-x)/2;
	if (x>y){
		int list2[11];
		for(int i=0;i<11; i++){
			if(list[i]<k&&list[i+1]>k){
				x = i+1;
			}
			if(i<x){
				list2[i] = list[i];
			}
			else if(i==x){
				list2[i] = k;
			}
			else list2[i] = list[i-1];
			printf("%d,",list2[i]);
		}
	}
	else {
		if (list[m]==k){
			printf("There is a number in list that equal to k!");
		} 
		else if (list[m]>k){//���õݹ������ֲ��� 
			return search(x,m-1,k);
		}
		else{
			return search(m+1,y,k);
		}
	}
}

int main(){
	int count = 0;
	while(count<2){//ѭ������չʾ��ͬ����ʱ��Ӧ�������� 
		printf("\nThis is a list:");
		int i;
		for(i=0;i<10;i++){
			printf("%d,",list[i]);
		}
		printf("\nPlease input a number k:");
		int k;
		scanf("%d",&k);
		search(0,9,k);
		count++;
	}
	return 0;
}
