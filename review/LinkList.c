//
// Created by 37157 on 2021/4/2.
//

#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>


void Init_head(LNode *L) { //初始化头结点
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
}

LinkList List_HeadInsert(LinkList L) { //头插法建立单链表
    LNode *s;
    ElemType x;
    L = (LinkList) malloc(sizeof(LNode));//创建头结点
    L->next = NULL;                      //初始为空链表
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode)); //创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s;                        //将新结点插入表中
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList L) { //尾插法建立单链表
    ElemType x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L, int i) { //按序号查找结点
    int j = 1;
    LNode *p = L->next;
    if (i == 0) return L;
    if (i < 0) return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e) { //按值查找结点
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

void Insert_linklist(LinkList L, int i, ElemType x) { //在第i位置插入值为x的结点
    LNode *s, *p;
    s = (LNode *) malloc(sizeof(LNode));
    s->data = x;
    p = GetElem(L, i - 1);//获取第i-1个结点
    s->next = p->next;
    p->next = s;
}

void delete_linklist(LinkList L, int i) { //删除第i个结点
    LNode *p = GetElem(L, i - 1), *q;
    q = p->next;
    p->next = q->next;
    free(q);
}

int get_linklist_length(LinkList L) { //获取链表长度
    int i = 0;
    LNode *p = L->next;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

void print_link_list(LinkList L) { //打印链表
    LNode *p;
    p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
