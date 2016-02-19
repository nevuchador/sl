#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorted-list.h"


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
	int* b = (int*)a;
	free(b);
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

int compareString(void *s1, void *s2){
	char *a = s1;
	char *b = s2;
	double cmp = strcmp(a, b);
	if(cmp<0){return -1;}
	if(cmp==0){return 0;}
	return 1;
}

void destroyString(void* a)
{
	char* x = (char*)a;
	free(x);
}

struct _Student{
	char* name;
	double gpa;
};
typedef struct _Student* Student; 

int compareStudent(void* a, void* b)
{
	Student s1 = (Student)a;
	Student s2 = (Student)b;
	if(s1->gpa > s2->gpa){return 1;}
	if(s1->gpa == s2->gpa){return 0;}
	return -1;
}

void destroyStudent(void* a)
{
	Student s = (Student)a;
	free(s);
}
void intTest()
{	
	printf("\n\n\nTesting integers: First, insert 1-8, in random order\n");
		printf("Included are some repeated inserts: 8, 1 , and 5.\n\n");
	int* x = malloc(sizeof(int*));
	int* y = malloc(sizeof(int*));
	int* z = malloc(sizeof(int*));
	int* a = malloc(sizeof(int*));
	int* b = malloc(sizeof(int*));
	int* c = malloc(sizeof(int*));
	int* d = malloc(sizeof(int*));
	int* e = malloc(sizeof(int*));
	int* f = malloc(sizeof(int*));
	int* g = malloc(sizeof(int*));
	int* h = malloc(sizeof(int*));

	*x=5;
	*y=8;
	*z=1;
	*a=3;
	*b=4;
	*c=7;
	*d=6;
	*e=2;
	*f=5;
	*g=1;
	*h=8;

	
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
	SLInsert(sl,f);
	SLInsert(sl,g);
	SLInsert(sl,h);

	SortedListIteratorPtr iter = SLCreateIterator(sl);
	printf("Here is the sorted list of integers - Success!\n");
	while(iter->curr!=NULL)
	{
		printf("%d - ",*(int*)iter->curr->data);
		SLNextItem(iter);
	}
	SLDestroyIterator(iter);

	printf("\nNow we remove the 1,2,3, and 8\n");

	SLRemove(sl,e);
	SLRemove(sl,z);
	SLRemove(sl,a);
	SLRemove(sl,y);
	SortedListIteratorPtr iter1 = SLCreateIterator(sl);
	printf("Here is the sorted list of integers - Success!\n");
	while(iter1->curr!=NULL)
	{
		printf("%d - ",*(int*)iter1->curr->data);
		
		SLNextItem(iter1);
	}
	printf("\n");
	SLDestroyIterator(iter1);
	SLDestroy(sl);
	printf("\n");
}

