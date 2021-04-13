//
// Created by 37157 on 2021/4/1.
//

#ifndef REVIEW_ARRAY_H
#define REVIEW_ARRAY_H
typedef int ElemType;

void print(ElemType A[], int n); //打印数组
void Reverse(ElemType A[], int from, int to, int n); //将数组从from到to的部分倒置
void Exchange(ElemType A[], int m, int n, int size); //p17 8
void find_x(ElemType A[], ElemType x, int *n); //p17 9
void right_move(ElemType A[], int p, int n); //p17 10
int median(int A[], int B[], int n); //p17 11
int main_cell(int A[], int n); //p17 12
int disappear_int(int A[], int n); //p17 13
int minimum(int A[], int B[], int C[], int a, int b, int c); //p17 14
#endif //REVIEW_ARRAY_H
