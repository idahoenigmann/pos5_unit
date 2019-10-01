//
// Created by ida on 10.09.19.
//

#include <iostream>
#include <vector>

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#define FMT_HEADER_ONLY
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include "sorting.h"

using namespace std;

int main(int argc, char *argv[]) {
    CLI::App app("Sorts the given sequence of number");

    app.get_formatter()->label("OPTIONS", "Options");

    vector<int> numbers;

    app.add_option("NUMBERS", numbers, "The numbers to sort")
            ->required();

    auto algorithm = app.add_option_group("algorithm",
            "Choose the preferred sorting algorithm");

    bool bubble = false;
    bool insertion = false;
    bool selection = false;

    algorithm->add_flag("-b,--bubble", bubble, "Use bubblesort");
    algorithm->add_flag("-i,--insertion", insertion, "Use insertion sort (default)");
    algorithm->add_flag("-s,--selection", selection, "Use selection sort");

    algorithm->require_option(0, 1);

    CLI11_PARSE(app, argc, argv);

    if (bubble) {
        sorting::bubble_sort(numbers.size(), numbers.data());
    } else if (insertion) {
        sorting::insertion_sort(numbers.size(), numbers.data());
    } else {
        sorting::selection_sort(numbers.size(), numbers.data());
    }

    fmt::print("{{{}}}\n", fmt::join(numbers, ", "));

    return 0;
}
