#include <stdio.h>

int main()
{
	int c;
    for(c = 32; c < 127; c++){
    	printf("%c",c);
    	printf(",");
	} 
    return 0;
}
