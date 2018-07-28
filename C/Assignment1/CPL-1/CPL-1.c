#include <stdio.h>

int main()
{
    int n,digit;
    printf("请输入一个三位数十进制的整数：");
    scanf("%d",&n);
    printf("它的个位、十位、百位数字分别是：");
    while(n!=0){
    	//用取余方式取出每次的末尾数，每次循环后去掉该数最后一位 。 
        digit = n%10;
        printf("%d",digit);
        printf(",");
        n = n/10;
    }
    printf("\n");
    return 0;
}
