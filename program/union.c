#include <stdio.h>
#include <string.h>
union day
{
    int a ;
    char b[266];

};
int main(int argc, const char *argv[])
{
    union day day1; 

    day1.a = 121 ;
    printf("%d\n",day1.a);
    strcpy(day1.b,"abc");
    printf("%c\n",&day1.a);

    return 0;
}
