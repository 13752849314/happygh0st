//
// Created by 37157 on 2021/4/27.
//

#include <cstdio>
#include <cstdlib>
#include "Stack.h"

/**
 * ��ʼ��˳��ջ
 * @param S
 */
void InitStack(SqStack &S) {
    S.top = -1;
}

/**
 * �ж�ջ�Ƿ�Ϊ��
 * @param S
 * @return
 */
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

/**
 * ��ջ
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, ElemType x) {
    if (S.top == Maxsize - 1) return false;//ջ��
    S.data[++S.top] = x;//ָ���ȼ�1������ջ
    return true;
}

/**
 * ��ջ
 * @param S
 * @param x ���ճ�ջԪ��
 * @return
 */
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//ջ��
    x = S.data[S.top--];//�ȳ�ջ��ָ���ټ�1
    return true;
}

/**
 * ��ȡջ��Ԫ��
 * @param S
 * @param x ����ջ��Ԫ��
 * @return
 */
bool GetTop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;//ջ��
    x = S.data[S.top];
    return true;
}

/**
 * ����ջ˳���ӡ
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
 * ��ʼ����ջ
 * @param S
 */
LinkStack *InitLinkStack(LinkStack *S) {
    S = (LiStack) malloc(sizeof(Linknode));
    S->next = nullptr;
    return S;
}

/**
 * �ж���ջ�Ƿ�Ϊ��
 * @param S
 * @return
 */
bool LinkStackEmpty(LiStack S) {
    return S->next == nullptr;
}

/**
 * ��ջ
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
 * ��ջ
 * @param S
 * @return
 */
LiStack LinkPop(LiStack S) {
    LiStack p = S->next;
    S->next = p->next;
    return p;
}

/**
 * ��ȡջ��Ԫ��
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
     * ����һ����ջ���жϳ���ջ�����Ƿ�Ϸ�
     * I��ʾ��ջ��O��ʾ��ջ
     * �㷨˼�룺
     * 1.��I��ʾΪ1��O��ʾΪ-1
     * 2.��������������ӣ�����Ͳ�С��0����Ϸ������򲻺Ϸ�
     * ʱ�临�Ӷ�  O(n)
     * �ռ临�Ӷ�  O(n)
     */
}

bool is_symmetry(Linklist L, int n) {
    SqStack S;
    InitStack(S);//��ʼ��ջ
    Linklist p = L->next;
    int temp = n / 2;
    while (temp--) {
        Push(S, p->data);//ǰһ����ջ
        p = p->next;
    }
    print_Pop(S);
    if (n % 2 == 1) p = p->next;//���n������������һλ
    int e;
    while (p != nullptr) {
        Pop(S, e);//��ջ
        if (e != p->data) {
            return false;
        }
        p = p->next;
    }
    return true;
    /**
     * �ж�����L�Ƿ����ĶԳ�
     * �㷨˼�룺
     * 1.������ǰһ����ջ
     * 2.���γ�ջ���벿��һһ�Ƚϣ����ȫ��ȣ������ĶԳ�
     * ʱ�临�Ӷ�  O(n)
     * �ռ临�Ӷ�  O(n)
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
 * ����ջ��ջ����
 * @param S
 * @param i ջ�� 0����ʾs1ջ 1����ʾs2ջ
 * @param x ��ջԪ��
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
 * ����ջ��ջ����
 * @param S
 * @param i ջ��
 * @param x ��x���ճ�ջԪ��
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


