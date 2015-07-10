//
// Created by Alex Fridlyand on 7/9/2015.
//
#include "Query.h"

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace qac;
using namespace std;

namespace {
    int getFileSize(ifstream& ifs) {
        ifs.seekg(0, ios_base::end);
        int size = ifs.tellg();
        ifs.seekg(0, ios_base::beg);
    }

    bool filter(std::string& str) {
        for (char& c : str) {
            if (isalpha(c)) {
                c = tolower(c);
            } else if (c != ' ' && c != '-') {
                return false;
            }
        }
        return true;
    }
}

void Query::loadHistory(string filename) {
    ifstream ifs{filename, ios_base::binary};
    if (!ifs) {
        cout << "Can't open log file.";
        return;
    }

//    int size = getFileSize(ifs);
//    string buffer;
//    buffer.resize(size, ' ');
//    char* begin = &*begin(buffer);
//    ifs.read(begin, size);

    for(std::string line; getline(ifs, line);)
    {
        if (filter(line)) {
            tst.insert(line);
        }
    }
}

queue<string> Query::suggest(string query) {
    return tst.keys(query);
}
