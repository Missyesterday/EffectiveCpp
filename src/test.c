#include <stdio.h>

int main()
{
    union
    {
        short val;
        char val2[sizeof(short)];
    } test;
    
    test.val = 0x0102;
    printf("%d\n", test.val2[0]);
    return 0;
}



