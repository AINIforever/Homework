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
	//��ÿһ��������ַ��ж��Ƿ�Ϸ� 
    	if (str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')//���������ʱ���жϷǷ�����У������������������������������������һ����Ƿ������˳�����������Ϊ�Ƿ����ڶ��������г��ֶ���������Ƿ��� 
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
    	else if ((str[i] >= '0') && (str[i] <= '9'))//�����������������������������ʼ�ڶ������ֵļ��� 
    	{
//    		if ((num1_num > 7)||(num2_num > 7))//������仰��������������ľ��ȣ����������˸�ʱ�޷������� 
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
    	else if (str[i]=='.')//�������С�������жϣ���һ�����г��ֶ��С�����ͷ����С������Ƿ� 
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
double result(char str[100]){//���������ʽ������ 
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
