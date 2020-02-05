#ifndef MAIN
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch2/catch.hpp"
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=341
#endif
#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// return maxsize
size_t toSorted(vector<string> &input, const size_t size_line = 60) {
  sort(input.begin(), input.end());
  auto sizeWord =
      (*max_element(input.begin(), input.end(), [](string s1, string s2) {
        return s1.length() < s2.length();
      })).length();
  // for(auto&s : input) {
  //     s.append(string(sizeWord-s.length(), ' '));
  // }
  return sizeWord;
}
void displayNames(vector<string> &input, size_t sizeWord,
                  size_t lineWidth = 60) {
  auto words_per_line = lineWidth / sizeWord;
  auto lines_count = input.size() / words_per_line;
  auto words_last_row = input.size() % words_per_line;

  string separator(60, '-');
  cout << separator << endl;
  
  for (auto i = 0; i < input.size(); i++) {
    // convert index
    auto c = i % words_per_line;
    auto r = i / words_per_line;
    auto position =
        c < words_last_row ? c * (lines_count + 1) + r : c * lines_count + r;
    cout << input[position];
    //insert spaces
    
    if (c == words_per_line - 1) cout << endl;
    else {
      if(words_per_line > 1) {
        cout <<
      }
    }
  }
}

#ifdef MAIN
int main() {
  auto size{0};
  //how many cases?
  while (cin >> size) {
    vector<string> input;

    for (auto i = 0; i < size; i++) {
      auto name = string();
      cin >> name;
      input.push_back(name);
    }
    auto wordLength = toSorted(input);
    displayNames(input, wordLength);
  }
}
#else

TEST_CASE("A simple test") {
  SECTION("test case 1") {
    vector<string> in{"d", "b", "ccc"};
    toSorted(in);
    REQUIRE(in == vector<string>{"b    ", "ccc  ", "d    "});
  }
}
#endif