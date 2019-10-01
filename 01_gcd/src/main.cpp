//
// Created by ida on 05.09.19.
//

#include "gcd.h"

#include <iostream>
#include <string.h>
#include <limits>
#include <tuple>

using namespace std;

constexpr string_view usage_msg{"Computes the greatest common divisor of two numbers\n"
                                "Usage: gcd [Options] FIRST SECOND\n\n"
                                "Positionals:\n"
                                "  FIRST UINT REQUIRED    First number\n"
                                "  SECOND UINT REQUIRED   Second number\n\n"
                                "Options:\n"
                                "  -h,--help              Print this help message and exit"};

void usage(string msg="") {
    cerr << usage_msg << "\n" << msg << endl;
    exit(1);
}

tuple<unsigned long long, unsigned long long> parse_args(int argc, char* argv[]) {
    if (argc > 1) {
        if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
            usage();
        }
    }

    if (argc == 3) {
        try {
            unsigned long long first = stoull(argv[1], nullptr);

            try {
                unsigned long long second = stoull(argv[2], nullptr);
                /*TODO:
                 * raise error for incorrect input such as "100a"
                 * */
                return make_tuple(first, second);
            } catch (invalid_argument&) {
                cerr << "Could not convert: SECOND = " << argv[2] << endl;
            } catch (out_of_range&) {
                cerr << "SECOND has to be " << std::numeric_limits<unsigned long long>::max() << ": SECOND = " << argv[2] << endl;
            }

        } catch (invalid_argument&) {
            cerr << "Could not convert: FIRST = " << argv[1] << endl;
        } catch (out_of_range&) {
            cerr << "FIRST has to be " << std::numeric_limits<unsigned long long>::max() << ": FIRST = " << argv[1] << endl;
        }

    } else if (argc == 2) {
        cerr << "SECOND is required" << endl;
    } else {
        cerr << "exactly 2 arguments needed, but " << argc - 1 << " given" << endl;
    }
    cerr << "Run with --help for more information." << endl;
    exit(1);
}

int main(int argc, char* argv[]) {
    auto [a, b] = parse_args(argc, argv);
    cout << "computed recursive: " << greatest_common_divisor::gcd_recursive(a, b) << endl;
    cout << "computed iterative: " << greatest_common_divisor::gcd_iterative(a, b) << endl;
}
