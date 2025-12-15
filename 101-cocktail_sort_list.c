#include "sort.h"

/**
* swap_nodes - Swap two adjacent nodes in a doubly linked list
* @list: Pointer to the head of the list
* @left: First node
* @right: Second node
*/
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
if (left->prev)
left->prev->next = right;
else
*list = right;

if (right->next)
right->next->prev = left;

left->next = right->next;
right->prev = left->prev;

right->next = left;
left->prev = right;
}

/**
* cocktail_forward - Forward pass of cocktail sort
* @list: Pointer to the head of the list
* @end: Last sorted node
*
* Return: 1 if swapped, 0 otherwise
*/
int cocktail_forward(listint_t **list, listint_t **end)
{
int swapped = 0;
listint_t *current = *list;

while (current->next != *end)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
else
current = current->next;
}
*end = current;
return (swapped);
}

/**
* cocktail_backward - Backward pass of cocktail sort
* @list: Pointer to the head of the list
*
* Return: 1 if swapped, 0 otherwise
*/
int cocktail_backward(listint_t **list)
{
int swapped = 0;
listint_t *current = *list;

while (current->next)
current = current->next;

while (current->prev)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
else
current = current->prev;
}
return (swapped);
}

/**
* cocktail_sort_list - Sort a doubly linked list using cocktail sort
* @list: Double pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *end = NULL;

if (!list || !*list || !(*list)->next)
return;

while (swapped)
{
swapped = cocktail_forward(list, &end);
if (!swapped)
break;
swapped = cocktail_backward(list);
}
}

