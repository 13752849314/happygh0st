//
// Created by 37157 on 2021/4/13.
//
#include <cstdio>
#include <cstdlib>
#include "linklist.h"

linklist::linklist() = default;

linklist::~linklist() = default;

linklist::linklist(Linklist L) {
    this->L = L;
    update_length();
}

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
    return L;
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
            per->next = p->next;//��֤L������
            p = p->next;
            //β�巨����B
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
            per->next = p->next;//��֤L������
            p = p->next;
            //ͷ�巨
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

void linklist::add_to_L(Linklist A) {
    auto c = (Linklist) malloc(sizeof(LNode));
    c->next = nullptr;
    Linklist p = L->next, q = A->next;
    while (p && q) {
        if (p->data < q->data) {
            Linklist t = p;
            p = p->next;
            t->next = c->next;
            c->next = t;
        } else {
            Linklist t = q;
            q = q->next;
            t->next = c->next;
            c->next = t;
        }
    }
    while (p != nullptr) {
        Linklist t = p;
        p = p->next;
        t->next = c->next;
        c->next = t;
    }
    while (q != nullptr) {
        Linklist t = q;
        q = q->next;
        t->next = c->next;
        c->next = t;
    }
    L = c;
}

Linklist linklist::Union(linklist &a) {
    auto c = (Linklist) malloc(sizeof(LNode));
    c->next = nullptr;
    Linklist p = L->next, q = a.L->next, g = c;
    while (p != nullptr && q != nullptr) {
        if (p->next != nullptr) {
            while (p->data == p->next->data) {//���������������ֵ��ͬ
                p = p->next;
                if (p->next == nullptr) break;//��ʱp�Ѿ�Ϊβ���
            }
        }
        if (q->next != nullptr) {
            while (q->data == q->next->data) {
                q = q->next;
                if (q->next == nullptr) break;
            }
        }
        if (p->data == q->data) {
            auto s = (Linklist) malloc(sizeof(LNode));
            s->data = p->data;
            s->next = g->next;
            g->next = s;
            g = s;
            p = p->next;
            q = q->next;
        } else {
            p = p->next;
        }
    }
    return c;
}

/**
 * �ж�a.L�Ƿ�ΪL������������ p38 16
 * @param a
 * @return 0:����  1:��
 */
int linklist::is_substr(linklist &a) {
    Linklist p = L->next, per = L->next, q = a.L->next;
    while (p != nullptr && q != nullptr) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            per = per->next;
            p = per;
            q = a.L->next;
        }
    }
    if (q == nullptr) return 1;
    else return 0;
}

/**
 * Ѱ����������k����� p39 21
 * @param k
 * @return 0:fail 1:success
 */
int linklist::Search_end_k(int k) {
    Linklist p = L->next, q = p;
    int count = 0;
    while (p != nullptr) {
        if (count < k) count++;
        else q = q->next;
        p = p->next;
    }
    if (count < k) {
        printf("Search Fail!\n");
        return 0;
    } else {
        printf("Search Success! data=%d\n", q->data);
        return 1;
    }
    /*�㷨˼�룺
     * p��q�����ָ��L�ĵ�һ����㣬count=0
     * ��ʹp����ƶ�k��(count++)��Ȼ����p��qһ������ƶ���ֱ��pΪ��
     * ��countС��k��˵�������Ȳ���k�����Ҳ�����Ӧ��㣻����q��ΪҪ�ҵĽ��
     * ʱ�临�Ӷ�  O(n)
     * �ռ临�Ӷ�  O(1)
     */
}

void linklist::delete_abs_same(int n) {
    int *a = new int[n + 1];//�����ռ�
    Linklist p = L, s;
    while (p->next != nullptr) {
        int m = abs(p->next->data);
        if (a[m] == 0) {//��һ�γ���
            a[m] = 1;//���Ϊ�Ѿ�����
            p = p->next;
        } else {
            s = p->next;//ɾ�����
            p->next = s->next;
            free(s);
        }
    }
    free(a);//�ͷ�����ռ�
    /**
     * 1.���츨������a[n+1],��ֵΪ0
     * 2.����ɨ���������a[abs(data)]==0,�����ý�㲢��a[abs(data)]=1������ɾ���ý��
     * ʱ�临�Ӷ�  O(len(L))
     * �ռ临�Ӷ�  O(n)
     */
}

/**
 * �ж�L�Ƿ��л� p39 24
 * @return  �����뻷���
 */
Linklist linklist::have_loop() {
    auto *k = new Linklist[N];//���������
    int i = 0;
    k[i] = L;
    Linklist p = L;
    while (p->next != nullptr) {//û�л��������˳�ѭ��
        p = p->next;
        i++;
        for (int j = 0; j < i; j++) {
            if (k[j] == p) {
                return p;//�л��������˳�
            }
        }
        k[i] = p;
    }
    return nullptr;
    /**
     * �㷨˼�룺��ʼ����ֻ��ͷ�����һ��Ԫ��
     * ���α����������p���������У���������飻��֮����p
     * ʱ�临�Ӷ�  O(n^2)
     * �ռ临�Ӷ�  O(n)
     */
}

void linklist::str_end() {
    Linklist p = L, q = L;
    while (p->next != nullptr) {//�ҵ��м���q O(n)
        p = p->next;
        q = q->next;
        if (p->next != nullptr) p = p->next;
    }
    //printf("%d    %d\n", q->data, p->data);
    auto head = (Linklist) malloc(sizeof(LNode));//���ص�ͷ���
    head->next = q->next;
    q->next = nullptr;//�ָ
    Linklist s = head->next, r = s->next, t;
    while (r != nullptr) {//���ú��� O(n)
        t = r->next;
        r->next = head->next;
        head->next = r;
        r = t;
    }
    s->next = nullptr;//������ĩβָ���
    p = L->next;
    q = head->next;
    while (p && q) {//�ϲ� O(n)
        r = p->next;
        s = q->next;

        q->next = p->next;
        p->next = q;

        p = r;
        q = s;
    }
    /**
     * �㷨˼�룺
     * 1.�ҵ��м���  ʱ�临�Ӷ�O(n)
     * 2.�����ص���  ʱ�临�Ӷ�O(n)
     * 3.�ϲ���Ҫ�������  ʱ�临�Ӷ�O(n)
     * �ܵ�ʱ�临�Ӷ�  O(n)
     * �ռ临�Ӷ�  O(1)
     */
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
 * ��ȡA��B�Ĺ������ (p38 8) (p38 22)ֻ��Ҫ�ı�����data����������
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
    while (i--) { //�ó�����������i��
        long_L = long_L->next;
    }
    while (long_L != short_L) {
        long_L = long_L->next;
        short_L = short_L->next;
    }
    return long_L;
    /**
     * 1.�����������ĳ���len1��len2
     * 2.long_Lָ�򳤵������ͷ��㣻short_Lָ��̵������ͷ���
     * 3.��long_L����ƶ�abs(len1-len2)��
     * 4.��long_L��short_Lͬʱ����ƶ���ֱ��ָ��ͬһ�����
     * ʱ�临�Ӷ�  O(max(len1,len2))
     * �ռ临�Ӷ�  O(1)
     */
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


