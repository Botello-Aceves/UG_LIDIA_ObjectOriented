#include <stdio.h>
#include <stdlib.h>
#include "insert_sort.h"
#include "comparators.h"

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int data[] = {5, -3, 8, 1, -9, 4};
    int size = sizeof(data)/sizeof(data[0]);

    int copy[size];

    // Ascending
    memcpy(copy, data, sizeof(data));
    insert_sort(copy, size, ascending);
    printf("Ascending: ");
    print_array(copy, size);

    // Descending
    memcpy(copy, data, sizeof(data));
    insert_sort(copy, size, descending);
    printf("Descending: ");
    print_array(copy, size);

    // Absolute
    memcpy(copy, data, sizeof(data));
    insert_sort(copy, size, absolute);
    printf("Absolute: ");
    print_array(copy, size);

    // Even first
    memcpy(copy, data, sizeof(data));
    insert_sort(copy, size, even_first);
    printf("Even first: ");
    print_array(copy, size);

    return 0;
}
