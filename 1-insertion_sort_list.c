#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers with the
 * Insertion sort algorithm
 * @list: unsorted integer double linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currentNode = NULL, *aux = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	currentNode = *list;
	while (currentNode != NULL)
	{
		aux = currentNode;
		while (currentNode->prev != NULL && currentNode->n < currentNode->prev->n)
		{
			aux->prev->next = aux->next;
			if (aux->next != NULL)
				aux->next->prev = aux->prev;
			aux->next = aux->prev;
			aux->prev = aux->prev->prev;
			aux->next->prev = aux;
			if (aux->prev != NULL)
				aux->prev->next = aux;
			else
				*list = aux;
			print_list(*list);
		}
		currentNode = currentNode->next;
	}
}
