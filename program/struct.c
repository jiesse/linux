#include <stdio.h>


int add(int a,int b){return a + b ;}
int sub(int a,int b){return a - b ;}
int mul(int a,int b){return a * b ;}
int div(int a,int b){return a / b ;}
int mod(int a,int b){return a % b ;}
struct cmd
{
    char sym;
    int (* fun_calc)(int , int);
};
struct cmd calc[] =
{
    {'+',add},
    {'-',sub},
    {'*',mul},
    {'/',div},
    {'%',mod},

};





int main(int argc, const char *argv[])
{
    int i;
    int x, y;
    char flag;
    flag = getchar();
    scanf("%d %d",&x,&y);
    for (i = 0; i < 5; i++) 
    {
        if(calc[i].sym == flag)
         printf("%d\n",calc[i].fun_calc(x,y));

    }
    return 0;



}





