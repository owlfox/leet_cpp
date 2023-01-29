#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
//#include <format>
#include <bits/stdc++.h>


using namespace std;

//https://leetcode.com/problems/maximum-average-subarray-i/description/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, ans = INT_MIN, curr = 0, right = k-1;
        auto sum = std::reduce(nums.begin()+left, nums.begin()+right);
        for (; right < nums.size(); right++) {
            // do logic here to add arr[right] to curr
            
            // you can also do this in a foreach, or accumulate. According to stackoveflow, reduce is sometimes faster
            //auto sum = std::reduce(nums.begin()+left, nums.begin()+right+1);
            // but it is too slow! extra time need to be spend on O(n+n*k)

            //cout << sum << ", begin:" << *(nums.begin()+left) <<" ends:" << *(nums.begin()+right) << endl;
            
            //Alteratively, using the idea of sliding window, here it's O(n+ n*2)
            sum += *(nums.begin()+right);
            if (sum > ans) ans = sum;
            sum -= *(nums.begin()+left);
            
            left++;
        }

        return (double)ans/(double)k;
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("leet example 1", "[643]") {
  Solution sol;
  vector<int> in{1,12,-5,-6,50,3};
  double out = sol.findMaxAverage(in, 4);
  CHECK(12.75 == out);
  
}
TEST_CASE("leet example 2", "[643]") {
  Solution sol;
  vector<int> in{5};
  double out = sol.findMaxAverage(in, 1);
  CHECK(5 == out);
}

TEST_CASE("upper limit test case", "[643]") {
  Solution sol;
  vector<int> in(100000, -10000);
  double out = sol.findMaxAverage(in, 10801);
  CHECK(-10000 == out);
}
