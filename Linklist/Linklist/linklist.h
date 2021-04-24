//
// Created by 37157 on 2021/4/13.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H
typedef int ElemType;
/**
 * 单链表
 */
typedef struct LNode {
    ElemType data; //数据域
    struct LNode *next; //指针域
} LNode, *Linklist;

class linklist {
public:
    int length{};
    Linklist L = (Linklist) malloc(sizeof(LNode));

    linklist();
    explicit linklist(Linklist L);
    linklist(const ElemType A[], int n);//尾插法创建单链表
    void print_Linklist();//打印链表
    Linklist get_by_i(int i);//获取第i个结点
    void insert_i(int i, ElemType e);//在第i个位置插入e
    void delete_i(int i, ElemType &e);//删除第i个结点
    void update_length();//更新长度
    void invert();//倒置链表 p38 5
    void delete_all_x(ElemType x);//删除所有的x  p38 2
    static void reverse_print(Linklist head);//反向打印链表 p38 3
    void delete_only_min();//删除最小值结点（唯一） p38 4
    void sort_Linklist();//排序（升序） p38 6
    void delete_a_to_b(ElemType a, ElemType b);//删除a，b之间的结点 p38 7
    void print_up();//按升序打印链表，并释放空间 p38 9
    Linklist divide_by_odd_even();//将链表保留原来处于奇数位的元素，返回B保存偶数位 p38 10
    Linklist divide_by_odd_even2();//将链表保留原来处于奇数位的元素，返回B保存偶数位并翻转 p38 11
    void delete_same();//删除L中重复的元素，L递增 p38 12
    void add_to_L(Linklist A);//L和A递增，将A和L合并成递减的单链表 p38 13
    Linklist Union(linklist &a);//a.L和L递增，返回交集 p38 14/15
    int is_substr(linklist &a);//判断a.L是否为L的连续子序列 p38 16
    int Search_end_k(int k);//寻找链表倒数第k个结点 p39 21
    void delete_abs_same(int n);//删除绝对值相同的元素结点，保留第一次出现的,链表要求abs(data)<=n
    Linklist have_loop();//判断L是否有环 p39 24
    virtual ~linklist();
};
void print_Linklist(Linklist L);//打印链表
void quick_sort(ElemType A[], int str, int fin);// 快速排序
Linklist find_common_Node(linklist &A, linklist &B);//获取A，B的公共结点 p38 8
#endif //LINKLIST_LINKLIST_H
