#include <stdio.h>

void print_one(void);
void print_matrix(int num,void (* fun)(void));

void print_one(void)
{
    printf("* ");
}

void print_matrix(int num,void (* fun)(void))
{
     int i, j;
     for (i = 0; i < num; i++) 
     {
         for (j = 0; j < num; j++) 
         {
                fun();    
         }
         printf("\n");
     }

}

int main(int argc, const char *argv[])
{


    print_matrix(5,print_one);

    return 0;
}




