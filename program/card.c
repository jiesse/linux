#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    int card[52] ={0};
    int count = 0;
    int ret,i=0,j=0,n;
    int arr[4][13] = {0};    

    srand(time(0));

    while(count < 52)     
    {
          ret = (int)rand()%52;
          if(card[ret] == 0)
          {
          
                      arr[i][j] = ret;
                      i++;
                      if(i==4){i=0;j++;}
                      count ++;
                      card[ret] = 1;
          
          } 

     }
     
     for (i = 0; i < 4; i++) 
     {
        for(j=0;j<13;j++)
            printf("%d\t",arr[i][j]);
        printf(" \n");

     }
     return 0;
     

}





