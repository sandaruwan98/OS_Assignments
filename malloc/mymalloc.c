
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
    MyFree(100);
    MyFree(160);
    MyFree(110);
    MyMalloc(300);
    PrintLL();
    return 0;
}