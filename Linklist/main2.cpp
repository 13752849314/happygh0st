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
    ElemType A[] = {1, 2, 4, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++) {
        EnQueue(D, A[i]);
    }
    print_Queue(D);
    ElemType e;
    DeQueue(D, e);
    cout << "e=" << e << endl;
    DeQueue(D, e);
    print_Queue(D);
    return 0;
}
