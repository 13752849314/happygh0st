//
// Created by 37157 on 2021/7/19.
//

#ifndef LINKLIST_BST_H
#define LINKLIST_BST_H

#include <iostream>

using namespace std;
typedef int DataType;
typedef struct Node {
    DataType data;
    struct Node *lchild, *rchild;
} BiTNode;

void PerOrder(BiTNode *t);

void InOrder(BiTNode *t);


bool BST_Insert(BiTNode *&t, DataType k);

void Creat_BST(BiTNode *&t, DataType data[], int n);

BiTNode *BST_Search(BiTNode *t, DataType key);

#endif //LINKLIST_BST_H
