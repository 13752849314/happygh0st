#include <cstdio>
#include <cstdlib>
#include "Linklist/linklist.h"
int main() {
    ElemType A[]={2,5,1,7,8,56,78};
    int n= sizeof(A)/ sizeof(A[0]);
    quick_sort(A,0,n-1);
    linklist s(A,n);
    s.print_Linklist();
    printf("%d\n",s.get_by_i(4)->data);
    s.insert_i(4,999);
    s.print_Linklist();
    ElemType e;
    s.delete_i(5,e);
    printf("e=%d\n",e);
    s.print_Linklist();

    s.invert();
    s.print_Linklist();
    return 0;
}
