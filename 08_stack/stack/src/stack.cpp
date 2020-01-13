//
// Created by ida on 26.12.19.
//

#include <iostream>
#include <stdexcept>

#include "stack.h"

using namespace std;

int& stacks::Stack::top() {
    if (top_) {
        return top_->value;
    }
    throw domain_error("stack is empty");
}

int stacks::Stack::pop() {
    if (!top_) {
        throw domain_error("stack is empty");
    }
    Node* n{top_};
    top_ = top_->next;
    int val = n->value;
    delete n;
    return val;
}

void stacks::Stack::push(int x) {
    Node* n = new Node{};
    n->value = x;
    Node* next{top_};
    top_ = n;
    top_->next = next;
}

void stacks::Stack::clear() {
    stacks::Node* curr{top_};
    stacks::Node* next{top_};
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

bool stacks::Stack::empty() {
    return !top_;
}

std::ostream& stacks::operator<<(std::ostream& s, Stack& stack) {
    Node* curr{stack.top_};

    while (curr) {
        s << curr->value << " ";
        curr = curr->next;
    }
    return s;
}

void stacks::swap(stacks::Stack& first, stacks::Stack& second) noexcept {
    using std::swap;
    swap(first.top_, second.top_);
}