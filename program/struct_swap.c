#include <stdio.h>
#include <string.h>


typedef struct stu
{
    int id;
    int chinese;
    char name[256];

}stu_t;

int struct_swap(stu_t *a, stu_t *b);

stu_t stu1 = {1,89,"zhangsan"};
stu_t stu2 = {2,78,"lisi"};

int struct_swap(stu_t *a, stu_t *b)
{
    stu_t swap;

    swap.id = a->id ;
    swap.chinese = a->chinese ;
    strcpy(swap.name,a->name);
    
    a->id = b->id ;
    a->chinese = b->chinese ;
    strcpy(a->name,b->name);

    b->id = swap.id ;
    b->chinese = swap.chinese ;
    strcpy(b->name,swap.name);

    return 0;
}
int main(int argc, const char *argv[])
{
    struct_swap(&stu1,&stu2);

    printf("%d %d %s\n",stu1.id,stu1.chinese,stu1.name);
    printf("%d %d %s\n",stu2.id,stu2.chinese,stu2.name);

    return 0;
}
