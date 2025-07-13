# Query Completion

> Personal tiny C++11 search-auto-completion and spelling-correction engine (circa 2015).

![C++](https://img.shields.io/badge/language-C%2B%2B11-blue)

## Features
* ⚡ **Fast prefix lookup** – queries stored in a Ternary Search Tree (TST) with frequency counts.  
* 📝 **Query popularity ranking** – suggestions are ordered by historical frequency.  
* 🪄 **Spell-correction** – Norvig edit-distance ≤ 2, backed by unigram counts.  
* 🚀 **Cold-start caches** – global and first-letter caches for instant first-keystroke results.  
* 🖥️ **Interactive CLI** – type a query, press <kbd>Enter</kbd>, get up to 10 suggestions.

## Build

```bash
git clone https://github.com/fridlyand/query-completion.git
cd query-completion
mkdir build && cd build
cmake ..        # requires CMake ≥3.0 and a C++11 compiler
make            # produces the `qac` binary
