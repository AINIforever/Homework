#include <stdio.h>

int main()
{
    int mark;
    printf("������ٷ��Ʒ�����");
    scanf("%d",&mark);
    printf("�˷�����Ӧ�ȼ��ǣ�");
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
