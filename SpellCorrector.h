#pragma once

#include "Query.h"

#include <memory>
#include <string>
#include <vector>
#include <utility>

namespace qac {
    class Query;
    class SpellCorrector {
    public:
        SpellCorrector(Query& q);

        std::string correct(std::string word);
    private:
        std::vector<std::string> edits1(std::string word); // edit distance of 1
        std::vector<std::string> edits2(std::string word,
                                        std::vector<std::string> edits1); // edit distance of 2
        void filter_known(std::vector<std::string>& words, std::pair<std::string, int>& best_match);

        Query& query;
    };
}


