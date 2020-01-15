//
// Created by ida on 26.12.19.
//

#ifndef HOENIGMANN_I15013_STACK_H
#define HOENIGMANN_I15013_STACK_H

#include <iostream>
#include <ostream>
#include <initializer_list>
#include <memory>

namespace stacks {

    struct Node {
        double value{};
        std::unique_ptr<Node> next{};

        Node(double value, std::unique_ptr<Node>&& next) : value{value}, next{move(next)} {};
    };

    class Stack final {
      public:
        Stack() = default;

        Stack(int x) {
            push(x);
        }

        Stack(std::initializer_list<double> l) {
            for (int e : l) {
                push(e);
            }
        }

        friend std::ostream& operator<<(std::ostream& s, Stack& stack);
        friend void swap(Stack& first, Stack& second) noexcept;

        double& top();
        double pop();
        void push(double);
        bool empty();
      private:
        std::unique_ptr<Node> top_;
    };

    std::ostream& operator<<(std::ostream& s, Stack& stack);
    void swap(Stack& first, Stack& second) noexcept;
}

#endif //HOENIGMANN_I15013_STACK_H
