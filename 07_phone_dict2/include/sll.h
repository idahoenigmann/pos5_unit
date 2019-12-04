//
// Created by ida on 28.11.19.
//

#ifndef HOENIGMANN_I15013_SLL_H
#define HOENIGMANN_I15013_SLL_H

class List final {
public:
    ~List();
    bool set(std::string key, int value);
    bool search(std::string key, int& value);
    bool remove(std::string key);
    void clear();
};

#endif //HOENIGMANN_I15013_SLL_H
