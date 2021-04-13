#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "LinkList.h"
#include "xxb/DLinklist.h"
#include "xxb/LoopLinklist.h"
int main() {
    ElemType A[]={1,2,3,4,5,6};
    LoopLinklist *L=NULL;
    L=Loop_start(L,A,6);
    print_LoopLinklist(L);
    printf("%d\n",get_LoopLinklist_length(L));
    return 0;
}

void test1() {
    ElemType A[9] = {1, 3, 5, 7, 9, 11, 13, 15, 0};
    int n = 9;
    right_move(A, 9, 9);
    print(A, n);

    int a[] = {7, 13, 15, 17, 19};
    int b[] = {2, 4, 6, 8, 9};
    int med = median(a, b, 5);
    printf("%d\n", med);

    int c[] = {5, 2, 2, 2, 3, 4, 5, 2, 2, 5, 5, 2, 2};
    printf("%d\n", main_cell(c, 13));

    int d[] = {-1, 1, 2, 3, 5};
    printf("%d\n", disappear_int(d, 5));

    int S1[] = {-1, 0, 9};
    int S2[] = {-25, -10, 10, 11};
    int S3[] = {2, 9, 17, 30, 41};
    printf("%d\n", minimum(S1, S2, S3, 3, 4, 5));
}

void test2() {
    LinkList L;
    L = List_TailInsert(L);
    print_link_list(L);
    printf("%d\n", get_linklist_length(L));
    Insert_linklist(L, 3, 6);
    print_link_list(L);
    printf("%d\n", get_linklist_length(L));
    delete_linklist(L, 4);
    print_link_list(L);
    printf("%d\n", get_linklist_length(L));
}

void test3() {
    ElemType A[] = {1, 2, 3, 4, 5, 6};
    DLinklist L = NULL;
    L = Init_DLinklist(L);
    L = start(L, A, 6);
    print_DLinklist(L);
    insert_DLinklist(L, 3, 30);
    print_DLinklist(L);
    delete_DLinklist(L, 4);
    print_DLinklist(L);
    printf("%d\n", get_node_byElem(L, 5)->prior->data);
}
