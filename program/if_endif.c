#include <stdio.h>
#define DEBUG  
#define M  



int main(int argc, const char *argv[])
{
    #ifdef DEBUG    
    printf("DEBUG define\n");
    #endif  
    #ifdef M
    printf("M is  define \n");
    #else
    printf("M not define\n");
    #endif
    return 0;
}
