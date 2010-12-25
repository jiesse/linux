#include <stdio.h>
#include <string.h>


void print_sym1(void)
{
    printf("*\n");
}
void print_sym2(void)
{
    printf("#\n");
}
struct stu
{
    char name[256];
    int id ;
    int chinese ;
    void (* print_sym)(void);
};
struct stu arr[] =
{
    {"zhangsan",1,90,},
    {"lisi",2,90,},
    {"wangwu",3,90,},
    {"liuqi",4,90,},
    {"lihao",5,90,},

};
int main(int argc, const char *argv[])
{
    int i ;
    char a[] = "fjdkfjkdf";
    strcpy(arr[0].name,"dfjdkkd")
    i = strlen("fkdjfkdjf");
    print_sym1;
    for (i = 0; i < 5; i++) 
    {
        printf("%s ",arr[i].name);
        printf("%d ",arr[i].id);
        printf("%d ",arr[i].chinese);
        ((print_sym)print_sym1)();

    }
  

    return 0;
}






