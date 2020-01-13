//
// Created by ida on 28.11.19.
//

#include <iostream>

#include "sll.h"

using namespace std;


List::~List() {
    Node* curr = root;
    Node* next = root;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

bool List::set(string key, int value) {
    if (root) {
        Node* curr{root};
        while(curr->next) {
            if (curr->key == key) {
                curr->value = value;
                return true;
            }
            curr = curr->next;
        }
        curr->next = new Node(key, value);
    } else {
        root = new Node(key, value);
    }
    return true;
}

bool List::search(string key, int& value) {
    if (root) {
        Node* curr = root;
        while (curr) {
            if (curr->key == key) {
                value = curr->value;
                return true;
            }
            curr = curr->next;
        }
    }
    return false;
}

bool List::remove(string key) {
    if (root) {
        Node* curr = root;
        Node* last = curr;
        while (curr) {
            if (curr->key == key) {
                last->next = curr->next;
                delete curr;
                return true;
            }
            last = curr;
            curr = curr->next;
        }
    }
    return false;
}

void List::clear() {
    Node* curr = root;
    Node* next = root;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    root = nullptr;
}