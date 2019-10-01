//
// Created by ida on 10.09.19.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cstdint>
#include <vector>

#include "doctest.h"

#include "primes.h"

using namespace std;

TEST_CASE("Prime factors of 0") {
    vector <uint64_t> res{prime_factorization::calculate_primes(0)};
    CHECK(res.size() == 1);
    CHECK(res.at(0) == 0);
}

TEST_CASE("Prime factors of 1") {
    vector <uint64_t> res{prime_factorization::calculate_primes(1)};
    CHECK(res.size() == 1);
    CHECK(res.at(0) == 1);
}

TEST_CASE("Prime factors of 2, 3, 4, 10, 21322314") {
    vector <uint64_t> input{2, 3, 4, 10, 21322314};
    vector <vector<uint64_t>> expected_res{{2},
                                       {3},
                                       {2, 2},
                                       {2, 5},
                                       {2, 3, 3, 13, 91121}};
    vector <uint64_t> res{};

    for(size_t i{0}; i<input.size(); i++) {
        res = prime_factorization::calculate_primes(input[i]);
        for (size_t j{0}; j<res.size(); j++) {
            CHECK(res[j] == expected_res[i].at(j));
        }
    }
}
