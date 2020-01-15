//
// Created by ida on 26.12.19.
//

#include <iostream>
#include <stdexcept>
#include <memory>

#include "stack.h"

using namespace std;

double& stacks::Stack::top() {
    if (top_) {
        return top_->value;
    }
    throw domain_error("stack is empty");
}

double stacks::Stack::pop() {
    if (!top_) {
        throw domain_error("stack is empty");
    }
    unique_ptr<Node> n{move(top_)};
    top_ = move(n->next);
    return n->value;
}

void stacks::Stack::push(double x) {
    unique_ptr<Node> n {new Node{x, move(top_)}};
    top_ = move(n);
}

bool stacks::Stack::empty() {
    return !top_;
}

std::ostream& stacks::operator<<(std::ostream& s, Stack& stack) {
    unique_ptr<Node> curr = move(stack.top_);

    while (curr) {
        s << curr->value << " ";
        curr = move(curr->next);
    }
    return s;
}

void stacks::swap(stacks::Stack& first, stacks::Stack& second) noexcept {
    using std::swap;
    swap(first.top_, second.top_);
}