//
// Created by 37157 on 2021/4/18.
//

#ifndef LINKLIST_LLINKLIST_H
#define LINKLIST_LLINKLIST_H

#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct LLNode {
    ElemType data;//������
    struct LLNode *next;//ָ����
} LLNode, *LLinklist;
typedef struct DNode {
    int freq = 0;// p38 20 ��
    ElemType data{};//������
    struct DNode *next{}, *prior{};//ָ����
} DNode, *DLinklist;


class llinklist {
public:
    int length{};
    LLinklist L = (LLinklist) malloc(sizeof(LLNode));

    llinklist();

    llinklist(const ElemType A[], int n);//ͨ������A������ѭ������
    int isEmpty();//�ж��Ƿ�Ϊ��
    void print_LLinklist();//��ӡ����
    void add_tail(llinklist &a);//��a.L���ӵ�L�ĺ��� p38 18
    void print_up();//�������ӡ����㣬���ͷſռ� p38 19
    virtual ~llinklist();
};

void creat_DLinklist(DLinklist L, const ElemType A[], int n);//����˫ѭ������
void print_DLinklist(DLinklist L);//��ӡ
int is_symmetry(DLinklist L);//�ж��Ƿ�Գ� p38 17
DLinklist Locate(DLinklist L, ElemType x);// p38 20
void test_Locate();//���� p38 20
void test_L_p(DLinklist L);

#endif //LINKLIST_LLINKLIST_H
