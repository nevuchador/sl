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
<<<<<<< HEAD
=======

>>>>>>> c1ed8a4404b90ea7675d53aecb8f196af5070829
	
	//make new node to store newObj
	n = (Node)malloc(sizeof(Node)+sizeof(newObj));
	n->data = newObj;
	n->next = NULL;
		
<<<<<<< HEAD
=======

>>>>>>> c1ed8a4404b90ea7675d53aecb8f196af5070829

	//make new node to store newObj; must free this node if it is not inserted, aka in 0 return.
	n = (Node)malloc(sizeof(Node)+sizeof(newObj));
	n->data = newObj;
	n->next = NULL;
	n->refs = 1;
<<<<<<< HEAD
=======

>>>>>>> c1ed8a4404b90ea7675d53aecb8f196af5070829

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
		if(cmp==0)
		{
			list->df(n->data);
			free(n);
			return 0;
		}
		list->head = n;
		n->next = tmp;
		list->size++;
		return 1;
  	}

	prev = list->head;
	tmp = tmp->next;
	//border case: only 1 item in list, which is at head; new item is less than it
	if(tmp == NULL)
	{
		prev->next = n;
	}
	//Normal case: item's proper place is anywhere else, besides after last item
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
		if(cmp==0)
		{
			list->df(n->data);
			free(n);
			return 0;
		}
		tmp = tmp->next;
		prev=prev->next;
		
	}
	
	cmp = list->cf(n->data,tmp->data);
	if(cmp==0)
	{
		list->df(n->data);
		free(n);
		return 0;
	}
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
	//Create prev and temp pointers.  Prev will point to the previous pointer
	//after the first node has been viewed, and tmp will point to the current node.  
	//These will be Nodes (Node pointers).  Comparisons will be made with the
	//compare func using newObj and the value within the currently-viewed node.
	//Variable "cmp" will be used to store the result for each comparison.
	
	Node prev, temp;
	int cmp;

	//Note to self: don't forget to free node->data and node for each removal!  
	//Don't want to lose memory.

	//Border case: the head is NULL.  Here we return 0 since nothing's been removed.
	if(list->head == NULL)
	{
		return 0;
	}
	temp = list->head;
	cmp = list->cf(newObj, temp->data);
	
	//We run cmp<=0 to indicate that output was either -1 or 0.  If it's
	//-1, that means that our current item is smaller than our target.  
	//If it's 0, that means our current item is our target.  This allows
	//us to leave the program early if we've reached a point in the list 
	//where we will no longer find the target (aka, cmp is -1, all values
	//from this point on will be smaller than the target).  This works because
	//the list is arranged from greatest to smallest. 
	//
	//When we HAVE reached the target, we delink it from the list and subtract
	//1 from its refs field.  If the refs field is equal to 0 at this point, we
	//delete it entirely.   
	
	//Border case: the head is the target.
	if(cmp <= 0)
	{
		if(cmp == 0)
		{
			list->head = list->head->next;
			temp->refs -= 1;
			if(temp->refs <= 0)
			{
				list->df(temp->data);
				free(temp);
			}
			return 1;
		}
		else{
			return 0;
		}
	}

	//Border case: the head is not the target, and it is the only
	//value in the list.
	if(list->head->next == NULL)
	{
		return 0;
	}

	//Normal case: the head is not the target for removal, and 
	//it has a value after that.
	//Iterate through the list and look for the value.
	temp = list->head->next;
	prev = list->head;
	while(temp->next!=  NULL)
	{
		cmp = list->cf(newObj, temp->data);
		if(cmp <= 0)
		{
			if(cmp == 0)
			{	
				prev->next = temp->next;
				temp->refs -= 1;
				if(temp->refs <= 0)
				{	
					list->df(temp->data);
					free(temp);
				}
				return 1;	
			}
			else
			{
				return 0; 
			}
		}
		temp = temp->next;
		prev = prev->next;
	}
	
	//Border case: the last value is the target.
	cmp = list->cf(newObj, temp->data);
	if(cmp <= 0)
	{
		if(cmp == 0)
		{
			prev->next = NULL;
			temp->refs -= 1;
			if(temp->refs <= 0)
			{
				list->df(temp->data);
				free(temp);
			}
			return 1;
		}
		else{
			return 0;
		}
	}
	return 0;
}


/*
 *SLDestroy destroys a SortedList and frees all dynamically-allocated memory
 *@param SortdListPtr list, a pointer to a SortedList
 */

void SLDestroy(SortedListPtr list)
{
	//This function will iterate through a sorted list and free
	//all of the data and nodes involved in a SortedListPtr.  It will a prev
	//and temp pointer.  The prev pointer is used in all cases with
	//more than one node in the actual list.  The temp pointer is used
	//in all cases.
	
	Node curr, next;	

	//Border case: list is NULL.
	if(list->head == NULL)
	{
		free(list);
		return;
	}

	//Border case: list only has one value, the head.
	if(list->head->next == NULL)
	{
		list->df(list->head->next->data);
		free(list->head);
		free(list);
		return;
	}

	//Normal case: the list has two or more values.
	//Start "curr" at the first Node and "next" at
	//the second Node. While next != NULL, iterate through
	//the list, deleting the node at "curr", then moving
	//curr to next, then moving next to next->next.  
	//
	//Once next is NULL, we delete the node at curr (the last node)
	//and return.  
	
	curr = list->head;
	next = list->head->next;
	while(next != NULL)
	{
		list->df(curr->data);
		free(curr);
		curr = next;
		next = next->next;
	}
	
	list->df(curr->data);
	free(curr);
	free(list);
	return;
	

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
	iter->curr->refs += 1;
	return iter;
}


/*
 * SLDestroyIterator destroys a SortedListIterator pointed to by parameter 'iter'
 * and frees any dynamically-allocated memory
 * @param SortedListIteratorPtr iter, a pointer to a SortedListIterator
 */

void SLDestroyIterator(SortedListIteratorPtr iter)
{

	if(iter->curr==NULL)
	{
		return;
	}
	//Before destroying the iterator, we destroy the node it points to
	//if its current references are <=1 (meaning that nothing but
	//the iterator itself is pointing at it)
	if(iter->curr->refs <= 1)
	{
			

	}
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

