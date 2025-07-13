# query-completion

A small C++11 program that loads a text file of historic search queries and returns auto-completion suggestions plus simple spell-correction.

## Contents

* **src/**
  * `main.cpp` – command-line interface
  * `Query.*` – prefix search and ranking logic
  * `TST.*` – ternary search-tree implementation
  * `SpellCorrector.*` – edit-distance spell checker
  * helper headers for strings and I/O
* **CMakeLists.txt**

## Build

```bash
git clone https://github.com/fridlyand/query-completion.git
cd query-completion
mkdir build && cd build
cmake ..          # CMake ≥3.0, C++11 compiler required
make              # produces the executable ‘qac’
