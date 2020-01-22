#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//only works when sizeof(int)==4
    vector<int> countBits(int n) {
        vector<int> rtn(n+1);
        for(auto i=0; i<=n; i++) {
            auto x=i;
            x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
            x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
            x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
            x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
            x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
            rtn[i] = x;
        }
        return rtn;
    }
    
};


TEST_CASE("A simple test")
{
    Solution sol;
    SECTION("test case 1")
    {
        auto rtn = sol.countBits(3);
        REQUIRE(rtn[0] == 0);
        REQUIRE(rtn[1] == 1);
        REQUIRE(rtn[2] == 1);
        REQUIRE(rtn[3] == 2);

        auto rtn1 = sol.countBits(2);
        REQUIRE(rtn1[0] == 0);
        REQUIRE(rtn1[1] == 1);
        REQUIRE(rtn1[2] == 1);
    }
}