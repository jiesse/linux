#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


void myprintf(char *format, ...)
{
    #if 0
    char *p = &format;
    p = p + 4;
    printf("%s\n",*(int*)p);
    p = p + 4;
    printf("%s\n",*(int*)p);
    p = p + 4;
    printf("%s\n",*(int*)p);

    int *p;
    va_list ap;
    va_start(ap,format);
    p = va_arg(ap,int*);
    printf("%s\n",p);
    p = va_arg(ap,int*);
    printf("%s\n",p);
    #endif
    return ;
}
void add(int format, ...)
{
    int i = 0;
    int rel = 0;
    va_list ap;
    va_start(ap,format);
    for (i = 0; i < format; i++) 
    {
        rel+= va_arg(ap,int);
    }
    va_end(ap);
    printf("%d\n",rel);
    return ;


}

int main(int argc, const char *argv[])
{
    
    add(9,1,2,3,4,5,6,7,8,9);
    return 0;
}
