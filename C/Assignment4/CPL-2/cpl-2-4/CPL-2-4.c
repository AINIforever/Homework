#include <stdio.h>

int main()
{
	int c, countCH=0, countNUM=0, countSPA=0, countELSE=0;
	printf("请输入一串字符：");
	while((c = getchar()) != '\n'){
		if(c>=65&&c<=90||c>=97&&c<=122){
			countCH++; 
		}
		else if(c>=48&&c<=57){
			countNUM++;
		}
		else if(c==9||c==32){
			countSPA++;
		}
		else{
			countELSE++;
		}
	}
	printf("字母个数：%d",countCH);
//	printf("%d",countCH);
	printf("\n");
	printf("数字个数：%d",countNUM);
	printf("\n");
	printf("空白个数：%d",countSPA);
	printf("\n");
	printf("其他个数：%d",countELSE);
//	printf("\n");
    return 0;
}
