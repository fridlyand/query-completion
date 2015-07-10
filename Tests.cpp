//
// Created by Alex Fridlyand on 7/9/2015.
//
#include "Tests.h"

#include "Trie.h"
#include "TST.h"

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace qac {
    namespace tests {
        void test_TST() {
            cout << "---TST_TEST---Begin-" << endl;
            cout << "---" << endl;

            string test_result = "";
            {
                cout << "Adding keys: " << endl;

                TST tst;
                vector<string> keys_insert = {"hello", "my", "name", "is", "Alex", "Halloween"};
                for_each(begin(keys_insert), end(keys_insert), [&tst](string key) {
                    tst.insert(key);
                    cout << "Key: " << key << std::endl;
                });

                cout << "Finding keys: " << endl;
                test_result = "";
                vector<string> keys_find = {"hello", "my", "name", "is", "Alex", "Halloween"};
                for_each(begin(keys_find), end(keys_find), [&tst, &test_result](string key) {
                    int val = tst.find(key);
                    cout << "Key: ";
                    if (val != -1) {
                        cout << "FOUND: " << key.c_str() << ", value: " << val << endl;
                    } else {
                        cout << "NOT FOUND " << key.c_str() << endl;
                        if (test_result.empty()) {
                            test_result = "TEST FAILED";
                        }
                    }
                });

                cout << (test_result.empty() ? "TEST SUCCEDED" : test_result.c_str()) << endl;
            }
            {
                vector<string> keys = {"by", "by sea", "by sea sells", "by sea sells she", "by sea sells she shells",
                                       "by sea sells she shells shore", "by sea sells she shells shore the"};
                cout << "Adding keys: " << endl;
                TST tst;
                for_each(begin(keys), end(keys), [&tst](string key) {
                    tst.insert(key);
                    cout << "Key: " << key << std::endl;
                });
                std::string pref = "by";
                cout << "Looking for keys with prefix: \'" << pref << "\'" << endl;
                auto q = tst.keys("by");
                int count = 0;
                while (!q.empty()) {
                    cout << "FOUND: " << q.front() << endl;
                    q.pop();
                    ++count;
                }
                test_result = "";
                if (count != keys.size()) {
                    test_result = "TEST FAILED";
                }
                cout << (test_result.empty() ? "TEST SUCCEDED" : test_result.c_str()) << endl;
            }
        }
    }
}