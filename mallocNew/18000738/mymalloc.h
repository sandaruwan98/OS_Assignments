#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define SIZE 25000
#define SIZE_FOR_LL 2000

char memory[SIZE];

struct memoryLL
{
    int IsFree;
    int startAdr;
    int endAdr;

    struct memoryLL *next;
    struct memoryLL *prev;
};

typedef struct memoryLL node;

 void CreateStart();
 node *NewNode(int , int , int );
 void PrintList();
 void *MyMalloc(size_t size);
 void freeLL(node *ptr);
 void MyFree(void* p);



