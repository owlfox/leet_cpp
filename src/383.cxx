#include <vector>
#include <algorithm>
#include <iostream>

#include <map>

using namespace std;
//https://leetcode.com/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magazine_char_count;
        //c++ initializes the map with 0 https://stackoverflow.com/questions/2667355/mapint-int-default-values
        for(char& c: magazine) {
            magazine_char_count[c] += 1;
        }
        for(char& c: ransomNote) {
            magazine_char_count[c] -= 1;
            if (magazine_char_count[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet 383") {
    
  Solution sol;
  SECTION("#1") {
    bool out = sol.canConstruct("a", "b");
    CHECK( false  == out);
  }
  SECTION("#2") {
    bool out = sol.canConstruct("aa", "ab");
    CHECK( false  == out);
  }
  SECTION("#2") {
    bool out = sol.canConstruct("aa", "aab");
    CHECK( true  == out);
  }
  
}
TEST_CASE("cases of mine 383") {
    
  Solution sol;
  SECTION("#1") {
    bool out = sol.canConstruct("a", "a");
    CHECK( true  == out);
  }

  
}

