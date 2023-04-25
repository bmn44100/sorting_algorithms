#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list
 * @n: Integer stored in node
 * @prev: Pointer to the previous element of list
 * @next: Pointer to the next element of list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, ssize_t start, ssize_t end, size_t size);
ssize_t partition(int *array, ssize_t start, ssize_t end, size_t size);
void swap(int *a, int *b);

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int find_highest(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void qsh(int *array, ssize_t start, ssize_t end, size_t size);
ssize_t partition_h(int *array, ssize_t start, ssize_t end, size_t size);

#endif
