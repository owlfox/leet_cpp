#include <vector>
#include <algorithm>
#include <iostream>

//#include <format>
#include <bits/stdc++.h>

using namespace std;

// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    //Honestly I think the definition of minDepth is hard to understand..
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int L = minDepth(root->left), R = minDepth(root->right);
        return 1 + (min(L, R) ? min(L, R) : max(L, R));
    }
    //TODO iterative solutions.
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[3,9,20,null,null,15,7]", "[111]") {
  auto sol = Solution();
  SECTION("test case 1") {
    auto nodes = vector<TreeNode>(10, {0});
    auto nodes1 = vector<TreeNode>(10, {0});

    // [3,9,20,null,null,15,7]
    vector<int> init_list{3,9,20,0,0,15,7};
    //TODO: refactor this to a utility function call
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i]=init_list[i];
            int root = (i-1)/2;
            cout << i << "root:" << init_list[(i-1)/2] << ", node: " << init_list[i] << endl;
            if(i==0){continue;}
            if (i%2 ==0) {
                cout << "left" << endl;
                nodes[root].right = &nodes[i];
            } else {
                cout << "right" << endl;
                nodes[root].left = &nodes[i];
            }
        }
    }
    auto ans = sol.minDepth(&nodes[0]);

    REQUIRE(ans == 2);
  }
}

TEST_CASE("[3]", "[111]") {
  auto sol = Solution();
  SECTION("test case") {
    auto nodes = vector<TreeNode>(10, {0});
    auto nodes1 = vector<TreeNode>(10, {0});

    vector<int> init_list{3};
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            int root = (i-1)/2;
            cout << i << "root:" << init_list[(i-1)/2] << ", node: " << init_list[i] << endl;
            if(i==0){continue;}
            if (i%2 ==0) {
                cout << "left" << endl;
                nodes[root].right = &nodes[i];
            } else {
                cout << "right" << endl;
                nodes[root].left = &nodes[i];
            }
        }
    }
    auto ans = sol.minDepth(&nodes[0]);

    REQUIRE(ans == 1);
  }
}
TEST_CASE("[3,1]", "[111]") {
  auto sol = Solution();
  SECTION("test case") {
    auto nodes = vector<TreeNode>(10, {0});
    auto nodes1 = vector<TreeNode>(10, {0});

    vector<int> init_list{3, 1};
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            int root = (i-1)/2;
            cout << i << "root:" << init_list[(i-1)/2] << ", node: " << init_list[i] << endl;
            if(i==0){continue;}
            if (i%2 ==0) {
                cout << "left" << endl;
                nodes[root].right = &nodes[i];
            } else {
                cout << "right" << endl;
                nodes[root].left = &nodes[i];
            }
        }
    }
    auto ans = sol.minDepth(&nodes[0]);

    REQUIRE(ans == 2);
  }
}

#define null 0
TEST_CASE("depth 5", "[111]") {
    auto sol = Solution();
    SECTION("test case") {
    auto nodes = vector<TreeNode>(20, {0});
    //https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation-
    cout << "[2,null,3,null,4,null,5,null,6]" << endl;
    nodes[0].val = 2;
    nodes[0].right=&nodes[1];
    nodes[1].val = 3;
    nodes[1].right=&nodes[2];
    nodes[2].val = 4;
    nodes[2].right=&nodes[3];
    nodes[3].val = 5;
    nodes[3].right=&nodes[4];
    nodes[4].val = 6;
    auto ans = sol.minDepth(&nodes[0]);

    REQUIRE(ans == 5);
    }
}
