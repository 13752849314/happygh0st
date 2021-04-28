//
// Created by 37157 on 2021/4/27.
//

#ifndef LINKLIST_STACK_H
#define LINKLIST_STACK_H

#include "../Linklist/linklist.h"
typedef int ElemType;
#define Maxsize 100  //����ջ��Ԫ�ص�������
/**
 * ˳��ջ
 */
typedef struct {
    ElemType data[Maxsize];
    int top;
} SqStack;
/**
 * ��ջ
 */
typedef struct Linknode {
    ElemType data;  //������
    struct Linknode *next;  //ָ����
} LinkStack,*LiStack;

/**
 * ����ջ
 */
typedef struct {
    ElemType data[Maxsize];
    int top[2];
}ShareStack;
void InitStack(SqStack &S);

bool StackEmpty(SqStack S);

bool Push(SqStack &S, ElemType x);

bool Pop(SqStack &S, ElemType &x);

bool GetTop(SqStack &S, ElemType &x);

void print_Pop(SqStack &S);

LinkStack *InitLinkStack(LinkStack *S);

bool LinkStackEmpty(LiStack S);

bool LinkPush(LiStack S,ElemType x);

LiStack LinkPop(LiStack S);

LiStack LinkGetTop(LiStack S);

void print_LinkPop(LiStack S);

bool is_legal(const char A[],int n);//�ж������Ƿ�Ϸ� p66 3

bool is_symmetry(Linklist L,int n);//�ж������Ƿ����ĶԳ� p66 4

//�����ǹ��ڹ���ջ��һЩ����
void InitShareStack(ShareStack &S);//��ʼ������ջ
bool ShareStackEmpty(ShareStack S);//�ж�ջ�Ƿ�Ϊ��
bool SPush(ShareStack &S,int i,ElemType x);//��ջ
bool SPop(ShareStack &S,int i,ElemType &x);//��ջ
#endif //LINKLIST_STACK_H
