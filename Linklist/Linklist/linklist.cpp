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
    if(i>=1&&i<=length){
        auto s=(Linklist)malloc(sizeof(LNode));
        s->data=e;
        Linklist per=get_by_i(i-1);//��ȡ������ǰһ�����
        s->next=per->next;
        per->next=s;
        length++;
    }
}
/**
 * ɾ����i�����
 * @param i Ҫɾ���Ľ��
 */
void linklist::delete_i(int i,ElemType &e) {
    if(i>=1&&i<=length){
        Linklist per=get_by_i(i-1),p;//��ȡҪɾ������ǰһ�����
        e=per->next->data;
        p=per->next;
        per->next=per->next->next;
        free(p);
        length--;
    }
}

/**
 * ��������
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
 * ��������
 * @param A Ҫ���������
 * @param str ��ʼ�±�
 * @param fin �����±�
 */
void quick_sort(ElemType A[],int str,int fin){
    int i=str,j=fin;
    ElemType temp;
    if(i<j){
        temp=A[i];//ѡȡ��һ��Ϊ����
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
