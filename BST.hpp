#include <iostream>

template <class T>
class Node {
    Node* left;
    Node* right;
    T value;
public:
    Node(T val) {
        left = nullptr;
        right = nullptr;
        value = val;
    }
    void insert(T v) {
        if (v == value) {
            return;
        }
        Node* &next = v > value ? right : left;
        if (next == nullptr) {
            next = new Node(v);
        } else {
            next->insert(v);
        }
    }
    Node* find(T v) {
        if (v == value) {
            return this;
        }
        Node* &next = v > value ? right : left;
        if (next == nullptr) {
            return nullptr;
        } else {
            return next->insert(v);
        }
    }
    Node* remove(T v) {
        if (v < value) {
            if (left == nullptr) {
                return this;
            }
            left = left->remove(v);
        } else if (v > value) {
            if (right == nullptr) {
                return this;
            }
            right = right->remove(v);
        } else {
            if (left == nullptr && right == nullptr) {
                delete this;
                return nullptr;
            }
            if (left == nullptr) {
                value = right->value;
                right = right->remove(value);
                return this;
            }
            if (right == nullptr) {
                value = left->value;
                left = left->remove(value);
                return this;
            }
            Node* smallest = right->getSmallest();
            value = smallest->value;
            right = right->remove(value);
        }
        return this;
    }
    Node* getSmallest() {
        if (left == nullptr) {
            return this;
        }
        return left->getSmallest();
    }
    Node* getLargest() {
        if (right == nullptr) {
            return this;
        }
        return right->getLargest();
    }
    void inOrder() {
        if (left != nullptr)
            left->inOrder();
        std::cout << value << std::endl;
        if (right != nullptr)
            right->inOrder();
    }
};
