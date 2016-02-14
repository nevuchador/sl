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

}


/*
 * SLDestroyIterator destroys a SortedListIterator pointed to by parameter 'iter'
 * and frees any dynamically-allocated memory
 * @param SortedListIteratorPtr iter, a pointer to a SortedListIterator
 */

void SLDestroyIterator(SortedListIteratorPtr iter)
{

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
}


/*
 * SLGetItem should return a pointer to the current data item
 * SLGetItem returns a NULL pointer if the SortedListIterator has been advanced
 *  all the way through its list.
 * @param SortedListIteratorPtr iter, a pointer to a sorted list iterator
 */

void * SLGetItem( SortedListIteratorPtr iter )
{

}

