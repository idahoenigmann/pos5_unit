//
// Created by ida on 14.01.20.
//

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <optional>
#include <variant>

#include "magic_enum.hpp"

#include "repl.h"
#include "stack.h"

using namespace std;

using Value=std::variant<double, repl::Command>;

optional<string> repl::raw_input(string prompt) {
    cout << prompt << flush;
    string s;

    getline(cin, s);
    if (cin.eof()) {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        return {};
    } else if (cin.bad()) {
        throw IOException{};
    }
    boost::trim(s);
    return s;
}

Value repl::input(string prompt) {
    string input_string = raw_input(prompt).value();
    size_t* pos{};
    try {
        double d{stod(input_string, pos)};
        return d;
    } catch (...) {
        if (input_string == "+")
            return repl::Command::add;
        else if (input_string == "-")
            return repl::Command::sub;
        else if (input_string == "*")
            return repl::Command::mul;
        else if (input_string == "/")
            return repl::Command::div;
        else if (input_string == "**")
            return repl::Command::pow;
        else {
            auto command = magic_enum::enum_cast<Command>(input_string);
            if (command.has_value()) {
                return command.value();
            }
        }
    }
    throw ParseException{};
}

double repl::Calc::eval(Value value) {
    if (value.index() == 0) {       // double
        stack.push(get<double>(value));
    } else {                        // repl::Command
        if (get<repl::Command>(value) == repl::Command::add) {
            double res{stack.pop() + stack.pop()};
            cout << res << endl;
            stack.push(res);
        } else if (get<repl::Command>(value) == repl::Command::sub) {
            double res{stack.pop() - stack.pop()};
            cout << res << endl;
            stack.push(res);
        } else if (get<repl::Command>(value) == repl::Command::mul) {
            double res{stack.pop() * stack.pop()};
            cout << res << endl;
            stack.push(res);
        } else if (get<repl::Command>(value) == repl::Command::div) {
            double res{stack.pop() / stack.pop()};
            cout << res << endl;
            stack.push(res);
        }

    }
    return 1;
}