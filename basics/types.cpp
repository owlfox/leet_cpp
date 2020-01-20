#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

enum class Gender {
    Male,
    Female,
    Not_Your_Business,
    NA
};

TEST_CASE( "Test gender enums", "[types]" ) {
    Gender g = Gender::NA;
    int rtn{};
    switch(g) {
        case Gender::Male: {
            rtn = 1;
        } break;
        case Gender::NA: {
            rtn = 0;
        } break;
        default: {
            rtn = -1;
        }
    }
    REQUIRE( rtn  == 0 );
}