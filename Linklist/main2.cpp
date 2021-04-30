//
// Created by 37157 on 2021/4/28.
//

#include <iostream>
#include "Queue/Queue.h"

using namespace std;
int temp = 0;

void divide() {
    cout << "==========" << temp << "==========" << endl;
    temp++;
}

int main() {
    SqQueue D;
    InitQueue(D);
    cout << QueueEmpty(D) << endl;
    ElemType A[] = {1, 2, 4, 6, 7, 8};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++) {
        EnQueue(D, A[i]);
    }
    print_Queue(D);
    ElemType e;
    DeQueue(D, e);
    cout << "e=" << e << endl;
    print_Queue(D);
    divide();

    SqQueue L;
    InitQueue(L);
    for (int i = 0; i < n; i++) {
        EnLoopQueue(L, A[i]);
    }
    DeLoopQueue(L, e);
    EnLoopQueue(L, 123);
    DeLoopQueue(L, e);
    EnLoopQueue(L, 333);
    print_LoopQueue(L);
    DeLoopQueue(L, e);
    cout << LoopQueueLength(L) << endl;
    divide();

    LinkQueue Q;
    InitLinkQueue(Q);
    EnLinkQueue(Q, 1);
    EnLinkQueue(Q, 123);
    EnLinkQueue(Q, 12);
    DeLinkQueue(Q, e);
    print_LinkQueue(Q);
    divide();

    SqQueue ck;
    InitQueue(ck);
    for(int i=0;i<n;i++){
        EnQueue(ck,A[i]);
    }
    print_Queue(ck);
    invert(ck);
    print_Queue(ck);
    divide();

    test_Stack_Queue();
    divide();
    return 0;
}
