#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
   int info_a[5];
   int info_b;

}info_t;

int main(int argc, const char *argv[])
{
    char *p, *q;
    int i = 0,j;
    info_t *info_p;

    //info_p = &a;
    info_p = (info_t *)malloc(sizeof(info_t) * 10);
    if(info_p == NULL) return 1;
    for(; i < 10; i++)
    {
    for(j = 0; j < 5; j++)(info_p[i]).info_a[j] = i;
    (info_p[i]).info_b = 100;
    }
    for(i = 0; i < 10; i++)
    {
    for(j = 0; j <5; j++)printf("%d\t",(*(info_p + i)).info_a[j]);
    printf("%d\n",(*(info_p + i)).info_b);
    }

    p =(char *)malloc(3);
    if(p == NULL) return 1;
    q = p;
    *p = 1;
    *(p+1) = 2;
    *(p+2) = 3;
    for(; p < q+3; p++)printf("%d\n",*p);

    free(info_p);
    free(q);//free(p)is illagel .the begin address couldnt change!!!!!!!

    info_p =NULL;
    q = NULL;
    p = NULL;
    return 0;
}



