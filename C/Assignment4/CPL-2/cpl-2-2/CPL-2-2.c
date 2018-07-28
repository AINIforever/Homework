#include <stdio.h>

int main()
{
	int c;
	printf("请输入一个字母：");
	scanf("%c",&c);
	//用条件语句判断字符属于那种类型 
	if(c<65||c>90&&c<96||c>122){
		printf("这不是字母");
	}
	else if(c>=65&&c<=90){
		printf("这是大写字母\n");
		printf("它的小写字母是：%c",c+32);
	}
	else{
		printf("这是小写字母\n");
		printf("它的大写字母是：%c",c-32);
	}
    return 0;
}
