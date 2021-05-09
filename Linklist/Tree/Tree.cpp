//
// Created by 37157 on 2021/5/7.
//

#include "Tree.h"

void Init_Tree(BiTNode **root) {
    *root = (BiTNode *) malloc(sizeof(BiTNode));
    (*root)->lchild = nullptr;
    (*root)->rchild = nullptr;
}

void Destroy(BiTNode **root) {
    if ((*root) != nullptr && (*root)->lchild != nullptr)
        Destroy(&(*root)->lchild);
    if ((*root) != nullptr && (*root)->rchild != nullptr)
        Destroy(&(*root)->rchild);
    free(*root);
}

/**
 * 若当前结点curr非空，在curr的左子树插入元素值为x的新结点；
 * 原curr所指结点的左子树成为新插入结点的左子树；
 * 若插入成功返回新插入结点的指针，否则返回空指针。
 * @param curr
 * @param x
 * @return 新插入结点的指针
 */
BiTNode *InsertLeftNode(BiTNode *curr, DataType x) {
    if (curr == nullptr) return nullptr;
    BiTNode *t, *s;
    t = curr->lchild;//保存原curr所指结点的左子树指针
    s = (BiTNode *) malloc(sizeof(BiTNode));
    s->data = x;
    s->lchild = t;//新插入结点的左子树为原curr的左子树
    s->rchild = nullptr;
    curr->lchild = s;//新结点成为curr的左子树
    return curr->lchild;//返回新插入结点的指针
}

/**
 * 若当前结点curr非空，在curr的右子树插入元素值为x的新结点；
 * 原curr所指结点的右子树成为新插入结点的右子树；
 * 若插入成功返回新插入结点的指针，否则返回空指针。
 * @param curr
 * @param x
 * @return 新插入结点的指针
 */
BiTNode *InsertRightNode(BiTNode *curr, DataType x) {
    if (curr == nullptr) return nullptr;
    BiTNode *t, *s;
    t = curr->rchild;//保存原curr所指结点的右子树指针
    s = (BiTNode *) malloc(sizeof(BiTNode));
    s->data = x;
    s->rchild = t;//新插入结点的右子树为原curr的右子树
    s->lchild = nullptr;
    curr->rchild = s;//新结点成为curr的右子树
    return curr->rchild;//返回新插入结点的指针
}

void PerOrder(BiTNode *t, void (*visit)(DataType)) {
    if (t != nullptr) {
        visit(t->data);
        PerOrder(t->lchild, visit);
        PerOrder(t->rchild, visit);
    }
}

void InOrder(BiTNode *t, void (*visit)(DataType)) {
    if (t != nullptr) {
        InOrder(t->lchild, visit);
        visit(t->data);
        InOrder(t->rchild, visit);
    }
}

void PostOrder(BiTNode *t, void (*visit)(DataType)) {
    if (t != nullptr) {
        PostOrder(t->lchild, visit);
        PostOrder(t->rchild, visit);
        visit(t->data);
    }
}

void Visit(DataType item) {
    cout << item << " ";
}

void PerOrder2(BiTNode *t, void (*visit)(DataType)) {
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//初始栈
    BiTNode *p = t;//遍历指针
    while (p || !StackEmpty(stack)) {
        if (p) {//一路向左
            visit(p->data);//访问当前结点
            Push(stack, p);//入栈
            p = p->lchild;
        } else {
            Pop(stack, p);//出栈
            p = p->rchild;//转向出栈结点的右子树
        }
    }
}

void InOrder2(BiTNode *t, void (*visit)(DataType)) {
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//初始栈
    BiTNode *p = t;
    while (p || !StackEmpty(stack)) {
        if (p) {
            Push(stack, p);
            p = p->lchild;
        } else {
            Pop(stack, p);
            visit(p->data);
            p = p->rchild;
        }
    }
}

void PostOrder2(BiTNode *t, void (*visit)(DataType)) {
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//初始栈
    BiTNode *p = t, *r = nullptr;
    while (p || !StackEmpty(stack)) {
        if (p) {
            Push(stack, p);
            p = p->lchild;
        } else {
            GetTop(stack, p);//读栈顶结点
            if (p->rchild && p->rchild != r) {//若右子树存在，且未被访问
                p = p->rchild;
            } else {
                Pop(stack, p);
                visit(p->data);
                r = p;//记录最近访问过的结点
                p = nullptr;//结点访问完后，重置p指针
            }
        }
    }
}

void LevelOrder(BiTNode *t, void (*visit)(DataType)) {
    Queue<BiTNode *> queue = Queue<BiTNode *>();//初始化队列
    BiTNode *p = t;
    EnQueue(queue, t);//根节点入队
    while (!QueueEmpty(queue)) {
        DeQueue(queue,p);
        visit(p->data);
        if(p->lchild!= nullptr){
            EnQueue(queue,p->lchild);//左子树不空，则左子树根节点入队
        }
        if(p->rchild!= nullptr){
            EnQueue(queue,p->rchild);//右子树不空，则右子树根节点入队
        }
    }
}

//栈和队列的方法的具体实现
template<typename T>
bool Push(my_stack<T> &S, T x) {
    if (S.top == Maxsize - 1) return false;
    S.data[++S.top] = x;
    return true;
}

template<typename T>
bool Pop(my_stack<T> &S, T &x) {
    if (S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

template<typename T>
bool StackEmpty(my_stack<T> S) {
    return S.top == -1;
}

template<typename T>
bool GetTop(my_stack<T> &S, T &x) {
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

template<typename T>
bool EnQueue(Queue<T> &Q, T x) {
    if (Q.rear == Maxsize) {
        cout << "Queue is Full!" << endl;//并不是真正意义上的满
        return false;
    }
    Q.data[Q.rear++] = x;
    return true;
}

template<typename T>
bool QueueEmpty(Queue<T> Q) {
    return Q.front == Q.rear;
}

template<typename T>
bool DeQueue(Queue<T> &Q, T &x) {
    if (QueueEmpty(Q)) {
        cout << "Queue is Empty!" << endl;
        return false;
    } else {
        x = Q.data[Q.front++];
        return true;
    }
}


