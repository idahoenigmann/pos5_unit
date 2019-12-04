//
// Created by ida on 28.11.19.
//

class List final {
public:
    ~List() {
        while (root) {
            while (curr->next->next) {
                curr = curr->next;
            }
            delete curr->next;
            curr->next = nullptr;
        }
        root = nullptr;
    }

    bool set(string key, int value) {
        if (root) {
            Node* curr{root};
            while(curr->right->key > key) {
                curr = curr->right;
            }
            // curr->key must now be <= key
            if (curr->key = key) {
                curr->value = value;
            } else {
                Node* next = curr->next;
                curr->next = Node*(key, value);
                curr->next->next = next;
            }
        } else {
            root = new Node(key, value);
            return
        }
    }

    bool search(string key, int& value) {

    }

    bool remove(string key) {

    }

    void clear() {

    }

private:
    Node* root{nullptr};
};

struct Node {
    Node(string key, int value) {
        this->key = key;
        this->value = value;
    }

    string key;
    int value;
    Node* next{};
};