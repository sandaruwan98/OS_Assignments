
#include <stdlib.h>
#include "mymalloc.h"


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
        node *ptr = start;
        while (ptr != NULL)
        {
            size_t x = ptr->endAdr - ptr->startAdr + 1;
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
    
    return (void*)(memory[ptr->startAdr]);
    return 0;
}

void freeLL(node *ptr){
    ptr->endAdr=0;
    ptr->startAdr=0;
    ptr->next=NULL;
    ptr->prev=NULL;

}


void MyFree(void* p)
{

    node *ptr ;
     if(((void*)memory<=p)&&(p<=(void*)(memory+(SIZE-SIZE_FOR_LL)))){
         ptr = (void*)p;
     }

    if (ptr == NULL)
    {
        printf("Invalid Argument or Given address not allocated");
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




// void pp(node *start)
// {

//     printf("%d %d %d\n", start->IsFree, start->startAdr, start->endAdr);
// }

// int main()
// {
//     // InsertNodeEnd(0, 0, SIZE - 1);
//     // printf("%p\n" ,MyMalloc(100));
//     // printf("%p\n" ,MyMalloc(10));
//     // printf("%p\n" ,MyMalloc(50));
//     // printf("%p\n" ,MyMalloc(200));

//     int *p = (int*) MyMalloc(10);
//     int *q = (int*)MyMalloc(50);
//     int *r = (int*)MyMalloc(200);
//     // MyMalloc(5);
//     // MyFree(10);


//     // MyFree(p);
//     MyFree(q);
//     // MyFree(r);
//     // MyMalloc(300);
//     PrintList();

//     // printf("%c", memory[0]);
//     //printf("%p\n", p);
// //    printf("%p\n", );
//     // printf("%p\n", &memory[3]);
//     // printf("%p\n", &memory[4]);
//     // printf("%p\n", &memory[5]);
//     // printf("%p\n", &memory[6]);
//     // printf("%p\n", &memory[SIZE]);
//     // printf("%s\n", &memory[24500]);

//     // CreateStart();
    
//     // char *p = memory;
//     // node *v = NgvfdsaewNode(1, 309, 400);
//     // printf("%p\n", *(&memory[24500]));
//     // printf("%p\n", &memory[24532]);
//     // printf("%d\n", memory[24520]);
//     // printf("%s\n", memory[24564]);
//     // printf("%s\n", memory[24565]);
//     // memory[24508] = 4;
//     // printf("%c\n", (p));
//     // PrintLL();

//     return 0;
// }
