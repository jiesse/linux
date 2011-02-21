#include <stdio.h>
#define N 2 
#define M 3 

int main(int argc, const char *argv[])
{
    int b[2][3] = {1,2,3,4,5,6};
    int (*p)[3];
    int *q;
    p = b;
    q = b[0];
    printf("%d%d\n",**p,**(p+1));
    printf("%d\n",*q);


    return 0;
}
