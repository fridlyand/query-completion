#include "SpellCorrector.h"

#include <algorithm>

using namespace qac;
using namespace std;

SpellCorrector::SpellCorrector(Query& q) : query(q) {}

string SpellCorrector::correct(string word) {
    if (query.unigrams.find(word)) {
        return word;
    }

    auto edits = edits1(word);
    pair<string, int> best_match {"", -1};
    auto edits_cp = edits;
    filter_known(edits, best_match);

    if (!edits.empty()) {
        return best_match.first;
    }

    edits = edits2(word, edits_cp);
    best_match = {"", -1};
    filter_known(edits, best_match);

    if (!edits.empty()) {
        return best_match.first;
    }

    return word;
}

vector<string> SpellCorrector::edits1(string word) {
    std::vector<string> edits;
    for (auto i = 0; i < word.size(); ++i) { // deletions (remove one letter)
        edits.push_back(word.substr(0, i) + word.substr(i + 1));
    }
    for (auto i = 0; i < static_cast<int>(word.size()) - 1; ++i) { // transpositions (swap adjacent letters)
        edits.push_back(word.substr(0, i) + word[i + 1] + word.substr(i + 2));
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i < word.size(); ++i) { // alterations (change one letter to another)
            edits.push_back(word.substr(0, i) + c + word.substr(i + 1));
        }
        for (int i = 0; i < word.size() + 1; ++i) { // insertions (add a letter)
            edits.push_back(word.substr(0, i) + c + word.substr(i));
        }
    }
    return edits;
}

vector<string> SpellCorrector::edits2(string word, vector<string> ed1) {
    vector<string> edits;
    for (auto edit_w : ed1) {
        auto e1 = edits1(edit_w);
        edits.insert(end(edits), begin(e1), end(e1));
    }
    return edits;
}

void SpellCorrector::filter_known(vector<string> &words, pair<string, int>& best_match) {
    best_match.second = -1;
    words.erase(remove_if(begin(words), end(words), [&](string s) {
        auto freq = query.unigrams.find(s);
        if (!freq) {
            return true;
        }
        auto m = max(freq, best_match.second);
        if (m == freq) {
            best_match.first = s;
            best_match.second = freq;
        }
        return false;
    }), end(words));
}
