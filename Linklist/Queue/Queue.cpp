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
    return (D.rear == 0) && (D.front == 0);
}

/**
 * 入队
 * @param D
 * @param x 入队元素
 * @return
 */
bool EnQueue(SqQueue &D, ElemType x) {
    if (D.rear == Maxsize) {
        cout << "Queue is Full!" << endl;
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
        x = D.data[D.front];
        D.rear--;//尾指针向前移一位
        for (int i = 0; i < D.rear; i++) {//移动元素，始终保持头对齐
            D.data[i] = D.data[i + 1];
        }
        return true;
    }
}
