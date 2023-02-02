#include <vector>
#include <algorithm>
#include <iostream>

//not allowed on leet
//#include <ranges>

using namespace std;
//https://leetcode.com/problems/maximum-69-number/description/
class Solution {
public:
    int maximum69Number (int num) {
        int input = num, rtn = 0;
        vector<int> digits;
        while (num > 0) {
          auto remainder = num % 10;
          num = num / 10;
          digits.insert(digits.begin(), remainder);
        }
        for(auto& digit: digits) {
          if(digit == 6) {
            digit = 9;
            break;
          }
        }
        // ranges::reverse_view rv {digits};
        // int base = 1;
        // for(auto& digit: rv) {
        //   rtn += base*digit; base *= 10;
        // }
       
        int base = 1;
        for(auto i=digits.size()-1; i!=-1; i--) {
          cout << digits[i] << endl;
          rtn += base*(digits[i]); base *= 10;
        }
        
        return rtn;
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet", "[1323]") {
    
  Solution sol;
  SECTION("#1") {
    auto out = sol.maximum69Number(9669);
    CHECK(9969 == out);
  }
  SECTION("#2") {
    auto out = sol.maximum69Number(9969);
    CHECK(9999 == out);
  }
  SECTION("#3") {
    auto out = sol.maximum69Number(9999);
    CHECK(9999 == out);
  }
  
}
