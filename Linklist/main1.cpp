//
// Created by 37157 on 2021/4/27.
//

#include <cstdio>
#include <iostream>
#include "Linklist/Stack.h"

using namespace std;

int temp = 0;

void divide() {
    printf("==========%d==========\n", temp);
    temp++;
}

int main() {
    SqStack S;
    ElemType e;
    InitStack(S);
    printf("%d\n", S.top);
    cout << StackEmpty(S) << endl;
    ElemType A[] = {1, 3, 5, 7, 3, 2, 4, 6};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++) {
        Push(S, A[i]);
    }
    print_Pop(S);
    Pop(S, e);
    printf("%d\n", e);
    print_Pop(S);
    GetTop(S, e);
    cout << e << endl;
    divide();

    LinkStack L;
    L=*InitLinkStack(&L);
    printf("%d\n", LinkStackEmpty(&L));
    for (int i = 0; i < n; i++) {
        LinkPush(&L, A[i]);
    }
    print_LinkPop(&L);
    LinkPush(&L,999);
    print_LinkPop(&L);
    LiStack t=LinkPop(&L);
    printf("%d\n",t->data);
    print_LinkPop(&L);
    return 0;
}
