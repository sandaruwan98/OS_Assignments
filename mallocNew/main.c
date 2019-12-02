// #include "mymalloc.h"
#include "mymalloc.c"

int main()
{

    int *p = (int *)MyMalloc(500);
    int *q = (int *)MyMalloc(50);
    int *r = (int *)MyMalloc(200);
    // MyMalloc(5);
    // MyFree(10);

    MyFree(p);
    // MyFree(r);
    // MyFree(p);
    // MyMalloc(300);
    PrintList();

    return 0;
}
