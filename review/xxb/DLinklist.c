//
// Created by 37157 on 2021/4/3.
//

#include "DLinklist.h"
#include <stdio.h>
#include <stdlib.h>

DLinklist Init_DLinklist(DLinklist L) {  //初始化头结点
    L = (DLinklist) malloc(sizeof(DNode));
    L->next = NULL;
    L->prior = NULL;
    return L;
}

void print_DLinklist(DLinklist L) { //打印
    DNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

DLinklist start(DLinklist L, ElemType A[], int n) { //将数组A中元素按顺序放入L中
    DNode *p = L;
    int i = 0;
    while (i < n) {
        DNode *s = (DNode *) malloc(sizeof(DNode));
        s->data = A[i];
        p->next = s;
        s->prior = p;
        p = s;
        i++;
    }
    p->next = NULL;
    return L;
}

DNode *get_node(DLinklist L, int i) { //获取第i个结点
    int j = 1;
    DNode *p = L->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

DNode *get_node_byElem(DLinklist L, ElemType x) { //获取第一个值为x的结点
    DNode *p = L->next;
    while (p->data != x) {
        p = p->next;
    }
    return p;
}

void insert_DLinklist(DLinklist L, int i, ElemType e) { //在第i个位置插入以元素e为数据的结点
    DNode *s, *p;
    p = get_node(L, i - 1);
    s = (DLinklist) malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

void delete_DLinklist(DLinklist L, int i) { //删除第i个位置的结点
    DNode *q;
    q = get_node(L, i);
    q->prior->next = q->next;
    q->next->prior = q->prior;
    free(q);
}
