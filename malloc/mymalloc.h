#include <stdlib.h>
#include<stdio.h>
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

node* start = NULL;;

void InsertNode(int freeOrAlloc, int stradr, int endAdr)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->IsFree = freeOrAlloc;
    newnode->startAdr = stradr;
    newnode->endAdr = endAdr;
    if (start==NULL)
    {
        start=newnode;
    }else
    {
        node* ptr = start;
        while (ptr->next!=NULL)     
            ptr=ptr->next;
        ptr->next=newnode;
        newnode->prev=ptr;        
    }
}

void PrintLL(){
    node* ptr =start;

    while (ptr!=NULL)
    {
        printf("Free - %d \t start - %d \t end - %d\n",ptr->IsFree,ptr->startAdr,ptr->endAdr);
        ptr=ptr->next;
    }
}

void FindFreeSpace(int size){
    node* ptr = start;
    while (ptr!=NULL)
    {
        int x = ptr->endAdr-ptr->startAdr;
        if (ptr->IsFree == 0 && size <= x)
            break;
        ptr=ptr->next;
    }
    
}

char* MyMalloc(int size){
    return &memory[0];
}

void MyFree(){

}


