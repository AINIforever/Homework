#include <stdio.h>

int main()
{
	int c;
	printf("������һ����ĸ��");
	scanf("%c",&c);
	//����������ж��ַ������������� 
	if(c<65||c>90&&c<96||c>122){
		printf("�ⲻ����ĸ");
	}
	else if(c>=65&&c<=90){
		printf("���Ǵ�д��ĸ\n");
		printf("����Сд��ĸ�ǣ�%c",c+32);
	}
	else{
		printf("����Сд��ĸ\n");
		printf("���Ĵ�д��ĸ�ǣ�%c",c-32);
	}
    return 0;
}
