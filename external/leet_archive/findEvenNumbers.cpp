#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto count = 0;
        for(auto n: nums){
            double n_double = static_cast<double>(n);
            int num = static_cast<int>(log10(n_double));
            if ((num % 2)) count += 1;
        }
        return count;
    }
};

TEST_CASE("A simple test")
{
    Solution sol;
    SECTION("test case 1")
    {
        vector<int> in{12,345,2,6,7896};
        REQUIRE(sol.findNumbers(in) == 2);
    }
    SECTION("test case 2")
    {
        vector<int> in{555,901,482,1771};
        REQUIRE(sol.findNumbers(in) == 1);
    }
}
