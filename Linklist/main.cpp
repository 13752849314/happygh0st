#include <cstdio>
#include <cstdlib>
#include "Linklist/linklist.h"
#include "Linklist/LLinklist.h"

int temp = 0;

void divide() {
    printf("==========%d==========\n", temp);
    temp++;
}


int main() {
    ElemType A[] = {-12, -5, 1, 7, 8, 56, -2, 78, 1, 1, 3, 5, 5, -78};
    int n = sizeof(A) / sizeof(A[0]);
    //quick_sort(A, 0, n - 1);
    linklist s(A, n);
    s.print_Linklist();
    divide();

    printf("%d\n", s.get_by_i(4)->data);
    s.insert_i(4, 999);
    s.print_Linklist();
    divide();

    ElemType e;
    s.delete_i(5, e);
    printf("e=%d\n", e);
    s.print_Linklist();
    divide();

    s.print_Linklist();
    s.invert();
    s.print_Linklist();
    divide();

    s.print_Linklist();
    printf("length=%d\n", s.length);
    s.delete_all_x(5);
    s.print_Linklist();
    printf("length=%d\n", s.length);
    divide();

    s.print_Linklist();
    linklist::reverse_print(s.L->next);
    putchar('\n');
    divide();

    s.print_Linklist();
    s.delete_only_min();
    s.print_Linklist();
    divide();

    s.print_Linklist();
    s.sort_Linklist();
    s.print_Linklist();
    divide();

    s.print_Linklist();
    s.delete_a_to_b(0, 9);
    s.print_Linklist();
    divide();

    linklist ss(A, n);
    s.print_Linklist();
    ss.print_Linklist();
    Linklist t = s.get_by_i(s.length);
    t->next = ss.get_by_i(ss.length);
    s.update_length();
    s.print_Linklist();
    printf("data=%d\n", find_common_Node(s, ss)->data);
    divide();

    ss.print_Linklist();
    ss.print_up();
    ss.print_Linklist();
    divide();

    ElemType a_78[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int n_79 = sizeof(a_78) / sizeof(a_78[0]);
    linklist sss(a_78, n_79);
    sss.print_Linklist();
    Linklist B_82 = sss.divide_by_odd_even();
    sss.update_length();
    sss.print_Linklist();
    print_Linklist(B_82);
    divide();

    sss.print_Linklist();
    Linklist B_89 = sss.divide_by_odd_even2();
    sss.update_length();
    sss.print_Linklist();
    print_Linklist(B_89);
    divide();

    s.print_Linklist();
    s.insert_i(2, -2);
    s.insert_i(2, -78);
    s.insert_i(2, 999);
    s.sort_Linklist();
    s.print_Linklist();
    s.delete_same();
    s.print_Linklist();
    divide();

    s.print_Linklist();
    sss.print_Linklist();
    s.add_to_L(sss.L);
    s.update_length();
    sss.update_length();
    s.print_Linklist();
    sss.print_Linklist();
    divide();

    ElemType a_118[] = {1, 1, 2, 3, 3, 4, 7, 9, 9, 9, 11};
    int n_116 = sizeof(a_118) / sizeof(a_118[0]);
    linklist a_117(a_118, n_116);
    a_117.print_Linklist();
    ElemType a_119[] = {3, 4, 7};
    int n_120 = sizeof(a_119) / sizeof(a_119[0]);
    linklist a_121(a_119, n_120);
    a_121.print_Linklist();
    Linklist c = a_117.Union(a_121);
    print_Linklist(c);
    divide();

    a_117.print_Linklist();
    a_121.print_Linklist();
    int boo = a_117.is_substr(a_121);
    printf("%d\n", boo);
    divide();

    ElemType hg[] = {1, 3, 5, 6, 6, 5, 3, 1};
    int z = sizeof(hg) / sizeof(hg[0]);
    llinklist fzy(hg, z);
    fzy.print_LLinklist();
    divide();

    auto L = (DLinklist) malloc(sizeof(DNode));
    creat_DLinklist(L, hg, z);
    print_DLinklist(L);
    is_symmetry(L);
    divide();

    ElemType sg[] = {2, 4, 7, 888, 999};
    int sg_n = sizeof(sg) / sizeof(sg[0]);
    llinklist pg(sg, sg_n);
    pg.print_LLinklist();
    fzy.add_tail(pg);
    fzy.print_LLinklist();
    divide();

    fzy.print_up();
    divide();

    test_Locate();
    divide();

    linklist a_160(A, n);
    a_160.print_Linklist();
    a_160.Search_end_k(10);
    divide();

    a_160.print_Linklist();
    a_160.delete_abs_same(78);
    a_160.print_Linklist();
    divide();

    linklist ou(A, n);
    ou.print_Linklist();
    Linklist end = ou.get_by_i(ou.length);//取最后一个结点
    Linklist ru = ou.get_by_i(6);//取第i个结点
    end->next = ru;//最后一个结点指向第i个结点
    Linklist re = ou.have_loop();
    printf("%d\n", re->data);
    divide();

    linklist ao(A, n);
    ao.print_Linklist();
    ao.str_end();
    ao.print_Linklist();
    divide();
    return 0;
}
