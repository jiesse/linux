#include <stdio.h>

typedef int (* fun_calc)(int a,int b);

int add_num(int a,int b)
{
    return a + b;
}

int sub_num(int a,int b)
{
    return a - b;
}

int mul_num(int a,int b)
{
    return a * b;
}

int div_num(int a,int b)
{
    return a / b;
}

int main(int argc, const char *argv[])
{
    int x;
    int y;
    char flag;
    flag = getchar();
    scanf("%d %d",&x,&y);
    switch(flag) 
    {
        case '+': printf("%d\n",((fun_calc)add_num)(x,y));break;
        case '-': printf("%d\n",((fun_calc)sub_num)(x,y));break;
        case '*': printf("%d\n",((fun_calc)mul_num)(x,y));break;
        case '/': printf("%d\n",((fun_calc)div_num)(x,y));break;
    
    }
    return 0;
}
