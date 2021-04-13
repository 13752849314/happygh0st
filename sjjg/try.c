#include <stdio.h>
#define N 100
int main(){
    int m,k,A[N],B[N],j;
    scanf("%d %d",&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d",&A[i]);
    }
    getchar();
    for(int i=0;i<m;i++){
        scanf("%d",&B[i]);
    }
//    for(int i=0;i<m;i++){
//        printf("%d__%d\n",A[i],B[i]);
//    }
    int max=0;
    for(int i=0;i<m-k+1;i++){
        int temp=0;
        for(int p=0;p<i;p++){
            if(B[p]==1){
                temp+=A[p];
            }
        }
        for(j=i;j<i+k;j++){
            temp+=A[j];
        }
        for(int q=j;q<m;q++){
            if(B[q]==1){
                temp+=A[q];
            }
        }
        if(temp>max) max=temp;
    }
    printf("%d",max);
    return 0;
}