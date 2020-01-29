//
// Created by ida on 14.01.20.
//

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <optional>
#include <variant>
#include <stdexcept>
#include <utility>
#include <deque>
#include <cmath>

#include "magic_enum.hpp"

#include "repl.h"

using namespace std;

using t = pair<deque<double>::const_iterator, deque<double>::const_iterator>;

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


pair<double, double> repl::Calc::get_arguments(repl::Command command) {
    double r1{};
    double r2{};
    switch (command) {
        case repl::Command::add:
        case repl::Command::sub:
        case repl::Command::mul:
        case repl::Command::div:
        case repl::Command::pow:
        case repl::Command::swap:
            if (stack.size() < 2) throw ParseException{};
            r1 = stack[0];
            stack.pop_front();
            r2 = stack[0];
            stack.pop_front();
            return make_pair(r1, r2);
        case repl::Command::chs:
        case repl::Command::sqrt:
        case repl::Command::log:
        case repl::Command::ln:
        case repl::Command::ld:
        case repl::Command::exp:
        case repl::Command::sin:
        case repl::Command::cos:
        case repl::Command::tan:
        case repl::Command::asin:
        case repl::Command::acos:
        case repl::Command::atan:
        case repl::Command::deg:
        case repl::Command::rad:
            if (stack.size() < 1) throw ParseException{};
            r1 = stack[0];
            stack.pop_front();
            return make_pair(r1, 0);
        default:
            return make_pair(0, 0);
    }
}


t repl::Calc::eval(Value value) {
    double res{};
    if (value.index() == 0) {       // double
        res = get<double>(value);
        stack.push_front(res);
        return pair{stack.cbegin(), stack.cbegin() + 1};
    } else {                        // repl::Command
        auto [r1, r2]{get_arguments(get<repl::Command>(value))};
        switch (get<repl::Command>(value)) {
            case repl::Command::add:
                res = r1 + r2;
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::sub:
                res = r1 - r2;
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::mul:
                res = r1 * r2;
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::div:
                res = r1 / r2;
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::pow:
                res = pow(r1, r2);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::chs:
                stack.push_front(r1 * -1);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::print:
                return pair{stack.cbegin(), stack.cend()};
            case repl::Command::clst:
                stack.clear();
                return pair{stack.cbegin(), stack.cbegin()};
            case repl::Command::sqrt:
                res = sqrt(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::swap:
                stack.push_front(r1);
                stack.push_front(r2);
                return pair{stack.cbegin(), stack.cbegin()};
            case repl::Command::rot:
                stack.push_front(stack.back());
                stack.pop_back();
                return pair{stack.cbegin(), stack.cbegin()};
            case repl::Command::log:
                res = log10(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::ln:
                res = log(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::ld:
                res = log2(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::exp:
                res = exp(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::sin:
                res = sin(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::cos:
                res = cos(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::tan:
                res = tan(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::asin:
                res = asin(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::acos:
                res = acos(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::atan:
                res = atan(r1);
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::deg:
                res = r1 * 180 / 3.141592653589793238463;
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::rad:
                res = r1 / 180 * 3.141592653589793238463;
                stack.push_front(res);
                return pair{stack.cbegin(), stack.cbegin() + 1};
            case repl::Command::help:
                cout << "this is a RPN (reverse polish notation) calculator" << endl <<
                "    try this to get started: " << endl <<
                "    >>> 1" << endl <<
                "    >>> 2" << endl <<
                "    >>> +" << endl << endl <<
                "    other operators: +, -, *, /, **, " << endl <<
                "                     chs, sqrt, swap, rot, log, ln, ld, exp," << endl <<
                "                     sin, cos, tan, asin, acos, atan, deg, rad," << endl <<
                "                     help, quit, print, clst" << endl;
                return pair{stack.cbegin(), stack.cbegin()};
            case repl::Command::quit:
                exit(0);
            default:
                throw invalid_argument("invalid Command");
        }
    }
}