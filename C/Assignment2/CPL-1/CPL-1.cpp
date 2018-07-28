#include <stdio.h>

int main()
{
    int mark;
    printf("请输入百分制分数：");
    scanf("%d",&mark);
    printf("此分数对应等级是：");
    switch((int)(mark/10))
	{
	    case 10:
	    case 9: 
		  printf("A");
	      break;
	    case 8: 
		  printf("B");
		  break;
		case 7: 
		  printf("C");
		  break;
		case 6: 
		  printf("D");
		  break;
		default: 
		  printf("E");
		  break;
	} 
    printf("\n");
    return 0;
}
