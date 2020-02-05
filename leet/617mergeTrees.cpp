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

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
 public:
  // inplace update... not sure how to deep copy
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL  && t2 == NULL) return NULL;
    
    TreeNode* rtn = new TreeNode{0};
    rtn->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
    if(t1) rtn->val += t1->val;
    if(t2) rtn->val += t2->val;
    rtn->right = mergeTrees(t1 ? t1->right : NULL,t2 ?  t2->right : NULL);
    return rtn;
  }
};

#ifdef MAIN
int main() {
  return 0
}
#else

TEST_CASE("A simple test") {
  auto sol = Solution();
  SECTION("test case 1") {
    auto nodes = vector<TreeNode>(10, {0});
    auto nodes1 = vector<TreeNode>(10, {0});

    // 3,2,1,r(2)
    auto& root = nodes[0];
    root.val = 2;
    nodes[1].val = 1;
    nodes[2].val = 2;
    nodes[3].val = 3;
    root.left = &nodes[1];
    nodes[1].left = &nodes[2];
    nodes[2].left = &nodes[3];
    
    // r(1),1,2,3
    auto& root1 = nodes1[0];
    root1.val = 1;
    nodes1[1].val = 1;
    nodes1[2].val = 2;
    nodes1[3].val = 3;
    root.right = &nodes1[1];
    nodes1[1].right = &nodes1[2];
    nodes1[2].right = &nodes1[3];

    
    
    REQUIRE(root1.val == 1);
    REQUIRE(root.val == 2);
    auto merged = sol.mergeTrees(&root, &root1);

    REQUIRE(merged->val == 3);
    REQUIRE(merged->left->val == 1);
    REQUIRE(merged->right->val == 1);
  }
}
#endif
