#include <vector>
#include <algorithm>
#include <iostream>

#include <stack>

using namespace std;
//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> seen;

        for(auto& c: s) {
            switch (c) {
                case '{':
                    seen.push(c);
                    break;
                case '[':
                    seen.push(c);
                    break;
                case '(':
                    seen.push(c);
                    break;
                case '}':
                    if (!seen.empty() && seen.top() == '{') {
                        seen.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!seen.empty() && seen.top() == '[') {
                        seen.pop();
                    } else {
                        return false;
                    }
                    break;
                case ')':
                    if (!seen.empty() && seen.top() == '(') {
                        seen.pop();
                    } else {
                        return false;
                    }
                    break;

                // all the other characters
                default:
                    return false;
            }
        }
        return seen.empty();
        
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet") {
    
  Solution sol;
  SECTION("test case 1") {
    bool out = sol.isValid("()");
    CHECK( true  == out);
  }
  SECTION("test case 2") {
    bool out = sol.isValid("()[]{}");
    CHECK( true == out);
  }
  SECTION("test case 3") {
    bool out = sol.isValid("(]");
    CHECK(out == false);
  }
  SECTION("test case 4") {
    bool out = sol.isValid("]");
    CHECK(out == false);
  }
  SECTION("test case 5") {
    bool out = sol.isValid("[");
    CHECK(out == false);
  }
}

