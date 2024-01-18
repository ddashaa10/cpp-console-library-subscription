#include "sort.h"
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// Функция сравнения по убыванию разницы между стоимостью продажи и покупки
int compare_by_price_difference(rate* a, rate* b) {
    double diffA = a->sale - a->purchase;
    double diffB = b->sale - b->purchase;

    return (diffA < diffB) ? 1 : ((diffA > diffB) ? -1 : 0);
}

// Функция сравнения по возрастанию названию банка и адреса
int compare_by_name_and_address(rate* a, rate* b) {
    int nameComparison = std::strcmp(a->bank, b->bank);
    if (nameComparison != 0) {
        return nameComparison;
    }
    return std::strcmp(a->address, b->address);
}

// Метод сортировки обменом
void bubble_sort(rate** arr, int size, int (*compare)(rate*, rate*)) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (compare(arr[j], arr[j + 1]) > 0) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Метод сортировки слиянием
void merge(rate** arr, int left, int mid, int right, int (*compare)(rate*, rate*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    rate* leftArr = new rate[n1];
    rate* rightArr = new rate[n2];

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = *arr[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        rightArr[j] = *arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(&leftArr[i], &rightArr[j]) > 0) {
            *arr[k++] = leftArr[i++];
        }
        else {
            *arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        *arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        *arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(rate** arr, int left, int right, int (*compare)(rate*, rate*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid, compare);
        merge_sort(arr, mid + 1, right, compare);
        merge(arr, left, mid, right, compare);
    }
}
