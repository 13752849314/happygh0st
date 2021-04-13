//
// Created by 37157 on 2021/4/2.
//

#ifndef REVIEW_LINKLIST_H
#define REVIEW_LINKLIST_H

typedef int ElemType;
typedef struct LNode {
    ElemType data;       //数据域
    struct LNode *next;  //指针域
} LNode, *LinkList;

void print_link_list(LinkList);

void Init_head(LNode *L);

LinkList List_HeadInsert(LinkList L);

LinkList List_TailInsert(LinkList L);

LNode *GetElem(LinkList L, int i);

LNode *LocateElem(LinkList L, ElemType e);

void Insert_linklist(LinkList L, int i, ElemType x);

void delete_linklist(LinkList L, int i);

int get_linklist_length(LinkList L);

#endif //REVIEW_LINKLIST_H
