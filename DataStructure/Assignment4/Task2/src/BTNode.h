#pragma once
#include <iostream>
#include <string>
#include <stack>


using namespace std;

template <class T>
struct BTNode {
	T data;
	BTNode<T> *lchild, *rchild;
	BTNode()
	{
		lchild = NULL;
		rchild = NULL;
		data = NULL;
	}
	BTNode(T pdata) {
		data = pdata;
		lchild = NULL;
		rchild = NULL;
	}
};

template <class T> void InOrder(BTNode<T> *root)
{
	if (!root) return;
	BTNode<T>* cur = root;
	stack<BTNode<T>*> stk;
	while (!stk.empty() || cur)
	{
		if (cur)
		{
			stk.push(cur);
			cur = cur->lchild;
		}
		else
		{
			cur = stk.top();
			stk.pop();
			cout << cur->data << " ";
			cur = cur->rchild;
		}
	}
}

template <class T> void PreOrder(BTNode<T> *root) {
	if (!root) return;
	cout << root->data << " ";
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}