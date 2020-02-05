#ifndef MAIN
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this \
                          // in one cpp file
#include "catch2/catch.hpp"
#endif

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode {
	int mval;

       public:
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x);
	const int val() { return mval; };
};

TreeNode::TreeNode(int x) : mval{x}, left{nullptr}, right{nullptr} {};
class Solution {
       public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) { return t1; }
};

#ifdef MAIN
int main() {
	return 0
}
#else

TEST_CASE("A simple test") {
	SECTION("test case 1") {
		auto nodes = vector<TreeNode>(10, {0});
		auto& root = nodes[0];
		INFO("hi");
		REQUIRE(root.val() == 0);
	}
}
#endif
