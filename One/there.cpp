#include <iostream>
#include <omp.h>

int main(){
   int threadID,totalThreads,temp;
#pragma omp parallel private(threadID)
    {
        threadID=omp_get_thread_num();
        printf("\n Hello World is from thread %d\n",threadID);
        if(threadID==0)
        {
            printf("\n Master thread being called\n");
            totalThreads=omp_get_num_threads();
            printf("Total number of threads are %d\n",totalThreads);
        }
    }
    return 0;
}
