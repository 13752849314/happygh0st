//
// Created by 37157 on 2021/5/4.
//

#ifndef LINKLIST_STR_H
#define LINKLIST_STR_H
#define Maxsize 255

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Str {
public:
    T ch[Maxsize]{};
    int length = 0;//��ǰ���ĳ���

    Str() = default;

    virtual ~Str() = default;

    Str(T *A, int n);//���εĹ��췽��

    T operator[](int idx);//����[]�����
    void operator=(const Str<T> &D);//����=
    bool operator==(const Str<T> &D);//����==

    void append(T x);//�ڴ���ĩβ׷��Ԫ��x
    void append(Str<T> &S);//�ڴ���ĩβ׷�Ӵ�S
    T at(int i);//��ȡ��i��Ԫ��
    Str<T> SubString(int post, int len);//����Ӵ�����post��ʼ����Ϊlen
    int Index(Str<T> &D);//ƥ��ģʽ��D�������е�λ��(�������)
    int KMP(Str<T> &D);//ƥ��ģʽ��D�������е�λ��
};

template<typename T>
Str<T>::Str(T *A, int n) {
    length = n;
    for (int i = 0; i < n; i++) {
        ch[i] = A[i];
    }
}

template<typename T>
void Str<T>::append(T x) {
    if (length != Maxsize) {
        ch[length++] = x;
    } else {
        cout << "The String is full!" << endl;
    }
}

template<typename T>
void Str<T>::append(Str<T> &S) {
    for (int i = 0; i < S.length; i++) {
        append(S[i]);
    }
}

template<typename T>
T Str<T>::at(int i) {
    T re = 0;
    if (i > 0 && i <= Maxsize) {
        return ch[i - 1];
    } else {
        cout << "The input parameter is invalid!" << endl;
        return re;
    }
}

template<typename T>
Str<T> Str<T>::SubString(int post, int len) {
    Str<T> re = Str<T>();
    if (post + len > length + 1) {
        cout << "The input parameter is invalid!" << endl;
    } else {
        for (int i = post; i < post + len; i++) {
            re.append(at(i));
        }
    }
    return re;
}

template<typename T>
T Str<T>::operator[](int idx) {
    if (idx >= 1 && idx <= Maxsize) {
        return ch[idx - 1];
    } else {
        T t = 0;
        return t;
    }
}

template<typename T>
void Str<T>::operator=(const Str<T> &D) {
    length = D.length;
    ch = D.ch;
}

template<typename T>
bool Str<T>::operator==(const Str<T> &D) {
    if (length != D.length) {
        return false;
    } else {
        for (int i = 0; i < length; i++) {
            if (ch[i] != D.ch[i]) {
                return false;
            }
        }
        return true;
    }
}

/**
 * ����ƥ��(������)
 * ʱ�临�Ӷ�(nm),nΪ�����ĳ���,mΪģʽ���ĳ���
 * @tparam T ����Ԫ�ص�����
 * @param D ģʽ��
 * @return ģʽ����һ���������г��ֵ�λ��
 */
template<typename T>
int Str<T>::Index(Str<T> &D) {
    int i = 1, j = 1;
    while (i <= length && j <= D.length) {
        if (ch[i - 1] == D.ch[j - 1]) {
            i++;
            j++;
        } else {
            i = i - j + 2;//���������һλ
            j = 1;//ģʽ����ͷ��ʼ
        }
    }
    if (j > D.length) return i - D.length;
    else return 0;
}

/**
 * KMP ƥ���㷨
 * ��һ��������ƥ���
 * �ڶ���������ƥ��
 * ʱ�临�Ӷ� O(n+m)
 * @tparam T ����Ԫ�ص�����
 * @param D ģʽ��
 * @return ģʽ����һ���������г��ֵ�λ��
 */
template<typename T>
int Str<T>::KMP(Str<T> &D) {
    //��һ������ģʽ������ƥ���
    int *pm = new int[D.length];
    pm[0] = 0;//��һλ��ƥ��ֵһ��Ϊ0
    for (int i = 2; i <= D.length; i++) {
        Str<T> sub = D.SubString(1, i);
        int p = 0;
        for (int j = 1; j < i; j++) {
            if (sub.SubString(1, j) == sub.SubString(i - j + 1, j)) {//ǰ��׺�Ƚ�
                p = j;
            }
        }
        pm[i - 1] = p;
    }
    //�ڶ���������ƥ��
    int i = 0, j = 0, total = 0;//total ��¼�ƶ�����Ŀ
    while (i < length && j < D.length) {
        if (ch[i] == D.ch[j]) {
            i++;
            j++;
        } else {
            if (j == 0) {//��һλ�Ͳ�ƥ��
                i++;//��������һλ
                total++;
            } else {
                int move = j - pm[j - 1];//�����ƶ���
                i = total + move;
                total += move;
                j = 0;
            }
        }
    }
    if (j == D.length) return i - j + 1;//����ƥ�䴮
    else return 0;
}


#endif //LINKLIST_STR_H
