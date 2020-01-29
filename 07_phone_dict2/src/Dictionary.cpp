//
// Created by ida on 15.12.19.
//

#include <vector>
#include <algorithm>
#include "Dictionary.h"
#include "sll.h"


// TODO: fix everything

using namespace std;

size_t Dictionary::hash(const unsigned char* str) {
    unsigned long hash{5381};
    int c;

    while  ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % Dictionary::length;
}

vector<pair<string, int>>::iterator Dictionary::begin() {
    return vector.begin();
}

const vector<pair<string, int>>::iterator Dictionary::cbegin() {
    return vector.cbegin();
}

vector<pair<string, int>>::iterator Dictionary::end() {
    return vector.end();
}

const vector<pair<string, int>>::iterator Dictionary::cend() {
    return vector.cend();
}

auto Dictionary::find(const std::string& s) {
    int idx{};

    for (size_t i{}; i < vector.size(); i++) {
        if (vector[idx].first == s) {
            return vector.begin() + idx;
        }
        idx++;
    }

    return vector.begin() + vector.size();
}

auto Dictionary::erase(const std::string& s) {
    return vector.erase(find(s));
}

auto& Dictionary::operator[](const std::string& s) {
    int idx{};

    for (size_t i{}; i < vector.size(); i++) {
        if (vector[idx].first == s) {
            return vector[idx];
        }
        idx++;
    }

    return vector[vector.size()];
}

auto Dictionary::clear() {
    clear_();
    vector.clear();
}

bool Dictionary::set_(std::string key, int value) {
    return arr[hash(reinterpret_cast<const unsigned char*>(key.c_str()))].set(key, value);
}

bool Dictionary::search_(std::string key, int& value) {
    return arr[hash(reinterpret_cast<const unsigned char*>(key.c_str()))].search(key, value);
}

bool Dictionary::remove_(std::string key) {
    return arr[hash(reinterpret_cast<const unsigned char*>(key.c_str()))].remove(key);
}

void Dictionary::clear_() {
    for (int i{}; i < Dictionary::length; i++) {
        arr[i].clear();
    }
}
