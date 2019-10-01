//
// Created by ida on 05.09.19.
//

#include "gcd.h"

namespace greatest_common_divisor {
    unsigned long long gcd_recursive(unsigned long long a, unsigned long long b) {
        if (a == b) {
            return a;
        } else if (a > b) {
            return gcd_recursive(a - b, b);
        } else {
            return gcd_recursive(a, b - a);
        }
    }

    unsigned long long gcd_iterative(unsigned long long a, unsigned long long b) {
        while (b) {
            unsigned long long r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}