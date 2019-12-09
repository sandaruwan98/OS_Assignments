#include <stdio.h>
#include <stdbool.h>

#include "mymalloc.h"

//char mallocarr[25000] = {'\0'};  // (char = 1byte)

char *first = mallocarr;

char freeflag = '0';
char allocate = '1';

char *findpiece(size_t size){
		
	char *apply;
	apply = first;
	
	int num = 0;
	
	char *next = NULL;
	
	while(true)
	{
		num = *(int *)(apply+1);
		
		if(*apply == freeflag && num >= size + 5)
		{
			return apply;
		}
		else if(!apply)
		{
			return NULL;
		}
		else
		{
			if( apply + num + size >= mallocarr + 24999)
			{
				printf("Memory is Overflow\n");
				return NULL;
			}
			apply = apply + num;
		}
	}
	
	return apply;
}

void splitpiece(char* p, size_t s){
	char* temp;
	int p_size = *(int *)(p+1);
	
	p_size = p_size - s - 5;
	
	temp = p + s + 5;
	
	*temp = freeflag;
	
	*(int *)(temp + 1) = p_size;
	*(int *)(p + 1) = s+5;
	*p = allocate;
}

void MyFree(){
	
	
	
}

void *MyMalloc(size_t size){
	if(size <= 0)
	
	{
		return NULL;
	}
	
	if(*first == NULL)//if !*first
	{
		*first = freeflag;
		*(int *)(first+1) = 24999 - 5;
	}
	
	size_t s = size;
	
	char* p = findpiece(s);
	
	if(p)
	{
		if(*(int *)(p+1) >= size)
		{
			splitpiece(p,s);
		}
	}
	else{
		 	return NULL;
		}
	
	return (void*)p;
}




