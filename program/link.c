#include <stdio.h>
#include <malloc.h>
#define  N 8

struct node
{
    int id;
    struct node *next;

};

typedef struct node *node_t;

node_t creat(int n)
{
    int i;
    node_t p ;
    node_t head = (node_t)malloc(sizeof(struct node));
    head->id = 0;
    head->next = NULL ;
    
    p = head;
    for(i = 0; i < n; i++)
    {

        p->next = (node_t)malloc(sizeof(struct node));
        p->next->id = i+1;
        p->next->next = NULL;
        p = p->next;
    }
    return head;

}
node_t sort(node_t head)
{
    node_t p1, p2, p3;
    p1 = head;
    p2 = p1->next;
    p3 = p2->next;
    
    p1->next = NULL;
    while(p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    
    p2->next = p1;
    p2 = p1;
    return p2;



}
void print(node_t k)
{
    int i ; 
    while(k != NULL)
    {
         printf("%d\n",k->id);
         k = k->next;
    
    }
    return ;

}

int main(int argc, const char *argv[])
{
   
    print(creat(N));
    print(sort(creat(N)));

    return 0;
}
