#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"


int compareInt(void* a,void* b)	
{	
	int x = *(int*)a;
	int y = *(int*)b;
	printf("comparison: %d and %d!\n", *(int*)a, *(int*)b);
	if(x==y){printf("comp return 0!\n");return 0;}
	if(x>y){printf("comp return 1!\n");return 1;}
	printf("comp return -1!\n");
	return -1;
}


void destroyInt(void* a)
{
	printf("initiate destroyInt!\n");
//	int* x = (int*)a;
//	free(x);
	return;
}

int compareChar(void* a,void* b)	
{	
	char x = *(char*)a;
	char y = *(char*)b;
	if(x==y){return 0;}
	if(x>y){return 1;}
	
	return -1;
}

void destroyChar(void* a)
{
	char* x = (char*)a;
	free(x);
}

void intTest()
{
	int* x = malloc(sizeof(int));
	int* y = malloc(sizeof(int));
	int* z = malloc(sizeof(int));
	int* a = malloc(sizeof(int));
	int* b = malloc(sizeof(int));
	int* c = malloc(sizeof(int));
	int* d = malloc(sizeof(int));
	int* e = malloc(sizeof(int));
//	int* f = malloc(sizeof(int));
	*x=5;
	*y=8;
	*z=1;
	*a=3;
	*b=4;
	*c=7;
	*d=6;
	*e=2;
//	*f=5;

	
	int (*CompareFuncT)(void*,void*) = &compareInt;
	void (*DestructFuncT)(void*) = &destroyInt;

	SortedListPtr sl= SLCreate(CompareFuncT,DestructFuncT);
		

	SLInsert(sl,x);
	SLInsert(sl,y);
	SLInsert(sl,z);
	SLInsert(sl,a);
	SLInsert(sl,b);
	SLInsert(sl,c);
	SLInsert(sl,d);
	SLInsert(sl,e);
//	SLInsert(sl,f);

	SortedListIteratorPtr iter = SLCreateIterator(sl);
	printf("Here is the sorted list of integers:\n");
	while(iter->curr!=NULL)
	{
		printf("%d\n",*(int*)iter->curr->data);
		SLNextItem(iter);
	}
	SLDestroyIterator(iter);

	printf("\nNow we remove the 7, 3, and 8:\n");

	SLRemove(sl,c);
	SLRemove(sl,a);
	SLRemove(sl,y);	
	SortedListIteratorPtr iter1 = SLCreateIterator(sl);
	printf("Here is the sorted list of integers:\n");
	while(iter1->curr!=NULL)
	{
		printf("%d\n",*(int*)iter1->curr->data);
		SLNextItem(iter1);
	}
	SLDestroyIterator(iter1);
}


int main(int argc, char** argv)
{	
	intTest();
	return 0;
}
