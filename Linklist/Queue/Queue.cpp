//
// Created by 37157 on 2021/4/28.
//

#include "Queue.h"
#include <iostream>

using namespace std;

void InitQueue(SqQueue &D) {
    D.front = 0;
    D.rear = 0;
}

bool QueueEmpty(SqQueue D) {
    return D.front == D.rear;
}

/**
 * 入队
 * @param D
 * @param x 入队元素
 * @return
 */
bool EnQueue(SqQueue &D, ElemType x) {
    if (D.rear == Maxsize) {
        cout << "Queue is Full!" << endl;//并不是真正意义上的满
        return false;
    }
    D.data[D.rear++] = x;
    return true;
}

void print_Queue(SqQueue &D) {
    if (!QueueEmpty(D)) {
        for (int i = D.front; i < D.rear; i++) {
            cout << D.data[i] << " ";
        }
        cout << endl;
    }
}

/**
 * 出队
 * @param D
 * @param x 用于接收出队元素
 * @return
 */
bool DeQueue(SqQueue &D, ElemType &x) {
    if (QueueEmpty(D)) {
        cout << "Queue is Empty!" << endl;
        return false;
    } else {
        x = D.data[D.front++];
        return true;
    }
}

bool LoopQueueEmpty(SqQueue D) {
    return D.front == D.rear % Maxsize;
}

bool EnLoopQueue(SqQueue &D, ElemType x) {
    if ((D.rear + 1) % Maxsize == D.front) {
        cout << "LoopQueue if full!" << endl;
        return false;
    } else {
        D.data[D.rear] = x;
        D.rear = (D.rear + 1) % Maxsize;
        return true;
    }
}

bool DeLoopQueue(SqQueue &D, ElemType &x) {
    if (LoopQueueEmpty(D)) {
        cout << "LoopQueue is empty!" << endl;
        return false;
    } else {
        x = D.data[D.front];
        D.front = (D.front + 1) % Maxsize;
        return true;
    }
}

void print_LoopQueue(SqQueue &D) {//这个函数可能有问题？？
    for (int i = D.front; i < D.rear; i++) {
        cout << D.data[i % Maxsize] << " ";
    }
    cout << endl;
}

int LoopQueueLength(SqQueue D) {
    return (D.rear + Maxsize - D.front) % Maxsize;
}

void InitLinkQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
}

bool LinkQueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

void EnLinkQueue(LinkQueue &Q, ElemType x) {
    auto *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}

void DeLinkQueue(LinkQueue &Q, ElemType &x) {
    if (LinkQueueEmpty(Q)) {
        cout << "LinkQueue is empty!" << endl;
        return;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;//如果原队列中只有一个结点，删除后变空
    }
    free(p);
}

void print_LinkQueue(LinkQueue &Q) {
    LinkNode *p = Q.front->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void EnLoopQueue1(SqQueue &Q, ElemType x) {
    if (Q.front == Q.rear && Q.tag == 1) {
        cout << "LoopQueue is full!" << endl;
        return;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    Q.tag = 1;//可能队满
}

void DeLoopQueue1(SqQueue &Q, ElemType &x) {
    if (Q.front == Q.rear && Q.tag == 0) {
        cout << "LoopQueue is empty!" << endl;
        return;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    Q.tag = 1;//可能队空
}

void invert(SqQueue &Q) {
    SqStack S;
    InitStack(S);
    ElemType x;
    while (!QueueEmpty(Q)) {//出队并压栈
        DeQueue(Q, x);
        Push(S, x);
    }
    while (!StackEmpty(S)) {//出栈并入队
        Pop(S, x);
        EnQueue(Q, x);
    }
}

bool EnQueue_Stack(SqStack &S1, SqStack &S2, ElemType e) {
    if (!StackOverflow(S1)) {
        Push(S1, e);
        return true;
    }
    if (StackOverflow(S1) && !StackEmpty(S2)) {
        cout << "The Stack_Queue is full!" << endl;
        return false;
    }
    if (StackOverflow(S1) && StackEmpty(S2)) {
        ElemType x;
        while (!StackEmpty(S1)) {
            Pop(S1, x);
            Push(S2, x);
        }
    }
    Push(S1, e);
    return true;
}

bool DeQueue_Stack(SqStack &S1, SqStack &S2, ElemType &x) {
    if (!StackEmpty(S2)) {
        Pop(S2, x);
        return true;
    } else if (StackEmpty(S1)) {
        cout << "The Stack_Queue is empty!" << endl;
        return false;
    } else {
        while (!StackEmpty(S1)) {
            Pop(S1, x);
            Push(S2, x);
        }
        Pop(S2, x);
        return true;
    }
}

bool Stack_Queue_Empty(SqStack S1, SqStack S2) {
    return StackEmpty(S1) && StackEmpty(S2);
}

void test_Stack_Queue() {
    ElemType A[] = {1, 3, 5, 7, 9};
    int n = sizeof(A) / sizeof(A[0]);
    SqStack S1, S2;
    InitStack(S1);
    InitStack(S2);
    for (int i = 0; i < n; i++) {
        EnQueue_Stack(S1, S2, A[i]);
    }
    ElemType e;
    while (!Stack_Queue_Empty(S1, S2)) {
        DeQueue_Stack(S1, S2, e);
        cout << e << " ";
    }
    cout << endl;
}
