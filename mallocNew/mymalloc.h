#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define SIZE 25000
#define SIZE_FOR_LL 500

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


void CreateStart(){
    node *tmp = (void*)memory;
    start = (void*)((void*)tmp+(SIZE-SIZE_FOR_LL));
    start->IsFree=0;
    start->startAdr=0;
    start->endAdr=SIZE-SIZE_FOR_LL;
    start->next=NULL;
    start->prev=NULL;
}




node *NewNode(int freeOrAlloc, int stradr, int endAdr)
{
	node *ptr=start;
    int st= SIZE-SIZE_FOR_LL;
    int offset = 0;
    while (ptr<(start+SIZE_FOR_LL))
    {
        if ((ptr->startAdr==0) && (ptr->endAdr==0))
            break;
            
        offset+=(sizeof(node));
        ptr++;
    }
    
    
    
    node *newnode = (void*)( (void*)start+offset);
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->IsFree = freeOrAlloc;
    newnode->startAdr = stradr;
    newnode->endAdr = endAdr;
    return newnode;
}
// ////////////////////////
// void InsertNodeEnd(int freeOrAlloc, int stradr, int endAdr)
// {

//     node *newnode = NewNode(freeOrAlloc, stradr, endAdr);
//     if (start == NULL)
//     {
//         start = newnode;
//     }
//     else
//     {
//         node *ptr = start;
//         while (ptr->next != NULL)
//             ptr = ptr->next;
//         ptr->next = newnode;
//         newnode->prev = ptr;
//     }
// }
/////////////////////////
void PrintList()
{
    node *ptr = start;

    while (ptr != NULL)
    {
        printf("IsFree = %d \t start = %d \t end = %d\n", ptr->IsFree, ptr->startAdr, ptr->endAdr);
        ptr = ptr->next;
    }
}



