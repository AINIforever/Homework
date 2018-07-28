#include <stdio.h>

int main()
{
	int n,count=0,i;
	char ch[100];
	printf("请输入偏移量：");
	scanf("%d",&n);
	int c;
	printf("请输入需要加密的序列：\n");
	while((c = getch()) != '\r'){		
		if(c>=65&&c<=90){
			c = c - 64;
			c = (c+4) % 26;
//			c = c + 64;
			ch[count++] = c + 64;
 		}
 		else if(c>=97&&c<=122){
 			c = c - 96;
			c = (c+4) % 26;
			c = c + 96;
			ch[count++] = c;
		}
		else{
			ch[count++] = c;
		}
	}
	printf("加密后的序列为：%s",ch);
	 return 0;
}
