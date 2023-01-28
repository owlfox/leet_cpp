#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <cstdint>
#include <iostream>
#include "catch2/catch.hpp"

class Solution {
public:

    // use int in an way of adders
    
    int32_t parity(int32_t x) {
        return countBitsHacker(x) % 2;
    }

private:
    int32_t countBitsHacker(int32_t x) {
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
        x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
        x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
        return x;
    }

};

TEST_CASE("A simple test") {
  Solution sol;
  SECTION("test it") {
    REQUIRE(sol.parity(0) == 0);
    REQUIRE(sol.parity(1) == 1);
    REQUIRE(sol.parity(3) == 0);
    REQUIRE(sol.parity(UINT32_MAX) == 0);
  }
}
