//
// Created by 37157 on 2021/4/13.
//
#include <cstdio>
#include <cstdlib>
#include "linklist.h"

linklist::linklist() = default;

linklist::~linklist() = default;

/**
 * ���캯�����������鴴��������
 * @param A ����
 * @param n ���鳤��
 */
linklist::linklist(const ElemType *A, int n) { //β�巨����������
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
    //ʱ�临�Ӷ�O(n)
    //�ռ临�Ӷ�O(n)
}

/**
 * ��ӡ����
 */
void linklist::print_Linklist() { //��ӡ����
    Linklist p = L->next;
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

/**
 * ��ȡ�������е�i�����
 * @param i ��ȡ��i�����
 * @return ��i�����
 */
Linklist linklist::get_by_i(int i) {//��ȡ��i�����
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
 * �ڵ�i��λ�ò���e
 * @param i Ҫ�����λ��
 * @param e ����Ԫ��
 */
void linklist::insert_i(int i, ElemType e) {
    if (i >= 1 && i <= length) {
        auto s = (Linklist) malloc(sizeof(LNode));
        s->data = e;
        Linklist per = get_by_i(i - 1);//��ȡ������ǰһ�����
        s->next = per->next;
        per->next = s;
        length++;
    }
}

/**
 * ɾ����i�����
 * @param i Ҫɾ���Ľ��
 */
void linklist::delete_i(int i, ElemType &e) {
    if (i >= 1 && i <= length) {
        Linklist per = get_by_i(i - 1), p;//��ȡҪɾ������ǰһ�����
        e = per->next->data;
        p = per->next;
        per->next = per->next->next;
        free(p);
        length--;
    }
}

/**
 * ��������
 */
void linklist::invert() {
    Linklist p = L->next, t = p->next, q;
    while (t != nullptr) {
        q = t->next;
        t->next = L->next;
        L->next = t;
        t = q;
    }
    p->next = nullptr;//ĩβ���ĺ��ָ���
}

/**
 * ɾ�����е�x
 * @param x Ҫɾ������ֵ
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
 * �����ӡ����
 * @param head �����һ�����
 */
void linklist::reverse_print(Linklist head) {
    if (head->next != nullptr) reverse_print(head->next);
    printf("%d ", head->data);
}

/**
 * ɾ����Сֵ��㣨Ψһ��
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
 * ɾ��a��b֮��Ľ��
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
        p=p->next;
    }
    length = i;
    printf("new length=%d\n",length);
}

/**
 * ��������
 * @param A Ҫ���������
 * @param str ��ʼ�±�
 * @param fin �����±�
 */
void quick_sort(ElemType A[], int str, int fin) {
    int i = str, j = fin;
    ElemType temp;
    if (i < j) {
        temp = A[i];//ѡȡ��һ��Ϊ����
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
 * ��ȡA��B�Ĺ������
 * @param A
 * @param B
 * @return �������
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
    while (i--) {
        long_L = long_L->next;
    }
    while (long_L != short_L) {
        long_L = long_L->next;
        short_L = short_L->next;
    }
    return long_L;
}


