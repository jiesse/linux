#include <stdio.h>

struct maxstr
{
    int num;
    char *add;

};
struct maxstr str_arg;
int get_maxstr(char *p)
{
    char *q;
    int count = 0;

    q = p;
    str_arg.num = 0;
    str_arg.add = q;
    while(*p != '\0')
    {
       if(*p == *(p+1))count++;
       else {
                if(count > str_arg.num) 
                {
                 str_arg.num = count;
                 str_arg.add = p - count;
                 }
                 count = 0;
            }
       p++;          
    }
    return 0;

}

int main(int argc, const char *argv[])
{
    int i;
    char a[256]; 

    scanf("%s",a);

    get_maxstr(a);
    for (i = 0; i <= str_arg.num; i++) 
    {
        printf("%c",*(str_arg.add+i));
    }
    printf(" \n");
    return 0;
}





