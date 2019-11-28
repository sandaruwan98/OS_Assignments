#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define SIZE 25000

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

node *start = NULL;
;

node *NewNode(int freeOrAlloc, int stradr, int endAdr)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->IsFree = freeOrAlloc;
    newnode->startAdr = stradr;
    newnode->endAdr = endAdr;
    return newnode;
}

void InsertNodeEnd(int freeOrAlloc, int stradr, int endAdr)
{

    node *newnode = NewNode(freeOrAlloc, stradr, endAdr);
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        node *ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void PrintLL()
{
    node *ptr = start;

    while (ptr != NULL)
    {
        printf("Free - %d \t start - %d \t end - %d\n", ptr->IsFree, ptr->startAdr, ptr->endAdr);
        ptr = ptr->next;
    }
}



