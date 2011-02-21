#include <stdio.h>
#include <string.h>

int mystrstr(char *pre, char *sub, char *rep)
{
    int count = 0;
    int i;
    char *d = sub;

    char *pp ;
    char *prep = rep;
    int len = strlen(rep);
    i = len ;
    while(*pre != '\0' && *sub != '\0') 
    {
            if(*pre == *sub)
            {
                sub++; 
                pre++;
                if(*sub == '\0')
                {
                        count++;
                        sub = d;
                        pp = pre;
                        while(*rep != '\0')
                        {
                            *(pp-len) = *rep;
                            rep++;
                            len--;
                        }
                        len = i;
                        rep = prep;
                }
                
            }
            else
            {
                pre++;
                sub = d;
            }
    }

    return count;
}
int main(int argc, const char *argv[])
{

    int ret = 0;
    char prechar[256];
    char subchar[256];
    char repchar[256];


    gets(prechar);
    gets(subchar);
    gets(repchar);

    printf("%s\n",prechar);
    printf("%s\n",subchar);
    printf("%s\n",repchar);

    ret = mystrstr(prechar,subchar,repchar);
    printf("ret = %d\n",ret);

    printf("%s\n",prechar);

    return 0;
}







