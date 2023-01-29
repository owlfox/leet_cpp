#include <vector>
#include <algorithm>
#include <iostream>

#include <unordered_map>

using namespace std;
//https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //unordered_map, faster than map
        std::unordered_map<int, int> seen;
        for(auto i=0; i<nums.size(); i++) {
            int seek = target - nums[i];
            auto it = seen.find(seek);
            if (it == seen.end()) {
                seen[nums[i]] = i;
            } else {
                return {it->second, i};
            }
        }
        return {-1, -1};
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
    vector<int> in{2,7,11,15};
    vector<int> out = sol.twoSum(in, 9);
    vector<int> expected{0, 1};
    CHECK(expected == out);
  }
  SECTION("test case 2") {
    vector<int> in{3, 2, 4};
    vector<int> out = sol.twoSum(in, 6);
    vector<int> expected{1, 2};
    CHECK(expected == out);
  }
  SECTION("test case 3") {
    vector<int> in{3, 3};
    vector<int> out = sol.twoSum(in, 6);
    vector<int> expected{0, 1};
    CHECK(expected == out);
  }
  
}

TEST_CASE("cases of me", "[1]") {
    
  Solution sol;
  SECTION("test case 1") {
    vector<int> in{1, 2};
    vector<int> out = sol.twoSum(in, 1);
    vector<int> expected{-1, -1};
    CHECK(expected == out);
  }
}