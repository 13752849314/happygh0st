//
// Created by 37157 on 2021/4/28.
//

#ifndef LINKLIST_QUEUE_H
#define LINKLIST_QUEUE_H

#include "../Stack/Stack.h"

#define Maxsize 100 //定义队列中最大元素个数
typedef int ElemType;
/**
 * 顺序队列
 * 整个顺序队列在数据不断地进队出队过程中，在顺序表中的位置不断后移。
 * 顺序队列整体后移造成的影响是：
 * 顺序队列之前的数组存储空间将无法再被使用，造成了空间浪费；
 * 如果顺序表申请的空间不足够大，则直接造成程序中数组溢出，产生溢出错误(假上溢)；
 */
typedef struct {
    int tag;//p80 1(用于标记当头指针与尾指针相同时的队列状态是空(0)还是满(1))
    ElemType data[Maxsize];
    int front, rear;//队头指针和队尾指针
} SqQueue;

void InitQueue(SqQueue &D);//初始化队列
void print_Queue(SqQueue &D);//按出队顺序打印
bool QueueEmpty(SqQueue D);//判断队列是否为空
bool EnQueue(SqQueue &D, ElemType x);//入队
bool DeQueue(SqQueue &D, ElemType &x);//出队

//下面是循环顺序队列的一些函数,初始化函数与上面的一样
void print_LoopQueue(SqQueue &D);//按出队顺序打印
bool LoopQueueEmpty(SqQueue D);//判断循环顺序队列是否为空
int LoopQueueLength(SqQueue D);//循环队列长度
bool EnLoopQueue(SqQueue &D, ElemType x);//循环队列入队
bool DeLoopQueue(SqQueue &D, ElemType &x);//循环队列出队

//链式队列
typedef struct LinkNode {//链式队列结点
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct {//链式队列
    LinkNode *front, *rear;//队列的队头和队尾指针
} LinkQueue;

void InitLinkQueue(LinkQueue &Q);//初始化链式队列
bool LinkQueueEmpty(LinkQueue Q);//判断链式队列是否为空
void EnLinkQueue(LinkQueue &Q, ElemType x);//入队
void DeLinkQueue(LinkQueue &Q, ElemType &x);//出队
void print_LinkQueue(LinkQueue &Q);//按出队顺序打印

//p80 1 的代码
void EnLoopQueue1(SqQueue &Q, ElemType x);//入队
void DeLoopQueue1(SqQueue &Q, ElemType &x);//出队

//p80 2
void invert(SqQueue &Q);//将顺序队列Q中元素倒置

//p80 3
bool EnQueue_Stack(SqStack &S1, SqStack &S2, ElemType e);//入队
bool DeQueue_Stack(SqStack &S1, SqStack &S2, ElemType &x);//出队
bool Stack_Queue_Empty(SqStack S1, SqStack S2);//判断是否为空
void test_Stack_Queue();//测试

//p80 4

#endif //LINKLIST_QUEUE_H
