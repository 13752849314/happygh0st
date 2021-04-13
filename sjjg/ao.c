#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;//数据域
    struct LNode *next;//指针域
} LNode;

/**
 * 尾插法创建链表
 * @return 链表L
 */
LNode *CreateListTail() {
    LNode *L;
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;//空表
    LNode *s, *r = L;//r是尾指针 s是新结点
    int x;
    scanf("%d", &x);
    int flag = 0;//结束标记
    while (x != flag) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;//最后一个元素next域指向NULL
    return L;
}

/**
 * 提取元素
 * @param L 链表
 * @param i 提取第i个元素
 * @param e 用e返回
 * @return
 */
int GetElem(LNode L, int i, ElemType *e) {
    LNode *head, *p;//head是头指针，p为查找下标
    head = &L;
    p = head;//p的初值指向第1个元素
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) return -1; //第i个元素不存在
    e = p->data;
    return 0;
}

/**
 * 插入元素
 * @param L 链表
 * @param i 插入位置
 * @param e 插入元素
 * @return
 */
int ListInsert(LNode *L, int i, ElemType e) {
    LNode *p;//设p为第i-1个结点
    //首先要找到第i-1个结点
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    //申请一个新结点
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;

    s->next = p->next; //s的直接后继指向p原来的直接后继
    p->next = s; //p的直接后继指向s

    return 0;
}
/**
 * 删除元素
 * @param L 链表
 * @param i 删除第i位的元素
 * @param e 用e返回
 * @return
 */
int ListDelete(LNode *L, int i, ElemType *e) {
    LNode *p, *q;//设p为第i-1个结点 q标示删除位置
    //首先要找到第i-1个结点
    int j = 0;
    p = L;//p为L的基地址
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    q = p->next;
    p->next = q->next;//p的next域指向p->next->next

    e = q->data;
    return 0;
}

int main() {
    LNode *L;
    L = CreateListTail();//创建一个线性链表，输入0结束
    ListInsert(L, 1, 100);//在第1个位置插入100
    ElemType e;//待删除的元素
    ListDelete(L, 3, e);//删除第3个元素
    LNode *p;
    p = L;

    printf("输出线性链表：\n");
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    return 0;
}