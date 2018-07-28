//给定一个数组，将其转换成用二叉链表实现的完全二叉树
#include <iostream>
#include "seqQueue.h"
using namespace std;

template <class T> class BTNode{
    T element;
    BTNode *lchild;
    BTNode *rchild;
public:
    BTNode(){
        lchild = rchild = NULL;
    }
    template <class T> friend class BTree;
};

template <class T> class BTree{
    BTNode<T> *root;
public:
    void PrintTree(BTNode<T> *r);
    void PrintTree(){
        PrintTree(root);
    }
    void BuildCompleteBTree(T arr[], int n);
}

//假设完全二叉树的根节点存放在数组元素arr[1]中
template <class T> void BTree<T>::BuildCompleteBTree(T arr[], int n){
    BTNode<T> *ptr;
    int i=0;
    if(n==0){
        root = NULL;
        return;
    }
    root = new BTNode<T>;
    root->element = arr[1];
    SeqQueue<BTNode<T>*> q(n); q.EnQueue(root);
    while(!q.IsEmpty()){
        ptr = q.Front();
        q.DeQueue();
        i++;
        if(2*i<=n){
            ptr->lchild = new BTNode<T>;
            ptr->lchild->element = arr[2*i];
            q.EnQueue(ptr->lchild);
        }
        if(2*i+1<=n){
            ptr->rchild = new BTNode<T>;
            ptr->rchild->element = arr[2*i+1];
            q.EnQueue(ptr->rchild);
        }
    }
}

template <class T> void BTree<T>::PrintTree(BTNode<T> *r){
    if(!r) return;
    PrintTree(r->lchild);
    cout<< r->element << "";
    PrintTree(r->rchild);
}

//假设二叉树用二叉链表表示，写一个算法求二叉树的高度
template <class T> int tree_height(BTNode<T> *root){
    if(!root) return 0;
    int LeftHeight = tree_height(root->lchild);
    int RightHeight = tree_height(root->rchild);
    if(LeftHeight>RightHeight) return LeftHeight+1;
    return RightHeight+1;
}

//写一个算法求叶节点数
template <class T> int leaf_num(BTNode<T> *root){
    if(!root) return 0;
    if(!root->lchild && !root->rchild){
        return 1;
    }
    else return leaf_num(root->lchild) + leaf_num(root->rchild);
}

//判断一棵树是否为完全二叉树
template <class T> bool isComplete(BTNode<T> *root){
    BTNode<T> *u;
    bool ended = false;
    if(!root) return true;
    SeqQueue<BTNode<T> *> q(CAPACITY);
    q.EnQueue(root);
    while(!q.IsEmpty()){
        q.DeQueue(u);//u出队
        if(!u) ended = true;
        else{//访问u的子节点并入队
            if(ended) return false;
            q.EnQueue(u->lchild);
            q.EnQueue(u->rchild);
        }
    }
    return true;
}

//判断一棵树是否为二叉搜索树
bool isBSTree(BTNode *tree, int &predecessor){
    if(!tree) return true;
    if(!isBSTree(tree->lchild, predecessor)) return false;
    if(tree->element<=predecessor) return false;
    predecessor = tree->element;
    return isBSTree(tree->rchild,predecessor);
}
bool isBSTree(BTNode *tree){
    int predecessor = numeric_limits<int>::min();
    return isBSTree(tree, predecessor);
}
//计算在第i（i>=1）层（包含第i层）之后所有节点的个数
int NumberofNodes(BTNode *tree, int level, int i){
    if(!tree) return 0;
    int leftn = NumberofNodes(tree->lchild, level+1, i);
    int rightn = NumberofNodes(tree->rchild, level+1, i);
    if(level>=i){
        return 1+leftn+rightn;
    }
    else return leftn+rightn;
}

int NumberofNodes(BTNode *tree, int i){
    return NumberofNodes(tree,1,i);
}

int main(){
    char str[] = {0,'A','B','C','D','E'};
    BTree<char> t;
    t.BuildCompleteBTree(str,5);
    t.PrintTree();
    getchar();
    return 0;
}

