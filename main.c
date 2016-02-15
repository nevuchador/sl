#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"

int main(int argc, char** argv)
{	
	int compareInt(void* a,void* b)	
	{	
		int x = *(int*)a;
		int y = *(int*)b;
		if(x==y){return 0;}
		if(x>y){return 1;}
		return -1;
	}

	void destroyInt(void* a)
	{
		
	}
	int* x = malloc(sizeof(int));
	int* y = malloc(sizeof(int));
	*x=5;
	*y=8;
	int (*CompareFuncT)( void *, void * ) = &compareInt;
	void (*DestructFuncT)( void * ) =&destroyInt;
	SortedListPtr sl= SLCreate(CompareFuncT,DestructFuncT);
	SLInsert(sl,x);
	SLInsert(sl,y);
	printf("%d",*(int*)sl->head->data);
	return 0;
}
