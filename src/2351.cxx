#include <vector>
#include <algorithm>
#include <iostream>

#include <unordered_map>

using namespace std;
//https://leetcode.com/problems/first-letter-to-appear-twice/description/
class Solution {
public:
    char repeatedCharacter(string s) {
        //but you can actually use unordered_set to reduce space complexity
        std::unordered_map<char, int> seen;
        for(auto i=0; i<s.size(); i++) {
            auto c = s[i];
            auto it = seen.find(c);
            if (it == seen.end()) {
              seen[c] = 1;
            } else {
              return c;
            }
        }
        return '!';
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet", "[1]") {
    
  Solution sol;
  SECTION("test case 1") {
    auto out = sol.repeatedCharacter("abccbaacz");
    CHECK('c' == out);
  }
  SECTION("test case 2") {
    auto out = sol.repeatedCharacter("abcdd");
    CHECK('d' == out);
  }
}

TEST_CASE("cases of me", "[1]") {
    
  Solution sol;
  SECTION("test case 1") {
    auto out = sol.repeatedCharacter("abc");
    CHECK('!' == out);
  }
}