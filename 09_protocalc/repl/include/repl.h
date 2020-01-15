//
// Created by ida on 14.01.20.
//

#ifndef HOENIGMANN_I15013_REPL_H
#define HOENIGMANN_I15013_REPL_H

#include <string>
#include <optional>
#include <variant>

#include "stack.h"

namespace repl {
    class IOException : std::exception {
      public:
        virtual const char* what() const noexcept {
            return "bad input stream";
        }

    };

    class ParseException : std::exception {
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
        double eval(Value);

      private:
        stacks::Stack stack{};
    };
}

#endif //HOENIGMANN_I15013_REPL_H
