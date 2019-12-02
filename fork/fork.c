#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (fork())
        printf("PARENT");
    else
        if(fork())
            printf("CHILD 1");
        else
            printf("CHILD 2");
        
        
    
    
    
}