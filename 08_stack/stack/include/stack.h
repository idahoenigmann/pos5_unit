//
// Created by ida on 26.12.19.
//

#ifndef HOENIGMANN_I15013_STACK_H
#define HOENIGMANN_I15013_STACK_H

#include <iostream>
#include <ostream>
#include <initializer_list>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace stacks {
    struct Node {
        int value{};
        Node* next{};
    };

    class Stack final {
      public:
        Stack() = default;


        Stack(int x) {
            top_ = new Node();
            top_->value = x;
        }


        Stack(std::initializer_list<int> l) {
            for (int e : l) {
                push(e);
            }
        }


        Stack(const Stack& other) {
            if (other.top_) {
                top_ = new Node();
                top_->value = other.top_->value;

                Node* curr_o{other.top_};
                Node* curr{top_};

                while (curr_o->next) {
                    curr_o = curr_o->next;
                    curr->next = new Node();
                    curr = curr->next;
                    curr->value = curr_o->value;
                }
                curr->value = curr_o->value;
            }
        }


        Stack(Stack&& other) noexcept {
            swap(*this, other);
        }


        Stack& operator=(Stack&& rhs) noexcept {
            Stack tmp{std::move(rhs)};
            swap(*this, tmp);
            return *this;
        }


        ~Stack() noexcept {
            clear();
        }

        Stack& operator=(const Stack& rhs) {
            if (this == &rhs) {
                return *this;
            }
            Stack tmp{rhs};
            swap(*this, tmp);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& s, Stack& stack);
        friend void swap(Stack& first, Stack& second) noexcept;

        int& top();
        int pop();
        void push(int);
        void clear();
        bool empty();
      private:
        Node* top_{};
    };

    std::ostream& operator<<(std::ostream& s, Stack& stack);
    void swap(Stack& first, Stack& second) noexcept;
}

#endif //HOENIGMANN_I15013_STACK_H
