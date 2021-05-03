//
// Created by 37157 on 2021/4/28.
//

#ifndef LINKLIST_QUEUE_H
#define LINKLIST_QUEUE_H

#include <string>
#include <cstring>
#include <vector>
#include <regex>
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

//p80 4   βָ��ָ�����һ�����Ԫ�أ�ͷָ��Ԫ��Ϊ��
void InitLoopLinkQueue(LinkQueue &Q);//��ʼ��
bool LoopLinkQueue_Empty(LinkQueue Q);//�ж��Ƿ�Ϊ��
bool LoopLinkQueue_Full(LinkQueue Q);//�ж��Ƿ���
bool En_LoopLinkQueue(LinkQueue &Q, ElemType e);//���
bool De_LoopLinkQueue(LinkQueue &Q, ElemType &e);//����
void print_LoopLinkQueue(LinkQueue &Q);//��ӡ
void test_LoopLinkQueue();//����

//begin ���ʽ�ļ���
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

bool check(std::string &exp);//�����ʽ�����Ƿ���ȷ
int priority(char op);//����������ȼ�
void test();//����

std::vector<std::string> format_input(std::string exp);//��ʽ������
std::vector<std::string> to_post_exp(std::vector<std::string> &mid_exp);//ת��Ϊ��׺���ʽ
double solve(std::vector<std::string> &post_exp);//��׺���ʽ��ֵ
//end ���ʽ�ļ���
#endif //LINKLIST_QUEUE_H
