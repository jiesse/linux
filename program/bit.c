#include <stdio.h>

/****************************************************
2.x * y
****************************************************/
int mul(int x,int y)
{
    int rel = 0;
    int i = 0;
    int len = sizeof(int)*8;
    for(i = 0; i < len; i++)
    {
        if(x>>i&0x01)
           rel += y<<i; 
    }
    return rel;

}
void x_y(void)
{
    int x = 0;
    int y = 0;
    printf("Please input x y :");
    scanf("%d %d",&x,&y);
    printf("%d * %d = %d\n",x,y,mul(x,y));
    
    return ;
}
/****************************************************
1.decimal to binary
****************************************************/
int mov(int a, int bn)
{
    return (a >> bn) & 0x01;
}

void dec_to_bin(void)
{
    int decimal = 0;
    int i = 0;
    int len = sizeof(int)*8;
    
    printf("Input a number :");
    scanf("%d",&decimal);
    printf("decimal %d change to binary is  ",decimal);
    for (i = 0; i < len; i++) 
    {
        printf("%d",mov(decimal,len-i-1));
    }
    printf(" \n");
}
/****************************************************
3.low to up exchange
****************************************************/
char * exchange(char *Arr)
{
    char *p = Arr;
    while(*p)
    {
        if(*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z')
        {
             if(*p >='a'&&*p<='z')
                 *p = *p - 32;
             else
                *p = *p + 32; 
        } 
       p++; 
    }

    return Arr;
}
void low_or_up(void)
{

    char arr[256];

    printf("Please input a string:");
    getchar();
    fgets(arr,256,stdin);
    printf("%s\n",exchange(arr));
    
    return ;
}
/****************************************************
4.encryption
****************************************************/
void encry(void)
{
    char input = 0;
    char tmp = '&';

    getchar();
    printf("Please input a char :");
    scanf("%c",&input);
    printf("after encrytion :");
    printf("%c\n",input^tmp);
    
    return ;

}

/****************************************************/
int print_menu(void)
{
    int choice = 0;

    printf("1.decimal to binary\n");
    printf("2.x*y\n");
    printf("3.low or up exchange\n");
    printf("4.encryption\n");
    printf("5.Exit\n");
    printf("Please choose [1-5] :");
    
    scanf("%d",&choice);
    return choice;
}
/****************************************************/
int main(int argc, const char *argv[])
{
    
    while(1) 
    {
        switch(print_menu()) 
        {
            case 1: dec_to_bin(); break; 
            case 2: x_y();        break; 
            case 3: low_or_up();  break; 
            case 4: encry(); break;
            case 5: return 0; 
        }
        printf(" \n");
    }
}
