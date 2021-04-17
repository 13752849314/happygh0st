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
    if (L->next == nullptr) {
        printf("Empty!\n");
        return;
    }
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
    return L;
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
    int i = 0;
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
    length = length - i;
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
        if (p->data < min->data) {
            min = p;
            min_per = per;
        } else {
            per = p;
            p = p->next;
        }
    }
    min_per->next = min->next;
    free(min);
    length--;
}

void linklist::sort_Linklist() {
    auto *a = new ElemType[length];
    int i = 0;
    Linklist p = L->next;
    while (p != nullptr) {
        a[i] = p->data;
        p = p->next;
        i++;
    }
    quick_sort(a, 0, length - 1);
    Linklist q = L->next;
    i = 0;
    while (q != nullptr) {
        q->data = a[i];
        q = q->next;
        i++;
    }
}

/**
 * 删除a，b之间的结点
 * @param a
 * @param b
 */
void linklist::delete_a_to_b(ElemType a, ElemType b) {
    Linklist p = L->next, per = L;
    int i = 0;
    while (p != nullptr) {
        if (p->data > a && p->data < b) {
            Linklist t = p;
            per->next = p->next;
            p = p->next;
            i++;
            free(t);
        } else {
            p = p->next;
            per = per->next;
        }
    }
    length = length - i;
}

void linklist::update_length() {
    int i = 0;
    Linklist p = L->next;
    while (p != nullptr) {
        i++;
        p = p->next;
    }
    length = i;
    printf("new length=%d\n", length);
}

void linklist::print_up() {
    Linklist p = L->next;
    while (p != nullptr) {
        Linklist per = L, min = p, min_per = L;
        while (p != nullptr) {
            if (p->data < min->data) {
                min = p;
                min_per = per;
            } else {
                per = p;
                p = p->next;
            }
        }
        min_per->next = min->next;
        printf("%d ", min->data);
        free(min);
        p = L->next;
    }
    //free(L);
    length = 0;
    putchar('\n');
}

Linklist linklist::divide_by_odd_even() {
    auto B = (Linklist) malloc(sizeof(LNode));
    B->next = nullptr;
    Linklist p = L->next, per = L, q = B;
    int i = 1;
    while (p != nullptr) {
        if (i % 2 == 0) {
            Linklist t = p;
            per->next = p->next;//保证L不断链
            p = p->next;
            //尾插法插入B
            t->next = q->next;
            q->next = t;
            q = t;
            i++;
        } else {
            per = per->next;
            p = p->next;
            i++;
        }
    }
    return B;
}

Linklist linklist::divide_by_odd_even2() {
    auto B = (Linklist) malloc(sizeof(LNode));
    B->next = nullptr;
    Linklist p = L->next, per = L;
    int i = 1;
    while (p != nullptr) {
        if (i % 2 == 0) {
            Linklist t = p;
            per->next = p->next;//保证L不断链
            p = p->next;
            //头插法
            t->next = B->next;
            B->next = t;
            i++;
        } else {
            p = p->next;
            per = per->next;
            i++;
        }
    }
    return B;
}

void linklist::delete_same() {
    if (length == 1) return;
    Linklist p = L->next, q = p->next;
    while (q != nullptr) {
        if (p->data == q->data) {
            Linklist t = q;
            p->next = q->next;
            q = q->next;
            free(t);
        } else {
            p = p->next;
            q = q->next;
        }
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

/**
 * 获取A，B的公共结点
 * @param A
 * @param B
 * @return 公共结点
 */
Linklist find_common_Node(linklist &A, linklist &B) {
    int len1 = A.length, len2 = B.length;
    Linklist long_L, short_L;
    if (len1 > len2) {
        long_L = A.L;
        short_L = B.L;
    } else {
        long_L = B.L;
        short_L = A.L;
    }
    int i = abs(len1 - len2);
    while (i--) { //让长的链表先走i步
        long_L = long_L->next;
    }
    while (long_L != short_L) {
        long_L = long_L->next;
        short_L = short_L->next;
    }
    return long_L;
}

void print_Linklist(Linklist L) {
    if (L->next == nullptr) {
        printf("Empty!\n");
        return;
    }
    Linklist p = L->next;
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}


