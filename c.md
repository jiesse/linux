#c study


##base

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
##fgets

    char *fgets(char *a,int size,FILE* stream);  :  if ok ; return a, or NULL ;end :1 ,'\n',2,size-1, 3, EOF
    fputs(const *s,FILE *stream); s write to file 



##atoi

    int atoi(char *string) : arrary to integrate, #include<stdlib.h>
    int c = atoi("24")+("34");
    c = 58;

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




