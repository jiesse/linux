#include <stdio.h>
#include <time.h>
#define D (24*60*60)
#define H (60*60)
#define M (60)

int main(int argc, const char *argv[])
{
    
    time_t *timer;
    long Time = 0;
    long h = 0; 
    long f = 0; 
    long m = 0; 
    long flag = 0;
    timer = NULL;
    while(1)
    {
        Time = time(0);

        h = Time % D / H +8;
        f = Time % D % H / M;
        m = Time % M;

        if(m == flag+1)
        {
            printf("%2ldH %2ldF %2ldM\n",h,f,m);
            flag = m;
            if(flag == 59) flag = -1;
        }
    }
    return 0;
}
