//
// Created by 37157 on 2021/4/4.
//

#include "LoopLinklist.h"
#include <stdio.h>
#include <stdlib.h>

LoopLinklist *Init_LoopLinklist(LoopLinklist *L) { //初始化头结点
    L = (LoopLinklist *) malloc(sizeof(LoopLinklist));
    L->next = L;
    return L;
}

void print_LoopLinklist(LoopLinklist *L) { //打印循环链表
    LoopLinklist *s = L->next;
    while (s != L) {
        printf("%d ", s->data);
        s = s->next;
    }
    putchar('\n');
}

LoopLinklist *Loop_start(LoopLinklist *L, ElemType A[], int n) {
    L = Init_LoopLinklist(L);
    LoopLinklist *s, *p = L;
    for (int i = 0; i < n; i++) {
        s = (LoopLinklist *) malloc(sizeof(LoopLinklist));
        s->data = A[i];
        p->next = s;
        s->next = L;
        p = s;
    }
    return L;
}

int get_LoopLinklist_length(LoopLinklist *L) { //获取链表长度
    int i = 0;
    LoopLinklist *p = L->next;
    while (p != L) {
        i++;
        p = p->next;
    }
    return i;
}

