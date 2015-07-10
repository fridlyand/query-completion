//
// Created by Alex Fridlyand on 7/8/2015.
//
#pragma once

#include <array>
#include <string>
#include <queue>

namespace qac {
    class TST {
    public:
        TST();
        ~TST();

        void insert(std::string key);
        int find(std::string key);
        std::queue<std::string> keys(std::string prefix);
    private:
        int count = 0;
        struct Node;
        Node* root;

        Node* insert(Node* node, std::string key, int i);
        Node* find(Node* node, std::string key, int i);
        void collect(Node* node, std::string prefix, std::queue<std::string>& q);
        struct Node {
            int value = -1;
            char c = -1;
            Node* left = nullptr;
            Node* mid = nullptr;
            Node* right = nullptr;

            ~Node();
        };
    };
}