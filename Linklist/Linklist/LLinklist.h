//
// Created by 37157 on 2021/4/18.
//

#ifndef LINKLIST_LLINKLIST_H
#define LINKLIST_LLINKLIST_H

#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct LLNode {
    ElemType data;//数据域
    struct LLNode *next;//指针域
} LLNode, *LLinklist;
typedef struct DNode {
    int freq = 0;// p38 20 用
    ElemType data{};//数据域
    struct DNode *next{}, *prior{};//指针域
} DNode, *DLinklist;


class llinklist {
public:
    int length{};
    LLinklist L = (LLinklist) malloc(sizeof(LLNode));

    llinklist();

    llinklist(const ElemType A[], int n);//通过数组A创建单循环链表
    int isEmpty();//判断是否为空
    void print_LLinklist();//打印链表
    void add_tail(llinklist &a);//将a.L链接到L的后面 p38 18
    void print_up();//按升序打印各结点，并释放空间 p38 19
    virtual ~llinklist();
};

void creat_DLinklist(DLinklist L, const ElemType A[], int n);//创建双循环链表
void print_DLinklist(DLinklist L);//打印
int is_symmetry(DLinklist L);//判断是否对称 p38 17
DLinklist Locate(DLinklist L, ElemType x);// p38 20
void test_Locate();//测试 p38 20
void test_L_p(DLinklist L);

#endif //LINKLIST_LLINKLIST_H
