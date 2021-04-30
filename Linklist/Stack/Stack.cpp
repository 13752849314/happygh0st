//
// Created by 37157 on 2021/4/27.
//

#include <cstdio>
#include <cstdlib>
#include "Stack.h"

/**
 * 初始化顺序栈
 * @param S
 */
void InitStack(SqStack &S) {
    S.top = -1;
}

/**
 * 判断栈是否为空
 * @param S
 * @return
 */
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

/**
 * 进栈
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, ElemType x) {
    if (S.top == Maxsize - 1) return false;//栈满
    S.data[++S.top] = x;//指针先加1，再入栈
    return true;
}

/**
 * 出栈
 * @param S
 * @param x 接收出栈元素
 * @return
 */
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//栈空
    x = S.data[S.top--];//先出栈，指针再减1
    return true;
}

/**
 * 获取栈顶元素
 * @param S
 * @param x 接收栈顶元素
 * @return
 */
bool GetTop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//栈空
    x = S.data[S.top];
    return true;
}

/**
 * 按出栈顺序打印
 * @param S
 */
void print_Pop(SqStack &S) {
    int i = S.top;
    if (i == -1) {
        printf("Stack Empty!\n");
    }
    while (i >= 0) {
        printf("%d ", S.data[i]);
        i--;
    }
    putchar('\n');
}

/**
 * 初始化链栈
 * @param S
 */
LinkStack *InitLinkStack(LinkStack *S) {
    S = (LiStack) malloc(sizeof(Linknode));
    S->next = nullptr;
    return S;
}

/**
 * 判断链栈是否为空
 * @param S
 * @return
 */
bool LinkStackEmpty(LiStack S) {
    return S->next == nullptr;
}

/**
 * 入栈
 * @param S
 * @param x
 * @return
 */
bool LinkPush(LiStack S, ElemType x) {
    auto s = (LiStack) malloc(sizeof(LinkStack));
    s->data = x;
    s->next = S->next;
    S->next = s;
    return true;
}

/**
 * 出栈
 * @param S
 * @return
 */
LiStack LinkPop(LiStack S) {
    LiStack p = S->next;
    S->next = p->next;
    return p;
}

/**
 * 获取栈顶元素
 * @param S
 * @return
 */
LiStack LinkGetTop(LiStack S) {
    return S->next;
}

void print_LinkPop(LiStack S) {
    LiStack p = S->next;
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

bool is_legal(const char *A, int k) {
    int i = 0;
    int *a = new int[Maxsize];
    for (i = 0; i < k; i++) {
        if (A[i] == 'I') a[i] = 1;
        if (A[i] == 'O') a[i] = -1;
    }
    //printf("n=%d\n", n);
    int sum = 0;
    for (int j = 0; j < k; j++) {
        //printf("%d\n", a[j]);
        sum += a[j];
        if (sum < 0) return false;
    }
    return true;
    /**
     * 对于一个空栈，判断出入栈序列是否合法
     * I表示入栈，O表示出栈
     * 算法思想：
     * 1.将I表示为1，O表示为-1
     * 2.从左向右依次相加，如果和不小于0，则合法，否则不合法
     * 时间复杂度  O(n)
     * 空间复杂度  O(n)
     */
}

bool is_symmetry(Linklist L, int n) {
    SqStack S;
    InitStack(S);//初始化栈
    Linklist p = L->next;
    int temp = n / 2;
    while (temp--) {
        Push(S, p->data);//前一半入栈
        p = p->next;
    }
    print_Pop(S);
    if (n % 2 == 1) p = p->next;//如果n是奇数，后移一位
    int e;
    while (p != nullptr) {
        Pop(S, e);//出栈
        if (e != p->data) {
            return false;
        }
        p = p->next;
    }
    return true;
    /**
     * 判断链表L是否中心对称
     * 算法思想：
     * 1.将链表前一半入栈
     * 2.依次出栈与后半部分一一比较，如果全相等，则中心对称
     * 时间复杂度  O(n)
     * 空间复杂度  O(n)
     */
}

void InitShareStack(ShareStack &S) {
    S.top[0] = -1;
    S.top[1] = Maxsize;
}

bool ShareStackEmpty(ShareStack S) {
    return S.top[0] + 1 == S.top[1];
}

/**
 * 共享栈入栈操作
 * @param S
 * @param i 栈号 0：表示s1栈 1：表示s2栈
 * @param x 入栈元素
 * @return
 */
bool SPush(ShareStack &S, int i, ElemType x) {
    if (i < 0 || i > 1) {
        printf("The ShareStack number false!\n");
        return false;
    }
    if (S.top[0] + 1 == S.top[1]) {
        printf("ShareStack is full!\n");
        return false;
    }
    switch (i) {
        case 0: {
            S.data[++S.top[0]] = x;
            return true;
        }
        case 1: {
            S.data[--S.top[1]] = x;
            return true;
        }
        default:
            return false;
    }
}

/**
 * 共享栈出栈操作
 * @param S
 * @param i 栈号
 * @param x 用x接收出栈元素
 * @return
 */
bool SPop(ShareStack &S, int i, ElemType &x) {
    if (i < 0 || i > 1) {
        printf("The ShareStack number false!\n");
        return false;
    }
    switch (i){
        case 0:{
            if(S.top[0]==-1){
                printf("Stack Empty!\n");
                return false;
            }else{
                x=S.data[S.top[0]--];
                return true;
            }
        }
        case 1:{
            if(S.top[1]==Maxsize){
                printf("Stack Empty!\n");
                return false;
            }else{
                x=S.data[S.top[1]++];
                return true;
            }
        }
        default:
            return false;
    }
}

bool StackOverflow(SqStack S) {
    return S.top==Maxsize-1;
}


