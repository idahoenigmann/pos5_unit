//
// Created by ida on 10.09.19.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "stack.h"

using namespace std;


TEST_CASE("is_empty(empty_stack())=true") {
    stacks::Stack s{};
    CHECK(s.empty());
}

TEST_CASE("is_empty(push(empty_stack(), x))=false") {
    stacks::Stack s{};
    s.push(1);
    CHECK(!s.empty());
}

TEST_CASE("pop(empty_stack())->Error") {
    stacks::Stack s{};
    CHECK_THROWS(s.pop());
}

TEST_CASE("pop(push(s,x))=x") {
    stacks::Stack s{};
    s.push(2);
    CHECK(s.pop() == 2);
}

TEST_CASE("top(empty_stack())->Error") {
    stacks::Stack s{};
    CHECK_THROWS(s.top());
}

TEST_CASE("top(push(s,x))=x") {
    stacks::Stack s{};
    s.push(2);
    CHECK(s.top() == 2);
}

TEST_CASE("push(pop(s),top(s))=s||Error") {
    stacks::Stack s{};
    s.push(2);
    s.push(3);
    int x = s.top();
    s.pop();
    s.push(x);
    CHECK(s.pop() == 3);
    CHECK(s.pop() == 2);
}

TEST_CASE("copy constructor") {
    stacks::Stack s1;
    s1.push(3);
    s1.push(2);
    stacks::Stack s2{s1};

    while (!s1.empty()) {
        CHECK(s1.pop() == s2.pop());
    }
}

TEST_CASE("copy constructor") {
    stacks::Stack s1;
    s1.push(3);
    s1.push(2);
    stacks::Stack s2{};

    s2 = s1;

    while (!s1.empty()) {
        CHECK(s1.pop() == s2.pop());
    }
}

TEST_CASE("Stack(int)") {
    stacks::Stack s1(1);

    CHECK(s1.pop() == 1);
    CHECK(s1.empty());
}

TEST_CASE("Stack(initializer_list)") {
    stacks::Stack s1{1, 2, 3};

    CHECK(s1.pop() == 3);
    CHECK(s1.pop() == 2);
    CHECK(s1.pop() == 1);
    CHECK(s1.empty());
}