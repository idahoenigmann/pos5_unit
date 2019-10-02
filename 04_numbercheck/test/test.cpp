//
// Created by ida on 10.09.19.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "numbercheck.h"

using namespace std;

TEST_CASE("correct integer numbers without exponent") {
    numbercheck::FloatingPointChecker floatingPointChecker{};

    CHECK(floatingPointChecker.check("42"));
    CHECK(floatingPointChecker.check("21322314"));
    CHECK(floatingPointChecker.check("+42"));
    CHECK(floatingPointChecker.check("+21322314"));
    CHECK(floatingPointChecker.check("-42"));
    CHECK(floatingPointChecker.check("-21322314"));
}

TEST_CASE("correct integer numbers with exponent") {
    numbercheck::FloatingPointChecker floatingPointChecker{};

    CHECK(floatingPointChecker.check("42.e10"));
    CHECK(floatingPointChecker.check("21322314.e10"));
    CHECK(floatingPointChecker.check("-42.e-10"));
    CHECK(floatingPointChecker.check("+21322314.e-10"));
    CHECK(floatingPointChecker.check("+42.e+10"));
    CHECK(floatingPointChecker.check("-21322314.e+10"));
}

TEST_CASE("correct floating point numbers without exponent") {
    numbercheck::FloatingPointChecker floatingPointChecker{};

    CHECK(floatingPointChecker.check("42.21322314"));
    CHECK(floatingPointChecker.check("21322314.42"));
    CHECK(floatingPointChecker.check(".21322314"));
    CHECK(floatingPointChecker.check("0.42"));
    CHECK(floatingPointChecker.check("+42.21322314"));
    CHECK(floatingPointChecker.check("-21322314.42"));
}

TEST_CASE("correct floating point numbers with exponent") {
    numbercheck::FloatingPointChecker floatingPointChecker{};

    CHECK(floatingPointChecker.check("42.123e10"));
    CHECK(floatingPointChecker.check("21322314.123e10"));
    CHECK(floatingPointChecker.check("-42.123e-10"));
    CHECK(floatingPointChecker.check("+21322314.123e-10"));
    CHECK(floatingPointChecker.check("+42.123e+10"));
    CHECK(floatingPointChecker.check("-21322314.123e+10"));
}

TEST_CASE("false numbers") {
    numbercheck::FloatingPointChecker floatingPointChecker{};

    CHECK(!floatingPointChecker.check("42.123.3"));
    CHECK(!floatingPointChecker.check("21322314e10"));
}