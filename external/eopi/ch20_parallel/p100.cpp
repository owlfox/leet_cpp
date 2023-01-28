#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <cstdint>
#include <vector>

#include <iostream>
#include <thread>
#include "catch2/catch.hpp"

void hello()
{
    std::cout<<"Hello Concurrent World\n";
}

TEST_CASE("A simple test") {
  std::vector<int64_t> coll = {3, 3, 3, 1, 2, 2, 2, 0, 0, 0};
  
  std::thread t(hello);
  
  SECTION("test it") {
    t.join();
    REQUIRE(1 == 1);
    // REQUIRE(coll.back() >  target);
  }
}