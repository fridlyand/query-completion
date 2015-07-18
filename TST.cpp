//
// Created by Alex Fridlyand on 7/9/2015.
//
#include "TST.h"

#include <iostream>
#include <algorithm>

using namespace qac;
using namespace std;

TST::TST() : count{0},
             root{nullptr} {}

TST::~TST() {
    delete root;
}

void TST::insert(std::string query) {
    ++count;
    root = insert(root, query, 0);
}

TST::Node* TST::insert(Node* node, std::string query, int i) {
    char c = query[i];
    if (!node) {
        node = new Node{};
        node->c = c;
    }
    if (c < node->c) {
        node->left = insert(node->left, query, i);
    } else if (c > node->c) {
        node->right = insert(node->right, query, i);
    } else if (i < (query.size() - 1)) {
        node->mid = insert(node->mid, query, i + 1);
    } else {
        ++node->key_count;
    }

    return node;
}

int TST::find(std::string key) {
    Node* node = find(root, key, 0);
    if (!node) {
        return 0; // can use experimental/optional
    }
    return node->key_count;
}

TST::Node* TST::find(Node* node, std::string key, int i) {
    if (!node) {
        return nullptr;
    }

    char c = key[i];
    if (c < node->c) {
        return find(node->left, key, i);
    } else if (c > node->c) {
        return find(node->right, key, i);
    } else if (i < (key.size() - 1)) {
        return find(node->mid, key, i + 1);
    } else {
        return node;
    }
}

TST::Node::~Node() {
    delete left;
    delete mid;
    delete right;
}

TST::Queue TST::keysWithPrefix(std::string prefix) {
    Queue keys([] (const std::pair<std::string, int> k1, const std::pair<std::string, int> k2) {
        return k1.second < k2.second;
    });
    if (prefix.empty()) {
        collect(root, prefix, keys);
    } else {
        if (auto node = find(root, prefix, 0)) {
            collect(node->mid, prefix, keys);
            if (node->key_count) { // exact match
                keys.push(make_pair(prefix, node->key_count));
            }
        }
    }

    return keys;
}

void TST::collect(TST::Node *node, string prefix, Queue& keys) {
    if (!node) {
        return;
    }
    if (node->key_count) {
        keys.push(make_pair(prefix + node->c, node->key_count));
    }

    if (node->mid) {
        collect(node->mid, prefix + node->c, keys);
    }

    collect(node->left, prefix, keys);
    collect(node->right, prefix, keys);
}

TST::Queue TST::keys() {
    return keysWithPrefix("");
}
