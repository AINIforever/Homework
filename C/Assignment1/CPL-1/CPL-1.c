#include <stdio.h>

int main()
{
    int n,digit;
    printf("������һ����λ��ʮ���Ƶ�������");
    scanf("%d",&n);
    printf("���ĸ�λ��ʮλ����λ���ֱַ��ǣ�");
    while(n!=0){
    	//��ȡ�෽ʽȡ��ÿ�ε�ĩβ����ÿ��ѭ����ȥ���������һλ �� 
        digit = n%10;
        printf("%d",digit);
        printf(",");
        n = n/10;
    }
    printf("\n");
    return 0;
}
