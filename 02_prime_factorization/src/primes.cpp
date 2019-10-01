//
// Created by ida on 10.09.19.
//

#include <cstdint>
#include <vector>
#include <cmath>

#include "primes.h"

using namespace std;

vector <uint64_t> prime_factorization::calculate_primes(uint64_t number) {
    vector <uint64_t> res{};

    if (number <= 3) {
        res.push_back(number);
    } else {

        while (!(number % 2)) {
            res.push_back(2);
            number = number / 2;
        }
        for (int i{3}; i <= sqrt(number); i += 2) {
            while (!(number % i)) {
                res.push_back(i);
                number = number / i;
            }
        }
        if (number > 2) {
            res.push_back(number);
        }
    }
    return res;
}
