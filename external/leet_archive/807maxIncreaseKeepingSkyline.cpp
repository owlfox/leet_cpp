#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
using namespace std;
class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> colMax, rowMax;
        size_t w = grid.at(0).size();
        vector<int>::iterator it;
        auto total = 0;
        for (size_t i = 0; i < w; i++)
        {
            rowMax.push_back(*max_element(grid.at(i).begin(), grid.at(i).end()));
        }
        for (size_t i = 0; i < w; i++)
        {
            auto min = 0;
            for (size_t j = 0; j < w; j++)
            {
                if (min < grid.at(j).at(i))
                    min = grid.at(j).at(i);
            }
            colMax.push_back(min);
        }

        for (size_t i = 0; i < w; i++)
        {
            for (size_t j = 0; j < w; j++)
            {   
                cout << grid.at(i).at(j);
                if (colMax.at(i) > rowMax.at(j)) {
                    
                    total += rowMax.at(j) - grid.at(i).at(j);
                    
                } else {
                    total += colMax.at(i) - grid.at(i).at(j);
                }
            }
            cout << endl;
        }
        return total;
    }
};

TEST_CASE("A simple test")
{
    vector<vector<int>> coll = {{8, 4, 8, 7},
                                {7, 4, 7, 7},
                                {9, 4, 8, 7},
                                {3, 3, 3, 3}};

    vector<vector<int>> coll2 = {{3, 0, 8, 4},
                                 {2, 4, 5, 7},
                                 {9, 2, 6, 3},
                                 {0, 3, 1, 0}};
    Solution sol;
    SECTION("test it")
    {
        REQUIRE(sol.maxIncreaseKeepingSkyline(coll2) == 35);
        REQUIRE(sol.maxIncreaseKeepingSkyline(coll) == 0);
        
    }
}
