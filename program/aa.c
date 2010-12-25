#include <stdio.h>

int main(int argc, const char *argv[])
{
    
    int a = 2;
    int *p;

    p = &a;
    printf("%d \n",*(p++));

    return 0;
}
