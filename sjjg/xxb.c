#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100 //定义线性表最大长度
typedef int ElemType;

typedef struct myList {
    ElemType data[N];
    int length;
} sqlist;


int initSqlist(sqlist *L)//初始化
{
    L->length = 0;
    return 1;
}

int Sqinsert(sqlist *L, int i, ElemType e)//在第i个位置插入元素
{
    if (i < 1 || i > N) {
        return 0;
    }
    if (L->length >= N) return 0;
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];//后移
    }
    L->data[i - 1] = e;
    L->length++;
    return 1;
}

int Sqdelete(sqlist *L, int i, ElemType *e)//删除第i个位置的元素，并用e返回
{
    if (i < 0 || i > L->length) return 0;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return 1;
}

void disp(sqlist *L)//打印线性表
{
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    putchar('\n');
}

int one(sqlist *L)//删除最小元素（唯一），空出来的位置由最后一个元素填补
{
    if (L->length <= 0) {
        printf("顺序表为空！\n");
        return 0;
    }
    int re = L->data[0];
    int flag = 0;
    for (int i = 1; i < L->length; i++) {
        if (re > L->data[i]) {
            re = L->data[i];
            flag = i;
        }
    }
    L->data[flag] = L->data[L->length - 1];
    L->length--;
    return 1;
}

void two(sqlist *L)//倒置顺序表L的所有元素
{
    ElemType flag;
    for (int i = 0; i < L->length / 2; i++) {
        flag = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = flag;
    }
}

void three(sqlist *L, ElemType x)//删除L中等于x的元素
{
    int k = 0;//记录不等于x元素的个数
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

int four(sqlist *L, ElemType s, ElemType t)//删除x（s<x<t）
{
    if (L->length == 0 || s >= t) {
        printf("顺序表为空或s，t输入不合法！\n");
        return 0;
    }
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] <= s || L->data[i] >= t) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
    return 0;
}

int four_1(sqlist *L, ElemType s, ElemType t)//删除x（s<x<t）--在有序顺序表中
{
    if (L->length == 0 || s >= t) return 0;
    int i, j;
    for (i = 0; i < L->length && L->data[i] < s; i++);//寻找值大于等于s的第一个元素
    if (i >= L->length) return 0;
    for (j = i; j < L->length && L->data[j] <= t; j++);//寻找值大于t的第一个元素
    for (; j < L->length; i++, j++) {
        L->data[i] = L->data[j];//前移，填补被删除元素位置
    }
    L->length = i;
    return 1;
}

int Sq_Del_Same(sqlist *L)//删除重复元素--有序顺序表
{
    if (L->length == 0) return 0;
    int i, j;
    for (i = 0, j = 1; j < L->length; j++) {
        if (L->data[i] != L->data[j]) {
            L->data[++i] = L->data[j];//前移
        }
    }
    L->length = i + 1;
    return 1;
}

typedef struct Hash {
    ElemType key;
    int flag;
    struct Hash *next;
} hash;

int Sq_Del_Same1(sqlist *L)//删除重复元素--无序顺序表
{   /*要求线性时间*/
    if (L->length == 0) return 0;
    hash key[N];
    int w = 0;//记录不重复元素个数
    int remember[N];
    for (int i = 0; i < L->length; i++) {
        int g = L->data[i] % N;
        if (key[g].key != L->data[i]) {
            key[g].key = L->data[i];
            key[g].flag = i;
            key[g].next = NULL;
            remember[w] = g;
            w++;
        }
    }
    //printf("%d\n",w);
    for (int i = 0; i < w; i++) {
        L->data[i] = key[remember[i]].key;
    }
    L->length = w;
    return 1;
}

void sort(sqlist *L, int temp)//排序，i=0升序,i=1降序
{
    ElemType flag;
    for (int i = 0; i < L->length - 1; i++) {//冒泡排序
        for (int j = i + 1; j < L->length; j++) {
            if (L->data[i] > L->data[j]) {
                flag = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = flag;
            }
        }
    }
    if (temp == 1) two(L);
}

sqlist merge_list(sqlist A, sqlist B) {//合并A，B两个线性表
    int i;
    sqlist re;
    initSqlist(&re);
    if (A.length + B.length <= N) {
        re.length = A.length + B.length;
        for (i = 0; i < A.length; i++) {
            re.data[i] = A.data[i];
        }
        for (int j = i; j < i + B.length; j++) {
            re.data[j] = B.data[j - i];
        }
    }
    return re;
}

int main() {
    sqlist p, q;
    ElemType a[6] = {1, 2, 1, 3, 4, 3}, e;
    initSqlist(&p);
    for (int i = 0; i < 6; i++) {
        Sqinsert(&p, i + 1, a[i]);
    }
    disp(&p);
    //Sqdelete(&p,5,&e);
    //two(&p);
    //three(&p,4);
    //four_1(&p,5,78);
    //Sq_Del_Same1(&p);
    //sort(&p,1);
    //q=merge_list(p,p);
    //disp(&q);
    disp(&p);
    return 0;
}
