#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "BTNode.h"


using namespace std;

void ConstructTree(string str) {
	int *sub_index = new int[50];
	sub_index[0] = -1;
	int j = 0;

	if (str.length() == 0) return;
	else {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				sub_index[j + 1] = i;
				j++;
			}
		}
		string* strElement = new string[j + 1];
		sub_index[j + 1] = str.length();
		for (int i = 0; i <= j; i++) {
			strElement[i] = str.substr(sub_index[i] + 1, sub_index[i + 1] - sub_index[i] - 1);
		}
		BTNode<char>* *treeNode = new BTNode<char>*[j + 1];
		for (int i = 0; i < j + 1; i++) {
			treeNode[i] = new BTNode<char>((strElement[i])[0]);

		}

		int t = 0;
		while (t <= j) {
			switch (strElement[t].length()) {
			case 5:
				for (int i = 0; i < t; i++) {
					if ((strElement[t])[2] == treeNode[i]->data)
					{
						treeNode[i]->rchild = treeNode[t];
					}
				}
				break;
			case 4:
				for (int i = 0; i < t; i++) {
					if ((strElement[t])[2] == treeNode[i]->data) {
						if (treeNode[i]->lchild == NULL) {
							treeNode[i]->lchild = treeNode[t];
						}
						else {
							treeNode[i]->rchild = treeNode[t];
						}
					}
				}
				break;
			}
			t++;
		}
		cout << "The tree constructed by your input has been finished.It's InOrder sequence(for Task1) is:" << endl;
		InOrder(treeNode[0]);
		cout << endl;
		cout << "And it's PreOrder sequence is:" << endl;
		PreOrder(treeNode[0]);
		cout << endl;

	}

}




int main() {
	string example = "A B(A) C(A) D(BR) E(C) F(C) G(E) H(E)";
	cout << "For Task2, We have the answer for example:";
	cout << example << endl;
	ConstructTree(example);
	cout << "You can define your own tree using this format" << endl;
	cout << "------------------------------------" << endl;

	string inputForTree;

	cout << "Please input your string to build the tree():" << endl;
	getline(cin, inputForTree);
	ConstructTree(inputForTree);
	getchar();


	return 0;
}