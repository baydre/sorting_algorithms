/*
 * sorting_algorithm, Task 1: function that sorts
 * a doubly linked list of integers in ascending order
 * using the insertion sort algorithm.
 */
#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of
 * integers in ascending order using insertion sort algorithm.
 * @list: pointer to a pointer to head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *head, *prev, *prev_inner, *curr_inner;

	if (list == NULL)
		return;
	if ((*list) == NULL || (*list)->next == NULL)
		return;
	prev = *list;
	curr = (*list)->next;
	head = *list;
	while (curr)
	{
		curr_inner = curr;
		prev_inner = prev;
		while (prev_inner && prev_inner->n > curr_inner->n)
		{
			if (prev_inner->prev == NULL)
				head = curr_inner;
			if (curr_inner == curr)
				curr = prev_inner;
			if (curr_inner->next != NULL)
				curr_inner->next->prev = prev_inner;
			if (prev_inner->prev != NULL)
				prev_inner->prev->next = curr_inner;
			curr_inner->prev = prev_inner->prev;
			prev_inner->next = curr_inner->next;
			curr_inner->next = prev_inner;
			prev_inner->prev = curr_inner;
			prev_inner = curr_inner->prev;
			print_list(head);
		}
		prev = curr;
		curr = curr->next;
	}
	*list = head;
}
