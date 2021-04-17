#include <cstdio>
#include <cstdlib>
#include "Linklist/linklist.h"

int temp = 0;

void divide() {
    printf("==========%d==========\n", temp);
    temp++;
}

int main() {
    ElemType A[] = {-12, 5, 1, 7, 8, 56, -2, 78, 1, 1, 3, 5, 5, -78};
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
    return 0;
}
