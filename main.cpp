#include "Tests.h"
#include "Query.h"

#include <locale>
#include <iostream>
#include <string>

//#define RUN_TESTS

using namespace std;
using namespace qac;
using namespace tests;

void init() {
    std::setlocale(LC_ALL, "en_US.UTF-8");
}

void tests_run() {
#ifdef RUN_TESTS
    test_TST();
#endif
}

void loadQueryLog(Query& query, string filename) {
    cout << "Loading query logs, please wait..." << endl;
    query.loadHistory(filename);
}

int main() {
    init();
    tests_run();

    Query query;

    cout << "---Initialization---" << endl;
    loadQueryLog(query, "D:\\Downloads\\query_logs.txt"); // change to argv
    cout << "---Initialization complete---" << endl << endl;

    cout << "Enter query (Press ENTER to get suggestions, type \'...\' to exit): " << endl;
    string user_q;
    while (true) {
        cout << "QUERY: ";
        std::getline(cin, user_q);
        if (user_q == "...") {
            break;
        }
        cout << "Processing request..." << endl;
        auto q = query.suggest(user_q);

        int sugg_count = 10;
        if (!q.empty()) {
            cout << sugg_count << " suggestions:" << endl;
            while (!q.empty() && (sugg_count--)) {
                cout << q.front() << endl;
                q.pop();
            }
        } else {
            cout << "No suggestions for this query, sorry..." << endl;
        }
    }
}