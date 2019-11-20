
#include <stdlib.h>
#include "mymalloc.h"

int main()
{
    InsertNodeEnd(0, 0, SIZE - 1);
    MyMalloc(100);
    MyMalloc(10);
    MyMalloc(50);
    MyMalloc(200);
    MyMalloc(5);
    // MyFree(67);
    // MyFree(360);
    
    PrintLL();
    return 0;
}