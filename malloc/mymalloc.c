
#include <stdlib.h>
#include "mymalloc.h"

void MyMalloc(int size)
{
    //find free partition
    node *ptr = start;
    while (ptr != NULL)
    {
        int x = ptr->endAdr - ptr->startAdr + 1;
        if (ptr->IsFree == 0 && size <= x)
            break;
        ptr = ptr->next;
    }
    //allocate memory(change linked list )
    ptr->IsFree = 1;
    int end = ptr->endAdr;
    int y = ptr->startAdr + size - 1;
    ptr->endAdr = y;
    node *NN = NewNode(0, y + 1, end);

    NN->next = ptr->next;
    NN->prev = ptr;
    if (ptr->next != NULL)
        ptr->next->prev = NN;
    ptr->next = NN;

    // return &memory[ptr->startAdr];
}

void MyFree(int adr)
{
    node *ptr = start;
    while ((ptr->startAdr != adr) && (ptr != NULL))
        ptr = ptr->next;
    if (ptr == NULL)
    {
        printf("Invalid Argument or Given address not allocated");
    }
    else
    {
        ptr->IsFree = 0;

        if (ptr->next != NULL)
        {
            //if Before node is also free we have to merge them
            if (ptr->next->IsFree == 0)
            {
                ptr->next->startAdr = ptr->startAdr;
                if (ptr == start)
                {
                    ptr->next->prev = NULL;
                    start = ptr->next;
                }
                else
                {
                    ptr->next->prev = ptr->prev;
                    ptr->prev->next = ptr->next;
                }
                free(ptr);
            }
        }
         if (ptr->prev != NULL)
        {
            if (ptr->prev->IsFree == 0)
            {
                ptr->prev->endAdr = ptr->endAdr;

                ptr->prev->next = ptr->next;
                if (ptr->next != NULL)
                    ptr->next->prev = ptr->prev; 
                free(ptr);
            }
        }
        if ((ptr->next != NULL) && (ptr->prev != NULL))
        {
            if ((ptr->next->IsFree == 0) && (ptr->prev->IsFree == 0))
            {
                node *tmpnext = ptr->next;

                ptr->prev->endAdr = tmpnext->endAdr;
                ptr->prev->next = tmpnext->next;
                if (tmpnext->next != NULL)
                    tmpnext->next->prev = ptr->prev;

                free(ptr);
                free(tmpnext);
            }
        }
    }
}



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