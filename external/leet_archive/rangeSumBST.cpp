#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
class Solution
{
public:
};

TEST_CASE("A simple test")
{
    Solution sol;
    SECTION("test it")
    {
        
    }
}
