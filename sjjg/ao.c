#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;//������
    struct LNode *next;//ָ����
} LNode;

/**
 * β�巨��������
 * @return ����L
 */
LNode *CreateListTail() {
    LNode *L;
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;//�ձ�
    LNode *s, *r = L;//r��βָ�� s���½��
    int x;
    scanf("%d", &x);
    int flag = 0;//�������
    while (x != flag) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;//���һ��Ԫ��next��ָ��NULL
    return L;
}

/**
 * ��ȡԪ��
 * @param L ����
 * @param i ��ȡ��i��Ԫ��
 * @param e ��e����
 * @return
 */
int GetElem(LNode L, int i, ElemType *e) {
    LNode *head, *p;//head��ͷָ�룬pΪ�����±�
    head = &L;
    p = head;//p�ĳ�ֵָ���1��Ԫ��
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) return -1; //��i��Ԫ�ز�����
    e = p->data;
    return 0;
}

/**
 * ����Ԫ��
 * @param L ����
 * @param i ����λ��
 * @param e ����Ԫ��
 * @return
 */
int ListInsert(LNode *L, int i, ElemType e) {
    LNode *p;//��pΪ��i-1�����
    //����Ҫ�ҵ���i-1�����
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    //����һ���½��
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;

    s->next = p->next; //s��ֱ�Ӻ��ָ��pԭ����ֱ�Ӻ��
    p->next = s; //p��ֱ�Ӻ��ָ��s

    return 0;
}
/**
 * ɾ��Ԫ��
 * @param L ����
 * @param i ɾ����iλ��Ԫ��
 * @param e ��e����
 * @return
 */
int ListDelete(LNode *L, int i, ElemType *e) {
    LNode *p, *q;//��pΪ��i-1����� q��ʾɾ��λ��
    //����Ҫ�ҵ���i-1�����
    int j = 0;
    p = L;//pΪL�Ļ���ַ
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    q = p->next;
    p->next = q->next;//p��next��ָ��p->next->next

    e = q->data;
    return 0;
}

int main() {
    LNode *L;
    L = CreateListTail();//����һ��������������0����
    ListInsert(L, 1, 100);//�ڵ�1��λ�ò���100
    ElemType e;//��ɾ����Ԫ��
    ListDelete(L, 3, e);//ɾ����3��Ԫ��
    LNode *p;
    p = L;

    printf("�����������\n");
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    return 0;
}