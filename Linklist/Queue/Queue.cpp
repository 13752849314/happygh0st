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
 * ���
 * @param D
 * @param x ���Ԫ��
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
 * ����
 * @param D
 * @param x ���ڽ��ճ���Ԫ��
 * @return
 */
bool DeQueue(SqQueue &D, ElemType &x) {
    if (QueueEmpty(D)) {
        cout << "Queue is Empty!" << endl;
        return false;
    } else {
        x = D.data[D.front];
        D.rear--;//βָ����ǰ��һλ
        for (int i = 0; i < D.rear; i++) {//�ƶ�Ԫ�أ�ʼ�ձ���ͷ����
            D.data[i] = D.data[i + 1];
        }
        return true;
    }
}
