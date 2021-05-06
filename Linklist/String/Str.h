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
    int length = 0;//当前串的长度

    Str() = default;

    virtual ~Str() = default;

    Str(T *A, int n);//带参的构造方法

    T operator[](int idx);//重载[]运算符
    void operator=(const Str<T> &D);//重载=
    bool operator==(const Str<T> &D);//重载==

    void append(T x);//在串的末尾追加元素x
    void append(Str<T> &S);//在串的末尾追加串S
    T at(int i);//获取第i个元素
    Str<T> SubString(int post, int len);//获得子串，从post开始长度为len
    int Index(Str<T> &D);//匹配模式串D在主串中的位置(暴力求解)
    int KMP(Str<T> &D);//匹配模式串D在主串中的位置
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
 * 串的匹配(暴力法)
 * 时间复杂度(nm),n为主串的长度,m为模式串的长度
 * @tparam T 串中元素的类型
 * @param D 模式串
 * @return 模式串第一次在主串中出现的位置
 */
template<typename T>
int Str<T>::Index(Str<T> &D) {
    int i = 1, j = 1;
    while (i <= length && j <= D.length) {
        if (ch[i - 1] == D.ch[j - 1]) {
            i++;
            j++;
        } else {
            i = i - j + 2;//主串向后移一位
            j = 1;//模式串从头开始
        }
    }
    if (j > D.length) return i - D.length;
    else return 0;
}

/**
 * KMP 匹配算法
 * 第一步：生成匹配表
 * 第二步：进行匹配
 * 时间复杂度 O(n+m)
 * @tparam T 串中元素的类型
 * @param D 模式串
 * @return 模式串第一次在主串中出现的位置
 */
template<typename T>
int Str<T>::KMP(Str<T> &D) {
    //第一步：由模式串生成匹配表
    int *pm = new int[D.length];
    pm[0] = 0;//第一位的匹配值一定为0
    for (int i = 2; i <= D.length; i++) {
        Str<T> sub = D.SubString(1, i);
        int p = 0;
        for (int j = 1; j < i; j++) {
            if (sub.SubString(1, j) == sub.SubString(i - j + 1, j)) {//前后缀比较
                p = j;
            }
        }
        pm[i - 1] = p;
    }
    //第二步：进行匹配
    int i = 0, j = 0, total = 0;//total 记录移动的数目
    while (i < length && j < D.length) {
        if (ch[i] == D.ch[j]) {
            i++;
            j++;
        } else {
            if (j == 0) {//第一位就不匹配
                i++;//主串后移一位
                total++;
            } else {
                int move = j - pm[j - 1];//计算移动量
                i = total + move;
                total += move;
                j = 0;
            }
        }
    }
    if (j == D.length) return i - j + 1;//存在匹配串
    else return 0;
}


#endif //LINKLIST_STR_H
