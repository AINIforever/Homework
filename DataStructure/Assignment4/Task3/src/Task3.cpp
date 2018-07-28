#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "BTNode.h"


using namespace std;

template <class T> void BuildCompleteTree(T arr[], int n) {
	BTNode<T> *cur;
	BTNode<T> *root = new BTNode<T>();
	int i = 0;
	if (n == 0) {
		return;
	}
	root->data = arr[1];
	queue<BTNode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		i++;
		if (2 * i <= n) {
			cur->lchild = new BTNode<T>;
			cur->lchild->data = arr[2 * i];
			q.push(cur->lchild);
		}
		if (2 * i + 1 <= n) {
			cur->rchild = new BTNode<T>;
			cur->rchild->data = arr[2 * i + 1];
			q.push(cur->rchild);
		}

	}
	cout << "The comlete binary tree has been finished" << endl;
	cout << "It's InOrder seqeunce is:" << endl;
	InOrder(root);
	cout << endl;
	cout << "And it's PreOrder sequence is:" << endl;
	PreOrder(root);
}




int main() {
	string str;
	cout << "Please input your array start with 0:(No sapce between elements)" << endl;
	cout << "(For example: 0123456, the the actual array is 123456)" << endl;
	getline(cin, str);
	char*arr = (char*)str.data();
	int n = strlen(arr);
	BuildCompleteTree(arr, n-1);
	getchar();
	return 0;
}