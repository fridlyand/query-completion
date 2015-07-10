//
// Created by Alex Fridlyand on 7/8/2015.
//
#pragma once

#include <array>
#include <string>

namespace qac {
    class Trie {
    public:
        Trie();
        ~Trie();

        void insert(std::string key);
        int find(std::string key);
    private:
        int count = 0;
        static constexpr int radix = 28;
        struct Node;
        Node* root;

        Node* insert(Node* node, std::string key, int i);
        Node* find(Node* node, std::string key, int i);

        struct Node  {
            int value = -1;
            std::array<Node*, radix> children {};

            ~Node();
        };
    };
}