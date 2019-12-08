#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (fork())
        printf("PARENT\n");
    else
        if(fork())
            printf("CHILD 1\n");
        else
            printf("CHILD 2\n");
        
        
    
    
    
}