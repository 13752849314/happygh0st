//
// Created by 37157 on 2021/4/27.
//

#include <cstdio>
#include <cstdlib>
#include "Stack.h"

/**
 * ��ʼ��˳��ջ
 * @param S
 */
void InitStack(SqStack &S) {
    S.top = -1;
}

/**
 * �ж�ջ�Ƿ�Ϊ��
 * @param S
 * @return
 */
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

/**
 * ��ջ
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, ElemType x) {
    if (S.top == Maxsize - 1) return false;//ջ��
    S.data[++S.top] = x;//ָ���ȼ�1������ջ
    return true;
}

/**
 * ��ջ
 * @param S
 * @param x ���ճ�ջԪ��
 * @return
 */
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//ջ��
    x = S.data[S.top--];//�ȳ�ջ��ָ���ټ�1
    return true;
}

/**
 * ��ȡջ��Ԫ��
 * @param S
 * @param x ����ջ��Ԫ��
 * @return
 */
bool GetTop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//ջ��
    x = S.data[S.top];
    return true;
}

/**
 * ����ջ˳���ӡ
 * @param S
 */
void print_Pop(SqStack &S) {
    int i = S.top;
    if (i == -1) {
        printf("Stack Empty!\n");
    }
    while (i >= 0) {
        printf("%d ", S.data[i]);
        i--;
    }
    putchar('\n');
}

/**
 * ��ʼ����ջ
 * @param S
 */
LinkStack *InitLinkStack(LinkStack *S) {
    S = (LiStack) malloc(sizeof(Linknode));
    S->next = nullptr;
    return S;
}

bool LinkStackEmpty(LiStack S) {
    return S->next == nullptr;
}

bool LinkPush(LiStack S, ElemType x) {
    auto s = (LiStack) malloc(sizeof(LinkStack));
    s->data = x;
    s->next = S->next;
    S->next = s;
    return true;
}

LiStack LinkPop(LiStack S) {
    LiStack p = S->next;
    S->next = p->next;
    return p;
}

LiStack LinkGetTop(LiStack S) {
    return S->next;
}

void print_LinkPop(LiStack S) {
    LiStack p = S->next;
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}


