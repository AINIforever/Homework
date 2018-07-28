#include <stdio.h>

int main(){
	printf("请输入9个数字（按空格隔开即可,每三个视为一行）:\n");
	int k;
	int a[3][3];
	for (k=0;k<3;k++){
		int y;
		for(y=0;y<3;y++){
			scanf("%d",&a[k][y]);
		}
	}
	printf("以下和的顺序分别为：第一行，第一列，第二行，...，右对角线，左对角线：\n");
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int i;
	for(i=0;i<3;i++){
		int j;
		for(j=0;j<3;j++){
			num1 += a[i][j];
			num2 += a[j][i];
			if(j==i){
				num3 += a[i][j];
			}
			if(j+i==2){
				num4 += a[i][j];
			}
		}
		printf("%d\n",num1);
		num1 = 0;
		printf("%d\n",num2);
		num2 = 0;
	}
	printf("%d\n",num3);
	printf("%d\n",num4);
}
