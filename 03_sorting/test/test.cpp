//
// Created by ida on 10.09.19.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "sorting.h"

using namespace std;

TEST_CASE("Test") {
    vector<int> sorted_numbers {-10, -5, -1, 0, 1, 5, 10, 42, 123456, 21322314};
    {
        vector<int> numbers{21322314, 0, 42, -10, -1, 123456, -5, 10, 5, 1};

        sorting::bubble_sort(numbers. size(), numbers.data());
        CHECK(numbers == sorted_numbers);
    }
    {
        vector<int> numbers{21322314, 0, 42, -10, -1, 123456, -5, 10, 5, 1};

        sorting::insertion_sort(numbers. size(), numbers.data());
        CHECK(numbers == sorted_numbers);
    }
    {
        vector<int> numbers{21322314, 0, 42, -10, -1, 123456, -5, 10, 5, 1};

        sorting::selection_sort(numbers. size(), numbers.data());
        CHECK(numbers == sorted_numbers);
    }
}
