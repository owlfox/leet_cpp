#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <cstdint>
#include <vector>
#include <deque>
#include "catch2/catch.hpp"

class Solution {
public:

    
    size_t max_diff(int *a, size_t m, size_t n, size_t z) {
        
    }

private:

};

TEST_CASE("A simple test") {
  int coll[][2][2] = {3, 7, 4, 1, 2, 2, 2, 0};
  Solution sol;
  SECTION("test it") {
    int64_t target = 1;
    sol.rearrange(coll, target);
    std::vector<int64_t>::iterator it = coll.begin();
    
    REQUIRE(coll.front() <  target);
    REQUIRE(coll.back() >  target);
  }
}
