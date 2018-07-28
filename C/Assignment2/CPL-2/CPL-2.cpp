#include <stdio.h>

int main()
{
    int mark;
    printf("请输入百分制分数：");
    scanf("%d",&mark);
    printf("此分数对应等级是：");
    if(mark>=90){
    	printf("A");
	}
	else if(mark>=80){
		printf("B");
	}
	else if(mark>=70){
		printf("C");
	}
	else if(mark>=60){
		printf("C");
	}
	else{
		printf("E");
	}
    printf("\n");
    return 0;
}
