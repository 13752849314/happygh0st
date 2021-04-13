//
// Created by 37157 on 2021/4/3.
//

#ifndef REVIEW_DLINKLIST_H
#define REVIEW_DLINKLIST_H
typedef int ElemType;
typedef struct DNode {
    ElemType data;              //数据域
    struct DNode *prior, *next;  //指针域
} DNode, *DLinklist;

DLinklist Init_DLinklist(DNode *L);

void print_DLinklist(DLinklist L);

DLinklist start(DLinklist L, ElemType A[], int n);

DNode *get_node(DLinklist L, int i);

void insert_DLinklist(DLinklist L, int i, ElemType e);

void delete_DLinklist(DLinklist L, int i);

DNode *get_node_byElem(DLinklist L, ElemType x);

#endif //REVIEW_DLINKLIST_H
