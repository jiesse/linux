#c study

##malloc

    void *malloc(size_t size) : int *p = (int *)malloc(sizeof(int)*num);
    free(p) : p comment can not change; p = NULL;
    p = realloc(p,256)
    memory lose : not free(p); wild point : the memory had lease, but point still point the memory ;
    the memory block : head point head; creat a loop;

##redicretion

    command <filename >file
    cat < filename : ls only output; not use keyboard; ls > filename
    command >>filename : will not overwrite file;
