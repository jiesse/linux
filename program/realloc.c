#include <stdio.h>
#include <stdlib.h>




int main(int argc, const char *argv[])
{

    int *p;
    int i = 0, j = 0;

    p = (int *)malloc(sizeof(int)*5);
    while(1) 
    {
            scanf("%d",&p[i]);
            if(p[i] == -1)break;
            i++;
            if(i%5 == 0)p =realloc(p,i + 5);
    }
    while(j++<i){ printf("%d\n",p[j-1]);};

    free(p); 
    p = NULL;

    return 0;
}
