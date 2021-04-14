//
// Created by 37157 on 2021/4/13.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
typedef int ElemType;
/**
 * ������
 */
typedef struct LNode {
    ElemType data; //������
    struct LNode *next; //ָ����
} LNode, *Linklist;

class linklist {
public:
    int length{};
    Linklist L = (Linklist) malloc(sizeof(LNode));

    linklist();

    linklist(const ElemType A[], int n);//β�巨����������
    void print_Linklist();//��ӡ����
    Linklist get_by_i(int i);//��ȡ��i�����
    void insert_i(int i, ElemType e);//�ڵ�i��λ�ò���e
    void delete_i(int i, ElemType &e);//ɾ����i�����
    void invert();//�������� p38 5
    void delete_all_x(ElemType x);//ɾ�����е�x  p38 2
    static void reverse_print(Linklist head);//�����ӡ���� p38 3
    void delete_only_min();//ɾ����Сֵ��㣨Ψһ�� p38 4
    void sort_Linklist();//�������� p38 6
    virtual ~linklist();
};

void quick_sort(ElemType A[], int str, int fin);// ��������

#endif //LINKLIST_LINKLIST_H
