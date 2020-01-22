#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include <iostream>
#include <vector>
using namespace std;
// not sure how to use RAII..
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {
    }
    void linkNodes(TreeNode* left_node=nullptr, TreeNode* right_node=nullptr) {
        left = left_node;
        right = right_node;
    }
};
class Solution {
public:
    //DFS
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        cout << "on: " << root << endl;
        cout << "  left: " << root->left << endl;
        cout << "  right: " << root->right << endl;
        if(root->left) {
            cout << "  go left->" << root->left << endl;
            root->left = removeLeafNodes(root->left, target);
        }
        if(root->right) {
            cout << "  go right->" << root->right << endl;
            root->right = removeLeafNodes(root->right, target);
        }
        if(root->left == nullptr && root->right == nullptr && target == root->val) {
            cout << "  returning&deleting ->" << root << endl;
            // delete root;
            return nullptr;
        } else {
            cout << "  returning" << endl;
            return root;
        }
    }
};

TEST_CASE("A simple test")
{
    Solution sol;
    SECTION("test case 1")
    {
        // Input: root = [1,2,3,2,null,2,4], target = 2
        // Output: [1,null,3,null,4]
        auto root = new TreeNode(1);
        cout << "root: " << root << endl;
        auto n1 = new TreeNode(2);
        cout << "n1: " << n1 << endl;
        auto n2 = new TreeNode(3);
        cout << "n2: " << n2 << endl;
        auto n3 = new TreeNode(2);
        cout << "n3: " << n3 << endl;
        auto n4 = new TreeNode(2);
        delete n4;
        n4 = nullptr;
        cout << "n4: " << n4 << endl;
        auto n5 = new TreeNode(2);
        cout << "n5: " << n5 << endl;
        auto n6 = new TreeNode(4);
        cout << "n6: " << n6 << endl;
        
        root->linkNodes(n1, n2);
        n1->linkNodes(n3, nullptr);
        n2->linkNodes(n5, n6);
        sol.removeLeafNodes(root, 2);
        REQUIRE( root->left == nullptr );
        REQUIRE( root->right->right->val == 4 );
        REQUIRE( root->right->right->val == 4 );
    }
    SECTION("test case 2")
    {
        // Input: root = [1,1,1], target = 1
        // Output: []
        vector<TreeNode*> nodes(7);
        cout << "case 2" << endl;
        for(auto& n: nodes) cout << n << endl;
        nodes[0] = new TreeNode(1);
        nodes[1] = new TreeNode(1);
        nodes[2] = new TreeNode(1);

        nodes[0]->linkNodes(nodes[1], nodes[2]);
        nodes[0]->val = 1;
        nodes[1]->val = 1;
        nodes[2]->val = 1;
        nodes[0] = sol.removeLeafNodes(nodes[0], 1);
        REQUIRE( nodes[0] == nullptr );
    }
}
