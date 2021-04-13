//
// Created by 37157 on 2021/4/8.
//

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 8

void *PrintHello(void *threadid) {
    printf("%d:Hello World!\n", threadid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *) t);
        if(rc){
            printf("ERROR return code from pthread_creat():%d\n",rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
