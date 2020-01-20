#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
using namespace std;
class Solution
{
public:
    int rangeSumBST(TreeNode* root, int L, int R)
    {
        vector<vector<int>>::iterator it = points.begin();
        vector<vector<int>>::iterator next;
        auto rtn = 0;
        auto x_diff = 0, y_diff = 0;
        while ((it+1) != points.end()) {
            next = it + 1;
            x_diff = abs((*it).at(0) - (*next).at(0));
            y_diff = abs((*it).at(1) - (*next).at(1));
            rtn += (x_diff > y_diff) ? x_diff : y_diff;
            it++;
        }
        return rtn;
        
        
    }
};

TEST_CASE("A simple test")
{
    vector<vector<int>> coll = {{1,1},{3,4},{-1,0}};

    vector<vector<int>> coll2 = {{3,2},{-2,2}};
    Solution sol;
    SECTION("test it")
    {
        REQUIRE(sol.minTimeToVisitAllPoints(coll) == 7);
        REQUIRE(sol.minTimeToVisitAllPoints(coll2) == 5);
        
    }
}
