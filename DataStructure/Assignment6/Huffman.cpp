#include <iostream>
#include <string.h>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include "MinHeap.h"
using namespace std;


// create a MinHeap of size, and insert the elements of data[] into this MinHeap 
MinHeap* createAndBuildMinHeap(char data[], double weight[], int size) {
	MinHeap* minHeap = new MinHeap(size);
	for (int i = 0; i < size; i++) {
		minHeap->array[i] = new TreeNode(data[i], weight[i],i);
	}
	minHeap->size = size;
	minHeap->buildMinHeap();
	return minHeap;
}

// build a HuffmanTree
TreeNode* buildHuffmanTree(char data[], double weight[], int size) {
	TreeNode *lchild, *rchild, *newInner; 
	MinHeap* minHeap = createAndBuildMinHeap(data, weight, size);  
	while (minHeap->size != 1) {
		lchild = minHeap->getMin();
		rchild = minHeap->getMin();
		// create a new inner node using the two minimun ones 
		// here '$' is just a symbol to mark the inner node, has no meaning.
		newInner = new TreeNode('$', lchild->weight + rchild->weight,0);
		newInner->lchild = lchild;
		newInner->rchild = rchild;

		minHeap->insertMinHeap(newInner);
	} 
	return minHeap->getMin();
}
//distroy the HuffmanTree
void distroyTree(TreeNode* current) {
	if (current->lchild && current->rchild)
	{
		distroyTree(current->lchild);
		distroyTree(current->rchild);
	}
	delete current;
}
//!!store the HuffmanCodes, the space of **hCodes are dynamically allocated
void storeCodes(TreeNode* root, stack<char> codesStk, char** hCodes, int* codeSize, char* dataArr, int top = 1) {
	if (root->lchild) {
		if (codesStk.size() == top)
			codesStk.pop();
		codesStk.push('0');
		storeCodes(root->lchild, codesStk, hCodes, codeSize, dataArr, top + 1);
	}
	if (root->rchild) {
		if (codesStk.size() == top)
			codesStk.pop();
		codesStk.push('1');
		storeCodes(root->rchild, codesStk, hCodes, codeSize, dataArr, top + 1);
	}
	if (root->isLeaf()) {
		hCodes[root->position] = new char[top];
		codeSize[root->position] = top;
		dataArr[root->position] = root->data;
		char* arrTest = new char[top];
		for (int i = 0; i < top-1; i++) {
			arrTest[i] = codesStk.top();
			codesStk.pop();
		}
		for (int i = 0; i <top-1; i++) {
			hCodes[root->position][i] = arrTest[top-i-2];
		}
		delete[] arrTest;
	}
	
}
// !!create an object of HuffmanTreeNode, and encode it's Huffamn code, store and output them.
void HuffmanCodes(char data[], double weight[], int size)
{
	TreeNode* root = buildHuffmanTree(data, weight, size);

	char **hCodes = new char*[size];
	int * codeSize = new int[size];
	stack<char> codesStk;
	codesStk.push('0');
	char* dataArr = new char[size];

	//encode the HuffmanCodes and store them in **hCodes.
	storeCodes(root, codesStk, hCodes, codeSize, dataArr);

	//output the results
	cout << "The datas and their weights:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << dataArr[i] << ":" << weight[i] << endl;
	}
	cout << endl;
	cout << "The HuffmanCodes of them:" << endl;
	for (int i = 0; i < size; ++i) {
		int k = codeSize[i];
		cout << dataArr[i] << ":";
		for (int j = 0; j < k; j++) {
			cout << hCodes[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "More intuitively, the structure of it's HuffmanTree:" << endl;
	root->levelOrder();
	cout << endl;
	cout << "Here, we use '*' to represent some null nodes, and '$' to represent the inner nodes" <<endl;

	//!!release all of the sapce that allocated dynamically
	distroyTree(root);
	delete[] dataArr;
	delete[] codeSize;
	for (int i = 0; i < size; i++)
	{
		delete hCodes[i];
	}
	delete[] hCodes;

}




int main() {
	char datas[] = { 'a', 'b', 'c', 'd', 'e', 'f','g','h' };
	double weight[] = { 1.07, 0.24, 0.26, 0.12, 0.32, 0.09, 0.14, 0.05 };  
	int size = sizeof(datas) / sizeof(datas[0]);
	HuffmanCodes(datas, weight, size);
	
	system("pause");
	return 0;
}


