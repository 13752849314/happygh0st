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

void Init_Tree(BiTNode **root);//��ʼ��������������ͷ���
void Destroy(BiTNode **root);//���ٶ�����
BiTNode *InsertLeftNode(BiTNode *curr, DataType x);

BiTNode *InsertRightNode(BiTNode *curr, DataType x);

void PerOrder(BiTNode *t, void visit(DataType item));//ǰ�����(�ݹ�)
void InOrder(BiTNode *t, void visit(DataType item));//�������(�ݹ�)
void PostOrder(BiTNode *t, void visit(DataType item));//�������(�ݹ�)
void Visit(DataType item);

void PerOrder2(BiTNode *t, void visit(DataType item));//ǰ�����(�ǵݹ�)
void InOrder2(BiTNode *t, void visit(DataType item));//�������(�ǵݹ�)
void PostOrder2(BiTNode *t, void visit(DataType item));//�������(�ǵݹ�) p141 3

void LevelOrder(BiTNode *t, void visit(DataType item));//��α���
void InvertLevel(BiTNode *t,void visit(DataType item));//p141 4

int Bi_depth(BiTNode *t);//�������ĸ߶�(�ݹ�)
int Bi_depth2(BiTNode *t);//�������ĸ߶�(�ǵݹ�) p141 5
BiTNode *PerInCreat(DataType A[],DataType B[],int strA,int finA,int strB,int finB);
bool IsComplete(BiTNode *t);//�ж϶������Ƿ�Ϊ��ȫ������ p141 7

//������Ҫ�õ���ջ�Ͷ��еĶ���
template<typename T>
struct my_stack {//����ջ
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
    int front = 0;//ͷָ��
    int rear = 0;//βָ��
};

template<typename T>
bool EnQueue(Queue<T> &Q, T x);

template<typename T>
bool DeQueue(Queue<T> &Q, T &x);

template<typename T>
bool QueueEmpty(Queue<T> Q);

#endif //LINKLIST_TREE_H
