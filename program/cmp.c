#include <stdio.h>


void * cmp_int(void *a, void *b)
{
    if(*(int *)a > *(int *)b)return a;
    else return b;
}

void * cmp_char(void *a, void *b)
{
    if(*(char *)a > *(char *)b)return (char *)a;
    else return (char *)b;
}
void * get_max(void *a, int len, int size, void * (*fun)(void *, void *))
{
    void * max;
    int i;

    max = a;
    for (i = 0; i < len; i++) 
    {
        max = fun(max , a + size*i);
    }

    return  max ;
}

int main(int argc, const char *argv[])
{
    int a[10] = {1,2,23,6,8,10,0};
    char b[8] = {23,5,7,78,2,3,77};

    printf("%d\n",*((int *)get_max(a, 10, 4, cmp_int)));
    printf("%d\n",*((char *)get_max(b, 8, 1, cmp_char)));

    return 0;
}




