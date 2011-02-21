#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu 
{
    char name[20];
    int chinese;
    int math;
    int average;
}stu_t;

int main(int argc, const char *argv[])
{
    FILE *src ,*dest;
    stu_t *p, *q;
    p = (stu_t *)malloc(sizeof(stu_t));
    q = (stu_t *)malloc(sizeof(stu_t));
    strcpy(p->name,"an");
    p->chinese = 99;
    p->math = 88;
    p->average = 100;


    src = fopen("/home/jiesse/a.txt","w");
    
    fprintf(src,"%s %d %d %d",p->name,p->chinese,p->math,p->average);
    printf("p is %s %d %d %d",p->name,p->chinese,p->math,p->average);
    printf(" \n");
    fclose(src);

    src = fopen("/home/jiesse/a.txt","r");
    fscanf(src,"%s %d %d %d",q->name,&(q->chinese),&(q->math),&(q->average));
    printf("q is %s %d %d %d",q->name,q->chinese,q->math,q->average);
    printf(" \n");

    fclose(src);
    return 0;
}






