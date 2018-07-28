#include <iostream>
#include <fstream>
#include <sstream> 
using namespace std;

inline void isLeapYear(int year, ofstream & output){
	
	if ((year%4==0 && year%100!=0) || year%400==0){
        output << year << " is a leap year." << endl;
    }
	else{
        output << year << " is not a leap year." << endl;
    }
}

int main(){
	char line[256];
	int year;

	ifstream ifile("data.txt");

	ifile.getline(line,256);
	istringstream iss(line);
	
	iss>>year;
   		
	ofstream outfile;
	outfile.open("1.txt");
	
	isLeapYear(year,outfile);

	outfile.close();
	
	return 0;
}
