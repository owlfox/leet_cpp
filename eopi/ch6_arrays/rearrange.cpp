#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <cstdint>
#include <vector>
#include <deque>
#include "catch2/catch.hpp"

class Solution {
public:

    // in-place version
    void rearrange(std::vector<int64_t>& coll, int64_t n) {
        std::vector<int64_t>::iterator it = coll.begin();
        std::deque<int64_t> bigger;
         while (it != coll.end()) {
           if(*it == n) {
             bigger.push_front(*it);
             it = coll.erase(it);    
           } else if (*it > n) {
             bigger.push_back(*it);
             it = coll.erase(it);  
           } else {
             it++;
           }
                
        }
        coll.insert(coll.end(), bigger.begin(), bigger.end());
    }

private:

};

TEST_CASE("A simple test") {
  std::vector<int64_t> coll = {3, 3, 3, 1, 2, 2, 2, 0, 0, 0};
  Solution sol;
  SECTION("test it") {
    int64_t target = 1;
    sol.rearrange(coll, target);
    std::vector<int64_t>::iterator it = coll.begin();
    
    REQUIRE(coll.front() <  target);
    REQUIRE(coll.back() >  target);
  }
}
