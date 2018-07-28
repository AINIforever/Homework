#include <iostream>
using namespace std;

namespace mynamespace{
	int max(int a, int b, int c){
		if(b>a) a = b;
		if(c>a) a = c; 
		return a;
	}
} 

int main(){
	int a,b,c;
	cout << "Please input three numbers:" << endl;
	cin >> a >> b >> c;
	cout << "The maxmum of the three numbers is:" << mynamespace::max(a,b,c) << endl;
	return 0;
}
