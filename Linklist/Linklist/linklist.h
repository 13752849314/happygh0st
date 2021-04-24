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
    explicit linklist(Linklist L);
    linklist(const ElemType A[], int n);//β�巨����������
    void print_Linklist();//��ӡ����
    Linklist get_by_i(int i);//��ȡ��i�����
    void insert_i(int i, ElemType e);//�ڵ�i��λ�ò���e
    void delete_i(int i, ElemType &e);//ɾ����i�����
    void update_length();//���³���
    void invert();//�������� p38 5
    void delete_all_x(ElemType x);//ɾ�����е�x  p38 2
    static void reverse_print(Linklist head);//�����ӡ���� p38 3
    void delete_only_min();//ɾ����Сֵ��㣨Ψһ�� p38 4
    void sort_Linklist();//�������� p38 6
    void delete_a_to_b(ElemType a, ElemType b);//ɾ��a��b֮��Ľ�� p38 7
    void print_up();//�������ӡ�������ͷſռ� p38 9
    Linklist divide_by_odd_even();//��������ԭ����������λ��Ԫ�أ�����B����ż��λ p38 10
    Linklist divide_by_odd_even2();//��������ԭ����������λ��Ԫ�أ�����B����ż��λ����ת p38 11
    void delete_same();//ɾ��L���ظ���Ԫ�أ�L���� p38 12
    void add_to_L(Linklist A);//L��A��������A��L�ϲ��ɵݼ��ĵ����� p38 13
    Linklist Union(linklist &a);//a.L��L���������ؽ��� p38 14/15
    int is_substr(linklist &a);//�ж�a.L�Ƿ�ΪL������������ p38 16
    int Search_end_k(int k);//Ѱ����������k����� p39 21
    void delete_abs_same(int n);//ɾ������ֵ��ͬ��Ԫ�ؽ�㣬������һ�γ��ֵ�,����Ҫ��abs(data)<=n
    Linklist have_loop();//�ж�L�Ƿ��л� p39 24
    virtual ~linklist();
};
void print_Linklist(Linklist L);//��ӡ����
void quick_sort(ElemType A[], int str, int fin);// ��������
Linklist find_common_Node(linklist &A, linklist &B);//��ȡA��B�Ĺ������ p38 8
#endif //LINKLIST_LINKLIST_H
