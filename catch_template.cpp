#ifndef MAIN
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this \
                          // in one cpp file
#include "catch2/catch.hpp"
#endif

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifdef MAIN
int main()
{
    return 0
}
#else

TEST_CASE("A simple test")
{
    SECTION("test case 1")
    {
        REQUIRE(false);
    }
}
#endif