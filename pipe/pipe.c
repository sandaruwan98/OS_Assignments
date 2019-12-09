#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd[2];
    char buf[30];
    
    if (pipe(fd) < 0)
    {
        exit(1);
    }
    
    if (fork())
    {
        write(fd[1],"Hello From Parent\0",18);
    }else
    {
        read(fd[0],buf,20);
        printf("%s\n",buf);
    }
    
    
    
    
}