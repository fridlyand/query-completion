#pragma once

#include "TST.h"
#include "SpellCorrector.h"

#include <string>
#include <vector>
#include <array>
#include <memory>

namespace qac {
    class SpellCorrector;
    class Query {
    friend class SpellCorrector;

    public:
        Query();

        void loadHistory(std::string filename);
        void buildCache();
        std::vector<std::string> suggest(std::string query/*, std::string& corr_q*/);
    private:
        static const int ALPHABET_SIZE = 26;
        const int sugg_limit = 10; // suggestion limit
        TST log {};
        std::array<TST::Queue, ALPHABET_SIZE + 1> cache {}; // +1 for the most popular queries
        TST unigrams {};

    private:
        std::unique_ptr<SpellCorrector> corrector;
    };
}


