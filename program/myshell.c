#include <stdio.h>
#include <string.h>

typedef struct cmd
{
    char * command[8];
    char * in;
    char * out;
}cmd_t;

cmd_t shell;

int parse(char *a);
void show(void);

int parse(char *a)
{
    char *p;
    char num = 0;
    int i = 0;

    p = a;
    while(*p)
    {
        if(*p == ' ')  
        {
            *p = 0;
            p++;
            continue;
        }
        if(*p == '>')
        {
            *p =0 ;
            p++;
            while(*p++ == ' ') ;
            shell.out = --p; 
                    
        }
        if(*p == '<')
        {
            *p = 0;
            p++;
            while(*p++ == ' ') ;
            shell.in = --p; 
                    
        }
        if(*p != 0 && *(p-1) == '\0' || p == a) 
        {
              shell.command[i++] = p;
        }
        p++;
    }
    
    return 0;
}
void show(void)
{
    printf("show the command\n");
    printf("command :%s\n",shell.command[0]);
    printf("argument1 :%s\n",shell.command[1]);
    printf("argument2 :%s\n",shell.command[2]);
    printf("infile :%s\n",shell.in);
    printf("outfile :%s\n",shell.out);


}

int main(int argc, const char *argv[])
{
    char a[256] = "      ls    ";
    int i;
    int len;
    
    while(1)
    {
        for (i = 0; i < 8; i++) 
        {
            shell.command[i] = NULL;
        }
        shell.in = NULL;
        shell.out = NULL;
        //FILE *stream;
        //char b[256];
        fgets(a,55,stdin);
        len = strlen(a);
        a[len - 1] = '\0';
        parse(a);
        show();
    }


    return 0;
}







