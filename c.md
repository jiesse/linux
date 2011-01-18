#c study  like a computer


##frame buffer
    /dev/fb0
    /boot/grub/grub.cfg
    vga= 0x318
## data

    all data in computer use bu code , >0 data , <0 data ,all;
    10000000 -128;
    00000101 5
    11111011 -5

    int  a = -10;
    unsigned b = 6;
    a + b == -4 ;  fault , tranlation to unsigned type
    double a = 2.2;
    float b = 2.2;
    now a != b;
##array



    int main(int argc, const char *argv[])
    {
        int b[2][3] = {1,2,3,4,5,6};
        int (*p)[3];
        p = b;
        printf("%d%d\n",**p,**(p+1));

        return 0;
    }

##base

    global variable the less the good , maybe can put into struct
    glabal var name the more long the good , locate the more short the good
    data nomally cann't  use in code ,but define 
    "hello"; : const, address
    <string.h>; strcpy(stingname,"hello") contain cp '\0'; strlen(string); not contain '\0'
    while(*a++ = *b++) : *a = *b; while(*a); a++ ; b++
    while(*++a = *++b) :
    libc.so.6 : share object
    * and & :
    j = *&i : so j = i
    ldd : ldd a.out, file , is a link ,locate ,file 
    objdump -d a.out :
    printf("%p",p);
    
    stack : argument , locate variable, function point
    heap : memory
    data : global variable
    rodata : string 
    .txt : code
    function package : most use in project(item)
    sudo apt-get install manpages-dev

    warning : the format expect type ... but argument has type ...: solve way, force transition type
    float : len = 4
    double : len = 8
    short : len =2
    long :  len = 4

##flush stdin

    int fflush(FILE*stream)
    fflush(stdin);  :  vc ok , but gcc not work
    setbuf();          not suggest to use under gcc
    int c; while((c=getchar())!= '\n'&& c!=EOF) ;effect fflush(); flush stream;
    
    while(!scanf("%d%d",&a,&b))
          while((c=getchar())!= '\n'&&c !=EOF);   ok,
    
##string

    strcpy(a,hello); : strcpy(a,a+1);  endless loop
    strlen(a);
    strcat(a,b);  :  memory,a > a+b
    strcmp(a,b);



##malloc

    void *malloc(size_t size) : int *p = (int *)malloc(sizeof(int)*num);
    free(p) : p comment can not change; p = NULL;
    p = realloc(p,256)
    memory lose : not free(p); wild point : the memory had lease, but point still point the memory ;
    the memory block : head point head; creat a loop;

##redicretion

    command <filename >file
    cat < filename : print file comment; ls only output; not use keyboard; ls > filename
    command >>filename : will not overwrite file;

##function point 

    typedef int(*f)(void) : f, data type; only typedef, can use (f)fun_name();
    typedef void(*fun_t)(void) : ((fun_t)0x800)(); equal : void (*fun)(void); fun = 0x800; fun(); jump to 0x800 run;    #define myint int * : myint p,q; q, int; 
    

    int (*fun)(int,int); fun = print (get the address); a= fun(2,3);
    arr[i].fun = print; a = arr[i].fun(2,3);
    f = *f ; solid

## getchar

    getchar(); get a char from buff not screen;
    getchar() and enter :

##scanf

    scanf("%d",&a); : only receive int; ASCII isn't int; 5
    scanf("%c",&a); : '5',53
    scanf("%d %d\n",&a,&b); : input form
    scanf("%lf"); : double
    scanf("%[^\n]",string)  :  receive a string only meet enter while  over ,
    the same effect with fgets(string,256,stdin)
    
    scanf("%[1234567890]",string) : only get  stdin   1234567890 
    scanf("%[^12345]",string) :    meet 12345 any letter , stop receive
    scanf("%[a-z]",string);
    scanf("%20s",string);



