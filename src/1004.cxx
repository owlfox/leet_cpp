#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int window_start=0, i;
        for(i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                --k;
            }
            if (k < 0) {
                k += 1 - nums[window_start++];
            }
        }
        return i - window_start;
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet", "[1004]") {
    Solution sol;

    SECTION("ex1", "[1004, array]") {
    vector<int> in{1,1,1,0,0,0,1,1,1,1,0};
    auto k=2;
    int expected = 6;
    CHECK(expected == sol.longestOnes(in, k));
    }

    SECTION("ex2", "[1004, array]") {
    vector<int> in{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    auto k=3;
    int expected = 10;
    CHECK(expected == sol.longestOnes(in, k));
    
    }
}
