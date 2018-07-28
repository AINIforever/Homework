#include <iostream>
using namespace std;

void sort(int &i, int &j, int &k) {
	int m;
	while (1) {
		if (i > j) {
			m = i; i = j; j = m;
		}
		m = j; j = k; k = m;
		if (i < j&&j < k)
			break;
	}
	
}

int main() {
	int i = 3;
	int j = 5;
	int k = 4;
	sort(i, j, k);
	cout << i << j << k << endl;
	getchar();
}
