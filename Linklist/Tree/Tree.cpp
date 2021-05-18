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
        DeQueue(queue, p);
        visit(p->data);
        if (p->lchild != nullptr) {
            EnQueue(queue, p->lchild);//左子树不空，则左子树根节点入队
        }
        if (p->rchild != nullptr) {
            EnQueue(queue, p->rchild);//右子树不空，则右子树根节点入队
        }
    }
}

/**
 * 自下而上，自右而左的层次遍历。
 * 算法思想：
 * 这样的遍历与正常的层次遍历顺序恰好相反。
 * 在原算法出队的同时将各结点入栈，在所有结点入栈后再从栈顶开始依次访问记为要求的结果
 * @param t 二叉树的第一个结点
 * @param visit 访问函数
 */
void InvertLevel(BiTNode *t, void (*visit)(DataType)) {
    if (t != nullptr) {
        my_stack<BiTNode *> stack = my_stack<BiTNode *>();
        Queue<BiTNode *> queue = Queue<BiTNode *>();
        EnQueue(queue, t);//头结点入队
        BiTNode *p = t;
        while (!QueueEmpty(queue)) {
            DeQueue(queue, p);//出队的同时入栈
            Push(stack, p);
            if (p->lchild) {//如果左子女不空，入队
                EnQueue(queue, p->lchild);
            }
            if (p->rchild) {//如果右子女不空，入队
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
    EnQueue(queue, t);//第一个结点入队
    BiTNode *p = t;
    int high = 0, last = 1;//last指向当前层的最右结点
    while (!QueueEmpty(queue)) {
        DeQueue(queue, p);
        if (p->lchild) {
            EnQueue(queue, p->lchild);
        }
        if (p->rchild) {
            EnQueue(queue, p->rchild);
        }
        if (queue.front == last) {//处理该层最右结点
            high++;
            last = queue.rear;//指向下一层
        }
    }
    return high;
}

/**
 * 由先序遍历A和中序遍历B建立二叉树 p141 6
 * @param A 存放先序遍历的数组
 * @param B 存放中序遍历的数组
 * @param strA A的开始下标
 * @param finA A的结束下标
 * @param strB B的开始下标
 * @param finB B的结束下标
 * @return 二叉树的根节点
 */
BiTNode *PerInCreat(DataType A[], DataType B[], int strA, int finA, int strB, int finB) {
    auto *root = (BiTNode *) malloc(sizeof(BiTNode));//建立根节点
    root->data = A[strA];
    int i;
    for (i = strB; B[i] != root->data; i++);//根节点在中序遍历中的划分
    int llen = i - strB;//左子树长度
    int rlen = finB - i;//右子树长度
    if (llen) {//递归建立左子树
        root->lchild = PerInCreat(A, B, strA + 1, strA + llen, strB, strB + llen - 1);
    } else {
        root->lchild = nullptr;
    }
    if (rlen) {//递归建立右子树
        root->rchild = PerInCreat(A, B, finA - rlen + 1, finA, finB - rlen + 1, finB);
    } else {
        root->rchild = nullptr;
    }
    return root;//返回根结点
}

/**
 * 算法思想：
 * 采用层次遍历，将所有结点加入队列（包括空结点），遇到空结点时，查看其后是否有非空结点。
 * 若有，则二叉树不是完全二叉树
 * @param t 二叉树的根结点
 * @return true：是；false：不是
 */
bool IsComplete(BiTNode *t) {
    if (t == nullptr) return true;//空树为满二叉树
    Queue<BiTNode *> queue = Queue<BiTNode *>();
    EnQueue(queue, t);//根节点入队
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
    EnQueue(queue, t);//根结点入队
    int sum = 0;//记录双分支结点的个数
    while (!QueueEmpty(queue)) {
        DeQueue(queue, p);
        if (p->lchild && p->rchild) sum++;//双分支结点加一
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
    my_stack<BiTNode *> stack = my_stack<BiTNode *>();//初始栈
    BiTNode *p = t;//遍历指针
    int i = 0;
    while (p || !StackEmpty(stack)) {
        if (p) {//一路向左
            i++;
            if (i == k) {
                //cout<<p->data<<endl;
                return p->data;
            }
            //visit(p->data);//访问当前结点
            Push(stack, p);//入栈
            p = p->lchild;
        } else {
            Pop(stack, p);//出栈
            p = p->rchild;//转向出栈结点的右子树
        }
    }
    return '#';
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




