#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int csum;
void *runner(void *param);

int main(int argc, char *argv[]){

    int msum = 0;
    int n = atoi(argv[1]);
    printf("n : %d\n",n);
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, runner, argv[1]);

    //pthread_join(tid,NULL);
    printf("child : %d\n",csum);
    sleep(10);
    int i;
    for(i = 1; i <= n; i++){
        msum += i;
    }

    printf("parent : %d\n",msum);
    printf("answer = %d\n",abs(csum-msum));

    return 0;
}

void *runner(void *param){
    int upper = atoi(param);
    int i;
    csum = 0;

    if(upper > 0){
        for(i = 1; i<= upper*2; i++)
            csum+=i;
    }

    pthread_exit(0);
}

//1. ลูกจบก่อน
//2. แม่จบก่อน