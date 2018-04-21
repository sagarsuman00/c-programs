/*
 * @author sagar
 * @date 4/15/2018
 * 
 * generic single linked list
 */


#include "list.h"

/* function to initialize the linked list to default value */

void list_init(list *l )
{
	l -> head = l -> tail  = NULL;
	l -> list_size = 0;
}

/* function to insert a node at the begining of the list*/

int list_insert_begin(list * l, void * val, int size)
{
	list_node_p n = (list_node_p)malloc(sizeof(list_node));
	n->value = malloc(size);
	n->next = NULL;
	memset(n->value, 0, size);
	memcpy(n->value, val, size);


	if(l->head == NULL) 
	{
		l->head = l -> tail =  n;
		l->list_size = 1;
		return 1;

	}
	else
	{

		n -> next = l -> head;
		l -> head  = n;
		l -> list_size += 1;
		return 1;
	}



	return 0;
}

/* function to insert a node at the end of the list */

int list_insert_end(list * l, void * val, int size)
{
	list_node_p n = (list_node_p)malloc(sizeof(list_node));
	n->value = malloc(size);
	n->next = NULL;
	memset(n->value, 0, size);
	memcpy(n->value, val, size);


	if(l->head == NULL) 
	{
		l->head = l -> tail = n;
	}
	else
	{
		l->tail -> next = n;
		l->tail = n;

	}

	l->list_size +=1;



	return 0;
}

/* function to delete a node from the begining of the list */

int list_delete_begin(list *l)
{
	if(l->head == NULL)
	{
		return 0;
	}
	else
	{
		list_node_p temp = l->head;
		l->head = l->head -> next;
		free(temp -> value);
		free(temp);
		if(l->list_size == 1)
		{
			l->tail = NULL;
		}
		l->list_size --;
	}
	return 1;
}

/*function to delete a node at specified index*/

int list_delete_at(list *l, int index)
{
	if(l->head == NULL)
	{
		return -1;
	}
	else if(index >= l-> list_size)
	{
		return -2;
	}
	else if(index == l->list_size - 1)
	{
		return list_delete_end(l);
	}
	else
	{
		int i = 0;
		list_node_p temp = l->head, temp2 = NULL;
		while(i < index)
		{
			temp2 = temp;
			temp = temp -> next;
		}


}
/* function to delete a node from the end of the list */

int list_delete_end(list *l)
{
	if(l->head == NULL)
	{
		return 0;
	}
	else if(l->head == l-> tail)
	{
		free(l->head->value);
		free(l->head);
		l->head = l->tail = NULL;
		l->list_size --;
	}
	else
	{
		list_node_p temp = l->head, temp2;
		while(temp -> next != NULL)
		{
			temp2 = temp;
			temp = temp -> next;
		}

		free(temp->value);
		free(temp);
		temp2->next = NULL;
		l->tail = temp2;
		l->list_size --;
		return 1;
	}
}

/* function to display the elements from the list */

void list_display(list l, void (*display)(void *))
{
	if(l.head == NULL)
	{
		printf("list is empty\n");
	}
	list_node_p temp = l.head;
	while(temp != NULL)
	{
		display(temp->value);
		temp = temp -> next;

	}
}

/* funtion to return the index of an object from the list */

int list_indexof(list l, void *val, int size)
{
	if(l.list_size == 0)
		return -1;
	list_node_p temp = l.head;
	int i = -1;
	while(++i < l.list_size)
	{
		printf("%s\n", (char *)temp->value);
		if(memcmp(val, temp->value, size) == 0)
		{
			return i;
		}
		temp = temp->next;
	}

	return -2;
}
/* function to return object from the list at a specified position */

void * list_value_at(list l, int index)
{
	if(index >= l.list_size || index < 0)
		return NULL;
	else
	{
		int i = 0;
		list_node_p temp = l.head;
		while(i++ < index)
		{
			temp = temp -> next;
		}
		return temp->value;
	}
}
/* function to return size of the list */
int list_size(list l)
{
	return l.list_size;
}

/* function to search an element from the list */
int list_search(list l, void *val, int size)
{
	list_node_p temp = l.head;
	int i = 0;
	while(temp != NULL)
	{
		if(memcmp(val, temp->value, size)== 0)
			return i;
		temp = temp -> next;
		i++;
	}
	return -1;
}
