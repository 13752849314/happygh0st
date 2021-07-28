//
// Created by 37157 on 2021/7/23.
//

#ifndef UTILS_UTILS_H
#define UTILS_UTILS_H
#define UtilsMaxSize 100

#include <iostream>

using namespace std;
template<typename T>
struct SqList {
    T data[UtilsMaxSize]{};
    int length = 0;
};

template<typename T>
void print(SqList<T> L);

template<typename T>
void print(SqList<T> L) {
    if (L.length == 0) {
        cout << "Empty!" << endl;
    } else {
        for (int i = 0; i < L.length; i++) {
            cout << L.data[i] << "->";
        }
        putchar('\n');
    }
}

template<typename T>
bool Insert_all(SqList<T> &L, T arr[], int n) {
    for (int i = 0; i < n; i++) {
        append(L, arr[i]);
    }
    return true;
}

template<typename T>
bool append(SqList<T> &L, T a);

template<typename T>
bool append(SqList<T> &L, T a) {
    if (L.length < UtilsMaxSize) {
        L.data[L.length++] = a;
        return true;
    }
    cout << "Full!" << endl;
    return false;
}


template<typename T>
bool Insert(SqList<T> &L, int i, T a);

template<typename T>
bool Insert(SqList<T> &L, int i, T a) {
    if (i < 0 || i > L.length + 1 || L.length >= UtilsMaxSize) {
        cout << "Insert fail!" << endl;
        return false;
    }
    for (int j = L.length; j >= i; j--) {//后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = a;
    L.length++;
    return true;
}

template<typename T>
bool Delete(SqList<T> &L, int i, T &e) {
    if (i < 0 || i > L.length) {
        cout << "Can not delete!" << endl;
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {//向前移动
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

template<typename T>
SqList<int> Search(SqList<T> L, T x) {
    SqList<int> re = SqList<int>();
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x) {
            append(re, i);
        }
    }
    return re;
}

template<typename T>
void Invert(SqList<T> &L) {
    T t;
    for (int i = 0; i < L.length / 2; i++) {
        t = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = t;
    }
}

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;
};

template<typename T>
class Linklist : public Node<T> {
private:
    Node<T> *head;//头结点
public:
    Linklist();

    Linklist(T A[], int n);

    bool Empty();

    int GetLen();

    void Head_insert(T t);

    Node<T> *GetNode(int i);

    bool insert(int idx, T elem);

    bool remove(int idx, T &elem);

    void traverse(void(*print)(T &elem));

    void Invert();
};

/**
 * 无参的构造函数
 * @tparam T
 */
template<typename T>
inline Linklist<T>::Linklist() {
    this->head = (Node<T> *) malloc(sizeof(Node<T>));
    if (!this->head) {
        cerr << "Error allocation memory!" << endl;
    }
    this->head->next = nullptr;
}

/**
 * 带参的构造函数，用数组A的元素的顺序创建单链表
 * @tparam T
 * @param A
 * @param n 数组长度
 */
template<typename T>
Linklist<T>::Linklist(T *A, int n) {
    Linklist();
    Node<T> *p = this->head;
    for (int i = 0; i < n; i++) {
        Node<T> *new_node;
        new_node = (Node<T> *) malloc(sizeof(Node<T>));
        new_node->data = A[i];
        new_node->next = p->next;
        p->next = new_node;
        p = new_node;
    }
}

/**
 * 判断是否为空
 * @tparam T
 * @return
 */
template<typename T>
inline bool Linklist<T>::Empty() {
    return this->head->next == nullptr;
}

/**
 * 获取链表的长度
 * @tparam T
 * @return
 */
template<typename T>
int Linklist<T>::GetLen() {
    Node<T> *tem = this->head->next;
    int counter = 0;
    while (tem) {
        counter++;
        tem = tem->next;
    }
    return counter;
}

/**
 * 头插法插入t
 * @tparam T
 * @param t
 */
template<typename T>
void Linklist<T>::Head_insert(T t) {
    Node<T> *new_node;
    new_node = (Node<T> *) malloc(sizeof(Node<T>));
    new_node->data = t;
    new_node->next = this->head->next;
    this->head->next = new_node;
}

/**
 * 获取第i个结点
 * @tparam T
 * @param i
 * @return
 */
template<typename T>
Node<T> *Linklist<T>::GetNode(int i) {
    if (i == 0) return this->head;
    if (i >= 1 && i <= GetLen()) {
        Node<T> *t = this->head;
        while (i--) {
            t = t->next;
        }
        return t;
    }
    return nullptr;
}

/**
 * 在第i个位置插入elem
 * @tparam T
 * @param i
 * @param elem
 * @return
 */
template<typename T>
bool Linklist<T>::insert(int i, T elem) {
    if (i < 1 || i > GetLen() + 1) {
        cerr << "subscript wrong!" << endl;
        return false;
    }
    Node<T> *new_node;
    new_node = (Node<T> *) malloc(sizeof(Node<T>));
    new_node->data = elem;
    Node<T> *t = GetNode(i - 1);
    new_node->next = t->next;
    t->next = new_node;
    return true;
}

/**
 * 遍历链表
 * @tparam T
 * @param print 遍历函数
 */
template<typename T>
void Linklist<T>::traverse(void (*print)(T &elem)) {
    Node<T> *tem = this->head->next;
    while (tem) {
        print(tem->data);
        tem = tem->next;
    }
    cout << endl;
}

template<typename T>
bool Linklist<T>::remove(int idx, T &elem) {
    if (idx >= 1 && idx <= GetLen()) {
        Node<T> *t = GetNode(idx - 1);
        Node<T> *p = t->next;
        elem = p->data;
        t->next = p->next;
        free(p);
        return true;
    } else {
        cerr << "subscript wrong!" << endl;
        return false;
    }
}

template<typename T>
void Linklist<T>::Invert() {
    Node<T> *p = this->head->next, *t = p->next, *q;
    while (t != nullptr) {
        q = t->next;
        t->next = this->head->next;
        this->head->next = t;
        t = q;
    }
    p->next = nullptr;
}

template<typename T>
void print(T &elem) {
    cout << elem << "->";
}

template<typename T>
class LinkStack : Node<T> {
private:
    Node<T> *top;//栈顶指针
public:
    LinkStack();

    bool Empty();

    bool Push(T elem);

    bool Pop(T &elem);

    T GetTop();
};

/**
 * 不带参的构造方法
 * @tparam T
 */
template<typename T>
LinkStack<T>::LinkStack() {
    this->top = (Node<T> *) malloc(sizeof(Node<T>));
    if (!this->top) {
        cerr << "Error allocation memory!" << endl;
    }
    this->top->next = nullptr;
}

template<typename T>
bool LinkStack<T>::Empty() {
    return this->top->next == nullptr;
}

template<typename T>
bool LinkStack<T>::Push(T elem) {
    Node<T> *p;
    p = (Node<T> *) malloc(sizeof(Node<T>));
    if (!p) {
        return false;
    }
    p->data = elem;
    p->next = this->top->next;
    this->top->next = p;
    return true;
}

template<typename T>
bool LinkStack<T>::Pop(T &elem) {
    if (Empty()) {
        cerr << "Stack empty!" << endl;
        return false;
    }
    Node<T> *p = this->top->next;
    elem = p->data;
    this->top->next = p->next;
    free(p);
    return true;
}

template<typename T>
T LinkStack<T>::GetTop() {
    T t;
    if (!Empty()) {
        return this->top->next->data;
    } else {
        return t;
    }
}

template<typename T>
class LinkQueue : Node<T> {
public:
    Node<T> *front, *rear;
    int length{};

    LinkQueue();

    bool EnQueue(T elem);

    bool Empty();

    bool DeQueue(T &elem);
};

template<typename T>
LinkQueue<T>::LinkQueue() {
    this->front = this->rear = (Node<T> *) malloc(sizeof(Node<T>));
    if (!this->front) {
        cerr << "Error allocation memory!" << endl;
    }
    this->length = 0;
    this->rear->next = nullptr;
}

template<typename T>
bool LinkQueue<T>::EnQueue(T elem) {
    Node<T> *p;
    p = (Node<T> *) malloc(sizeof(Node<T>));
    if (!p) {
        cerr << "Error allocation memory!" << endl;
        return false;
    }
    p->data = elem;
    p->next = nullptr;
    this->rear->next = p;
    this->rear = p;
    this->length++;
    return true;
}

template<typename T>
bool LinkQueue<T>::Empty() {
    return this->front == this->rear;
}

template<typename T>
bool LinkQueue<T>::DeQueue(T &elem) {
    if (Empty()) {
        cerr << "Empty!" << endl;
        return false;
    }
    Node<T> *p = this->front->next;
    elem = p->data;
    this->front = p;
    this->length--;
    return true;
}

template<typename T>
class TNode {
public:
    T data;
    TNode<T> *lchild, *rchild;
};

template<typename T>
class Tree : TNode<T> {
public:
    TNode<T> *root;

    Tree();

    Tree(T A[], T B[], int strA, int finA, int strB, int finB);

    Tree(T A[], int n);

    TNode<T> *PerInCreat(T A[], T B[], int strA, int finA, int strB, int finB);

    bool BST_Insert(TNode<T> *&t, T elem);

    TNode<T> *Creat_BST(T A[], int n);

    static void Destroy(TNode<T> *root);

    TNode<T> *InsertLeftNode(TNode<T> *curr, T elem);

    TNode<T> *InsertRightNode(TNode<T> *curr, T elem);

    static void PerOrder(TNode<T> *t, void (*visit)(T &elem));

    void PerOrder(void (*visit)(T &elem));

    static void InOrder(TNode<T> *t, void (*visit)(T &elem));

    void InOrder(void (*visit)(T &elem));

    static void PostOrder(TNode<T> *t, void (*visit)(T &elem));

    void PostOrder(void (*visit)(T &elem));

    static void PerOrder2(TNode<T> *t, void(*visit)(T &elem));

    void PerOrder2(void(*visit)(T &elem));

    static void InOrder2(TNode<T> *t, void (*visit)(T &elem));

    void InOrder2(void (*visit)(T &elem));

    static void PostOrder2(TNode<T> *t, void (*visit)(T &elem));

    void PostOrder2(void (*visit)(T &elem));

    static void LevelOrder(TNode<T> *t, void(*visit)(T &elem));

    void LevelOrder(void (*visit)(T &elem));

    static int Get_depth(TNode<T> *t);

    int Get_depth();

    static int Get_width(TNode<T> *t);

    int Get_width();

    TNode<T> *BST_Search(T key);
};

template<typename T>
Tree<T>::Tree() {
    this->root = (TNode<T> *) malloc(sizeof(TNode<T>));
    this->root->lchild = nullptr;
    this->root->rchild = nullptr;
}

/**
 * 通过前序序列和中序序列创建二叉树
 * @tparam T
 * @param A 存储前序序列
 * @param B 存储中序序列
 * @param strA
 * @param finA
 * @param strB
 * @param finB
 */
template<typename T>
Tree<T>::Tree(T A[], T B[], int strA, int finA, int strB, int finB) {
    this->root = (TNode<T> *) malloc(sizeof(TNode<T>));
    this->root->lchild = this->root->rchild = nullptr;
    TNode<T> *t = nullptr;
    t = PerInCreat(A, B, strA, finA, strB, finB);
    this->root->lchild = t;
}

/**
 * 创建二叉排序树
 * @tparam T
 * @param A
 * @param n
 */
template<typename T>
Tree<T>::Tree(T A[], int n) {
    this->root = (TNode<T> *) malloc(sizeof(TNode<T>));
    this->root->lchild = this->root->rchild = nullptr;
    this->root->lchild = Creat_BST(A, n);
}

/**
 * 若当前结点curr非空，在curr的左子树插入元素值为x的新结点；
 * 原curr所指结点的左子树成为新插入结点的左子树；
 * 若插入成功返回新插入结点的指针，否则返回空指针。
 * @tparam T
 * @param curr
 * @param elem
 * @return 新插入结点的指针
 */
template<typename T>
TNode<T> *Tree<T>::InsertLeftNode(TNode<T> *curr, T elem) {
    if (curr == nullptr) return nullptr;
    TNode<T> *t, *s;
    t = curr->lchild;//保存原curr所指结点的左子树指针
    s = (TNode<T> *) malloc(sizeof(TNode<T>));
    s->data = elem;
    s->lchild = t;//新插入结点的左子树为原curr的左子树
    s->rchild = nullptr;
    curr->lchild = s;//新结点成为curr的左子树
    return curr->lchild;//返回新插入结点的指针
}

/**
 * 若当前结点curr非空，在curr的右子树插入元素值为x的新结点；
 * 原curr所指结点的右子树成为新插入结点的右子树；
 * 若插入成功返回新插入结点的指针，否则返回空指针。
 * @tparam T
 * @param curr
 * @param elem
 * @return 新插入结点的指针
 */
template<typename T>
TNode<T> *Tree<T>::InsertRightNode(TNode<T> *curr, T elem) {
    if (curr == nullptr) return nullptr;
    TNode<T> *t, *s;
    t = curr->rchild;//保存原curr所指结点的右子树指针
    s = (TNode<T> *) malloc(sizeof(TNode<T>));
    s->data = elem;
    s->rchild = t;//新插入结点的右子树为原curr的右子树
    s->lchild = nullptr;
    curr->rchild = s;//新结点成为curr的右子树
    return curr->rchild;//返回新插入结点的指针
}

template<typename T>
void Tree<T>::Destroy(TNode<T> *root) {
    if (root != nullptr && root->lchild != nullptr) {
        Destroy(root->lchild);
    }
    if (root != nullptr && root->rchild != nullptr) {
        Destroy(root->rchild);
    }
    free(root);
}

template<typename T>
void Tree<T>::PerOrder(TNode<T> *t, void (*visit)(T &elem)) {
    if (t != nullptr) {
        visit(t->data);
        PerOrder(t->lchild, visit);
        PerOrder(t->rchild, visit);
    }
}

template<typename T>
void Tree<T>::PerOrder(void (*visit)(T &elem)) {
    Tree<T>::PerOrder(this->root->lchild, visit);
}

template<typename T>
void Tree<T>::InOrder(TNode<T> *t, void (*visit)(T &)) {
    if (t != nullptr) {
        InOrder(t->lchild, visit);
        visit(t->data);
        InOrder(t->rchild, visit);
    }
}

template<typename T>
void Tree<T>::InOrder(void (*visit)(T &elem)) {
    Tree<T>::InOrder(this->root->lchild, visit);
}

template<typename T>
void Tree<T>::PostOrder(TNode<T> *t, void (*visit)(T &)) {
    if (t != nullptr) {
        PostOrder(t->lchild, visit);
        PostOrder(t->rchild, visit);
        visit(t->data);
    }
}

template<typename T>
void Tree<T>::PostOrder(void (*visit)(T &)) {
    Tree<T>::PostOrder(this->root->lchild, visit);
}

template<typename T>
void Tree<T>::PerOrder2(TNode<T> *t, void (*visit)(T &)) {
    LinkStack<TNode<T> *> stack;
    TNode<T> *p = t;
    while (p || !stack.Empty()) {
        if (p) {
            visit(p->data);
            stack.Push(p);
            p = p->lchild;
        } else {
            stack.Pop(p);
            p = p->rchild;
        }
    }
}

template<typename T>
void Tree<T>::PerOrder2(void (*visit)(T &)) {
    Tree<T>::PerOrder2(this->root->lchild, visit);
}

template<typename T>
void Tree<T>::InOrder2(TNode<T> *t, void (*visit)(T &)) {
    LinkStack<TNode<T> *> stack;
    TNode<T> *p = t;
    while (p || !stack.Empty()) {
        if (p) {
            stack.Push(p);
            p = p->lchild;
        } else {
            stack.Pop(p);
            visit(p->data);
            p = p->rchild;
        }
    }
}

template<typename T>
void Tree<T>::InOrder2(void (*visit)(T &)) {
    Tree<T>::InOrder2(this->root->lchild, visit);
}

template<typename T>
void Tree<T>::PostOrder2(TNode<T> *t, void (*visit)(T &)) {
    LinkStack<TNode<T> *> stack;
    TNode<T> *p = t, *r = nullptr;
    while (p || !stack.Empty()) {
        if (p) {
            stack.Push(p);
            p = p->lchild;
        } else {
            p = stack.GetTop();//读栈顶结点
            if (p->rchild && p->rchild != r) {//若右子树存在，且未被访问
                p = p->rchild;
            } else {
                stack.Pop(p);
                visit(p->data);
                r = p;//记录最近访问过的结点
                p = nullptr;//结点访问完后，重置p指针
            }
        }
    }
}

template<typename T>
void Tree<T>::PostOrder2(void (*visit)(T &elem)) {
    Tree<T>::PostOrder2(this->root->lchild, visit);
}

template<typename T>
void Tree<T>::LevelOrder(TNode<T> *t, void (*visit)(T &elem)) {
    LinkQueue<TNode<T> *> queue;
    TNode<T> *p = t;
    queue.EnQueue(p);//根节点入队
    while (!queue.Empty()) {
        queue.DeQueue(p);
        visit(p->data);
        if (p->lchild != nullptr) {
            queue.EnQueue(p->lchild);
        }
        if (p->rchild != nullptr) {
            queue.EnQueue(p->rchild);
        }
    }
}

template<typename T>
void Tree<T>::LevelOrder(void (*visit)(T &elem)) {
    Tree<T>::LevelOrder(this->root->lchild, visit);
}

template<typename T>
int Tree<T>::Get_depth(TNode<T> *t) {
    if (t == nullptr) return 0;
    int l_dep = Get_depth(t->lchild);
    int r_dep = Get_depth(t->rchild);
    if (l_dep > r_dep) {
        return l_dep + 1;
    } else {
        return r_dep + 1;
    }
}

template<typename T>
int Tree<T>::Get_depth() {
    return Tree<T>::Get_depth(this->root->lchild);
}

template<typename T>
int Tree<T>::Get_width(TNode<T> *t) {
    if (t == nullptr)
        return 0;
    TNode<T> *p = t, *r = nullptr;
    LinkQueue<TNode<T> *> queue;
    queue.EnQueue(p);
    int width = 1;
    r = queue.rear->data;
    while (!queue.Empty()) {
        queue.DeQueue(p);
        if (p->lchild != nullptr) {
            queue.EnQueue(p->lchild);
        }
        if (p->rchild != nullptr) {
            queue.EnQueue(p->rchild);
        }
        if (p == r && queue.length > width) {
            width = queue.length;
            r = queue.rear->data;
        }
    }
    return width;
}

template<typename T>
int Tree<T>::Get_width() {
    return Tree<T>::Get_width(this->root->lchild);
}

template<typename T>
void Visit(T &elem) {
    cout << elem << "->";
}

template<typename T>
TNode<T> *Tree<T>::PerInCreat(T A[], T B[], int strA, int finA, int strB, int finB) {
    TNode<T> *t;
    t = (TNode<T> *) malloc(sizeof(TNode<T>));
    t->data = A[strA];
    int i;
    for (i = strB; B[i] != t->data; i++);////根节点在中序遍历中的划分
    int llen = i - strB;
    int rlen = finB - i;
    if (llen) {//递归建立左子树
        t->lchild = PerInCreat(A, B, strA + 1, strA + llen, strB, strB + llen - 1);
    } else {
        t->lchild = nullptr;
    }
    if (rlen) {//递归建立右子树
        t->rchild = PerInCreat(A, B, finA - rlen + 1, finA, finB - rlen + 1, finB);
    } else {
        t->rchild = nullptr;
    }
    return t;//返回根结点
}

template<typename T>
bool Tree<T>::BST_Insert(TNode<T> *&t, T elem) {
    if (t == nullptr) {
        t = (TNode<T> *) malloc(sizeof(TNode<T>));
        t->data = elem;
        t->lchild = t->rchild = nullptr;
        return true;
    } else if (elem == t->data) {
        return false;
    } else if (elem < t->data) {
        return BST_Insert(t->lchild, elem);
    } else {
        return BST_Insert(t->rchild, elem);
    }
}


template<typename T>
TNode<T> *Tree<T>::Creat_BST(T data[], int n) {
    TNode<T> *t = nullptr;
    int i = 0;
    for (i = 0; i < n; i++) {
        BST_Insert(t, data[i]);
    }
    return t;
}

template<typename T>
TNode<T> *Tree<T>::BST_Search(T key) {
    TNode<T> *t = this->root->lchild;
    while (t != nullptr && key != t->data) {
        if (key > t->data) t = t->rchild;
        else t = t->lchild;
    }
    return t;
}

template<typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Invert(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        Swap(arr[i], arr[n - i - 1]);
    }
}

