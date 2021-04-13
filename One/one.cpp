//
// Created by 37157 on 2021/3/12.
//
#include <iostream>
#include <ctime>
int main(){
    int a[128][40960],b[128][40960];
    clock_t str,fin;
    str=clock();
    for(int i=0;i<128;i++)
    {
        for(int j=0;j<40960;j++)
        {
            b[i][j]=1;
            a[i][j]=b[i][j];
        }
    }
    fin=clock();
    printf("t=%f\n",(double)(fin-str)/CLOCKS_PER_SEC);
    str=clock();
    for(int i=0;i<40960;i++)
    {
        for(int j=0;j<128;j++)
        {
            b[j][i]=1;
            a[j][i]=b[j][i];
        }
    }
    fin=clock();
    printf("t=%f\n",(double)(fin-str)/CLOCKS_PER_SEC);
    return 0;
}
