//
// Created by 37157 on 2021/4/28.
//

#ifndef LINKLIST_QUEUE_H
#define LINKLIST_QUEUE_H
#define Maxsize 100 //定义队列中最大元素个数
typedef int ElemType;
/**
 * 顺序队列
 */
typedef struct {
    ElemType data[Maxsize];
    int front, rear;//队头指针和队尾指针
} SqQueue;

void InitQueue(SqQueue &D);//初始化队列
void print_Queue(SqQueue &D);//按出队顺序打印
bool QueueEmpty(SqQueue D);//判断队列是否为空
bool EnQueue(SqQueue &D, ElemType x);//入队
bool DeQueue(SqQueue &D, ElemType &x);//出队
#endif //LINKLIST_QUEUE_H
