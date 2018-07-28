#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

bool judgeLegal(char str[100]);
double result(char str[100]);

int i = -1;
	int operFir = 0;
	int operSec = 0;
	int dotNum = 0;
	int operNum = 0;
	
	int num1_num = 0;
	int num2_num = 0;

int operXu;
double number1 = 0;
double number2 = 0;
int sign1 = 1;
int sign2 = 1;
bool judgeLegal(char str[100]){
	//对每一个输入的字符判断是否合法 
    	if (str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')//出现运算符时，判断非法情况有：接连出现两个运算符，若不与正负号连在一起，则非法；将乘除当做正负号为非法；第二个数字中出现多个运算符则非法； 
    	{
    		if ((i==0)&&(str[i]!='*')&&(str[i]!='/'))
    		{
    			operFir = 1;
    			if (str[i]=='-')
    			{
    				sign1 = -1;
    			}
    		}
    		else if ((i==1)&&(operFir==1))
    		{
    			return false;
    		}
    		else if (operNum == 0)
    		{
    			operNum = 1;
    			operXu = i;
    			dotNum = 0;
    		}
    		else if ((operNum == 1)&&(i == operXu+1)&&(str[i]!='*')&&(str[i]!='/'))
    		{
    			operSec = 1;
    			if (str[i]=='-')
    			{
    				sign2 = -1;
    			}
    		}
    		else return false;
    	}
    	else if ((str[i] >= '0') && (str[i] <= '9'))//对数字作计数，当出现运算符，则开始第二个数字的计数 
    	{
//    		if ((num1_num > 7)||(num2_num > 7))//加上这句话可限制输入的数的精度，但当出现退格时无法起作用 
//    		{
//    			return false;
//    		}
    		if (operNum==0)
    		{
    			num1_num++;
    		}
    		else if (operNum==1)
    		{
    			num2_num++;	
    		}
    	}
    	else if (str[i]=='.')//对输入的小数点做判断，若一个数中出现多个小数点或开头出现小数点则非法 
    	{
    		if(i==0){
    			return false;
			}
    		if (operNum==0)
    		{
    			dotNum++;
    			if (dotNum>1)
    			{
    				return false;
    			}
    			else if (operFir==1&&i==1)
    			{
    				return false;
    			}
    		}
    		if (operNum==1)
    		{
    			dotNum++;
    			if (dotNum>1)
    			{
    				return false;
    			}
    			else if (str[i-1]=='+'||str[i-1]=='-'||str[i-1]=='*'||str[i-1]=='/')
    			{
    				return false;
    			}
    		}
    	}
    	else return false;
    	return true;
}
double result(char str[100]){//对输入的算式计算结果 
	int j;
	double dotNum = 0;
	int operNum = 0;
	for (j = 0; j < i+1; j++){
		if((str[j] >= '0') && (str[j] <= '9')){
		
	    	if(operNum == 0){
				if (dotNum == 0) {
					number1 = number1 * 10 + (int)str[j] - (int)'0';
				}
		    else {
				dotNum = dotNum*0.1;
				number1 = number1 + dotNum*((int)str[j] - (int)'0');
			}
		}
		else{
			if (dotNum == 0) {
				number2 = number2 * 10 + (int)str[j] - (int)'0';
				}
		    else {
				dotNum = dotNum*0.1;
				number2 = number2 + dotNum*((int)str[j] - (int)'0');
			}
		}
		}
		if(str[j]=='.'){
			dotNum = dotNum +1;
		}
		if(j==operXu){
			operNum = 1;
			dotNum=0;
		}
	}
	number1 *= sign1;
	number2 *= sign2;
	if (str[operXu] == '+') {
		return number1 + number2;
	}
	else if (str[operXu] == '-') {
		return number1 - number2;
	}
	else if (str[operXu] == '/') {
		return number1 / number2;
	}
	else if (str[operXu] == '*') {
		return number1*number2;
	}
	return number1;
}

int main() {

	char ch;
	char str[100];
	while ((ch = _getch())!='\r') {
		i++;
		str[i] = ch;
		if (ch == '\b') {
			printf("\b");
			printf(" ");
			printf("\b");
			i=i-2 ;
		}
		else if (judgeLegal(str)){
			printf("%c", ch);
		}
		else {
			i--;
			printf("\07");
		}
	}
	printf("\n");
	if (judgeLegal(str)) {
		printf("%g\n",result(str));
	}
	else printf("Wrong equation.\n");

	system("pause");
	return 0;
}