##fgets

    char *fgets(char *a,int size,FILE* stream);  :  if ok ; return a, or NULL ;end :1 ,'\n',2,size-1, 3, EOF
    fputs(const *s,FILE *stream); s write to file, '\n' , also write into; '\0', over; 

    fgets gets acording to  '\n' to over
    but gets receive '\n', fgets not


##atoi

    int atoi(char *string) : arrary to integrate, #include<stdlib.h>
    int c = atoi("24")+("34");
    c = 58;

    atof(argv[i]);


##sprintf

    <stdio.h>
    int sprintf(char*buffer, const char *format, ...) : return the buffer's len 
    sprintf(a,"%d",12345); now a[] = "12345"  len = 5
    int i = 100; len = sprintf(a,"%.2f",(double)i); len = 6  "100.00"
    %f : double to float
    %x : integrate to hex (a-z)
    %X : integrate to hex (A-Z)
    %o : integrate to ocotonary
    %s : to string
    sprintf(buffer,"%08",123); print  00000123
    sprintf(buffer,"-10f",3.1415926789);

    sprintf(buffer,"string: %s\n","hello"); : print , string: hello, then enter  : the same effect strcat
    char i[] = "i";
    char you[] = "you";
    sprintf(buffer,"%s love %s",i,you);
    sprintf(buffer,"%.3s%.2s","abcdef","uiopk");  print, abcui, detail check www.baidu.com 
    sprintf(buffer,"%.*s%.*s",3,"abcdef",2,"uiopk"); the same effect previous instruction
    sprintf(buffer,"%.*s%.*s",sizeof("abcdef"),"abcdef",sizeof(uiopk),"uiopk");

    sprintf() : can use to strcat many times, detail useage acordding to baidu

    strftime(); can display the local time , detail useage refer to baidu


##srand

    #include<stdlib.h>
    #include<time.h>
    void srand(unsigned seed)
    srand(seed);
    a[i] = rand();


## force transition

    (float *)&a; : previous a is double,  according to float type to read data
    b = (char)a; a not change
    (int *)address;
    (char *)address; become a point
    *((int *)add);
   
##struct

    typedef struct stu
    {
        char name[256];
        char a;
        int b;
    }stu_t;
    stu_t arr;
    strcpy(arr.name,"hello world");
    arr.name[256] = "hello world" : not work
    char a[]="hello world "; arr.name = a; : not work
    strcpy(arr.name,&a); ok

    struct info *p;
    struct info a;
    p = &a;
    so (*p).id = p->id
    
    typedef struct stu *link   :  a point  , it can define other struct points ,its memory is 4
    typedef struct stu link    :  a struct , it can define other struct 


##union

    union day day1;  member share memory,
    union day day2[256];

##enum

    enum : memory is 4
    enum week
    {
        a,b,c  
    };  : now a=0 ,b=1, c=2
    enum week day; day = b; 
    so day = 1
    
##point array

    int *p[4]; 
    int b[4] = {2,3,4,5};
    p[1] = &b[0];
    so *(p[i]) = *(*(p+1))  :  p, array first address
    so *(p[1]+1) = *(*(p+1)+1)  : b[1]

    char a[] = {97,98,99};  : 'a','b'
    int a[] = {97,98,99};   :  97 ,98

##linked list

    struct stu
    {
        int id;
        int chinese;
        char name[256];
        struct stu *next;
    };
    struct stu *head;
    head = (struct stu *)malloc(sizeof(struct stu));
    head->id = 1;
    head->chinese = 100;
    head->next = null;

    struct stu *p;
    p = (struct stu *)malloc(sizeof(struct stu));
    p->id = 2;
    p->chinese = 90;
    p->next = null;

    head->next = p;
    
    delete node :

    struct stu *q;
    q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;

    a = a->next;
    b = b->next;

    a = b;
    b = a->next; : b next;  a become previous b;

    loop linked list :

    p->next = q->next;
    q->next = p;

