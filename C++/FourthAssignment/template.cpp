#include <iostream>
using namespace std;
int i;
int j;

template <typename U, typename V>
class Mytest{
	U u;
	V v;
public:
	void getSize(){
		cout << "The size of u is: " << sizeof(u) << "\nThe size of v is: " << sizeof(v) << endl;
	}
};

template <typename K>
void list_item(K *list,int size){
	for (j=0; j<size; j++){
		cout << list[j] << ",";
	}
}

template <typename T>
int find(T val,T *list,int size){
	for (i=0; i<size; i++){
		if (list[i]==val){
			return i;
		}
	}
	return -1;
}


int main(){
	
	int list1[5] = {1,2,3,4,5};
	cout << "list1:";
	list_item(list1,5);
	cout << "\nThe i that satisfy list1[i] == 4 is:" << find(4,list1,5) << endl;
	
	double list2[6] = {1.1,2.2,3.3,4.4,6.6,5.5};
	cout << "list2:";
	list_item(list2,6);
	cout << "\nThe j that satisfy list1[j] == 6.6 is:" << find(6.6,list2,6) << endl;
	
	Mytest <int ,double> test;
	test.getSize();
	return 0;
} 
