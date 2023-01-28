#ifndef MAIN
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this \
                          // in one cpp file
#include "catch2/catch.hpp"
using namespace Catch::Matchers;
#endif

#include <map>
// https://stackoverflow.com/questions/5493474/graph-implementation-c
struct edge {
    int nodes[2];
    float cost; // add more if you need it
};

using graph = std::map<int, std::vector<edge>>;
graph g;


#ifdef MAIN
int main() {
    
}
#else

TEST_CASE("A simple test") {
  SECTION("test case 1") {
    vector<string> in{"d", "b", "ccc"};
    toSorted(in);
    REQUIRE(in == vector<string>{"b    ", "ccc  ", "d    "});
  }
}
#endif