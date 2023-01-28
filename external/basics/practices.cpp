#ifndef MAIN
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this \
                          // in one cpp file
#include "catch2/catch.hpp"
using namespace Catch::Matchers;
#endif
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// You should define Pair here:
// (Use as many lines as you need!)
// ...
// ...
class Pair
{
public:
    int a{0}, b{0};
    int sum();
};
int Pair::sum()
{
    return a + b;
}
TEST_CASE("Test Pair")
{
    SECTION("test pair works")
    {
        Pair p;
        p.a = 100;
        p.b = 200;
        REQUIRE(p.a + p.b == p.sum());
    }
}
namespace pair2
{
class Pair
{
public:
    int *pa, *pb;
    Pair(int a, int b){
        pa = new int(a);
        pb = new int(b);
    };
    Pair(const Pair & pair){
        pa = new int(*pair.pa);
        pb = new int(*pair.pb); 
    };
    ~Pair(){
        delete pa;
        delete pb;
    };
    int sum();
};
int Pair::sum() {
    return *pa + *pb;
}
TEST_CASE("Test Pair 2 .. still silly")
{
    SECTION("test pair works")
    {
        Pair p(15, 16);
        Pair q(p);
        Pair *hp = new Pair(23, 42);
        delete hp;
        REQUIRE(*p.pa + *p.pb == p.sum());
    }
}
} // namespace pair2



int div_zero(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        throw "All params should be > 0.";
    else if (a == b == c == 1)
        throw - 1;

    return a * c + b / c;
}

TEST_CASE("Catch exception")
{
    SECTION("test case char* catchable")
    {
        CHECK_NOTHROW(div_zero(1, 2, 3));
        CHECK_THROWS(div_zero(1, 2, -1));
        CHECK_THROWS_WITH(div_zero(1, 2, -1), Contains("> 0"));
    }
    SECTION("test it also throws int")
    {
        CHECK_THROWS_AS(div_zero(1, 1, 1), int);
    }
}

