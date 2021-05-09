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
 * ����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½�㣻
 * ԭcurr��ָ������������Ϊ�²��������������
 * ������ɹ������²������ָ�룬���򷵻ؿ�ָ�롣
 * @param curr
 * @param x
 * @return �²������ָ��
 */
BiTNode *InsertLeftNode(BiTNode *curr, DataType x) {
    if (curr == nullptr) return nullptr;
    BiTNode *t, *s;
    t = curr->lchild;//����ԭcurr��ָ����������ָ��
    s = (BiTNode *) malloc(sizeof(BiTNode));
    s->data = x;
    s->lchild = t;//�²������������Ϊԭcurr��������
    s->rchild = nullptr;
    curr->lchild = s;//�½���Ϊcurr��������
    return curr->lchild;//�����²������ָ��
}

/**
 * ����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½�㣻
 * ԭcurr��ָ������������Ϊ�²��������������
 * ������ɹ������²������ָ�룬���򷵻ؿ�ָ�롣
 * @param curr
 * @param x
 * @return �²������ָ��
 */
BiTNode *InsertRightNode(BiTNode *curr, DataType x) {
    if (curr == nullptr) return nullptr;
    BiTNode *t, *s;
    t = curr->rchild;//����ԭcurr��ָ����������ָ��
    s = (BiTNode *) malloc(sizeof(BiTNode));
    s->data = x;
    s->rchild = t;//�²������������Ϊԭcurr��������
    s->lchild = nullptr;
    curr->rchild = s;//�½���Ϊcurr��������
    return curr->rchild;//�����²������ָ��
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
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//��ʼջ
    BiTNode *p = t;//����ָ��
    while (p || !StackEmpty(stack)) {
        if (p) {//һ·����
            visit(p->data);//���ʵ�ǰ���
            Push(stack, p);//��ջ
            p = p->lchild;
        } else {
            Pop(stack, p);//��ջ
            p = p->rchild;//ת���ջ����������
        }
    }
}

void InOrder2(BiTNode *t, void (*visit)(DataType)) {
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//��ʼջ
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
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//��ʼջ
    BiTNode *p = t, *r = nullptr;
    while (p || !StackEmpty(stack)) {
        if (p) {
            Push(stack, p);
            p = p->lchild;
        } else {
            GetTop(stack, p);//��ջ�����
            if (p->rchild && p->rchild != r) {//�����������ڣ���δ������
                p = p->rchild;
            } else {
                Pop(stack, p);
                visit(p->data);
                r = p;//��¼������ʹ��Ľ��
                p = nullptr;//�������������pָ��
            }
        }
    }
}

void LevelOrder(BiTNode *t, void (*visit)(DataType)) {
    Queue<BiTNode *> queue = Queue<BiTNode *>();//��ʼ������
    BiTNode *p = t;
    EnQueue(queue, t);//���ڵ����
    while (!QueueEmpty(queue)) {
        DeQueue(queue,p);
        visit(p->data);
        if(p->lchild!= nullptr){
            EnQueue(queue,p->lchild);//���������գ������������ڵ����
        }
        if(p->rchild!= nullptr){
            EnQueue(queue,p->rchild);//���������գ������������ڵ����
        }
    }
}

//ջ�Ͷ��еķ����ľ���ʵ��
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
        cout << "Queue is Full!" << endl;//���������������ϵ���
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


