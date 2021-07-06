//
// Created by 37157 on 2021/5/7.
//
#include <iostream>
#include "Tree/Tree.h"

using namespace std;

int main() {
    BiTNode *root, *p, *pp;
    Init_Tree(&root);
    p = InsertLeftNode(root, 'A');
    p = InsertLeftNode(p, 'B');
    p = InsertLeftNode(p, 'D');
    p = InsertRightNode(p, 'G');
    p = InsertRightNode(root->lchild, 'C');
    pp = p;
    InsertLeftNode(p, 'E');
    InsertRightNode(pp, 'F');
    cout << "Recursive pre-order traversal:" << endl;
    PerOrder(root->lchild, Visit);
    cout << endl;
    cout << "Recursive mid-order traversal:" << endl;
    InOrder(root->lchild, Visit);
    cout << endl;
    cout << "Recursive post-order traversal:" << endl;
    PostOrder(root->lchild, Visit);
    cout << endl;
    cout << "Non-recursive pre-order traversal:" << endl;
    PerOrder2(root->lchild, Visit);
    cout << endl;
    cout << "Non-recursive mid-order traversal:" << endl;
    InOrder2(root->lchild, Visit);
    cout << endl;
    cout << "Non-recursive post-order traversal:" << endl;
    PostOrder2(root->lchild, Visit);
    cout << endl;
    cout << "Level traversal:" << endl;
    LevelOrder(root->lchild, Visit);
    cout << endl;
    cout << "p141 4:" << endl;
    InvertLevel(root->lchild, Visit);

    cout << endl;
    cout << "depth is:" << Bi_depth(root->lchild) << endl;
    cout << "depth2 is:" << Bi_depth2(root->lchild) << endl;

    DataType A[] = {'#', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    DataType B[] = {'#', 'B', 'C', 'A', 'E', 'D', 'G', 'H', 'F', 'I'};
    BiTNode *t = PerInCreat(A, B, 1, 9, 1, 9);
    PerOrder(t, Visit);
    cout << endl;
    InOrder(t, Visit);
    cout << endl;
    cout << "IsComplete?:" << IsComplete(t) << endl;
    cout << "Double branch node's number is:" << DsonNodes(t) << endl;
    cout << "Double branch node's number is:" << DsonNodes2(t) << endl;
    swap(t);
    cout<<"t PerOrder:"<<endl;
    PerOrder(t,Visit);
    cout<<endl;
    cout<<"t InOrder:"<<endl;
    InOrder(t,Visit);
    cout<<endl;
    cout<<"The Node at 5 in PerOrder is:"<<PerNode(t,5)<<endl;

    BiTNode *tt=PerInCreat(A,B,1,9,1,9);
    Search(tt,'D');
    PerOrder(tt,Visit);
    cout<<endl;

    tt=PerInCreat(A,B,1,9,1,9);
    find_ancestor(tt,'H',Visit);
    return 0;
}
