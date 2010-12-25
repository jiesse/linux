#include <stdio.h>
#include <string.h>

struct info {
    char id ;
    int  chinese ;

};

int main(int argc, const char *argv[])
{
////int i, j;
//
//for (i = 1; i <=100; i++) 
//{
//for (j = 2; j < i; j++) 
//{
//if (i%j == 0) 
//{
//break;
//}
//}
//if(j == i)printf("%d\n",i);
//}
    struct info *p;
    struct info arr;
    int *q;

    p = &arr;
    p->id = 5;
    p->chinese = 95;
    printf("%d\n",sizeof(struct info));
    printf("%d\n",sizeof(q));
    printf("%d\n",(*p).id);
    printf("%d\n",(*p).chinese);

    return 0;
    
}
