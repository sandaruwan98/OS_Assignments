#include "mymalloc.h"
#include "mymalloc.c"

int main()
{
    InsertNodeEnd(0, 0, SIZE - 1);
    printf("%p\n" ,MyMalloc(100));
    printf("%p\n" ,MyMalloc(10));
    printf("%p\n" ,MyMalloc(50));
    printf("%p\n" ,MyMalloc(200));
    
    MyMalloc(10);
    MyMalloc(50);
    MyMalloc(200);
    // MyMalloc(5);
    // MyFree(100);
    // MyFree(160);
    MyFree(160);
    // MyMalloc(300);
    PrintLL();
    return 0;
}