//
// Created by 37157 on 2021/4/27.
//

#ifndef LINKLIST_STACK_H
#define LINKLIST_STACK_H

#include "../Linklist/linklist.h"
typedef int ElemType;
#define Maxsize 100  //定义栈中元素的最大个数
/**
 * 顺序栈
 */
typedef struct {
    ElemType data[Maxsize];
    int top;
} SqStack;
/**
 * 链栈
 */
typedef struct Linknode {
    ElemType data;  //数据域
    struct Linknode *next;  //指针域
} LinkStack,*LiStack;

/**
 * 共享栈
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

bool is_legal(const char A[],int n);//判断序列是否合法 p66 3

bool is_symmetry(Linklist L,int n);//判断链表是否中心对称 p66 4

//下面是关于共享栈的一些函数
void InitShareStack(ShareStack &S);//初始化共享栈
bool ShareStackEmpty(ShareStack S);//判断栈是否为空
bool SPush(ShareStack &S,int i,ElemType x);//入栈
bool SPop(ShareStack &S,int i,ElemType &x);//出栈
#endif //LINKLIST_STACK_H
