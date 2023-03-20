#include <vector>
#include <algorithm>
#include <iostream>

#include <unordered_map>
#include <cctype>
#include <string>



using namespace std;
//https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    /*

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000

    */
    string convert(string s, int numRows) {
      if (numRows == 1) {
          return s;
      }
      
      vector<string> rows(numRows);
      int curr_row = 0;
      bool going_down = false;
      
      for (char c : s) {
          rows[curr_row] += c;
          if (curr_row == 0 || curr_row == numRows - 1) {
              going_down = !going_down;
          }
          curr_row += going_down ? 1 : -1;
      }
      
      string result;
      for (string row : rows) {
          result += row;
      }
      
      return result;
    }

};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet 6", "") {
    
  Solution sol;
  SECTION("test case 1") {
    auto in{"PAYPALISHIRING"};
    auto out = sol.convert(in, 3);
    CHECK("PAHNAPLSIIGYIR" == out);
  }

  SECTION("test case 2") {
    auto in{"PAYPALISHIRING"};
    auto out = sol.convert(in, 4);
    CHECK("PINALSIGYAHRPI" == out);
  }

  SECTION("test case 3") {
    auto in{"A"};
    auto out = sol.convert(in, 1);
    CHECK("A" == out);
  }


}

TEST_CASE("cases from me 125", "") {
    
  Solution sol;
    SECTION("test case 1") {

  }

}