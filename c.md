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

    typedef int(*f)(void) : f, data type; 
    typedef void(*fun_t)(void) : ((fun_t)0x800)(); fun_t fun; fun = 0x800; fun(); jump to 0x800 run;    #define myint int * : myint p,q; q, int; 
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



















