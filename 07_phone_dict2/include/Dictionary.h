//
// Created by ida on 15.12.19.
//

#ifndef HOENIGMANN_I15013_DICTIONARY_H
#define HOENIGMANN_I15013_DICTIONARY_H

#include <cstring>
#include <string>
#include <vector>

#include "sll.h"

class Dictionary {
public:
    Dictionary() {
        for (int i{}; i < Dictionary::length; i++) {
            arr[i] = List();
        }
    }

    auto begin();
    auto cbegin();
    auto end();
    auto cend();
    auto find(const std::string& s);
    auto erase(const std::string& s);
    auto clear();
    auto& operator[](const std::string& s);

private:
    size_t hash(const unsigned char* str);
    bool set_(std::string, int);
    bool search_(std::string, int&);
    bool remove_(std::string);
    void clear_();

    static constexpr int length{13};
    List arr[Dictionary::length];
    std::vector<std::pair<std::string, int>> vector;
};


#endif //HOENIGMANN_I15013_DICTIONARY_H
