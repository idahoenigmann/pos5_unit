//
// Created by ida on 10.09.19.
//

#include <iostream>
#include <string.h>

#include "CLI11.hpp"

#include "numbercheck.h"

using namespace std;

int main(int argc, char *argv[]) {
    CLI::App app("Checks if word from stdin is correct floating point number");

    app.get_formatter()->label("OPTIONS", "Options");

    string inputStreamString;

    app.add_option("STDIN", inputStreamString, "stdin marker (must be '-')");

    string text;

    app.add_option("-v,--value", text, "The number to check");

    CLI11_PARSE(app, argc, argv);

    numbercheck::FloatingPointChecker floatingPointChecker{};

    if (inputStreamString == "-") {
        text = cin.readline();
    }

    cout << boolalpha << floatingPointChecker.check("123") << endl;

    return 0;
}
