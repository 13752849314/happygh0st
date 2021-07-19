//
// Created by 37157 on 2021/7/19.
//
#include "BST/BST.h"

int main() {
    DataType A[] = {7, 1, 3, 8, 9, -2, 78, 23};
    int n = sizeof(A) / sizeof(A[0]);
    BiTNode *bst = nullptr;
    Creat_BST(bst, A, n);
    PerOrder(bst);
    cout << endl;
    InOrder(bst);
    cout << endl;
    cout << BST_Search(bst, 7)->data << endl;
    return 0;
}
