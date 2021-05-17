//
// Created by 37157 on 2021/5/7.
//

#ifndef LINKLIST_TREE_H
#define LINKLIST_TREE_H
#define Maxsize 100

#include <cstdlib>
#include <iostream>

using namespace std;
typedef char DataType;

typedef struct BiTNode {
    DataType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void Init_Tree(BiTNode **root);//初始化创建二叉树的头结点
void Destroy(BiTNode **root);//销毁二叉树
BiTNode *InsertLeftNode(BiTNode *curr, DataType x);

BiTNode *InsertRightNode(BiTNode *curr, DataType x);

void PerOrder(BiTNode *t, void visit(DataType item));//前序遍历(递归)
void InOrder(BiTNode *t, void visit(DataType item));//中序遍历(递归)
void PostOrder(BiTNode *t, void visit(DataType item));//后序遍历(递归)
void Visit(DataType item);

void PerOrder2(BiTNode *t, void visit(DataType item));//前序遍历(非递归)
void InOrder2(BiTNode *t, void visit(DataType item));//中序遍历(非递归)
void PostOrder2(BiTNode *t, void visit(DataType item));//后序遍历(非递归) p141 3

void LevelOrder(BiTNode *t, void visit(DataType item));//层次遍历
void InvertLevel(BiTNode *t,void visit(DataType item));//p141 4

int Bi_depth(BiTNode *t);//二叉树的高度(递归)
int Bi_depth2(BiTNode *t);//二叉树的高度(非递归) p141 5
BiTNode *PerInCreat(DataType A[],DataType B[],int strA,int finA,int strB,int finB);
bool IsComplete(BiTNode *t);//判断二叉树是否为完全二叉树 p141 7

//下面是要用到的栈和队列的定义
template<typename T>
struct my_stack {//泛型栈
    T data[Maxsize]{};
    int top = -1;
};

template<typename T>
bool Push(my_stack<T> &S, T x);

template<typename T>
bool Pop(my_stack<T> &S, T &x);

template<typename T>
bool StackEmpty(my_stack<T> S);

template<typename T>
bool GetTop(my_stack<T> &S, T &x);

template<typename T>
struct Queue {
    T data[Maxsize]{};
    int front = 0;//头指针
    int rear = 0;//尾指针
};

template<typename T>
bool EnQueue(Queue<T> &Q, T x);

template<typename T>
bool DeQueue(Queue<T> &Q, T &x);

template<typename T>
bool QueueEmpty(Queue<T> Q);

#endif //LINKLIST_TREE_H
