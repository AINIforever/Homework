#include<stdio.h>
 
int main()
{
    int a, b;
    char c;
    printf("������������:");
    scanf("%d %d", &a, &b);
    getchar();
    printf("����������Ҫ�����㷨��");
    scanf("%c",&c);
 
    switch (c)
    {
    case '+':
        printf("%d+%d = %d", a, b, a+b);
        break;
    case '-':
        printf("%d-%d = %d", a, b, a-b);
        break;
    case '*':
        printf("%d*%d = %d", a, b, a*b);
        break;
    case '/':
        printf("%d/%d = %d", a, b, a/b);
        break;
    default:
        printf("����ķ����д�");
        break;
    }
    return 0;
}
