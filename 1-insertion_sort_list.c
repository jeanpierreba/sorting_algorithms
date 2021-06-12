#include "sort.h"

void swap(listint_t *to_right, listint_t **list);

/**
 * swap - change the place of two nodes
 * @to_right: node to move to the previous position in the list
 */

void swap(listint_t *to_right, listint_t **list)
{
	listint_t *gparent, *parent, *child, *gchild;

/* Input: gparent child(to_right) parent gchild */
/* Objetive: gparent parent child gchild */


/* 1. Save the reference of all the nodes involved*/
	gparent = to_right->prev;
	child = to_right;
	parent = to_right->next;
	gchild = to_right->next->next;

/* 2. Assign a child to each parent */
	if (gparent != NULL)
		gparent->next = parent;
	else
		*list = parent;
	parent->next = child;
	child->next = gchild;

/* 3. Assign a parent to each child */
	parent->prev = gparent;
	child->prev = parent;
	if (gchild != NULL)
		gchild->prev = child;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *now;

/* Check list exist and have at least two nodes */
	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
	{
		return;
	}

/* Assign the second node to a temporary pointer to node that can be moved */
	now = (*list)->next;

/* Walk throught the list starting from the second node */
	while (now)
	{
/* Is this value bigger than the previous?*/
		while (now && now->prev && now->n < now->prev->n)
		{/* Yes, so it need to be swaped and printed to see the progress */
			swap(now->prev, list);
			print_list(*list);
		}
		now = now->next; /* move to the next node */
	}
}
