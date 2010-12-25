#include <stdio.h>

char * strcpy_t(char *dest, char *src)
{
    char *p;

    //p = dest ;
    //for (; *src!= '\0'; src++) 
    //{
    //*p = *src;
    //p++;
    //}
    // 
    //return dest ;
    
    p = dest ;
    while(*p++ = *src++);

    return dest ;

}

int strlen_tt(const char *str)
{
    int num = 0;

    while(*str++ != '\0')
    {
        num++;
    }

    return num;
}


int main(int argc, const char *argv[])
{
    char a[10];
    printf("%s\n",strcpy_t(a,"hello"));

    return 0;

}





