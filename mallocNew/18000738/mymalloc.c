#include "mymalloc.h"

node *start = NULL;

void CreateStart()
{
    node *tmp = (void *)memory;
    start = (void *)((void *)tmp + (SIZE - SIZE_FOR_LL));
    start->IsFree = 0;
    start->startAdr = 0;
    start->endAdr = SIZE - SIZE_FOR_LL;
    start->next = NULL;
    start->prev = NULL;
}

node *NewNode(int freeOrAlloc, int stradr, int endAdr)
{
    node *ptr = start;
    int st = SIZE - SIZE_FOR_LL;
    int offset = 0;
    while (ptr < (start + SIZE_FOR_LL))
    {
        if ((ptr->startAdr == 0) && (ptr->endAdr == 0))
            break;

        offset += (sizeof(node));
        ptr++;
    }

    node *newnode = (void *)((void *)start + offset);
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->IsFree = freeOrAlloc;
    newnode->startAdr = stradr;
    newnode->endAdr = endAdr;
    return newnode;
}
void PrintList()
{
    node *ptr = start;

    while (ptr != NULL)
    {
        printf("IsFree = %d \t start = %d \t end = %d\n", ptr->IsFree, ptr->startAdr, ptr->endAdr);
        ptr = ptr->next;
    }
}

void *MyMalloc(size_t size)
{

    if (start == NULL)
    {
        CreateStart();
    }
    //find free partition
    size_t node_size;
    node *ptr = start;
    while (ptr != NULL)
    {
        node_size = ptr->endAdr - ptr->startAdr + 1;
        if (ptr->IsFree == 0 && size <= node_size)
            break;
        ptr = ptr->next;
    }

    //allocate memory(change linked list )
    if (ptr == NULL)
    {
        printf("No enough space to allocate\n");
        return NULL;
    }

    if (node_size == size)
    {
        ptr->IsFree = 1;
    }
    else
    {
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
    }

    return (void *)(&memory[ptr->startAdr]);
    return 0;
}

void freeLL(node *ptr)
{
    ptr->endAdr = 0;
    ptr->startAdr = 0;
    ptr->next = NULL;
    ptr->prev = NULL;
}

void MyFree(void *p)
{
    int adr;
    if (((void *)memory <= p) && (p <= (void *)(memory + (SIZE - SIZE_FOR_LL))))
    {
        adr = (int)(p - (void *)memory);
    }
    else
    {
        printf("Invalid  address given to free\n");
        return;
    }

    node *ptr = start;
    while ((ptr->startAdr != adr) && (ptr != NULL))
        ptr = ptr->next;

    if (ptr == NULL)
    {
        printf("Invalid Argument or Given address not allocated\n");
    }
    else
    {
        ptr->IsFree = 0;

        if ((ptr->next != NULL) && (ptr->prev != NULL))
        {
            if ((ptr->next->IsFree == 0) && (ptr->prev->IsFree == 0))
            {
                node *tmpnext = ptr->next;

                ptr->prev->endAdr = tmpnext->endAdr;
                ptr->prev->next = tmpnext->next;
                if (tmpnext->next != NULL)
                    tmpnext->next->prev = ptr->prev;
                freeLL(ptr);
                freeLL(tmpnext);
            }
        }

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
                freeLL(ptr);
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
                freeLL(ptr);
            }
        }
    }
}

int main()
{

    int *p = (int *)MyMalloc(564);
    int *q = (int *)MyMalloc(15000);
    // float *r = (float *)MyMalloc(45000);
    char *w = (char *)MyMalloc(500);

    // MyMalloc(5);
    // MyFree(10);

    MyFree(q);
    // int *j = (int *)MyMalloc(3);
    int *j = (int *)MyMalloc(6000);

    // MyFree(r);
    // MyFree(p);
    // MyMalloc(300);
    PrintList();
    return 0;
}