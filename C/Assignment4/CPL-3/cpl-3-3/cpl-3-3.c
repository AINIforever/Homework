#include<stdio.h>
 
int main()
{
    int a, b;
    char c;
    printf("请输入两个数:");
    scanf("%d %d", &a, &b);
    getchar();
    printf("请输入你需要的运算法则：");
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
        printf("输入的符号有错！");
        break;
    }
    return 0;
}
