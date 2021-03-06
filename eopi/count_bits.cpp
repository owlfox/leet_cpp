#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <cstdint>
#include <iostream>
#include "catch2/catch.hpp"

class Solution {
public:

    // use int in an way of adders
    int32_t countBitsHacker(int32_t x) {
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
        x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
        x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
        return x;
    }

    int32_t countBits(int32_t x) {
        int32_t count = 0;
        for(size_t i = 0; i< sizeof(int32_t) * 8; i++) {
            count += x & 0x1;
            x >>= 1;
        }
        return count;
    }
};

TEST_CASE("A simple test") {
  Solution sol;
  SECTION("test hacker way") {
    REQUIRE(sol.countBitsHacker(0) == 0);
    REQUIRE(sol.countBitsHacker(0x1000000) == 1);
    REQUIRE(sol.countBitsHacker(1024) == 1);
    REQUIRE(sol.countBitsHacker(3) == 2);
  }
  SECTION("test simple way") {
    REQUIRE(sol.countBitsHacker(0) == 0);
    REQUIRE(sol.countBits(0x1000000) == 1);
    REQUIRE(sol.countBits(1024) == 1);
    REQUIRE(sol.countBits(3) == 2);
  }
}
