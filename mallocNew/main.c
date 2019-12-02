// #include "mymalloc.h"
#include "mymalloc.c"
#include<stdio.h>

int main()
{

    int *p = (int *)MyMalloc(564);
    int *q = (int *)MyMalloc(15000);
    float *r = (float *)MyMalloc(45000);
    char *w = (char *)MyMalloc(500);

    // MyMalloc(5);
    // MyFree(10);

    // MyFree(q);
    // int *j = (int *)MyMalloc(3);
    int *j = (int *)MyMalloc(6000);

    // MyFree(r);
    // MyFree(p);
    // MyMalloc(300);
    PrintList();
    return 0;
}