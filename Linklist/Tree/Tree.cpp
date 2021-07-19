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
    root->weight = 2;//p142 19
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

/**
 * ���������������ҽ��
 * @param t ���������ڵ�
 */
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

void DeleteXTree(BiTNode *t) {
    if (t) {
        DeleteXTree(t->lchild);
        DeleteXTree(t->rchild);
        free(t);
    }
}

/**
 * ɾ��ֵxΪ��������
 * @param t
 * @param x
 */
void Search(BiTNode *t, DataType x) {
    Queue<BiTNode *> queue = Queue<BiTNode *>();
    if (t) {
        if (t->data == x) {
            DeleteXTree(t);
            exit(0);
        }
        BiTNode *p = t;
        EnQueue(queue, t);
        while (!QueueEmpty(queue)) {
            DeQueue(queue, p);
            if (p->lchild) {
                if (p->lchild->data == x) {
                    DeleteXTree(p->lchild);
                    p->lchild = nullptr;
                } else {
                    EnQueue(queue, p->lchild);
                }
            }
            if (p->rchild) {
                if (p->rchild->data == x) {
                    DeleteXTree(p->rchild);
                    p->rchild = nullptr;
                } else {
                    EnQueue(queue, p->rchild);
                }
            }
        }
    }
}

/**
 * �ҵ�x(Ψһ)���������ȡ�
 * ���÷ǵݹ�ĺ�������������ʵ�xʱ��ջ������Ԫ�ؾ�Ϊx������
 * @param t
 * @param x
 */
void find_ancestor(BiTNode *t, DataType x, void visit(DataType item)) {
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//��ʼջ
    BiTNode *p = t, *r = nullptr;
    while (p || !StackEmpty(stack)) {
        if (p) {
            Push(stack, p);
            p = p->lchild;
        } else {
            GetTop(stack, p);//��ջ�����
            if (p->data == x) break;//���ʵ�x
            if (p->rchild && p->rchild != r) {//�����������ڣ���δ������
                p = p->rchild;
            } else {
                Pop(stack, p);
                r = p;//��¼������ʹ��Ľ��
                p = nullptr;//�������������pָ��
            }
        }
    }
    Pop(stack, r);
    while (!StackEmpty(stack)) {
        Pop(stack, r);
        visit(r->data);
    }
}

template<typename T>
void find_ancestor1(BiTNode *t, DataType x, vector<T> &vector1, void (*operate)(DataType, vector<T> &)) {//Ѱ��x������
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//��ʼջ
    BiTNode *p = t, *r = nullptr;
    while (p || !StackEmpty(stack)) {
        if (p) {
            Push(stack, p);
            p = p->lchild;
        } else {
            GetTop(stack, p);//��ջ�����
            if (p->data == x) break;//���ʵ�x
            if (p->rchild && p->rchild != r) {//�����������ڣ���δ������
                p = p->rchild;
            } else {
                Pop(stack, p);
                r = p;//��¼������ʹ��Ľ��
                p = nullptr;//�������������pָ��
            }
        }
    }
    Pop(stack, r);
    while (!StackEmpty(stack)) {
        Pop(stack, r);
        operate(r->data, vector1);
    }
}

template<typename T>
void Operate(DataType item, vector<T> &vector) {//��������
    vector.push_back(item);
}

/**
 * �ڶ�����t���ҵ�x��y�Ĺ������ȣ�
 * ���÷ǵݹ�ĺ���������ҵ�x��y�����Ȳ��ֱ�洢��һ��vector�У�
 * ����ҵ�������vector�е�һ����ͬ��Ԫ�ؼ�Ϊ�������ȡ�
 * @param t
 * @param x
 * @param y
 * @return �������ȵ�ֵ
 */
