//
// Created by 37157 on 2021/4/27.
//

#include <cstdio>
#include <cstdlib>
#include "Stack.h"

/**
 * 初始化顺序栈
 * @param S
 */
void InitStack(SqStack &S) {
    S.top = -1;
}

/**
 * 判断栈是否为空
 * @param S
 * @return
 */
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

/**
 * 进栈
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, ElemType x) {
    if (S.top == Maxsize - 1) return false;//栈满
    S.data[++S.top] = x;//指针先加1，再入栈
    return true;
}

/**
 * 出栈
 * @param S
 * @param x 接收出栈元素
 * @return
 */
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//栈空
    x = S.data[S.top--];//先出栈，指针再减1
    return true;
}

/**
 * 获取栈顶元素
 * @param S
 * @param x 接收栈顶元素
 * @return
 */
bool GetTop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//栈空
    x = S.data[S.top];
    return true;
}

/**
 * 按出栈顺序打印
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
 * 初始化链栈
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


