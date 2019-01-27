#include "BST.hpp"

int main() {
    auto x = new Node<int>(1);
    x->insert(2);
    x->insert(1);
    x->insert(5);
    x->insert(0);
    x->insert(-1);
    x->insert(3);
    x->insert(11);
    x->insert(-11);
    x->remove(1);
    x->remove(-1);
    x->inOrder();
    auto y = new Node<std::string>("abc");
    y->insert("a");
    y->insert("b");
    y->insert("abcde");
    y->inOrder();
    return 0;
}
