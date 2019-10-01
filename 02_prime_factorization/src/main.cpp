//
// Created by ida on 10.09.19.
//

#include <iostream>
#include <string.h>
#include <limits>
#include <vector>
#include <cstdint>

#include "CLI11.hpp"

#include "primes.h"

using namespace std;
using namespace prime_factorization;

int main(int argc, char *argv[]) {
    CLI::App app("Calculates the prime factors of the given number");

    uint64_t number;

    app.add_option("NUMBER", number, "The number")
            ->required();
    app.get_formatter()->label("OPTIONS", "Options");

    CLI11_PARSE(app, argc, argv);

    vector <uint64_t> primes{calculate_primes(number)};

    for (size_t i{0}; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;

    return 0;
}