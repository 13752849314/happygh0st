//
// Created by 37157 on 2021/4/28.
//

#ifndef LINKLIST_QUEUE_H
#define LINKLIST_QUEUE_H
#define Maxsize 100 //������������Ԫ�ظ���
typedef int ElemType;
/**
 * ˳�����
 */
typedef struct {
    ElemType data[Maxsize];
    int front,rear;//��ͷָ��Ͷ�βָ��
}SqQueue;
void InitQueue(SqQueue &D);//��ʼ������
bool QueueEmpty(SqQueue D);//�ж϶����Ƿ�Ϊ��
bool EnQueue(SqQueue &D,ElemType x);//���
#endif //LINKLIST_QUEUE_H
