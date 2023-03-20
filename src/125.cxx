#include <vector>
#include <algorithm>
#include <iostream>

#include <unordered_map>
#include <cctype>
#include <string>



using namespace std;
//https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    /*
    1 <= s.length <= 2 * 10^5
    s consists only of printable ASCII characters.
    */
    bool isPalindrome(std::string s) {
        // Convert the string to lowercase and remove non-alphanumeric characters
        s.erase(std::remove_if(
          s.begin(),
          s.end(),
          [](unsigned char c) { return !std::isalnum(c); }
        ), s.end());
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
        // Check if the resulting string reads the same forward and backward
        return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet 125", "") {
    
  Solution sol;
  SECTION("test case 1") {
    auto in{"A man, a plan, a canal: Panama"};
    auto out = sol.isPalindrome(in);
    CHECK(true == out);
  }

  SECTION("test case 2") {
    auto in{"race a car"};
    auto out = sol.isPalindrome(in);
    CHECK(false == out);
  }

  SECTION("test case 3") {
    auto in{" "};
    auto out = sol.isPalindrome(in);
    CHECK(true == out);
  }


}

TEST_CASE("cases from me 125", "") {
    
  Solution sol;
    SECTION("test case 1") {

  }

}