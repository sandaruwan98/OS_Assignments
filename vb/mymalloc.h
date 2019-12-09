#include <stdio.h>
#include <stddef.h>
char mallocarr[25000] = {'\0'}; 

void *MyMalloc(size_t size);
char *findpiece(size_t size);
void splitpiece(char* p, size_t s);


