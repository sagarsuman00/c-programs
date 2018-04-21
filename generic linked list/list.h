/*
 * @author sagar
 * @date 4/15/2018 * 
 * header file of single generic linked list
 */

#ifndef __LIST_H
	#define __LIST_H
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	typedef struct list_node * list_node_p;
	typedef struct list_node list_node;
	typedef struct list list;
	typedef struct list_iterator list_iterator;

	struct list_node
	{
		void *value;
		struct list_node *next;
	};

	
	struct list
	{
		list_node_p head;
		list_node_p tail;
		int list_size;
	};
	
	struct list_iterator
	{
		list_node_p current;
	};
/* initialize a given list variable with initial values
arguments: pointer to list
return: none
*/

	void list_init(list * l);


/* insert a value at the begining of the linked list 
arguments: pointer to list, pointer to the data, size of the data
return: if successfull 1 otherwise -1
*/
	int list_insert_begin(list *l , void *val, int size );


/* insert a value at the end of the linked list 
arguments: pointer to list, pointer to the data, size of the data
return: if successfull 1 otherwise -1
*/
	int list_insert_end(list * l, void * val, int size);



/* delete a value from the begining of the linked list 
arguments: pointer to list
return: if successfull 1 otherwise 0
*/

	int list_delete_begin(list *l);



/* delete a value from the specific index of the linked list 
arguments: pointer to list, index 
return: if successfull 1 otherwise 0
*/
	int list_delete_at(list *l, int index);



/* delete a value from the end of the linked list 
arguments: pointer to list
return: if successfull 1 otherwise 0
*/
	int list_delete_end(list *l);



/* display all elements of the list. To display a display function must be provided to print the values
arguments: list, pointer to the display function
return:	none
*/
	void list_display(list l, void (*display)(void *));



/* return the index of a value in the list
arguments: list, pointer to element to be search, size of the element
return:	if not present -1, otherwise the index of the element
*/
	int list_indexof(list l, void *val, int size);



/* return pointer to the element present at specified index
arguments: list, index
return: if index is invalid, or list is empty then NULL
	otherwise pointer to the element
*/
	void *list_value_at(list l, int index);



/* return size of the list
arguments: list
return:	size of the list
*/
	int list_size(list l);


/* searches an element in the list
arguments: list, pointer to element, size of element
return: if present, 1
	otherwise 0
*/
	int list_search(list l, void *val, int size);


/*this function is used to traverse elements one by one
arguments: pointer to list_iterator of a list
return: on each call returns pointer of next element
	return NULL when end of the list reached, or any error(iterator not assigned to a list)
	
	void *list_next(list_iterator *i);
*/
#endif
