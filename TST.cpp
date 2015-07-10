//
// Created by Alex Fridlyand on 7/9/2015.
//
#include "TST.h"

using namespace qac;
using namespace std;

TST::TST() : count{0},
               root{nullptr} {}

TST::~TST() {
    delete root;
}

void TST::insert(std::string key) {
    ++count;
    root = insert(root, key, 0);
}

TST::Node* TST::insert(Node* node, std::string key, int i) {
    char c = key[i];
    if (!node) {
        node = new Node{};
        node->c = c;
    }
    if (c < node->c) {
        node->left = insert(node->left, key, i);
    } else if (c > node->c) {
        node->right = insert(node->right, key, i);
    } else if (i < (key.size() - 1)) {
        node->mid = insert(node->mid, key, i + 1);
    } else {
        node->value = count;
    }

    return node;
}

int TST::find(std::string key) {
    Node* node = find(root, key, 0);
    if (!node) {
        return -1; // can use experimental/optional
    }
    return node->value;
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

queue<string> TST::keys(std::string prefix) {
    queue<string> q;
    collect(find(root, prefix, 0), prefix, q);
    return q;
}

void TST::collect(TST::Node *node, string prefix, queue<string>& q) {
    if (!node) {
        return;
    }
    if (node->value != -1) {
        q.push(prefix);
    }
    if (node->left) {
        collect(node->left, prefix + node->left->c, q);
    }
    if (node->mid) {
        collect(node->mid, prefix + node->mid->c, q);
    }
    if (node->right) {
        collect(node->right, prefix + node->right->c, q);
    }
}
