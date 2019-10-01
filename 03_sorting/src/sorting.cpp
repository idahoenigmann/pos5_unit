//
// Created by ida on 12.09.19.
//

#include <iostream>
#include <algorithm>

#include "sorting.h"

using namespace std;

void sorting::bubble_sort(unsigned int n, int numbers[]) {
    while (true) {
        unsigned int new_n = 1;
        for (unsigned int i{0}; i < n - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                int temp{numbers[i + 1]};
                numbers[i + 1] = numbers[i];
                numbers[i] = temp;
                new_n = i + 1;
            }
        }
        n = new_n;
        if (n == 1) {
            break;
        }
    }
}

void sorting::insertion_sort(unsigned int n, int numbers[]) {
    for (unsigned int i{1}; i < n; i++) {
        int val{numbers[i]};
        unsigned int j{i};
        while (true) {
            if (j == 0 || numbers[j - 1] <= val) {
                break;
            }

            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j] = val;
    }
}

void sorting::selection_sort(unsigned int n, int numbers[]) {
    for (unsigned int i{0}; i < n - 1; i++) {
        int min = i;
        for (unsigned int j{i + 1}; j < n; j++) {
            if (numbers[j] < numbers[min]) {
                min = j;
            }
        }
        int temp{numbers[i]};
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
}