DataType find_comm_ancestor(BiTNode *t, DataType x, DataType y) {
    vector<DataType> vector1, vector2;
    find_ancestor1(t, x, vector1, Operate);//�ҵ�x���������ȣ�����vector1��
    find_ancestor1(t, y, vector2, Operate);//�ҵ�y���������ȣ�����vector2��
    /*for(int i=0;i<vector1.size();i++){
        cout<<vector1.at(i)<<"->";
    }
    cout<<endl;
    for(int i=0;i<vector2.size();i++){
        cout<<vector2.at(i)<<"->";
    }*/
    //��һ������vector1��vector2���ҵ���һ����ͬ��Ԫ�أ���Ϊx��y�Ĺ�������
    for (DataType i : vector1) {
        for (DataType j : vector2) {
            if (i == j) return i;
        }
    }
    cout << "Fail!" << endl;
    return 1;
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

/**
 * ���ò�α������õ�ÿ�����Ĳ�Σ���ͳ��ÿ��Ľ����������ļ�Ϊ���
 * @param t �������ĸ��ڵ�
 * @return �����
 */
int BTWidth(BiTNode *t) {
    Queue<BiTNode *> queue = Queue<BiTNode *>();
    BiTNode *p = t;
    p->level = 1;
    EnQueue(queue, p);
    while (!QueueEmpty(queue)) {
        DeQueue(queue, p);
        //cout<<p->data<<"->";
        if (p->lchild) {
            p->lchild->level = p->level + 1;
            EnQueue(queue, p->lchild);
        }
        if (p->rchild) {
            p->rchild->level = p->level + 1;
            EnQueue(queue, p->rchild);
        }
    }
    int max = 0;
    int max_level = queue.data[queue.rear - 1]->level;//������
    for (int i = 1; i <= max_level; i++) {
        int n = 0;
        for (int j = 0; j < queue.rear; j++) {
            if (queue.data[j]->level == i) n++;
        }
        if (n > max) max = n;
    }
    return max;
}

/**
 * ������������ǰ���������������
 * @param per ǰ������
 * @param str1 ��ʼ
 * @param fin1 ����
 * @param post �洢��������
 * @param str2 ��ʼ
 * @param fin2 ����
 */
void PerToPost(DataType *per, int str1, int fin1, DataType *post, int str2, int fin2) {
    int half;
    if (fin1 >= str1) {
        post[fin2] = per[str1];
        half = (fin1 - str1) / 2;
        PerToPost(per, str1 + 1, str1 + half, post, str2, str2 + half - 1);
        PerToPost(per, str1 + half + 1, fin1, post, str2 + half, fin2 - 1);
    }
}

/**
 * ����ǰ����������ҵ������ҵ�Ҷ�ڵ�
 * @param t ���������ڵ�
 * @return ����ͷ���
 */
BiTNode *Make_Leaf_to_Linklist(BiTNode *t) {
    auto re = (BiTNode *) malloc(sizeof(BiTNode));//ͷ���
    BiTNode *q = re, *p = t;//����ָ��
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();
    while (p || !StackEmpty(stack)) {
        if (p) {
            if (p->lchild == nullptr && p->rchild == nullptr) {//��Ҷ�ڵ�
                q->rchild = p;
                q = p;
            }
            Push(stack, p);
            p = p->lchild;
        } else {
            Pop(stack, p);
            p = p->rchild;
        }
    }
    return re;
}

/**
 * �ж϶�����t1��t2�Ƿ�����
 * @param t1
 * @param t2
 * @return
 */
bool similar(BiTNode *t1, BiTNode *t2) {
    bool left, right;
    if (t1 == nullptr && t2 == nullptr) return true;
    else if (t1 == nullptr || t2 == nullptr) return false;
    else {
        left = similar(t1->lchild, t2->lchild);
        right = similar(t1->rchild, t2->rchild);
        return left && right;
    }
}


/**
 * �������Ĵ�Ȩ·������WPL��
 * �㷨˼�룺���õݹ�������������ÿ�����������Ϊ�ݹ麯����һ��������
 * 1.���ý��ΪҶ��㣬�����wpl���ϸý��������Ȩֵ�ĳ˻���
 * 2.��Ϊ��Ҷ��㣬����������������������õݹ��㷨������������������������õݹ��㷨��
 * @param t
 * @param deep
 * @param wpl
 */
void WPL(BiTNode *t, int deep, int &wpl) {
    if (t->lchild == nullptr && t->rchild == nullptr) {
        wpl += deep * t->weight;
//        cout<<"deep:"<<deep<<"weight"<<t->weight<<endl;
//        getchar();
    }
    if (t->lchild != nullptr) {
        WPL(t->lchild, deep + 1, wpl);
    }
    if (t->rchild != nullptr) {
        WPL(t->rchild, deep + 1, wpl);
    }
}

/**
 * ���õݹ���������
 * @param t
 * @param deep
 */
void BtreeToExp(BiTNode *t, int deep) {
    if (t == nullptr) return;
    else if (t->lchild == nullptr && t->rchild == nullptr) {
        cout << t->data;
    } else {
        if (deep > 0) cout << "(";
        BtreeToExp(t->lchild, deep + 1);
        cout << t->data;
        BtreeToExp(t->rchild, deep + 1);
        if (deep > 0) cout << ")";
    }
}


