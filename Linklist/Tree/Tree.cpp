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
        DeQueue(queue, p);
        visit(p->data);
        if (p->lchild != nullptr) {
            EnQueue(queue, p->lchild);//���������գ������������ڵ����
        }
        if (p->rchild != nullptr) {
            EnQueue(queue, p->rchild);//���������գ������������ڵ����
        }
    }
}

/**
 * ���¶��ϣ����Ҷ���Ĳ�α�����
 * �㷨˼�룺
 * �����ı����������Ĳ�α���˳��ǡ���෴��
 * ��ԭ�㷨���ӵ�ͬʱ���������ջ�������н����ջ���ٴ�ջ����ʼ���η��ʼ�ΪҪ��Ľ��
 * @param t �������ĵ�һ�����
 * @param visit ���ʺ���
 */
void InvertLevel(BiTNode *t, void (*visit)(DataType)) {
    if (t != nullptr) {
        my_stack<BiTNode *> stack = my_stack<BiTNode *>();
        Queue<BiTNode *> queue = Queue<BiTNode *>();
        EnQueue(queue, t);//ͷ������
        BiTNode *p = t;
        while (!QueueEmpty(queue)) {
            DeQueue(queue, p);//���ӵ�ͬʱ��ջ
            Push(stack, p);
            if (p->lchild) {//�������Ů���գ����
                EnQueue(queue, p->lchild);
            }
            if (p->rchild) {//�������Ů���գ����
                EnQueue(queue, p->rchild);
            }
        }
        while (!StackEmpty(stack)) {
            Pop(stack, p);
            visit(p->data);
        }
    }
}

int Bi_depth(BiTNode *t) {
    if (t == nullptr) return 0;
    int l_dep = Bi_depth(t->lchild);
    int r_dep = Bi_depth(t->rchild);
    if (l_dep > r_dep) {
        return l_dep + 1;
    } else {
        return r_dep + 1;
    }
}

int Bi_depth2(BiTNode *t) {
    if (t == nullptr) return 0;
    Queue<BiTNode *> queue = Queue<BiTNode *>();
    EnQueue(queue, t);//��һ��������
    BiTNode *p = t;
    int high = 0, last = 1;//lastָ��ǰ������ҽ��
    while (!QueueEmpty(queue)) {
        DeQueue(queue, p);
        if (p->lchild) {
            EnQueue(queue, p->lchild);
        }
        if (p->rchild) {
            EnQueue(queue, p->rchild);
        }
        if (queue.front == last) {//����ò����ҽ��
            high++;
            last = queue.rear;//ָ����һ��
        }
    }
    return high;
}

/**
 * ���������A���������B���������� p141 6
 * @param A ����������������
 * @param B ����������������
 * @param strA A�Ŀ�ʼ�±�
 * @param finA A�Ľ����±�
 * @param strB B�Ŀ�ʼ�±�
 * @param finB B�Ľ����±�
 * @return �������ĸ��ڵ�
 */
BiTNode *PerInCreat(DataType A[], DataType B[], int strA, int finA, int strB, int finB) {
    auto *root = (BiTNode *) malloc(sizeof(BiTNode));//�������ڵ�
    root->data = A[strA];
    int i;
    for (i = strB; B[i] != root->data; i++);//���ڵ�����������еĻ���
    int llen = i - strB;//����������
    int rlen = finB - i;//����������
    if (llen) {//�ݹ齨��������
        root->lchild = PerInCreat(A, B, strA + 1, strA + llen, strB, strB + llen - 1);
    } else {
        root->lchild = nullptr;
    }
    if (rlen) {//�ݹ齨��������
        root->rchild = PerInCreat(A, B, finA - rlen + 1, finA, finB - rlen + 1, finB);
    } else {
        root->rchild = nullptr;
    }
    return root;//���ظ����
}

/**
 * �㷨˼�룺
 * ���ò�α����������н�������У������ս�㣩�������ս��ʱ���鿴����Ƿ��зǿս�㡣
 * ���У��������������ȫ������
 * @param t �������ĸ����
 * @return true���ǣ�false������
 */
bool IsComplete(BiTNode *t) {
    if (t == nullptr) return true;//����Ϊ��������
    Queue<BiTNode *> queue = Queue<BiTNode *>();
    EnQueue(queue, t);//���ڵ����
    BiTNode *p = t;
    while (!QueueEmpty(queue)) {
        DeQueue(queue, p);
        if (p) {
            EnQueue(queue, p->lchild);
            EnQueue(queue, p->rchild);
        } else {
            while (!QueueEmpty(queue)) {
                DeQueue(queue, p);
                if (p) {
                    return false;
                }
            }
        }
    }
    return true;
}

int DsonNodes(BiTNode *t) {
    if (t == nullptr) return 0;
    else if (t->lchild != nullptr && t->rchild != nullptr) {
        return DsonNodes(t->lchild) + DsonNodes(t->rchild) + 1;
    } else {
        return DsonNodes(t->lchild) + DsonNodes(t->rchild);
    }
}

int DsonNodes2(BiTNode *t) {
    if (t == nullptr) return 0;
    BiTNode *p = t;
    Queue<BiTNode *> queue = Queue<BiTNode *>();
    EnQueue(queue, t);//��������
    int sum = 0;//��¼˫��֧���ĸ���
    while (!QueueEmpty(queue)) {
        DeQueue(queue, p);
        if (p->lchild && p->rchild) sum++;//˫��֧����һ
        if (p->lchild) {
            EnQueue(queue, p->lchild);
        }
        if (p->rchild) {
            EnQueue(queue, p->rchild);
        }
    }
    return sum;
}

void swap(BiTNode *t) {
    if (t) {
        swap(t->lchild);
        swap(t->rchild);
        BiTNode *p;
        p = t->lchild;
        t->lchild = t->rchild;
        t->rchild = p;
    }
}

DataType PerNode(BiTNode *t, int k) {
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//��ʼջ
    BiTNode *p = t;//����ָ��
    int i = 0;
    while (p || !StackEmpty(stack)) {
        if (p) {//һ·����
            i++;
            if (i == k) {
                //cout<<p->data<<endl;
                return p->data;
            }
            //visit(p->data);//���ʵ�ǰ���
            Push(stack, p);//��ջ
            p = p->lchild;
        } else {
            Pop(stack, p);//��ջ
            p = p->rchild;//ת���ջ����������
        }
    }
    return '#';
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




