//
// Created by 37157 on 2021/4/27.
//

#include <cstdio>
#include <iostream>
#include "Stack/Stack.h"
#include "Linklist/linklist.h"


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
    std::cout << StackEmpty(S) << std::endl;
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
    std::cout << e << std::endl;
    divide();

    LinkStack L;
    L = *InitLinkStack(&L);
    printf("%d\n", LinkStackEmpty(&L));
    for (int i = 0; i < n; i++) {
        LinkPush(&L, A[i]);
    }
    print_LinkPop(&L);
    LinkPush(&L, 999);
    print_LinkPop(&L);
    LiStack t = LinkPop(&L);
    printf("%d\n", t->data);
    print_LinkPop(&L);
    divide();

    char c[] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
    printf("%d\n", is_legal(c, 8));
    divide();

    ElemType B[] = {1, 2, 3, 4, 4, 3, 2, 4, 1};
    n = sizeof(B) / sizeof(B[0]);
    linklist ck(B, n);
    ck.print_Linklist();
    bool sd = is_symmetry(ck.L, n);
    std::cout << sd << std::endl;
    divide();

    ShareStack SS;
    InitShareStack(SS);
    SPush(SS,0,1);
    SPush(SS,0,2);
    SPush(SS,0,3);
    SPush(SS,1,3);
    SPush(SS,1,7);
    ElemType ee;
    SPop(SS,1,ee);
    std::cout<<ee<<std::endl;
    return 0;
}
