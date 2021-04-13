#include <iostream>
#define n 10
#include <ctime>
int main() {
    int i,j,k,A[n][n],B[n][n],C[n][n];
    time_t str,fin;
    double T;
    for (i = 0; i < n; i++) {
        for(j=0;j<n;j++){
            A[i][j]=1;
            B[i][j]=1;
            C[i][j]=0;
        }
    }
    str=clock();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                C[i][j]+=A[i][k]*B[k][i];
            }
        }
    }
    fin=clock();
    for (i = 0; i < n; i++) {
        for(j=0;j<n;j++){
            printf("%d\t",C[i][j]);
        }
        putchar('\n');
    }
    T=(double)(fin-str)/CLOCKS_PER_SEC;
    printf("%fs",T);
    return 0;
}
