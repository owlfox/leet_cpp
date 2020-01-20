#define CATCH_CONFIG_FAST_COMPILE
#include "catch2/catch.hpp"
#include <iostream>
   struct mystruct1 {
       uint8_t data1;
       uint16_t data2;
};

TEST_CASE("A simple test")
{   
    SECTION("test packing")
    {
        REQUIRE( sizeof(mystruct1)  == 4 );
    }
}