##file

    ascii file :  128 , 3 byte;  
    binary file : 128 , 1 byte;
    EOF : file end, End Of File  -1, only in ascii file(0~255)

    FILE *src,*dest;
    src = ("a.txt","r");
    dest = ("b.txt","w");
    int a = fgetc(dest);
    if(EOF == a) ; file end
    a = feof(dest);
    a  == 1 : file end
    fputc(a,dest);

    fclose(src);
    fclose(dest);

    '\n' 10 : every file end 
    r,w,a,r+,w+,a+
    hexdump a.out :  check a.out comment
    
    fgets(a,256,src);  ; read 255 bytes , and add '\0' end , every time read one line :be fit for ascii files 
    if(feof(src))break;
    fputs(a,dest);

    int fread(void *ptr,size_t size, size_t numb, FILE *stream)   : no adding '\0' end ;for ascii files or binary files
    fwrite(void *ptr,size_t size, size_t numb, FILE *stream)
    len = fread(c,10,10,src); : had read numb successfully
    if(feof(src))break;
    fwrite(c,10,10,dest);   universally, size, numb  is 1;

    fflush(dest); focus write data to file from buff while the process doesn't end 

    fopen("/home/jiesse/a.txt","w");
    fprintf(dest,"%s %d %d",p->name,p->chinese,p->math);
    fclose(dest);

    fopen("/home/jiesse/a.txt","r");
    fscanf(src,"%s %d %d",p->name,&p->chinese,&p->math);
    fclose(src);

##bit

    & | ! ~
    & : set bit  0
    | : set bit  1
    ^ : 1 = 1^0;
    
    swap a b
    a = a^b;
    b = a^b;
    a = a^b;
    
    <<  : symbol bit not move
    >>   

##variable argument

    printf(const char * format, ...)  : format, must have , acording it to find other argument; and format's address is least in stack ,all arguments address put into stack
    int *p = (int *)&format;
    p = p + 1;   now, *p is the second argument's address, stack address own 4 bytes to point arguments which in roldata
    
    char *p = &format;
    char *p = (char *)&format;
    p = p + 4;   now, *(int *)p is the second argument's address ,*p not work,
    because argument's address own 4 bytes in stack
    
    detail message and application in var_argu.c
    printf("%s %d",a,b);   :

    #include<stdarg.h>

    void function(void format, ...) : format, int, char, point, all ok
    va_list ap;
    var_start(ap,format);

    add(int begin, ...)
    va_list ap;
    var_start(ap,begin);
    add += va_arg(ap,int);
    va_end(ap);

    va_start(va_list ap, last);  ap type : char *
    ap = &last + size(last)    : function size() :stack, (sizeof(last) + 3 )&(~3); means, in stack, char own 4 bytes, int own 4bytes , but if last is 8 bytes, size(last)  is 8 bytes
    va_arg(ap,type)  : type = *(type*)((ap += sizeof(type) - sizeof(type))
    va_end(ap)  : ap = NULL;

##pass argument

    void m(char **x)
    {
        char *p = malloc(100) ;
        *x = p;
    }
    main()
    {
        char *p;
        m(&p);
    }
    now, p point to heap memory

    void m(char *x)
    {
        char*p = malloc(100) ;
        x = p; 
    }
    main()
    {
        char *p;
        m(p);
    }
    now, p point random


    char *p;
    char **q = &p;
    or
    char *p;
    char **q;
    q = &p;

##link

    gcc -c -g main.c   : check code ,include c code 
    objdump main.o -dS : check the code 
    gcc -c main.c -I./lib   : lib include main.c's including files
    
    ar rs libstack.a push.o stack.o  : static library
    gcc main.o -L./lib -lstack  : L, path; l, name, libstack.a  : call static library


##floor ceil

    
    #include<math.h>
    double floor(double arg)
    floor(3.14); return 3
    ceil(3.14);
    floor(9.99);  return 9

##stdin stdout stderr


    stdout : can rediction to file, stderr cannot , only print to screen

##exit

    #include<stdlib.h>
    exit(1);  :  quit process abnomally
    exit(0);   return 0;   : the same effect in main , but in functions,
    exit()  quit process, over the pragram; return(), will return the previous position













