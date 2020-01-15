//
// Created by ida on 10.09.19.
//

#include <iostream>

#include "repl.h"
#include "magic_enum.hpp"

using namespace std;

int main() {
    repl::Calc calc{};
    try {
        while (true) {
            calc.eval(repl::input());
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
