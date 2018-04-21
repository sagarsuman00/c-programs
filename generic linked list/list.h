/* an implementatin of generic linked list. Any user can use the functions of this linked list into their programs directly.
created by : sagar suman
date : 15/04/2018
email : sagarsuman00@gmail.com
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

	void list_init(list * l);
	int list_insert_begin(list *l , void *val, int size );
	int list_insert_end(list * l, void * val, int size);
	int list_delete_begin(list *l);
	int list_delete_at(list *l, int index);
	int list_delete_end(list *l);
	void list_display(list l, void (*display)(void *));
	int list_indexof(list l, void *val, int size);
	void *list_value_at(list l, int index);
	int list_size(list l);
	int list_search(list l, void *val, int size);
	void *list_next(list_iterator *i);
#endif
