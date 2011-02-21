#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *dest,*src;
    int a = 0;
    char b[256];
    char c[256];
    int len = 0; 
    size_t size = 1;
    size_t numb = 100;
  

    c[0] = 'a';
    c[1] = 'b';
    c[2] = '\0';
    c[3] = 'c';
    c[4] = 'd';
    c[5] = '\n';
    c[6] = 'n';
    c[7] = 'm';
    if(argc != 3)
    {
         printf("please input two files\n");
         return 0;
    }
    src = fopen(argv[1],"r");
    dest = fopen(argv[2],"w");
    
    
    printf("%s\n",c);
       #if 0 
        a = fgetc(src);
        //if(a == EOF) break;
        if(feof(src)) break;
        fputc(a,dest);
        printf("%c",a);
       #endif 
       #if 0 
        fgets(b,256,src);
        if(feof(src)) break;
        fputs(b,dest);
       #endif
        //len =  fread(c,size,numb,src);
        //if(feof(src))break;
       fwrite(c,size,numb,dest);
    
    

    fclose(src);
    fclose(dest);
    return 0;
}