void charTest()
{	
	printf("\n\n\nTesting chars: First, insert a-h, in random order\n");
		printf("Included are some repeated inserts: a, f , and h.\n\n");
	int* a = malloc(sizeof(char*));
	int* b = malloc(sizeof(char*));
	int* c = malloc(sizeof(char*));
	int* d = malloc(sizeof(char*));
	int* e = malloc(sizeof(char*));
	int* f = malloc(sizeof(char*));
	int* g = malloc(sizeof(char*));
	int* h = malloc(sizeof(char*));
	int* i = malloc(sizeof(char*));
	int* j = malloc(sizeof(char*));
	int* k = malloc(sizeof(char*));

	*a='a';
	*b='b';
	*c='c';
	*d='d';
	*e='e';
	*f='f';
	*g='g';
	*h='h';
	*i='a';
	*j='f';
	*k='h';

	
	int (*CompareFuncT)(void*,void*) = &compareChar;
	void (*DestructFuncT)(void*) = &destroyChar;

	SortedListPtr sl= SLCreate(CompareFuncT,DestructFuncT);
		

	SLInsert(sl,a);
	SLInsert(sl,b);
	SLInsert(sl,c);
	SLInsert(sl,d);
	SLInsert(sl,e);
	SLInsert(sl,f);
	SLInsert(sl,g);
	SLInsert(sl,h);
	SLInsert(sl,i);
	SLInsert(sl,j);
	SLInsert(sl,k);

	SortedListIteratorPtr iter = SLCreateIterator(sl);
	printf("Here is the sorted list of characters - Success!\n");
	while(iter->curr!=NULL)
	{
		printf("%c - ",*(char*)iter->curr->data);
		SLNextItem(iter);
	}
	SLDestroyIterator(iter);

	printf("\nNow we remove the a,b,c and h\n");

	SLRemove(sl,a);
	SLRemove(sl,b);
	SLRemove(sl,c);
	SLRemove(sl,h);
	SortedListIteratorPtr iter1 = SLCreateIterator(sl);
	printf("Here is the sorted list of characters - Success!\n");
	while(iter1->curr!=NULL)
	{
		printf("%c - ",*(char*)iter1->curr->data);
		
		SLNextItem(iter1);
	}
	printf("\n");
	SLDestroyIterator(iter1);
	SLDestroy(sl);
	printf("\n\n");
}
void stringTest()
{	
	printf("\n\n\nTesting strings: We will sort the following sentence:\n");
		printf("Did you ever hear the tragedy of Darth Plagueis the Wise?\n\n");
	char* a = malloc(sizeof(char*)*10);
	char* b = malloc(sizeof(char*)*10);
	char* c = malloc(sizeof(char*)*10);
	char* d = malloc(sizeof(char*)*10);
	char* e = malloc(sizeof(char*)*10);
	char* f = malloc(sizeof(char*)*10);
	char* g = malloc(sizeof(char*)*10);
	char* h = malloc(sizeof(char*)*10);
	char* i = malloc(sizeof(char*)*10);
	char* j = malloc(sizeof(char*)*10);
	char* k = malloc(sizeof(char*)*10);

	strcpy(a,"did");
	strcpy(b,"you");
	strcpy(c,"ever");
	strcpy(d,"hear");
	strcpy(e,"the");
	strcpy(f,"tragedy");
	strcpy(g,"of");
	strcpy(h,"darth");
	strcpy(i,"plagueis");
	strcpy(j,"the");
	strcpy(k,"wise");

	
	int (*CompareFuncT)(void*,void*) = &compareString;
	void (*DestructFuncT)(void*) = &destroyString;

	SortedListPtr sl= SLCreate(CompareFuncT,DestructFuncT);
		

	SLInsert(sl,a);
	SLInsert(sl,b);
	SLInsert(sl,c);
	SLInsert(sl,d);
	SLInsert(sl,e);
	SLInsert(sl,f);
	SLInsert(sl,g);
	SLInsert(sl,h);
	SLInsert(sl,i);
	//SLInsert(sl,j);
	SLInsert(sl,k);

	SortedListIteratorPtr iter = SLCreateIterator(sl);
	printf("Here is the sorted list of words - Success!\n");
	while(iter->curr!=NULL)
	{
		printf("%s - ",(char*)iter->curr->data);
		SLNextItem(iter);
	}
	SLDestroyIterator(iter);

	printf("\nNow we remove some words...\n");
	
	SLRemove(sl,a);
	SLRemove(sl,d);
	SLRemove(sl,c);
	SLRemove(sl,e);
	SLRemove(sl,f);
	SLRemove(sl,g);
	SLRemove(sl,h);
	SortedListIteratorPtr iter1 = SLCreateIterator(sl);
	printf("Here is the sorted list of words - Success!\n");
	while(iter1->curr!=NULL)
	{
		printf("%s - ",(char*)iter1->curr->data);
		
		SLNextItem(iter1);
	}
	printf("\n");
	SLDestroyIterator(iter1);
	SLDestroy(sl);
}
void studentTest()
{	
	printf("\n\n\nTesting students: We will have 4 students:\n");
		printf("Student\tGPA\nJaime\t2.4\nCersei\t3.3\nTyrion\t3.99\nTywin\t3.78\n\n");
	Student jamie = malloc(sizeof(Student));
	jamie->name="Jaime";
	jamie->gpa=2.41;
	Student cersei = malloc(sizeof(Student));
	cersei->name="Cersei";
	cersei->gpa=3.35;
	Student tyrion = malloc(sizeof(Student));
	tyrion->name="Tyrion";
	tyrion->gpa=3.99;
	Student tywin = malloc(sizeof(Student));
	tywin->name="Tywin";
	tywin->gpa=3.78;

	
	int (*CompareFuncT)(void*,void*) = &compareStudent;
	void (*DestructFuncT)(void*) = &destroyStudent;
	
	SortedListPtr sl= SLCreate(CompareFuncT,DestructFuncT);

		
	SLInsert(sl,jamie);
	SLInsert(sl,cersei);
	SLInsert(sl,tyrion);
	SLInsert(sl,tywin);

	SortedListIteratorPtr iter = SLCreateIterator(sl);
	printf("Here is the sorted list of students - Success!\n");
	while(iter->curr!=NULL)
	{
		Student current = (Student)iter->curr->data;
		char* currName = current->name;
		double currGPA = current->gpa;
		printf("%s\t%g\n ",currName,currGPA);
		SLNextItem(iter);
	}
	SLDestroyIterator(iter);
	printf("\n");
	
	printf("Unfortunately, Tyrion and Tywin have left school (spoilers!)\n");
	
	SLRemove(sl,tyrion);
	SLRemove(sl,tywin);

	SortedListIteratorPtr iter1 = SLCreateIterator(sl);
	printf("Here is the sorted list of words - Success!\n");
	while(iter1->curr!=NULL)
	{
		Student current = (Student)iter1->curr->data;
		char* currName = current->name;
		double currGPA = current->gpa;
		printf("%s\t%g\n ",currName,currGPA);
		SLNextItem(iter1);
	}
	printf("\n");
	SLDestroyIterator(iter1);
	SLDestroy(sl);
	printf("\n\n");
}
int main(int argc, char** argv)
{	
	intTest();
	charTest();
	stringTest();
	studentTest();

	return 0;
}
