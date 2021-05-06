//
// Created by 37157 on 2021/5/4.
//

#include <iostream>
#include "String/Str.h"

using namespace std;
int temp = 0;

void divide() {
    cout << "==========" << temp << "==========" << endl;
    temp++;
}

int main() {
    char A[] = {'2', 'r', 'c', 't'};
    int na = sizeof(A) / sizeof(A[0]);
    Str<char> str(A, na);
    str.append('c');
    double B[] = {1.2, 2.3, 3.4, 4.5, 5.6, 2.3, 3.4, 4.5};
    int nb = sizeof(B) / sizeof(B[0]);
    Str<double> str1(B, nb);
    Str<double> sub = str1.SubString(1, 1);
    cout << str1.Index(sub) << endl;
    divide();

    char M[] = {'a', 'b', 'a', 'b', 'c', 'a', 'b', 'c', 'a', 'c', 'b', 'a', 'b'};
    int L = sizeof(M) / sizeof(M[0]);
    Str<char> Msc(M, L);
    char P[] = {'c','a', 'b', 'c', 'a', 'c'};
    int pl = sizeof(P) / sizeof(P[0]);
    Str<char> Ppc(P, pl);
    cout<<Msc.Index(Ppc)<<endl;
    cout<<Msc.KMP(Ppc)<<endl;
    return 0;
}
