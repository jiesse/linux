#include <stdio.h>
#define N 10

struct people
{
    int id;
    int out;
};

int josephus(struct people *brr, int Num, int out_num);

struct people arr[N]; 

int josephus(struct people *brr, int Num, int out_num)
{
   int num = 0,people = 0;
   struct people *q;


   q = brr;
   while(1)
   {
       if((*q).out == 0)
       {   
            num++;
            if(num == out_num)
            {
                num = 0;
                (*q).out = 1;
                people++;
                if(people == (Num-1)) break;
            }

       }

       if((*q).id == Num)q = brr-1; 
       q++;
       
  } 
  return 0;
}

int main(int argc, const char *argv[])
{
    struct people *p ;
    int i;

    for (i = 0; i < N; i++) 
    {
        arr[i].id = i+1;
        arr[i].out = 0;

    }
    

    for(p = arr; p < arr+N; p++)printf("%d ",(*p).id);    
    printf(" \n");
    for(p = arr; p < arr+N; p++)printf("%d ",(*p).out);    

    printf(" \n");
    p = arr;
    josephus(p, N, 3);

    for(p = arr; p < arr+N; p++)printf("%d ",(*p).id);    
    printf(" \n");
    for(p = arr; p < arr+N; p++)printf("%d ",(*p).out);    

    printf(" \n");

    return 0;
}


