//
// Created by 37157 on 2021/4/28.
//

#ifndef LINKLIST_QUEUE_H
#define LINKLIST_QUEUE_H

#include "../Stack/Stack.h"

#define Maxsize 100 //������������Ԫ�ظ���
typedef int ElemType;
/**
 * ˳�����
 * ����˳����������ݲ��ϵؽ��ӳ��ӹ����У���˳����е�λ�ò��Ϻ��ơ�
 * ˳��������������ɵ�Ӱ���ǣ�
 * ˳�����֮ǰ������洢�ռ佫�޷��ٱ�ʹ�ã�����˿ռ��˷ѣ�
 * ���˳�������Ŀռ䲻�㹻����ֱ����ɳ�������������������������(������)��
 */
typedef struct {
    int tag;//p80 1(���ڱ�ǵ�ͷָ����βָ����ͬʱ�Ķ���״̬�ǿ�(0)������(1))
    ElemType data[Maxsize];
    int front, rear;//��ͷָ��Ͷ�βָ��
} SqQueue;

void InitQueue(SqQueue &D);//��ʼ������
void print_Queue(SqQueue &D);//������˳���ӡ
bool QueueEmpty(SqQueue D);//�ж϶����Ƿ�Ϊ��
bool EnQueue(SqQueue &D, ElemType x);//���
bool DeQueue(SqQueue &D, ElemType &x);//����

//������ѭ��˳����е�һЩ����,��ʼ�������������һ��
void print_LoopQueue(SqQueue &D);//������˳���ӡ
bool LoopQueueEmpty(SqQueue D);//�ж�ѭ��˳������Ƿ�Ϊ��
int LoopQueueLength(SqQueue D);//ѭ�����г���
bool EnLoopQueue(SqQueue &D, ElemType x);//ѭ���������
bool DeLoopQueue(SqQueue &D, ElemType &x);//ѭ�����г���

//��ʽ����
typedef struct LinkNode {//��ʽ���н��
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct {//��ʽ����
    LinkNode *front, *rear;//���еĶ�ͷ�Ͷ�βָ��
} LinkQueue;

void InitLinkQueue(LinkQueue &Q);//��ʼ����ʽ����
bool LinkQueueEmpty(LinkQueue Q);//�ж���ʽ�����Ƿ�Ϊ��
void EnLinkQueue(LinkQueue &Q, ElemType x);//���
void DeLinkQueue(LinkQueue &Q, ElemType &x);//����
void print_LinkQueue(LinkQueue &Q);//������˳���ӡ

//p80 1 �Ĵ���
void EnLoopQueue1(SqQueue &Q, ElemType x);//���
void DeLoopQueue1(SqQueue &Q, ElemType &x);//����

//p80 2
void invert(SqQueue &Q);//��˳�����Q��Ԫ�ص���

//p80 3
bool EnQueue_Stack(SqStack &S1, SqStack &S2, ElemType e);//���
bool DeQueue_Stack(SqStack &S1, SqStack &S2, ElemType &x);//����
bool Stack_Queue_Empty(SqStack S1, SqStack S2);//�ж��Ƿ�Ϊ��
void test_Stack_Queue();//����

//p80 4

#endif //LINKLIST_QUEUE_H
