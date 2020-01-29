//
// Created by ida on 10.09.19.
//

#include <iostream>

#include "repl.h"
#include "magic_enum.hpp"

using namespace std;

int main() {
    repl::Calc calc{};
    while (true) {
        try {
            auto iterators {calc.eval(repl::input())};

            for (auto e{iterators.first}; e != iterators.second; e++) {
                cout << *e << endl;
            }

        } catch (std::exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}
