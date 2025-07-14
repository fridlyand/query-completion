#pragma once

#include "TST.h"

#include <string>
#include <vector>
#include <queue>
#include <iostream>

namespace qac {
    namespace helpers {
        std::string& ltrim(std::string& s);
        std::string& rtrim(std::string& s);
        std::string& trim(std::string& s);

        bool filter(std::string& s);
        bool isWordStart(char space, char firstLet);
        bool isWordEnd(char lastLet, char space);
        std::vector<std::string> splitWords(std::string sentence);

        void print_queue(TST::Queue& q, std::ostream& ostr);
    }
}