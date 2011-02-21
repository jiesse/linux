#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    unsigned ID;
    char name[20];
    float chgrade;
    float mathgrade;
    float average;
    struct node *next;
};
typedef struct node NODE;

NODE *creat_node(NODE *pr, unsigned id, char *Name, float ch, float math, float aver);
NODE * creat_stu_link(void);
int  print_main_menu(void);
int count_stu_num(NODE *head);
/*************************************************************************************/
NODE *creat_head_node(unsigned id, char *Name, float ch, float math, float aver)
{

    NODE *head = (NODE *)malloc(sizeof(NODE));
    head->ID = id;
    strcpy(head->name,Name);
    head->chgrade = ch;
    head->mathgrade = math;
    head->average = aver;

    head->next =  NULL;

    return head;
}

NODE *creat_node(NODE *pr, unsigned id, char *Name, float ch, float math, float aver)
{

    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->ID = id;
    strcpy(p->name,Name);
    p->chgrade = ch;
    p->mathgrade = math;
    p->average = aver;

    p->next =  NULL;
    pr->next = p;

    return p;
}

NODE * creat_stu_link(void)
{
    unsigned id;
    char Name[10];
    float ch;
    float math;
    float aver;
    FILE *src = fopen("stud_system.txt","r");
    fscanf(src,"%u %s %f %f %f",&id,Name,&ch,&math,&aver);
    NODE *head = creat_head_node(id,Name,ch,math,aver);
    
    NODE *p = head;
    while(1)
    {
        fscanf(src,"%u %s %f %f %f",&id,Name,&ch,&math,&aver);
        if(feof(src)) break;
        p = creat_node(p,id,Name,ch,math,aver);
        
    }
    fclose(src);

    return head;
}
void close_stu_link(NODE*p)
{
    FILE *src = fopen("stud_system.txt","w");
    while(p != NULL)
    {
        fprintf(src,"%u %s %.1f %.1f %.1f\n",p->ID,p->name,p->chgrade,p->mathgrade,p->average);
        p = p->next;
    }
    fclose(src);
    return ;
}
/************************************************************************************/
int  print_main_menu(void)
{
    int choice = 0;

    printf("Please select the option :\n");
    printf("1.Display all student's info\n");
    printf("2.Sort by average\n");
    printf("3.Insert a new info\n");
    printf("4.Delete a record\n");
    printf("5.Quit\n");
    printf("Please input your choice :");
    
    scanf("%d",&choice);
    printf(" \n");
    return choice;
}
/************************************************************************************/
int print_stu_message(NODE * link_head)
{
    int sed = 1;
    printf("sed    ID        NAME      CHGRADE    MATHGRADE     AVERAGE\n");
    printf("-------------------------------------------------------------------\n");
    while(link_head != NULL)
    {
         printf(" %d:",sed++);
         printf("%5u %11s %11.1f %12.1f %12.1f\n",link_head->ID,link_head->name,link_head->chgrade,link_head->mathgrade,link_head->average);
         link_head = link_head->next;
    
    }
    printf("-------------------------------------------------------------------\n");
    printf(" \n");
    return  sed;

}
/************************************************************************************/
NODE* insert_rank(NODE* head,NODE* n)
{
    NODE* p = head;
    NODE* pr;
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
NODE* rank_list(NODE* p)
{
    NODE* new = NULL;
    NODE* tmp = NULL;
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
/*********************************************************************************/
NODE* insert_stu(NODE *head)
{
     NODE *q = head;
     unsigned id;
     char Name[10];
     float ch;
     float math;
     float aver;
     int Stu_num = count_stu_num(q);
     printf("Please input the new info(ID name chgrade mathgrade average) :\n");
     printf("ID should more than %d\n",Stu_num);
     scanf("%u %s %f %f %f",&id,Name,&ch,&math,&aver);
     while(q->next != NULL)q = q->next;
     creat_node(q,id,Name,ch,math,aver);
     
     return head;

}
/**********************************************************************/
NODE* delete_node_id(NODE *head, int id)
{
    NODE *q;
    NODE *p = head;

    if(p->ID == id) 
    {
        q = p;
        p = p->next;
        free(q);
        q = NULL;
        return p; 
    }
    while(p->next->ID != id) p = p->next; 
    q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;

    return head;
}
char* delete_stu_name(void)
{
    char arr[256];
    char *p = arr;
    printf("Please input a name:");
    scanf("%s",p);

    return p;

}
NODE* delete_node_name(NODE *head, char*Name)
{
    NODE *q;
    NODE *p = head;

    if(!strcmp(p->name,Name)) 
    {
        q = p;
        p = p->next;
        free(q);
        q = NULL;
        return p; 
    }
    while(strcmp(p->next->name,Name)) p = p->next; 
    q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;

    return head;

}
int print_del_menu(void)
{

    int choice_del = 0;
    int i = 0;

    printf("Please input the way :\n");    
    printf("1.Delete by ID\n");
    printf("2.Delete by name\n");
    printf("3.Exit\n");
    printf("Your choice:");

    while((i=getchar()) != '\n'&& i!= EOF);
    scanf("%d",&choice_del);
    return choice_del;
}
NODE * delete_stu_id(NODE*head)
{
    int del_id = 0;
    printf("You should choose the number include 1-%d :",count_stu_num(head));
    printf("\n");
    printf("selnum = ");
    scanf("%d",&del_id) ;
    head = delete_node_id(head,del_id);

    return head  ;
}
NODE * delete_stu(NODE *head)
{

    while(1)
    {
        switch(print_del_menu())
        {

            case 1: head = delete_stu_id(head);  break;
            case 2: head = delete_node_name(head,delete_stu_name()) ;break;
            case 3: return head;
        }
    }
}
int count_stu_num(NODE *head)
{

     int stu_num = 0;
     while(head->next != NULL)
     {
            stu_num++;
            head = head->next;
     }
     stu_num++;

     return stu_num;

}
/************************************************************************/
int main(int argc, const char *argv[])
{
    
    NODE *p;
    p = creat_stu_link();
    while(1)
    {
        
        switch(print_main_menu())
        {
            case 1:print_stu_message(p) ;break;
            case 2:p = rank_list(p) ; print_stu_message(p);break;
            case 3:p = insert_stu(p); print_stu_message(p);break;
            case 4:p =  delete_stu(p) ; print_stu_message(p);break;
            case 5:close_stu_link(p);return 0;

        }
        
     }
}
