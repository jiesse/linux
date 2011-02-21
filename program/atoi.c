#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *str)
{

    int return_num = 0;
    int singal = 1;
    
    if(*str >= '0'&& *str <='9'|| *str == '-' || *str == '+')
    {
         if(*str == '-'){ singal = -1;str++;}
         while(*str)
         {
               return_num = return_num*10 + *str++ - '0'; 
         }
         return return_num*singal;
    
    }
    else return 0;
}


int main(int argc, const char *argv[])
{
    int c = 0;
    
    c = my_atoi(argv[1]) + my_atoi(argv[2]);
    printf("c= %d\n",c);

    return 0;
}






