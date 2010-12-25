#include <stdio.h>


int  cmp_int(void * a, void * b);
int  cmp_char(void * a, void * b);
void get_rank(void *a, int len, int size, int (* f)(void *, void*));

int  cmp_int(void * a, void * b)
{
    int i;
    if(*(int *)a < *(int *)b)
    {
        i = *(int *) b;
        *(int *)b = *(int *)a;
        *(int *)a = i;
        return 0;
    }
    else return 0;
}
int  cmp_char(void * a, void * b)
{
    char i;
    if(*(char *)a < *(char *)b)
    {
        i = *(char *) b;
        *(char *)b = *(char *)a;
        *(char *)a = i;
        return 0;
    }
    else return 0;
}
void get_rank(void *a, int len, int size, int (* f)(void *, void*))
{
    void * max, * p;
    int i; 
    for (i = 0; i < len ; i++) 
    {
           max = a + size*i;   
           for (p = a + size*i; p < a + size*len; p+=size) 
           {
                f(max, p);

           }
    }
}

int main(int argc, const char *argv[])
{
    int a[8] = {12,3,45,5,6,78,9};    
    char b[6] = {1,2,55,7,9,88};
    int i;

    printf("int large to small\n");
    for (i = 0; i < 8; i++) printf("%d ",*(a + i));

    printf("\n");
    get_rank(a, 8, 4, cmp_int);
    for (i = 0; i < 8; i++) printf("%d ",*(a + i));

    printf("\n");

    printf("char large to small\n");
    for (i = 0; i < 6; i++) printf("%d ",*(b + i));

    printf("\n");
    get_rank(b, 6, 1, cmp_char);
    for (i = 0; i < 6; i++) printf("%d ",*(b + i));

    return 0;
}






