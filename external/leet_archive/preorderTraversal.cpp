#ifndef MAIN
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this \
                          // in one cpp file
#include "catch2/catch.hpp"
#endif

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> history;
        vector<int> rtn;

        if (root == NULL)
            return rtn;
        history.push(root);
        while (!history.empty()) {
            auto current = history.top();
            history.pop();
            if (current->right)
                history.push(current->right);
            if (current->left)
                history.push(current->left);
            rtn.push_back(current->val);
        }

        return rtn;
    }
};
#ifdef MAIN
int main() {
    return 0
}
#else

TEST_CASE("A simple test") {
    SECTION("test case 1") {
        auto nodes = vector<TreeNode>(10, {0});

        // 3,2,1,r(2)
        auto& root = nodes[0];
        root.val = 2;
        nodes[1].val = 1;
        nodes[2].val = 2;
        nodes[3].val = 3;
        root.left = &nodes[1];
        nodes[1].left = &nodes[2];
        nodes[2].left = &nodes[3];
        nodes[2].right = &nodes[4];
        root.right = &nodes[5];
        Solution sol;
        auto rtn = sol.preorderTraversal(&root);
        REQUIRE(rtn == vector<int>{2, 1, 2, 3, 0, 0});
    }
}
#endif
