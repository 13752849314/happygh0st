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
void InvertLevel(BiTNode *t, void visit(DataType item));//p141 4

int Bi_depth(BiTNode *t);//�������ĸ߶�(�ݹ�)
int Bi_depth2(BiTNode *t);//�������ĸ߶�(�ǵݹ�) p141 5
BiTNode *PerInCreat(DataType A[], DataType B[], int strA, int finA, int strB, int finB);

bool IsComplete(BiTNode *t);//�ж϶������Ƿ�Ϊ��ȫ������ p141 7
int DsonNodes(BiTNode *t);//�����������˫��֧���ĸ���(�ݹ�) p142 8
int DsonNodes2(BiTNode *t);//�����������˫��֧���ĸ���(�ǵݹ�) p142 8

void swap(BiTNode *t);//���������������ҽ�� p142 9
DataType PerNode(BiTNode *t, int k);//��������е�k������ֵ p142 10

//p142 11
void DeleteXTree(BiTNode *t);

void Search(BiTNode *t, DataType x);

//p142 12
void find_ancestor(BiTNode *t, DataType x, void visit(DataType item));//�ҵ�x(Ψһ)��ȫ������

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
