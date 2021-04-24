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
        //ͷ�巨
//        s->next=p->next;
//        p->next=s;
        //β�巨
        s->next = p->next;
        p->next = s;
        p = s;
    }
    length = n;
}

/**
 * �ж�L�Ƿ�Ϊ��
 * @return 0:�� 1:�ǿ�
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
    while (p->next != L) {//�ҵ�L��β���
        p = p->next;
    }
    int i = 0;
    while (q->next != a.L) {//�ҵ�a.L��β���
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
        //β�巨
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
 * �ж�˫ѭ�������Ƿ�Գ�
 * @param L ����ͷ���
 * @return 1���Գ� 0�����Գ�
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
    while (p && p->data != x) {// �ҵ�ֵΪx�ĵ�һ�����
        p = p->next;
    }
    if (!p) {
        printf("x is not existing!\n");
        return nullptr;
    } else {
        p->freq++;
        if (p->next != nullptr) p->next->prior = p->prior;//��ֹ����
        p->prior->next = p->next;//��p��������ȡ��
        DLinklist q = p->prior;//��¼p��ǰ��
        while (q != L && q->freq <= p->freq) {//�ҵ�����λ��
            q = q->prior;
        }
        //����
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
    //���������ɳɹ�
    /*DLinklist q=L->next;//����Ƿ�ok
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
