//
// Created by 37157 on 2021/5/7.
//

#ifndef LINKLIST_TREE_H
#define LINKLIST_TREE_H

#include <iostream>
#include <cstdlib>
#include <vector>

#define Maxsize 100
using namespace std;
typedef char DataType;

typedef struct BiTNode {
    int level;//p142 14
    int weight=2;//p142 19
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
void InvertLevel(BiTNode *t, void visit(DataType item));//p141 4

int Bi_depth(BiTNode *t);//二叉树的高度(递归)
int Bi_depth2(BiTNode *t);//二叉树的高度(非递归) p141 5
BiTNode *PerInCreat(DataType A[], DataType B[], int strA, int finA, int strB, int finB);

bool IsComplete(BiTNode *t);//判断二叉树是否为完全二叉树 p141 7
int DsonNodes(BiTNode *t);//计算二叉树中双分支结点的个数(递归) p142 8
int DsonNodes2(BiTNode *t);//计算二叉树中双分支结点的个数(非递归) p142 8

void swap(BiTNode *t);//交换二叉树的左右结点 p142 9
DataType PerNode(BiTNode *t, int k);//先序遍历中第k个结点的值 p142 10

//p142 11
void DeleteXTree(BiTNode *t);

void Search(BiTNode *t, DataType x);

//p142 12
void find_ancestor(BiTNode *t, DataType x, void visit(DataType item));//找到x(唯一)的全部祖先

//p142 13
template<typename T>
void find_ancestor1(BiTNode *t, DataType x, vector<T> &vector1, void operate(DataType item, vector<T> &vector));

template<typename T>
void Operate(DataType item, vector<T> &vector);

DataType find_comm_ancestor(BiTNode *t, DataType x, DataType y);

//p142 14
int BTWidth(BiTNode *t);

//p142 15
void PerToPost(DataType *per, int str1, int fin1, DataType *post, int str2, int fin2);

//p142 16
BiTNode *Make_Leaf_to_Linklist(BiTNode *t);

//p142 17
bool similar(BiTNode *t1,BiTNode *t2);

//p142 19
void WPL(BiTNode *t,int deep,int &wpl);

//p142 20
void BtreeToExp(BiTNode *t,int deep);

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
