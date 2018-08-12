#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
  /* FIXME: you must write this */
    lst->firstLink = malloc(sizeof(struct DLink));
    lst->lastLink = malloc(sizeof(struct DLink));
    
    lst->firstLink->next = lst->lastLink;
    lst->firstLink->prev = NULL;
    lst->lastLink->prev = lst->firstLink;
    lst->lastLink->next = NULL;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */
    struct DLink *new = malloc(sizeof(struct DLink));
    assert(new !=0);
    new->value = v;
    new->prev = l->prev;
    new->prev->next = new;
    new->next = l;
    l->prev = new;
    
    lst->size++;

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
    /* FIXME: you must write this */
    
    _addLinkBefore(lst, lst->firstLink->next, e);
    
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
	/* FIXME: you must write this */
   
    
    _addLinkBefore(lst, lst->lastLink, e);
    /*
    struct DLink *new = malloc(sizeof(struct DLink));
    struct DLink *temp = malloc(sizeof(struct DLink));

    
    new->value = e;
    temp = lst->lastLink;
    new->prev = temp;
    lst->firstLink = new;
    lst->size++;
    */
    
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
    
	return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
    /* FIXME: you must write this */
    l->prev->next = l->next->prev;
    free(l);
};

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
    struct DLink *temp = malloc(sizeof(struct DLink));
	struct DLink *temp2 = malloc(sizeof(struct DLink));
    temp = lst->firstLink->next;
    temp2 = lst->firstLink;
    free(temp2);
    lst->firstLink = temp;
    lst->size--;

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	/* FIXME: you must write this */
    struct DLink *temp, *temp2;
    temp = lst->lastLink->next;
    temp2 = lst->lastLink;
    free(temp2);
    lst->lastLink = temp;
    lst->size--;

}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
    if (lst->firstLink == lst->lastLink)
        return(1);
    else return 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */
    struct DLink *temp = malloc(sizeof(struct DLink));
    while (temp != NULL)
        printf("%d", temp->value);
    temp = temp->next;

}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	/* FIXME: you must write this */
    struct DLink *new = malloc(sizeof(struct DLink));
    new->value = v;
    new->next = lst->firstLink;
    new->prev = NULL;
    lst->firstLink = new;
    lst->size++;

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
    struct DLink *temp = malloc(sizeof(struct DLink));
    while (temp != NULL){
        if (temp->value == e)
            return 1;
        else temp = temp->next;
            }
	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
    struct DLink *temp = malloc(sizeof(struct DLink));
    while (temp != NULL){
        if (temp->value == e){
            temp->next->prev = temp->prev->next;
            free(temp);
            printf("Link removed!");
            lst->size--;
        }
        else temp = temp->next;
        }
    
}
