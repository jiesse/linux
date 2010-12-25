#include <stdio.h>

void read_line(char str[], int n)
{
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n')
        if(i < n)
        str[i++] = ch ;
    str[i] = '\0';

 }

 
 int main(int argc, const char *argv[])
 {
    char string[8]="" ;
    int i = 4 ;

    read_line(string, i) ;
    printf("%s\n",string);
    return 0;
     
 }
