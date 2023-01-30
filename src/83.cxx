#include <vector>
#include <algorithm>
#include <iostream>

//#include <format>
#include <bits/stdc++.h>

using namespace std;



/** https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //1. trivial soln: time O(N), space O(1)
    // do you have to release the detached nodes?
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* rtn = head;
        while (head != nullptr && head->next != nullptr) {
            //cout << head->val << " v.s. next val:" << head->next->val << endl;
            if (head->next->val == head->val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return rtn;
    }
};
int run() {
    Solution s;
    cout << "test" << endl;
    return 0;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("leet code test cases", "[876]") {
  auto sol = Solution();
  SECTION("test case 1") {
    auto nodes = vector<ListNode>(10, {0});

    vector<int> init_list{1,1,2};
    //TODO: refactor this to a utility function call
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            if(i==0){continue;}
            nodes[i-1].next = &nodes[i];
            cout << i << ", node: " << nodes[i].val << ", prev: " << nodes[i-1].val << endl;
        }
    }
    auto ans = sol.deleteDuplicates(&nodes[0]);

    REQUIRE(1 == ans->val);
    REQUIRE(2 == ans->next->val);
  }
  SECTION("test case 2") {
    auto nodes = vector<ListNode>(10, {0});

    vector<int> init_list{1,1,2,3,3};
    //TODO: refactor this to a utility function call
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            if(i==0){continue;}
            nodes[i-1].next = &nodes[i];
            cout << i << ", node: " << nodes[i].val << ", prev: " << nodes[i-1].val << endl;
        }
    }
    auto ans = sol.deleteDuplicates(&nodes[0]);

    REQUIRE(1 == ans->val);
    REQUIRE(2 == ans->next->val);
    REQUIRE(3 == ans->next->next->val);
  }

  SECTION("test case 3") {
    auto nodes = vector<ListNode>(10, {0});

    vector<int> init_list{1,1,1};
    //TODO: refactor this to a utility function call
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            if(i==0){continue;}
            nodes[i-1].next = &nodes[i];
            cout << i << ", node: " << nodes[i].val << ", prev: " << nodes[i-1].val << endl;
        }
    }
    auto ans = sol.deleteDuplicates(&nodes[0]);

    REQUIRE(1 == ans->val);
    REQUIRE(nullptr == ans->next);
    
  }
}

TEST_CASE("my test cases", "[83]") {
  auto sol = Solution();
  SECTION("test case 1") {
    auto nodes = vector<ListNode>(10, {0});

    vector<int> init_list{1};
    //TODO: refactor this to a utility function call
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            if(i==0){continue;}
            nodes[i-1].next = &nodes[i];
            cout << i << ", node: " << nodes[i].val << ", prev: " << nodes[i-1].val << endl;
        }
    }
    auto ans = sol.deleteDuplicates(&nodes[0]);

    REQUIRE(1 == ans->val);
  }
}