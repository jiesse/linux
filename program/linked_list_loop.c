#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N  20
#define PEOPLE  20

struct  stu 
{
    int id;
    int chinese;
    char name[256];
    struct stu *next;
};
typedef struct stu *link;

link creat(link q, int Id, int Chinese, char *Name);

link creat(link q, int Id, int Chinese, char *Name)
{
    link p = (link)malloc(sizeof(struct stu));
    p->id = Id;
    p->chinese = Chinese;
    strcpy(p->name,Name);
    p->next = q->next; 
    q->next = p;

    return p;
}
int josephus(int n, link add)
{
    int i = 0;
    link tmp;
    while(add != add->next)
    {
         add = add->next;
         i++;
         if(i == n - 1)
         {
            tmp = add->next->next;
            free(add->next);
            add->next = tmp;
            i = 0;
         }
    }
    return add->id; 
}
void print(link q)
{
    int i = 0;
    while(1)
    {
        printf("%d %s\n",q->id,q->name);
        q = q->next;
        i++;
        if(i == PEOPLE)break;
    }
    
    return ;
}
int main(int argc, const char *argv[])
{
    
    int people = 1;
    link head;
    link p = (link)malloc(sizeof(struct stu));
    p->id = 0;
    p->chinese = 100;
    strcpy(p->name,"zhangsan");
    head = p;
    head->next = head;

    for(; people < PEOPLE; people++) p = creat(p,people,99,"lisi") ;

    print(head);
    printf(" \n");
    printf("the lost is %d\n",josephus(4,head));

    return 0;
}







