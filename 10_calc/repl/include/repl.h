//
// Created by ida on 14.01.20.
//

#ifndef HOENIGMANN_I15013_REPL_H
#define HOENIGMANN_I15013_REPL_H

#include <string>
#include <optional>
#include <variant>
#include <utility>
#include <deque>

using t = std::pair<std::deque<double>::const_iterator, std::deque<double>::const_iterator>;

namespace repl {
    class IOException : public std::exception {
      public:
        virtual const char* what() const noexcept {
            return "bad input stream";
        }

    };

    class ParseException : public std::exception {
      public:
        virtual const char* what() const noexcept {
            return "received invalid input";
        }

    };

    enum class Command {
        add,
        sub,
        mul,
        div,
        pow,
        chs,
        print,
        clst,
        sqrt,
        swap,
        rot,
        log,
        ln,
        ld,
        exp,
        sin,
        cos,
        tan,
        asin,
        acos,
        atan,
        deg,
        rad,
        help,
        quit
    };

    using Value=std::variant<double, repl::Command>;

    std::optional<std::string> raw_input(std::string prompt=">>> ");

    Value input(std::string prompt=">>> ");

    class Calc {
      public:
        t eval(Value);

      private:
        std::deque<double> stack{};

        std::pair<double, double> get_arguments(repl::Command command);
    };
}

#endif //HOENIGMANN_I15013_REPL_H
