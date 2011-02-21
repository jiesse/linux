#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n",s, (unsigned int)pid, (unsigned int )tid, (unsigned int)tid);
}
void *thr_fn(void *arg)
{
    printids(arg);
    return NULL;

}

void *thr_fn1(void *arg)
{
    printf("thread 1 returning\n");
    sleep(2);

    return (int *)5;

}
void *thr_fn2(void *arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((int *)1);
}
void *thr_fn3(void *arg)
{
        printf("thread 3 writing\n");
        sleep(1);
}


int main(int argc, const char *argv[])
{
/*
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
    if(err != 0)
    {
        fprintf(stderr, "can't create thread : %s\n",strerror(err));
        exit(1);
    }
    printids("main thread:");
    sleep(1);
    return 0;
 */
    pthread_t tid;
    void *tret;

    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_join(tid, &tret);
    printf("thread 1 exit code %d\n",(int)tret);

    pthread_create(&tid, NULL, thr_fn2, NULL);
    pthread_join(tid, &tret);
    printf("thread 2 exit code %d\n",(int)tret);

    pthread_create(&tid, NULL, thr_fn3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &tret);
    printf("thread 3 exit code %d\n",(int)tret);

    return 0;

}




