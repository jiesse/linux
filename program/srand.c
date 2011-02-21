#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cmp(char *pre, char *sub)
{
    
    int i,n,j = 0;
    char  *p = pre;
    char  *s = sub;

    char pre_s[5];
    char sub_s[5];

    int count_a = 0;
    int count_b = 0;

    for (i = 0; i < 4; i++) 
    {
       if(*p == *s)count_a ++;
       else
       {
            pre_s[j] = *p; 
            sub_s[j] = *s; 
            j++;
       }
       p++;
       s++;
    }

    p = pre_s;
    s = sub_s;
    
    for (i = 0; i < j; i++) 
    {
        for (n = 0; n < j; n++) 
        {
           if(*p == *s)
           {
                    count_b++;
                    break;
           }
           s++;  
        }
        s = sub_s;
        p++;
    }
    printf("%dA%dB\n",count_a,count_b);
    if(count_a == 4 && count_b == 0)
    {
        for (i = 0; i < 4; i++) 
        {
            printf("%c",*pre);
            pre++;
        }
        printf("success!!\n");
    }
    else printf("wrong!!\n");


}

int main(int argc, const char *argv[])
{
    int a = 0;
    int b = 0;
    int dat = 0;
    char pre[5]; 
    char sub[5];

    srand(time(NULL));
    while(dat < 1000)dat = rand()%10000;

    sprintf(pre,"%d",dat);

    while(1)
    {
        printf("please input : ");
        scanf("%s",sub);
        cmp(pre,sub);
    }
    return 0;
}





