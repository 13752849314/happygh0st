//
// Created by 37157 on 2021/7/19.
//

#include "BST.h"

bool BST_Insert(BiTNode *&t, DataType k) {
    if (t == nullptr) {
        t = (BiTNode *) malloc(sizeof(BiTNode));
        t->data = k;
        t->rchild = t->lchild = nullptr;
        return true;
    } else if (t->data == k) {
        cout << "The k=" << k << " is repeated!" << endl;
        return false;
    } else if (t->data > k) {//插到t的左子树
        return BST_Insert(t->lchild, k);
    } else {//插到t的右子树
        return BST_Insert(t->rchild, k);
    }
}

void Creat_BST(BiTNode *&t, DataType data[], int n) {
    for (int i = 0; i < n; i++) {
        BST_Insert(t, data[i]);
    }
}

void PerOrder(BiTNode *t) {
    if (t != nullptr) {
        cout << t->data << "->";
        PerOrder(t->lchild);
        PerOrder(t->rchild);
    }
}

void InOrder(BiTNode *t) {
    if (t != nullptr) {
        InOrder(t->lchild);
        cout << t->data << "->";
        InOrder(t->rchild);
    }
}

BiTNode *BST_Search(BiTNode *t, DataType key) {
    BiTNode *p = t;
    while (p != nullptr && key != p->data) {
        if (key < p->data) p = p->lchild;
        else p = p->rchild;
    }
    return p;
}
