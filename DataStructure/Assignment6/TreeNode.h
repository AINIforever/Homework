#pragma once
#include <iostream>
using namespace std;
// the Node of HuffmanTree  
class TreeNode {
public:
	char data;
	double weight;
	TreeNode *lchild, *rchild;
	int position;
	TreeNode(char data, double weight, int position) {
		this->lchild = this->rchild = NULL;
		this->data = data;
		this->weight = weight;
		this->position = position;
	}
	bool isLeaf();
	int getTreeHeight();
	void printNodeAtLevel(int level, int total);
	void levelOrder();
};

bool TreeNode::isLeaf()
{
	return !(this->lchild) && !(this->rchild);
}

int max(int a, int b) {
	return a > b ? a : b;
}

int TreeNode::getTreeHeight()
{
	if (!this)
		return 0;
	int leftHeight = this->lchild->getTreeHeight();
	int rightHeight = this->rchild->getTreeHeight();
	return max(leftHeight, rightHeight) + 1;
}


void TreeNode::printNodeAtLevel(int level, int total)
{
	if (!this || level < 0) {
		int space = pow(2, total - 1) - 1;
		for (int i = 0; i < space; i++)
			cout << "_";
		cout << "*";
		for (int i = 0; i < space+1; i++)
			cout << "_";
		return;
	}
	
	if (0 == level)
	{
		int space = pow(2, total - 1) - 1;
		for (int i = 0; i < space; i++)
			cout << "_";
		
		cout << this->data;
		for (int i = 0; i < space+1; i++)
			cout << "_";
		return;
	}   

	this->lchild->printNodeAtLevel(level - 1,total-1);    
	this->rchild->printNodeAtLevel(level - 1,total-1);
}

void TreeNode::levelOrder()
{
	if (!this)
		return;
	int totalLevel = this->getTreeHeight();
	for (int i = 0; i < totalLevel; i++)
	{
		this->printNodeAtLevel(i,totalLevel);
		cout << endl; 
	}
}