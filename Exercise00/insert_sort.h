#ifndef INSERT_SORT_H
#define INSERT_SORT_H

typedef int (*CompareFn)(int a, int b);

void insert_sort(int arr[], int size, CompareFn compare);

#endif
