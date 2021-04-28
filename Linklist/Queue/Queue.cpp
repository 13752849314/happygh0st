//
// Created by 37157 on 2021/4/28.
//

#include "Queue.h"
#include <iostream>
void InitQueue(SqQueue &D) {
    D.front=0;
    D.rear=0;
}

bool QueueEmpty(SqQueue D) {
    return (D.rear==0)&&(D.front==0);
}

bool EnQueue(SqQueue &D, ElemType x) {
    
}
