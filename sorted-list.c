#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"


/*
 *SLCreate creates a new sorted list
 *@param CompareFuncT cf, a user-defined comparator function
 *@param DestructFuncT df, a user-defined detructor function
 */

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df)
{
	
	SortedListPtr list = (SortedListPtr)malloc(sizeof(SortedListPtr));
	list->cf = cf;
	list->df = df;
	list->size=0;
	list->head==NULL;
	
	return list;
}

/*
 * SLInsert inserts a given data item 'newObj' into a SortedList while maintaining the
 *   order and uniqueness of list items.
 * 
 * SLInsert returns 1 if 'newObj' was succesfully inserted
 * SLInsert returns 0 if 'newObj' was not succesfully inserted,
 * such as if it is equal to an item already in the sortedList
 * Data item equality is tested with the user's comparator function 
 * @param SortedListPtr list, a sorted list
 * @param void* newObj, the object to be inserted
 */

int SLInsert(SortedListPtr list, void *newObj)
{	
	int ret = 0;
	int cmp;
	Node tmp,n,prev;

	//check for NULL object
	if(newObj == NULL)
	{
		return 0;
	}
	
	//make new node to store newObj
	n = (Node)malloc(sizeof(Node)+sizeof(newObj));
	n->data = newObj;
	n->next = NULL;
		

	//border case: if the list head is null, place the item there
	if(list->head == NULL)
	{
		
		list->head = n;
		list->size++;
		return 1;
	}
	tmp = list->head;
	cmp = list->cf(n->data,tmp->data);
          //border case: new item is greater than the head of the list
	if(cmp >= 0)
	{
		if(cmp==0){return 0;}
		list->head = n;
		n->next = tmp;
		list->size++;
		return 1;
  	}

	prev = list->head;
	tmp = tmp->next;
	//border case: only 1 item
	if(tmp == NULL)
	{
		prev->next = n;
	}
	while(tmp->next!= NULL)
	{
		cmp = list->cf(n->data,tmp->data);
		//if cmp>0, we should add the new node here
		if(cmp>0)
		{
			prev->next = n;
			n->next = tmp;
			return 1;		
		}	
		if(cmp==0){return 0;}
		tmp = tmp->next;
		prev=prev->next;
		
	}
	
	cmp = list->cf(n->data,tmp->data);
	if(cmp==0){return 0;}
	if(cmp>0)
	{
		prev->next = n;
		n->next = tmp;
		return 1;
	}
	tmp->next=n;
	return 1;
}

/*
 * SLRemove removes 'newObj' from the SortedList in a manner that
 *   maintains list order.
 * returns 1 on success, and 0 on failure.
 * @param SortedListPtr list, a pointer to a sorted list
 * @param void* newObj, a pointer to the object to be removed
 */

int SLRemove(SortedListPtr list, void *newObj)
{

}


/*
 *SLDestroy destroys a SortedList and frees all dynamically-allocated memory
 *@param SortdListPtr list, a pointer to a SortedList
 */

void SLDestroy(SortedListPtr list)
{

}

//-----Sorted List Iterator Functions ------

/*
 * SLCreateIterator creates a SortedListIterator for a specific sorted list.
 *
 * SLCreateIterator returns a non-NULL SortedListIteratorPtr on success.
 * SLCreateIterator returns a NULL SortedListIteratorPtr if on failure
 * @param SortedListPtr list, a pointer to a sorted list
 */

SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{	
	if(list == NULL || list->head == NULL)
	{
		return NULL;
	}
	Node tmp = list->head;
	SortedListIteratorPtr iter = (SortedListIteratorPtr)malloc(
		sizeof(SortedListPtr) + sizeof(tmp));
	iter->curr = tmp;
	return iter;
}


/*
 * SLDestroyIterator destroys a SortedListIterator pointed to by parameter 'iter'
 * and frees any dynamically-allocated memory
 * @param SortedListIteratorPtr iter, a pointer to a SortedListIterator
 */

void SLDestroyIterator(SortedListIteratorPtr iter)
{
	free(iter->curr->data);
	free(iter->curr);
	free(iter);
}

/*
 * SLNextItem returns a pointer to the data associated with the
 *  next item in the SortedListIterator's list
 *
 * SLNextItem should returns a NULL if there are no more items,
 * i.e. if it is already on the last item.
 * @param SortedListIteratorPtr iter, a pointer to a sorted list iterator
 */

void * SLNextItem(SortedListIteratorPtr iter)
{
	Node tmp = iter->curr->next;
	if(tmp==NULL)
	{	
		//show that the iterator has passed the end of the list
		iter->curr = NULL;
		return NULL;
	}
	iter->curr = tmp;
	return tmp->data;
}


/*
 * SLGetItem should return a pointer to the current data item
 * SLGetItem returns a NULL pointer if the SortedListIterator has been advanced
 *  all the way through its list.
 * @param SortedListIteratorPtr iter, a pointer to a sorted list iterator
 */

void * SLGetItem( SortedListIteratorPtr iter )
{
	if(iter->curr==NULL){return NULL;}
	return iter->curr->data;
}

