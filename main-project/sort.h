#ifndef SORT_H
#define SORT_H

#include "rate.h"

int compare_by_price_difference(rate* a, rate* b);
int compare_by_name_and_address(rate* a, rate* b);
void bubble_sort(rate** arr, int size, int (*compare)(rate*, rate*));
void merge_sort(rate** arr, int left, int right, int (*compare)(rate*, rate*));

#endif
