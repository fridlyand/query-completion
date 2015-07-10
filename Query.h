//
// Created by Alex Fridlyand on 7/9/2015.
//
#pragma once

#include "TST.h"

#include <string>
#include <queue>

namespace qac {
    class Query {
    public:
        void loadHistory(std::string filename);
        std::queue<std::string> suggest(std::string query);
    private:
        TST tst {};
    };
}


