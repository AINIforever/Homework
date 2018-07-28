#include<iostream>

using namespace std;

class Student 
{
public:
	Student(int n) 
	{
		num = n;
		cout << "Constructor called. The sutdent's num is:" << num << endl; 
	}
	~Student() 
	{
		cout << "Destructor called. The student's num is " << num << "." << endl;
	} 
	void displayNum() 
	{
		cout << "Method displayNum() called. The sudent's num is: " << num << endl;

	}
private:
	int num;
};

Student stud3(3);
Student stud4(4);
int main()
{
	Student stud1(1); 
	Student stud2(2); 

	stud1.displayNum();
	stud2.displayNum(); 

	stud3.displayNum();
	stud4.displayNum();
	return 0;
}

//By running the program, we can find that:
//1. The one who is constructed first will be destructed last.
//2. Global objects's destructor will be excuted later than the local ones. 