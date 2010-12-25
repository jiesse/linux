#include <stdio.h>

int cmp_int(void *a ,void *b);
void get_rank(void *a, int len, int size, int (*f)(void *, void *));

int cmp_int(void *a ,void *b)
{
    int i;

    if(*(int *)a - *(int *)b > 0)return 0;
    else 
    {
        i = *(int *)b;
        *(int *)b = *(int *)a;
        *(int *)a = i;
        return 0;
    }
}

void get_rank(void *a, int len, int size, int (*f)(void *, void *))
{
    int i;
    void *p;

    for (i = 0; i < len; i++) 
    {
        for(p = a; p < a+len*size; p+=size)
        {
            f(p, p+size);
        }
    }
}

int main(int argc, const char *argv[])
{
    int a[9] ;
    int *p;

    for(p = a; p < a+9; p++) scanf("%d",p);
    printf("\n");    

    get_rank(a, 9, 4, cmp_int);
    for(p = a; p < a+9; p++) printf("%d ",*p);

    return 0;
}




