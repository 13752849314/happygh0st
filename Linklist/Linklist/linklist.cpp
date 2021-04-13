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
    if(i>=1&&i<=length){
        auto s=(Linklist)malloc(sizeof(LNode));
        s->data=e;
        Linklist per=get_by_i(i-1);//获取插入点的前一个结点
        s->next=per->next;
        per->next=s;
        length++;
    }
}
/**
 * 删除第i个结点
 * @param i 要删除的结点
 */
void linklist::delete_i(int i,ElemType &e) {
    if(i>=1&&i<=length){
        Linklist per=get_by_i(i-1),p;//获取要删除结点的前一个结点
        e=per->next->data;
        p=per->next;
        per->next=per->next->next;
        free(p);
        length--;
    }
}

/**
 * 倒置链表
 */
void linklist::invert() {
    Linklist p=L->next,t=p->next,q;
    while(t!= nullptr){
        q=t->next;
        t->next=L->next;
        L->next=t;
        t=q;
    }
    p->next= nullptr;
}

/**
 * 快速排序
 * @param A 要排序的数组
 * @param str 起始下标
 * @param fin 结束下标
 */
void quick_sort(ElemType A[],int str,int fin){
    int i=str,j=fin;
    ElemType temp;
    if(i<j){
        temp=A[i];//选取第一个为中轴
        while(i<j){
            while(i<j&&A[j]>=temp) j--;
            A[i]=A[j];
            while(i<j&&A[i]<=temp) i++;
            A[j]=A[i];
        }
        A[i]=temp;
        quick_sort(A,str,i-1);
        quick_sort(A,i+1,fin);
    }
}
