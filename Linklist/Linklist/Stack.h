//
// Created by 37157 on 2021/4/27.
//

#ifndef LINKLIST_STACK_H
#define LINKLIST_STACK_H
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
#endif //LINKLIST_STACK_H
