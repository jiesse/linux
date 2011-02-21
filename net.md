



##base

    system("clear");   clear the screen

    char *p = fb_v.mem;
    memset(p,0,1024*768);  clear the screen

    sleep(1) ;   delay 1 second
    usleep(1);   delay 1 us


##process

program run, dynamic, code add hardware source

socket : (net interface ) , in kernel; 1, connect area (unix , internet)2, type (stream(like phone),other like letter )3, agreement

address 100 101 102 103 
data 10 20 30 40 bit end 
data 40 30 20 10 little end


##mode

stream :(TCP)

    server : socket() ->  bind() -> listen() -> access() 

    guest :  socket() -> connect() -> access();

##buffer

    typedef struct
    {
        char dest;
        char src;
        char type;
        char len;
        int x;
        int y;
    }msg_t;

    msg_t  * p;
    p = (msg_t *) buffer;
    p->x = ?
    P->y = ?

    include<string.h>
    memcpy((char*)&buffer[4],(char*)&x,4);


##pthread

    pthread : cpu will time-sharing multiplexing , hardware sourse   share;  
    a thread : joinable and unjoinable , joinable ; thread function end return and pthread_exit(), not release the memory 
    so you must call pthread_join(); unjoinable;  will  auto to release memory, 
    but before this do, should call  pthread_detach(pthread_self()) , to be unjoinable; pthread_self(), return the id
   
    include<pthread.h>

    gcc  add  -lpthread

    pthread_t id;
    int ret;

    ret = pthread_create(&id,NULL,(void*)mouse_doing,NULL);  : create ok return 0, EAGAIN, stand for too many pthread
    EINVAL stand for pthread property illegal;
    while(1)another_function();

    void *pthread_return;
    pthread_join(id,&pthread_return);   wait  until  called id pthread end; to release the hardware sourse, like malloc() and free(); the same effect when call  pthread_detach();


    pthread_detach(pthread_self()) ;

    void pthread_exit(void *retval)    /(NULL)  : not release the memory 
    pthread_exit("now return pthread");
    int pthread_join(pthread_t pid, void **thread_return);  a pthread allow just one join to wait
##exit


    exit(EXIT_FAILUREA);  usually use in  program  middle

    exit(EXIT_SUCCESS);  normally use in program   end
    



















