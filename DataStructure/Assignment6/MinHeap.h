#pragma once
#include "TreeNode.h"

class MinHeap {
public:
	int size;   
	int capacity; 
	TreeNode **array;
	MinHeap(int capacity) {
		this->size = 0;
		this->capacity = capacity;
		TreeNode **array = (TreeNode **)malloc(capacity * sizeof(TreeNode*));
		this->array = array;
	}
	void adjustDown(int index);
	TreeNode* getMin();
	void insertMinHeap(TreeNode* TreeNode);
	void buildMinHeap();
};
 
void swapTreeNode(TreeNode **a, TreeNode **b) {
	TreeNode* temp = *a;
	*a = *b;
	*b = temp;
}
  
int getLeftIndex(int index) {
	return ((index << 1) + 1);
}
 
int getRightIndex(int index) {
	return ((index << 1) + 2);
}

//adjust the MinHeap
void MinHeap::adjustDown(int index)
{
	int less = index;
	int left = getLeftIndex(index);
	int right = getRightIndex(index);
	if (left < this->size && this->array[left]->weight < this->array[less]->weight) {
		less = left;
	}
	if (right < this->size && this->array[right]->weight < this->array[less]->weight) {
		less = right;
	}
	if (less != index) {
		swapTreeNode(&this->array[less], &this->array[index]);
		adjustDown(less);
	}
}

//get the minimun of the heap
TreeNode * MinHeap::getMin()
{
	TreeNode* temp = this->array[0];
	this->array[0] = this->array[this->size - 1];
	this->size--;
	this->adjustDown(0);
	return temp;
}
//insert a TreeNode into the MinHeap
void MinHeap::insertMinHeap(TreeNode * TreeNode)
{
	this->size++;
	int i = this->size - 1;
	while (i && TreeNode->weight < this->array[(i - 1) / 2]->weight) {
		this->array[i] = this->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	this->array[i] = TreeNode;
}
//!!build a MinHeap by repeating the adjustDown operation
void MinHeap::buildMinHeap()
{
	int index = this->size - 1;
	for (int i = (index - 1) / 2; i >= 0; i--) {
		this->adjustDown(i);
	}
}