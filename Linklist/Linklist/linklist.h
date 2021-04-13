//
// Created by 37157 on 2021/4/13.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
typedef int ElemType;
/**
 * 单链表
 */
typedef struct LNode {
    ElemType data; //数据域
    struct LNode *next; //指针域
} LNode, *Linklist;

class linklist {
public:
    ElemType *A{};
    int length{};
    Linklist L = (Linklist) malloc(sizeof(LNode));

    linklist();

    linklist(const ElemType A[], int n);//尾插法创建单链表
    void print_Linklist();//打印链表
    Linklist get_by_i(int i);//获取第i个结点
    void insert_i(int i, ElemType e);//在第i个位置插入e
    void delete_i(int i,ElemType &e);//删除第i个结点
    void invert();//倒置链表
    virtual ~linklist();
};
void quick_sort(ElemType A[],int str,int fin);// 快速排序

#endif //LINKLIST_LINKLIST_H
