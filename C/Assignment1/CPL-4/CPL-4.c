#include <stdio.h>

int main()
{
	int c, countCH=0, countNUM=0, countSPA=0, countELSE=0;
	printf("������һ���ַ���");
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
	printf("��ĸ������%d",countCH);
//	printf("%d",countCH);
	printf("\n");
	printf("���ָ�����%d",countNUM);
	printf("\n");
	printf("�հ׸�����%d",countSPA);
	printf("\n");
	printf("����������%d",countELSE);
//	printf("\n");
    return 0;
}
