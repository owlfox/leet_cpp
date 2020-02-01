#ifndef MAIN
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this \
                          // in one cpp file
#include "catch2/catch.hpp"
#endif
#include <iostream>
#include <string>
#include <limits>
using namespace std;
template<typename T>
T the_sum(const T (&input)[], int N) {
    if (N < 0) throw "N >= 0 please";
    auto sum = T{};
    for(auto i=0; i<N; i++) {
        sum += input[i];
    }
    return sum;
}

int sum(const int input[], int N) {
    if (N < 0) throw "N >= 0 please";
    auto sum{0};
    for(auto i=0; i<N; i++) {
        sum += input[i];
    }
    return sum;
}

int div_zero(int a, int b, int c) {
    if( a <= 0 || b <= 0 || c <= 0) 
        throw "All params should be > 0.";
    else if (a == b == c == 1)
        throw -1;
    
    return a*c + b/c;
}

using namespace Catch::Matchers;

TEST_CASE("Catch exception")
{
    SECTION("test case char* catchable")
    {
        CHECK_NOTHROW( div_zero(1,2,3) );
        CHECK_THROWS( div_zero(1,2,-1) );
        CHECK_THROWS_WITH( div_zero(1,2,-1), Contains( "> 0" ));
    }
    SECTION("test it also throws int")
    {
        CHECK_THROWS_AS( div_zero(1, 1, 1), int );
    }
    SECTION("test sum throws")
    {
        int a[] = {1,2,3};
        CHECK_NOTHROW( sum(a, 2) );
        REQUIRE(sum(a, 2) == 3);
        CHECK_THROWS_WITH( sum(a, -1), Contains( "N >= 0" ));
    }
}

template <typename T>
class List
{
private:
    T *elem; // elem points to an array of sz elements of type T
    size_t sz;

public:
    // constructor: establish invariant, acquire resources
    explicit List(size_t s) : sz{s} 
    {
        elem = new T[s];
    }; 
    // destructor: release resources
    ~List() 
    {
        delete[] elem;
    } 
    // for non-const
    T &operator[](size_t i) 
    {
        return elem[i];
    }
    // for const Vectors (§4.2.1)
    const T &operator[](size_t i) const; 
    size_t size() const { return sz; }
};

#if defined MAIN && defined LIST1
int main()
{
    cout << "hello" << endl;
    {
        // cout << "try allocate a " << std::numeric_limits<int>::max() << " sized List" << endl;
        // List<double> l{std::numeric_limits<long>::max()};
        constexpr auto size{100};
        cout << "try allocate a " << size << " sized List" << endl;
        List<double> l{size};
        cout << "l size: " << l.size() << endl;
    }
    cout << "bye" << endl;
}
#else


TEST_CASE("A simple test suite for List")
{
    SECTION("test case 1 with string")
    {
        List<string> l = List<string>(3);
        l[0] = "test";
        REQUIRE(l.size() == 3);
        REQUIRE(l[0] == "test");
    }
}

#endif