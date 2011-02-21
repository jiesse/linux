#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5

struct stu
{
    char name[256];
    int average;
    struct stu *next;

};
typedef struct stu *link;

link creat(link q, char *Name, int Average)
{

    link p = (link)malloc(sizeof(struct stu));
    strcpy(p->name,Name);
    p->average = Average;

    p->next = NULL;
    q->next = p;

    return p;
}
link insert_rank(link head,link n)
{
    link p = head;
    link pr;
    if(n->average > head->average){n->next = p; return  n;}
    while(p)
    {
        if(n->average > p->average)break;
        pr = p; p = p->next;
    
    }
    if(p)
    {
        n->next = p;
        pr->next = n;
    }
    if(!p) 
    {
        pr->next = n;
        n->next = NULL;
    }
    return head;

}
link rank_list(link p)
{
    link new = NULL;
    link tmp = NULL;
    new = p;
    p = p->next;
    new->next = NULL;
    while(p)
    {
        tmp = p->next;
        new = insert_rank(new,p);
        p = tmp;
    }
    return new;

}
#if 0 
struct stu * rank_list(struct stu * pp)
{
    link head_pr = NULL;
    link head_cu = NULL;
    link travel = NULL;
    link tmp = NULL;
    tmp = pp;
    head_pr = tmp->next;
    tmp->next = NULL;
    head_cu = tmp ;
    while(head_pr != NULL)
    {
        tmp = head_pr;
        head_pr = head_pr->next;
        tmp->next = NULL;
        if( tmp->average >= head_cu->average) 
        {
            tmp->next = head_cu; 
            head_cu = tmp ;
        
        }
        else
        {
            travel = head_cu;
            if(travel->next == NULL)
            {
                head_cu->next = tmp;
                continue;
            }
            while(tmp->average < travel->next->average) 
            {
                    
                travel = travel->next;
                if(travel->next == NULL) break;
            }
            tmp->next = travel->next;
            travel->next = tmp;
        
        }

    }
    return head_cu;

}
#endif
void print(link p)
{
    while(p != NULL)
    {
         printf("%s %d\n",p->name,p->average);
         p = p->next;
    
    }
    return ;
}
int main(int argc, const char *argv[])
{
    int i = 0;
    link head = (link)malloc(sizeof(struct stu));
    strcpy(head->name,"zhang");
    head->average = 99;
    link p = head;
    
    p = creat(p,"guo",67);
    p = creat(p,"wang",57);
    p = creat(p,"liu",77);
    p = creat(p,"qian",87);
    p = creat(p,"zhao",37);
    p = creat(p,"you",47);
    p = creat(p,"zhou",86);
    p = creat(p,"gao",27);
    p = creat(p,"fan",67);

    print(head);
    printf(" \n");
    
    p = rank_list(head);
    print(p);
    printf(" \n");

    return 0;
}








