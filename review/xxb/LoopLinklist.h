//
// Created by 37157 on 2021/4/4.
//

#ifndef REVIEW_LOOPLINKLIST_H
#define REVIEW_LOOPLINKLIST_H
typedef int ElemType;
typedef struct LoopLinklist {
    ElemType data;               //数据域
    struct LoopLinklist *next;   //指针域
} LoopLinklist;

LoopLinklist *Loop_start(LoopLinklist *L, ElemType A[], int n);

void print_LoopLinklist(LoopLinklist *L);

int get_LoopLinklist_length(LoopLinklist *L);

#endif //REVIEW_LOOPLINKLIST_H
