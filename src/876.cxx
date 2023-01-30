#include <vector>
#include <algorithm>
#include <iostream>

//#include <format>
#include <bits/stdc++.h>

using namespace std;


//https://leetcode.com/problems/middle-of-the-linked-list/description/
/**
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
    //1. fast and slow pointer: time O(N), space O(1)
    //When the # of items in list is even, fast is at the tail(nullptr), while slow is at floor(N/2)+1, which is what the problem is asking for.
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow=slow->next;
            fast=fast->next->next;
            // cout << "slow: " << slow->val << endl;
            // if (fast) {
            //     cout << "fast:" << fast->val << endl;
            // }
        }
        return slow;
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

    vector<int> init_list{1,2,3,4,5};
    //TODO: refactor this to a utility function call
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            if(i==0){continue;}
            nodes[i-1].next = &nodes[i];
            cout << i << ", node: " << nodes[i].val << ", prev: " << nodes[i-1].val << endl;
        }
    }
    auto ans = sol.middleNode(&nodes[0]);

    REQUIRE(ans->val == nodes[2].val);
  }
  SECTION("test case 1") {
    auto nodes = vector<ListNode>(10, {0});

    vector<int> init_list{1,2,3,4,5,6};
    //TODO: refactor this to a utility function call
    for (auto i=0; i<init_list.size();i++){
        if (init_list[i]) {
            nodes[i].val=init_list[i];
            if(i==0){continue;}
            nodes[i-1].next = &nodes[i];
            cout << i << ", node: " << nodes[i].val << ", prev: " << nodes[i-1].val << endl;
        }
    }
    auto ans = sol.middleNode(&nodes[0]);

    REQUIRE(ans->val == nodes[3].val);
  }
}

TEST_CASE("my test cases", "[876]") {
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
    auto ans = sol.middleNode(&nodes[0]);

    REQUIRE(ans->val == nodes[0].val);
  }
}