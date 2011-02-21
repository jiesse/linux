//#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

typedef struct stu 
{
    int id;
    int chinese;
    char name[256];
    struct stu *next ;

}stu_t;

typedef void (* fun)(stu_t *);

stu_t * create(stu_t *pro, int id, int chinese, char * name);
void print(stu_t *q);
stu_t * delete(stu_t *p, int ID);
void insert_next(stu_t *p, int id_next, int id, int chinese, char *name );
void free_list(stu_t * head);


stu_t * create(stu_t *pro, int id, int chinese, char * name)
{
    stu_t *p = (stu_t *)malloc(sizeof(stu_t));
    p->id = id;
    p->chinese = chinese;
    strcpy(p->name,name);
    p->next = NULL;
    
    pro->next = p;

    return p;

}
void print(stu_t *q)
    //{
    while(q != NULL)
    {
        printf("%d %d %s\n",q->id,q->chinese,q->name);
        q = q->next;
    }
    return ;
}
stu_t* delete(stu_t *head, int ID)
{
    stu_t *q;
    stu_t *p = head;

    if(p->id == ID) 
    {
        q = p;
        p = p->next;
        free(q);
        q = NULL;
        return p; 
    }
    while(p->next->id != ID) p = p->next; 
    q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;

    return head;

}
void insert_next(stu_t *p, int id_next, int id, int chinese, char *name )
{

    stu_t *q;
    stu_t *next =(stu_t *)malloc(sizeof(stu_t));
    next->id = id;
    next->chinese = chinese;
    strcpy(next->name,name);

    while(p->id != id_next)
    {
        p = p->next; 
    
    }
    q = p->next;
    p->next = next;
    next->next = q;

    return ;
}
void free_list(stu_t * head)
{
    stu_t *p;
    while(head->next !=NULL)
    {
    p = head;
    head = head->next; 
    free(p);
    p = NULL;
    ((fun)print)(head);
    }

    return ;


}
int main(int argc, const char *argv[])
{


    
    stu_t *head, *p; 

    head = (stu_t *)malloc(sizeof(stu_t));
    head->id = 0;
    head->chinese = 98;
    strcpy(head->name,"zhangsan");

    p = create(head,1,99,"lisi");
    p = create(p,2,99,"wangwu");
    p = create(p,3,99,"manliu");
    p = create(p,4,99,"qi");

    
    ((fun)print)(head);

    printf("\n");
    head = delete(head,4);    
    ((fun)print)(head);

    
    printf("\n");
    insert_next(head, 2, 5, 66,"guoba");
    ((fun)print)(head);

    free_list(head);

    return 0;
}









