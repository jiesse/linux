#include <stdio.h>
#define N 20

struct people
{
    int id ;
    int out;
};

struct people arr[N];


int main(int argc, const char *argv[])
{
    int i;
    int j = 0, m = 0;

    for (i = 0; i < N; i++) 
    {
        arr[i].id = i+1;
        arr[i].out = 0;
    }
    for(i = 0; i < N; i++) 
    {
        for (;;) 
        {
            if (arr[m].out == 0) 
            {
                j++;
            }
            if(j == 5)
            {
                j = 0 ;
                arr[m].out = 1;
                printf("%d\n",arr[m].id);
                break;
            }
            m++;
            m = m % N;
        
         }
    }
    return 0;
}
