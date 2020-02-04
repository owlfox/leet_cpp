#ifndef MAIN
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this \
                          // in one cpp file
#include "catch2/catch.hpp"
using namespace Catch::Matchers;
#endif
#include <iostream>
#include <string>
using namespace std;

class Fun {
       private:
	string mName{};

       public:
	Fun(const string &in) { mName = in; }
	string GetName() const { return mName; }
};
class Fun1 {
       private:
	string mName{};

       public:
	Fun1(const string &in) { mName = in; }
	const string &GetName() const { return mName; }
	string &GetRef() { return mName; }
};
TEST_CASE("Test Const!") {
	SECTION("see the diff") {
		Fun f{"hahaha"};
		Fun1 f1{"hehehe"};
		auto s = f.GetName();
		s = "123";
		auto s1 = f1.GetName();
		s1 = "456";

		REQUIRE(f.GetName() == "hahaha");

		REQUIRE(f1.GetName() == "hehehe");
		auto r = f1.GetRef();
		r = "changed";
		REQUIRE(f1.GetName() == "changed");
	}
}

TEST_CASE("const member function") {
	SECTION("const const const!") {

	}
}
