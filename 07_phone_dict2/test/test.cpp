//
// Created by ida on 10.09.19.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "sll.h"

using namespace std;

TEST_CASE("Test") {
    List list;

    int value{};
    CHECK(!list.search("abc", value));

    list.set("abc", 1);
    CHECK(list.search("abc", value));
    CHECK(value == 1);

    list.set("def", 2);
    CHECK(list.search("def", value));
    CHECK(value == 2);

    list.set("ghi", 3);
    CHECK(list.search("ghi", value));
    CHECK(value == 3);

    CHECK(!list.remove("xyz"));

    CHECK(list.remove("def"));
    CHECK(!list.search("def", value));

    list.clear();

    CHECK(!list.search("abc", value));
}

