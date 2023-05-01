#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        deque<TreeNode*> bfs;
        auto rtn = root;
        if (root == NULL)
            return root;
        bfs.push_back(root);
        while (!bfs.empty()) {

            root = bfs.front();
            bfs.pop_front();
            
            if (root->left || root->right) {
                swap(root->left, root->right);
            }
            if (root->left)
                bfs.push_back(root->left);
            if (root->right)
                bfs.push_back(root->right);
        }
        return rtn;
    };
};

int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}
#include <catch2/catch_test_macros.hpp>

TEST_CASE("A simple test") {
    SECTION("test case 1") {
        auto nodes = vector<TreeNode>(10, {0});
        auto i = 0;
        for (auto& n : nodes) {
            n.val = i++;
        }
        auto& root = nodes[0];
        root.left = &nodes[1];
        root.right = &nodes[5];
        nodes[1].left = &nodes[2];
        nodes[2].left = &nodes[3];
        nodes[2].right = &nodes[4];
        Solution sol;
        auto rtn = sol.invertTree(&root);
        REQUIRE(rtn->right->val == 1);
        REQUIRE(rtn->left->val == 5);
        REQUIRE(rtn->right->right->right->val == 3);
    }
}

