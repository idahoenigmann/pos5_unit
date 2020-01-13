//
// Created by ida on 28.11.19.
//

#ifndef HOENIGMANN_I15013_SLL_H
#define HOENIGMANN_I15013_SLL_H

struct Node {
    Node(std::string key, int value) {
        this->key = key;
        this->value = value;
    }

    std::string key;
    int value;
    Node* next{};
};

class List final {
public:
    ~List();
    bool set(std::string key, int value);
    bool search(std::string key, int& value);
    bool remove(std::string key);
    void clear();
private:
    Node* root{nullptr};
};

#endif //HOENIGMANN_I15013_SLL_H
