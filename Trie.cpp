#include "Trie.h"

using namespace qac;

Trie::Trie() : count{0},
               root{nullptr} {}

Trie::~Trie() {
    delete root;
}

void Trie::insert(std::string key) {
    ++count;
    root = insert(root, key, 0);
}

Trie::Node* Trie::insert(Node* node, std::string key, int i) {
    if (!node) {
        node = new Node{};
    }
    if (i == key.size()) {
        node->value = count;
        return node;
    }

    char c = key[i];
    node->children.at(c % radix) = insert(node->children.at(c % radix), key, i + 1);
    return node;
}

int Trie::find(std::string key) {
    Node* node = find(root, key, 0);
    if (!node) {
        return -1; // can use experimental/optional
    }
    return node->value;
}

Trie::Node* Trie::find(Node* node, std::string key, int i) {
    if (!node) {
        return nullptr;
    }
    if (i == key.size()) {
        return node;
    }
    char c = key[i];
    return find(node->children[c % radix], key, i + 1);
}

Trie::Node::~Node() {
    for (auto node : children) {
        delete node;
    }
}
