#include <stdio.h>

unsigned short swap_byte(unsigned short num)
{

    char high = 0, low = 0;

    high = num >> 8;
    low = num & 0xff;
    
    return (low << 8 | high);


}



int main(int argc, const char *argv[])
{
   
    unsigned short byte;

    byte = 0x6789;
    printf("0x%x\n",swap_byte(byte));

    return 0;
}