template<typename T>
void Invert(T arr[], int str, int fin) {
    int mid = (fin - str + 1) / 2;
    for (int i = 0; i < mid; i++) {
        Swap(arr[str + i], arr[fin - i]);
    }
}

template<typename T>
void bubble_sort(T arr[], int str, int fin) {
    for (int i = str; i < fin; i++) {
        for (int j = str; j < fin + str - i; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * 冒泡排序：
 * 1.平均时间复杂度O(n^2) 最好O(n) 最坏O(n^2)
 * 2.空间复杂度O(1)
 * 3.In-place
 * 4.稳定
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void bubble_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * 选择排序：
 * 1.平均时间复杂度O(n^2) 最好 O(n^2) 最坏O(n^2)
 * 2.空间复杂度O(1)
 * 3.In-place
 * 4.不稳定
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void select_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        Swap(arr[i], arr[min]);
    }
}

/**
 * 插入排序：
 * 1.平均时间复杂度O(n^2) 最好O(n) 最坏O(n^2)
 * 2.空间复杂度O(1)
 * 3.In-place
 * 4.稳定
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void insertion_sort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * 希尔排序：
 * 1.时间复杂度O(n^1.3-2)
 * 2.空间复杂度O(1)
 * 3.In-place
 * 4.buwend
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void shell_sort(T arr[], int n) {
    int h = 1;
    while (h < n / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && arr[j - h] > arr[j]; j -= h) {
                Swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

template<typename T>
void merge(T arr[], int left, int mid, int right) {//并
    T b[right - left + 1];
    int i = left, j = mid + 1, k = i, t;
    while (i <= mid && j <= right) {
        if (arr[j] > arr[i]) {
            b[k - left] = arr[i];
            i++;
            k++;
        } else {
            b[k - left] = arr[j];
            j++;
            k++;
        }
    }
    if (i <= mid) {
        for (t = i; t <= mid; t++) {
            b[k - left] = arr[t];
            k++;
        }
    } else {
        for (t = j; t <= right; t++) {
            b[k - left] = arr[t];
            k++;
        }
    }
    for (i = left; i <= right; i++) {
        arr[i] = b[i - left];
    }
}

/**
 * 归并排序：
 * 1.平均时间复杂度O(nlog(n)) 最好O(nlog(n)) 最坏O(nlog(n))
 * 2.空间复杂度O(n)
 * 3.Out-place
 * 4.稳定
 * @tparam T
 * @param arr
 * @param from
 * @param to
 */
template<typename T>
void merge_sort(T arr[], int from, int to) {//归
    if (from < to) {
        int mid = (from + to) / 2;
        merge_sort(arr, from, mid);
        merge_sort(arr, mid + 1, to);
        merge(arr, from, mid, to);
    }
}

/**
 * 快速排序：
 * 1.平均时间复杂度O(nlog(n)) 最好O(nlog(n)) 最坏O(n^2)
 * 2.空间复杂度O(log(n))
 * 3.In-place
 * 4.不稳定
 * @tparam T
 * @param arr
 * @param str
 * @param fin
 */
template<typename T>
void quick_sort(T arr[], int str, int fin) {
    int i = str, j = fin;
    T temp;
    if (i < j) {
        temp = arr[i];//选取第一个为中轴
        while (i < j) {
            while (i < j && arr[j] >= temp) j--;
            arr[i] = arr[j];
            while (i < j && temp >= arr[i]) i++;
            arr[j] = arr[i];
        }
        arr[i] = temp;
        quick_sort(arr, str, i - 1);
        quick_sort(arr, i + 1, fin);
    }
}

template<typename T>
void max_heapify(T arr[], int str, int fin) {//大根堆
    int dad = str;
    int son = dad * 2 + 1;
    while (son <= fin) {//子节点在范围内
        if (son + 1 <= fin && arr[son + 1] > arr[son]) {//先比较两个子节点大小，选择大的
            son++;
        }
        if (arr[dad] > arr[son]) {//如果父节点大于子节点代表调整完毕
            return;
        } else {//否则交换父子内容再继续子节点和父节点比较
            Swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

/**
 * 堆排序：
 * 1.平均时间复杂度O(nlog(n)) 最好O(nlog(n)) 最坏O(nlog(n))
 * 2.空间复杂度O(1)
 * 3.In-place
 * 4.不稳定
 * @tparam T
 * @param arr
 * @param len
 */
template<typename T>
void head_sort(T arr, int len) {
    int i;
    //初始化，i从最后一个父节点开始调整
    for (i = len / 2 - 1; i >= 0; i--) {
        max_heapify(arr, i, len - 1);
    }
    //先将第一个元素和已排好元素前一位交换，再重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--) {
        Swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

template<typename T>
T Max(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

template<typename T>
T Min(T arr[], int n) {
    T min = arr[0];
    for (int i = 1; i < n; i++) {
        if (min > arr[i]) min = arr[i];
    }
    return min;
}

/**
 * 计数排序：(只能用于非负整数的排序)
 * 1.平均时间复杂度O(n+k) 最好O(n+k) 最坏O(n+k)
 * 2.空间复杂度O(k)
 * 3.Out-place
 * 4.稳定
 * @param arr 要排序的数组
 * @param re 排序好的数组
 * @param n
 */
void count_sort(int arr[], int re[], int n) {
    int max = Max(arr, n);
    int min = Min(arr, n);
    int count_len = max - min + 1;
    int *count = new int[count_len];
    for (int i = 0; i < count_len; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    for (int i = 1; i < count_len; i++) {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < n; i++) {
        re[--count[arr[i] - min]] = arr[i];
    }
    free(count);
}

int maxbit(int arr[], int n) {
    int max = Max(arr, n);
    int d = 0;
    while (max != 0) {
        max /= 10;
        d++;
    }
    return d;
}

/**
 * 基数排序：
 * 1.平均时间复杂度O(d(n+r)) 最好O(d(n+r)) 最坏O(d(n+r))
 * 2.空间复杂度 O(r)
 * 3.Out-place
 * 4.稳定
 * @param arr
 * @param n
 */
void base_sort(int arr[], int n) {
    int d = maxbit(arr, n);
    int *temp = new int[n];
    int *count = new int[10];//计数器
    int i, j, k, radix = 1;
    for (i = 1; i <= d; i++) {//进行d次排序
        for (j = 0; j < 10; j++) {//清空计数器
            count[j] = 0;
        }
        for (j = 0; j < n; j++) {//每位进行排序时采用计数排序
            k = (arr[j] / radix) % 10;
            count[k]++;
        }
        for (j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        for (j = n - 1; j >= 0; j--) {
            k = (arr[j] / radix) % 10;
            temp[--count[k]] = arr[j];
        }
        for (j = 0; j < n; j++) {//将临时数组的内容复制回arr中
            arr[j] = temp[j];
        }
        radix *= 10;
    }
    free(temp);
    free(count);
}

/**
 * 折半查找
 * @tparam T
 * @param L
 * @param key
 * @return
 */
template<typename T>
int Binary_Search(SqList<T> L, T key) {
    int low = 0, high = L.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == key) return mid;
        else if (L.data[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;//查找失败
}

#endif //UTILS_UTILS_H
