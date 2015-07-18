//
// Created by Alex Fridlyand on 7/16/2015.
//

#include "Helpers.h"

#include <algorithm>
#include <locale>
#include <sstream>
#include <iterator>

using namespace std;
using namespace qac;

std::string& helpers::ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

std::string& helpers::rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

std::string& helpers::trim(std::string& s) {
    return ltrim(rtrim(s));
}

bool helpers::filter(std::string& s) {
//        if (str.at(str.size() - 1) == '\r') {
//            str.pop_back();
//        }
    if (!s.empty()) {
        if (s.front() == '-') {
            return false;
        }
    }
    for (char& c : s) {
        if (isalpha(c)) {
            c = tolower(c);
        } else if (c != ' ' && c != '-') {
            return false;
        }
    }
    return true;
}

bool helpers::isWordStart(char space, char firstLet) {
    return isWordEnd(firstLet, space);
}

bool helpers::isWordEnd(char lastLet, char space) {
    if (isalpha(lastLet) && space == ' ') {
        return true;
    }
    return false;
}

vector<string> helpers::splitWords(string sentence) {
    vector<string> tokens;
    istringstream iss{sentence};
//    copy(istream_iterator<string>(iss),
//         istream_iterator<string>(),
//         ostream_iterator<string>(cout, "\n"));
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(tokens));
    return tokens;
}

void helpers::print_queue(TST::Queue& q, ostream& ostr) {
    while(!q.empty()) {
        auto pair = q.top();
        ostr << pair.first.c_str() << " " << pair.second << endl;
        q.pop();
    }
}