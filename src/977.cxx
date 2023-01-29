#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (auto& i : nums) {
            i = i*i;
        }
        std::sort(nums.begin(), nums.end());
        return std::move(nums);
    }
    vector<int> sortedSquaresFaster(vector<int>& nums) {
        //TODO: leverage the fact that the input list is sorted.
        return std::move(nums);
    }


    
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("list of 5 with minus and plus ints", "[977]") {
  Solution sol;
  vector<int> in{-4,-1,0,3,10};
  vector<int> out = sol.sortedSquares(in);
  vector<int> expected{0,1,9,16,100};
  CHECK(expected == out);
  
}

TEST_CASE("ex2", "[977]") {
  Solution sol;
  vector<int> in{-7,-3,2,3,11};
  vector<int> out = sol.sortedSquares(in);
  vector<int> expected{4,9,9,49,121};
  CHECK(expected == out);
  
}
