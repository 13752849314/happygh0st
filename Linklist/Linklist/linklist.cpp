//
// Created by 37157 on 2021/4/13.
//
#include <cstdio>
#include <cstdlib>
#include "linklist.h"

linklist::linklist() = default;

linklist::~linklist() = default;

/**
 * 构造函数，利用数组创建单链表
 * @param A 数组
 * @param n 数组长度
 */
linklist::linklist(const ElemType *A, int n) { //尾插法创建单链表
    length = n;
    Linklist p = L;
    for (int i = 0; i < length; i++) {
        auto s = (Linklist) malloc(sizeof(LNode));
        s->data = A[i];
        s->next = p->next;
        p->next = s;
        p = s;
    }
    p->next = nullptr;
    //时间复杂度O(n)
    //空间复杂度O(n)
}

/**
 * 打印链表
 */
void linklist::print_Linklist() { //打印链表
    Linklist p = L->next;
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

/**
 * 获取单链表中第i个结点
 * @param i 获取第i个结点
 * @return 第i个结点
 */
Linklist linklist::get_by_i(int i) {//获取第i个结点
    if (i >= 1 && i <= length) {
        int j = 1;
        Linklist p = L->next;
        while (j != i) {
            p = p->next;
            j++;
        }
        return p;
    }
    return nullptr;
}

/**
 * 在第i个位置插入e
 * @param i 要插入的位置
 * @param e 插入元素
 */
void linklist::insert_i(int i, ElemType e) {
    if (i >= 1 && i <= length) {
        auto s = (Linklist) malloc(sizeof(LNode));
        s->data = e;
        Linklist per = get_by_i(i - 1);//获取插入点的前一个结点
        s->next = per->next;
        per->next = s;
        length++;
    }
}

/**
 * 删除第i个结点
 * @param i 要删除的结点
 */
void linklist::delete_i(int i, ElemType &e) {
    if (i >= 1 && i <= length) {
        Linklist per = get_by_i(i - 1), p;//获取要删除结点的前一个结点
        e = per->next->data;
        p = per->next;
        per->next = per->next->next;
        free(p);
        length--;
    }
}

/**
 * 倒置链表
 */
void linklist::invert() {
    Linklist p = L->next, t = p->next, q;
    while (t != nullptr) {
        q = t->next;
        t->next = L->next;
        L->next = t;
        t = q;
    }
    p->next = nullptr;//末尾结点的后继指向空
}

/**
 * 删除所有的x
 * @param x 要删除结点的值
 */
void linklist::delete_all_x(ElemType x) {
    Linklist p = L->next, per = L;
    int i=0;
    while (p != nullptr) {
        if (p->data == x) {
            Linklist t = p;
            per->next = p->next;
            p = p->next;
            free(t);
            i++;
        } else {
            p = p->next;
            per = per->next;
        }
    }
    length=length-i;
}

/**
 * 反向打印链表
 * @param head 链表第一个结点
 */
void linklist::reverse_print(Linklist head) {
    if (head->next != nullptr) reverse_print(head->next);
    printf("%d ", head->data);
}

/**
 * 删除最小值结点（唯一）
 */
void linklist::delete_only_min() {
    Linklist p = L->next, per = L;
    Linklist min = p, min_per = per;
    while (p != nullptr) {
        if(p->data<min->data){
            min=p;
            min_per=per;
        }else{
            per=p;
            p=p->next;
        }
    }
    min_per->next=min->next;
    free(min);
    length--;
}

void linklist::sort_Linklist() {
    auto *a=new ElemType[length];
    int i=0;
    Linklist p=L->next;
    while(p!= nullptr){
        a[i]=p->data;
        p=p->next;
        i++;
    }
    quick_sort(a,0,length-1);
    Linklist q=L->next;
    i=0;
    while(q!= nullptr){
        q->data=a[i];
        q=q->next;
        i++;
    }
}

/**
 * 快速排序
 * @param A 要排序的数组
 * @param str 起始下标
 * @param fin 结束下标
 */
void quick_sort(ElemType A[], int str, int fin) {
    int i = str, j = fin;
    ElemType temp;
    if (i < j) {
        temp = A[i];//选取第一个为中轴
        while (i < j) {
            while (i < j && A[j] >= temp) j--;
            A[i] = A[j];
            while (i < j && A[i] <= temp) i++;
            A[j] = A[i];
        }
        A[i] = temp;
        quick_sort(A, str, i - 1);
        quick_sort(A, i + 1, fin);
    }
}
