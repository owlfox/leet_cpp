#include <vector>
#include <algorithm>
#include <iostream>

#include <unordered_set>

using namespace std;
//https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> charSet(sentence.begin(), sentence.end());
        // for (const auto& elem: charSet) {
        //     cout << elem;
        // }
        return charSet.size() == 26 ? true : false;
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet",) {
    
  Solution sol;
  SECTION("test case 1") {
    auto out = sol.checkIfPangram("thequickbrownfoxjumpsoverthelazydog");
    CHECK(true == out);
  }
  SECTION("test case 2") {
    auto out = sol.checkIfPangram("leetcode");
    CHECK(false == out);
  }
}

TEST_CASE("cases of me",) {
    
  Solution sol;
  SECTION("test case 1") {
    auto out = sol.checkIfPangram("");
    CHECK(false == out);
  }
}