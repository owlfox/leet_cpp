#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

// it breaks when x == INT_MIN
int absolute_value(int x){
 return x < 0 ? -x : x;
}

TEST_CASE("A simple test") {
  SECTION("test ") {
	  REQUIRE(absolute_value(-10) == 10);
  }
}
