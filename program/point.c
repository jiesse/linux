#include <stdio.h>
#define N 10
int main(int argc, const char *argv[])
{
    int *p[4];
    int i = 0;
    char b[7] = {97,98,99,100,101,102};
    char c[11] = "hello world";
    char d[N] = "hello" ;

    int *q,*r,*y;
    int k = 10,t = 33;
    
    b[++i] = 5 ;
    q = &k;
    r = q;
    *r = 20;
    
    y = &t;
    *r = *y;

    printf("%s\n",d);
    printf("%d %d\n",b[0],b[1]);
    printf("%d %d\n",*r,*q);
    
    p[1] = b;
    printf("%d\n",*((char *)(p[1]+1)));

    return 0;
}
