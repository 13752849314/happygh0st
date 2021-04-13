#include<iostream>
#include <ctime>
#define N 10000
#define M 100000

int min(int a,int b){
    return a>b?b:a;
}
double cache(int s){
    int A[N],B[N];
    for(int i=0;i<N;i++){
        A[i]=i;
        B[i]=i;
    }
    clock_t fin,str;
    str=clock();
    for(int j=0;j<N;j+=s){
        for(int i=0;i<N;i++){
            for(int jj=j;jj<min(j+s,N);jj++){
                A[i]+=B[jj];
            }
        }
    }
    fin=clock();
//    for(int i=0;i<N;i++){
//        printf("%d\n",A[i]);
//    }
    return (double)(fin-str)/CLOCKS_PER_SEC;
}
double Zhankai(int k){
    int A[M];
    for(int i=0;i<M;i++){
        A[i]=i;
    }
    clock_t str,fin;
    int d=0;
    str=clock();
    for(int i=0;i<M%k;i++){
        d+=A[i];
    }
    for(int i=(M%k);i<M;i+=k){
        for(int j=0;j<k;j++){
            d+=A[i+j];
        }
    }
    fin=clock();
    //printf("%d\n",d);
    return (double)(fin-str)/CLOCKS_PER_SEC;
}
int main(){
    int a=0;
    clock_t str,fin;
    str=clock();
    for(int i=0;i<100000000;i++){
        for(int j=0;j<5;j++){
            a++;
        }
    }
    fin=clock();
    printf("外循环大：time=%fs\n",(double)(fin-str)/CLOCKS_PER_SEC);
    str=clock();
    for(int i=0;i<5;i++){
        for(int j=0;j<100000000;j++){
            a++;
        }
    }
    fin=clock();
    printf("内循环大：time=%fs\n",(double)(fin-str)/CLOCKS_PER_SEC);

    int A[N],B[N];
    for(int i=0;i<N;i++){
        A[i]=i;
        B[i]=i;
    }
    str=clock();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i]+=B[j];
        }
    }
    fin=clock();
    printf("不优化：time=%fs\n",(double)(fin-str)/CLOCKS_PER_SEC);
//    for(int i=0;i<N;i++){
//        printf("%d\n",A[i]);
//    }
    double t_min=cache(2);
    int t=2;
    for(int s=3;s<=500;s++){
        double New=cache(s);
        if (t_min>New){
            t_min=New;
            t=s;
        }
    }
    printf("优化：time=%fs  此时s=%d\n",t_min,t);

    int d=0;
    int AA[M];
    for(int i=0;i<M;i++){
        AA[i]=i;
    }
    str=clock();
    for(int i=0;i<M;i++){
        d+=AA[i];
    }
    fin=clock();
    printf("不展开：time=%fs\n",(double)(fin-str)/CLOCKS_PER_SEC);
    //printf("%d\n",d);
    double tt=Zhankai(1);
    int TT=1;
    for(int i=2;i<=500;i++){
        double flag=Zhankai(i);
        //printf("%f\n",flag);
        if(flag<tt){
            tt=flag;
            TT=i;
        }
    }
    printf("展开：time=%fs  此时s=%d\n",tt,TT);
    return 0;
}