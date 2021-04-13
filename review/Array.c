//
// Created by 37157 on 2021/4/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array.h"

void sort(ElemType A[], int n) // 升序排序（冒泡）
{
    ElemType temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

void print(ElemType A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    putchar('\n');
}

void Reverse(ElemType A[], int from, int to, int n) { //将数组从from到to的部分倒置
    if (to <= from || to >= n) return;
    ElemType temp;
    for (int i = 0; i < (to - from + 1) / 2; i++) {
        temp = A[from + i];
        A[from + i] = A[to - i];
        A[to - i] = temp;
    }
}

void Exchange(ElemType A[], int m, int n, int size) {
    Reverse(A, 0, m + n - 1, size);
    Reverse(A, 0, n - 1, size);
    Reverse(A, n, m + n - 1, size);
}

void find_x(ElemType A[], ElemType x, int *n) {
    int str = 0, fin = *n - 1, mid = 0;
    while (str <= fin) {
        mid = (str + fin) / 2;
        if (A[mid] == x) break;
        else if (A[mid] < x) str = mid + 1;
        else fin = mid - 1;
    }
    if (A[mid] == x && mid != *n - 1) { //若最后一个元素与x相等，则不存在与其后继交换的操作
        ElemType temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }
    if (str > fin) { //查找失败，插入数据x
        int i;
        for (i = *n - 1; i > fin; i--) {
            A[i + 1] = A[i]; // 元素后移
        }
        A[i + 1] = x; //插入x
        *n = *n + 1; //数组长度加一
    }
}

void right_move(ElemType A[], int p, int n) //左移p位
{

    p = p % n;
    if (p <= 0)
        return;
    Reverse(A, 0, p - 1, n);
    Reverse(A, p, n - 1, n);
    Reverse(A, 0, n - 1, n);
}

int median(int A[], int B[], int n) { //A,B为升序，n表示A，B的长度。要求A，B合并之后的中位数
    int med_A = A[n / 2], med_B = B[n / 2];
    if (med_A == med_B) return med_A;
    int i = 0, j = 0, k = 0, temp;
    while (1) {
        if (A[i] > B[j]) {
            j++;
            k++;
            temp = 0;
        } else {
            i++;
            k++;
            temp = 1;
        }
        if (k == n) break;
    }
    return temp == 0 ? B[j - 1] : A[i - 1];
    // 时间复杂度O(n)
    // 空间复杂度O(1)
}

int main_cell(int A[], int n) { //寻找主元素,A中大于n/2个相同元素为主元素
    int main, i, count = 1; //main用来保存主元素，count计数
    main = A[0];
    for (i = 1; i < n; i++) {
        if (A[i] == main) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                main = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        for (i = count = 0; i < n; i++) {
            if (main == A[i]) count++;
        }
    }
    if (count > n / 2) return main;
    return -1;
}

int disappear_int(int A[], int n) {
    int i, *B;
    B = (int *) malloc(sizeof(int) * n); //分配空间
    memset(B, 0, sizeof(int) * n); //赋初值为0
    for (i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            B[A[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (B[i] == 0) break;
    }
    return i + 1;
    // 时间复杂度O(n)
    // 空间复杂度O(n)
}

int absoluteValue(int a) { //求绝对值
    return a >= 0 ? a : -a;
}

int find_min(int a, int b, int c) {
    if (a <= b && a <= c) return 1;
    return 0;
}

int minimum(int A[], int B[], int C[], int a, int b, int c) {
    int i = 0, j = 0, k = 0, D_min = 0x7fffffff, D;
    while (i < a && j < b && k < c && D_min > 0) {
        D = absoluteValue(A[i] - B[j]) + absoluteValue(B[j] - C[k]) + absoluteValue(C[k] - A[i]);
        if (D < D_min) D_min = D;
        if (find_min(A[i], B[j], C[k])) i++;
        else if (find_min(B[j], C[k], A[i])) j++;
        else k++;
    }
    return D_min;
    // 时间复杂度O(n)
    // 空间复杂度O(1)
}
