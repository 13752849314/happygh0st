//
// Created by 37157 on 2021/4/18.
//

#include "LLinklist.h"
#include <cstdio>
#include <cstdlib>

llinklist::llinklist() = default;

llinklist::~llinklist() = default;

llinklist::llinklist(const ElemType *A, int n) {
    L->next = L;
    LLinklist p = L;
    for (int i = 0; i < n; i++) {
        auto s = (LLinklist) malloc(sizeof(LLNode));
        s->data = A[i];
        //头插法
//        s->next=p->next;
//        p->next=s;
        //尾插法
        s->next = p->next;
        p->next = s;
        p = s;
    }
    length = n;
}

/**
 * 判断L是否为空
 * @return 0:空 1:非空
 */
int llinklist::isEmpty() {
    if (L->next == L) return 0;
    return 1;
}

void llinklist::print_LLinklist() {
    if (isEmpty()) {
        LLinklist p = L->next;
        while (p != L) {
            printf("%d ", p->data);
            p = p->next;
        }
        putchar('\n');
    }
}

void llinklist::add_tail(llinklist &a) {
    LLinklist p = L, q = a.L;
    while (p->next != L) {//找到L的尾结点
        p = p->next;
    }
    int i = 0;
    while (q->next != a.L) {//找到a.L的尾结点
        q = q->next;
        i++;
    }
    p->next = a.L->next;
    q->next = L;
    length += i;
}

void llinklist::print_up() {
    LLinklist p, per, min, min_per;
    while (L->next != L) {
        p = L->next;
        per = L;
        min = p;
        min_per = per;
        while (p != L) {
            if (p->data < min->data) {
                min = p;
                min_per = per;
            }
            per = p;
            p = p->next;
        }
        printf("%d ", min->data);
        min_per->next = min->next;
        free(min);
    }
    putchar('\n');
    free(L);
}

void creat_DLinklist(DLinklist L, const ElemType *A, int n) {
    L->next = L;
    L->prior = L;
    DLinklist p = L;
    for (int i = 0; i < n; i++) {
        auto s = (DLinklist) malloc(sizeof(DNode));
        s->data = A[i];
        //尾插法
        s->next = p->next;
        p->next->prior = s;
        s->prior = p;
        p->next = s;
        p = s;
    }
}

void print_DLinklist(DLinklist L) {
    DLinklist p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

/**
 * 判断双循环链表是否对称
 * @param L 链表头结点
 * @return 1：对称 0：不对称
 */
int is_symmetry(DLinklist L) {
    DLinklist p = L->next, q = L->prior;
    while (p != q && q->next != p) {
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            printf("no symmetry!\n");
            return 0;
        }
    }
    printf("symmetry!\n");
    return 1;
}

DLinklist Locate(DLinklist L, ElemType x) {
    DLinklist p = L->next;
    while (p && p->data != x) {// 找到值为x的第一个结点
        p = p->next;
    }
    if (!p) {
        printf("x is not existing!\n");
        return nullptr;
    } else {
        p->freq++;
        if (p->next != nullptr) p->next->prior = p->prior;//防止断链
        p->prior->next = p->next;//将p从链表中取出
        DLinklist q = p->prior;//记录p的前驱
        while (q != L && q->freq <= p->freq) {//找到插入位置
            q = q->prior;
        }
        //插入
        p->next = q->next;
        q->next->prior = p;
        p->prior = q;
        q->next = p;
    }
    return p;
}

void test_Locate() {
    auto L=(DLinklist)malloc(sizeof(DNode));
    ElemType a[]={1,3,5,7,2,4,999};
    int n= sizeof(a)/ sizeof(a[0]);
    creat_DLinklist(L,a,n);
    L->prior= nullptr;
    DLinklist p=L;
    while(p->next!=L){
        p=p->next;
    }
    p->next= nullptr;
    //至此链表构成成功
    /*DLinklist q=L->next;//检查是否ok
    while(q){
        printf("%d  %d\n",q->data,q->freq);
        q=q->next;
    }*/
    Locate(L,3);
    //test_L_p(L);
    Locate(L,5);
    //test_L_p(L);
    Locate(L,3);
    //test_L_p(L);
    DLinklist re=Locate(L,4);
    test_L_p(L);
    printf("%d----%d\n",re->data,re->freq);
}

void test_L_p(DLinklist L){
    DLinklist p=L->next;
    while(p){
        printf("%d  %d\n",p->data,p->freq);
        p=p->next;
    }
}
