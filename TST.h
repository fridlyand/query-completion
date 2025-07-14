#pragma once

#include <string>
#include <queue>
#include <utility>
#include <functional>

namespace qac {
    class TST {
    public:
        using Queue = std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>,
                std::function<bool(const std::pair<std::string, int> k1, const std::pair<std::string, int> k2)>>;

        TST();
        ~TST();

        void insert(std::string query);
        int find(std::string key);
        Queue keys();
        Queue keysWithPrefix(std::string prefix);
    private:
        int count = 0;
        struct Node;
        Node* root;

        Node* insert(Node* node, std::string query, int i);
        Node* find(Node* node, std::string key, int i);
        void collect(Node *node, std::string prefix, Queue& keys);
        struct Node { // storing words as keys
            int key_count = 0;
            char c = -1;

            Node* left = nullptr;
            Node* mid = nullptr;
            Node* right = nullptr;

            ~Node();
        };
    };
}