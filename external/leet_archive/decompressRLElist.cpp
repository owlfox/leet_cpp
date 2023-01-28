#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> rtn;
        for(auto i=0; i<nums.size(); i+=2){
            vector<int> to_append(nums[i+1], nums[i]);
            rtn.insert(rtn.end(), to_append.begin(), to_append.end());
        }
        return rtn;
    }
};

TEST_CASE("A simple test")
{
    Solution sol;
    SECTION("test case 1")
    {
        vector<int> in{1,3,3,3};
        REQUIRE(sol.decompressRLElist(in) == vector<int> {1,1,1,3,3,3});
    }
    SECTION("test case 2")
    {
        vector<int> in{2,4,3,3};
        REQUIRE(sol.decompressRLElist(in) == vector<int> {2,2,2,2,3,3,3});
    }
}
