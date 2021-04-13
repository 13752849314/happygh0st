//
// Created by 37157 on 2021/4/3.
//

#include <stdio.h>
#include <omp.h>

int main() {
    int threadID, totalThreads, temp;
    temp=0;
#pragma omp parallel private(threadID)
    {

        threadID = omp_get_thread_num();
        printf("Hello World is from thread %d\n", threadID);
        printf("temp=%d from thread %d\n",temp,threadID);
        temp++;
        if (threadID == 0) {
            printf("Master thread being called\n");
            totalThreads = omp_get_num_threads();
            printf("Total number of threads are %d\n", totalThreads);
        }
    }
    printf("finish temp=%d\n",temp);
    return 0;
}
