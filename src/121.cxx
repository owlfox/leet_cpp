#include <vector>
#include <algorithm>
#include <iostream>

#include <unordered_map>

using namespace std;
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    //1 <= prices.length <= 1^5
    //0 <= prices[i] <= 10^4
    int maxProfit(vector<int>& prices) {
      if (prices.size() == 0) return 0;

      int max_gain=0, min_index=0;
      for(int i=1; i!=prices.size(); i++) {
        //local max profit only happens when you know the absolute minimun of a valley
        //you can only gain it from selling it after the minimum happened
        // or you can check every price and the prices after it, O(n^2)
        if((prices[i]-prices[min_index])>max_gain) max_gain=prices[i]-prices[min_index];
        if(prices[i]<prices[min_index]) min_index=i;
      }
      return max_gain;
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("cases of leet 121", "[121]") {
    
  Solution sol;
  SECTION("test case 1") {
    vector<int> in{7,1,5,3,6,4};
    auto out = sol.maxProfit(in);
    auto expected = 5;
    CHECK(expected == out);
  }
  SECTION("test case 1") {
    vector<int> in{7,6,4,3,1};
    auto out = sol.maxProfit(in);
    auto expected = 0;
    CHECK(expected == out);
  }

}

TEST_CASE("cases from me 121", "[121]") {
    
  Solution sol;
    SECTION("test case 1") {
    vector<int> in{};
    auto out = sol.maxProfit(in);
    auto expected = 0;
    CHECK(expected == out);
  }

}