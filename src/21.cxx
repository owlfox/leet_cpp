#include <vector>
#include <algorithm>
#include <iostream>

//#include <format>
#include <bits/stdc++.h>

using namespace std;



// https://leetcode.com/problems/merge-two-sorted-lists

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //This should be done in place, or say the memory stored the linked list nodes should be reused.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* rtn = nullptr;
        if (list1->val < list2->val) {
            rtn = list1;
            list1 = list1->next;
        } else {
            rtn = list2;
            list2 = list2->next;
        }

        //Time complexity should be O(len(l1)+len(l2))
        ListNode* current = rtn;
        while(list2 && list1) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current=current->next;
        }
        // if one of the list exhausted first
        if (list1) {
            current->next=list1;
        } else if (list2) {
            current->next=list2;
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

//return a new list
vector<ListNode> init_list(vector<int> init_list) {
    auto nodes = vector<ListNode>();
    if (init_list.size()) {
        nodes = vector<ListNode>(init_list.size(), {0});
        for (auto i=0; i<init_list.size();i++){
            if (init_list[i]) {
                nodes[i].val=init_list[i];
                if(i==0){continue;}
                nodes[i-1].next = &nodes[i];
                cout << i << ", node: " << nodes[i].val << ", prev: " << nodes[i-1].val << endl;
            }
        }
    }
    return nodes;
}

TEST_CASE("leet code test cases 21", "[21 list]") {
  auto sol = Solution();
  SECTION("test case 1") {
    
    
    vector<int> init_list1{1,2,4};
    auto nodes1 = init_list(init_list1);
    vector<int> init_list2{1,3,4};
    auto nodes2 = init_list(init_list2);

    auto ans = sol.mergeTwoLists(&nodes1[0], &nodes2[0]);

    vector<int> gold{1,1,2,3,4,4};
    auto head = ans;
    for (auto i=0; i<gold.size();i++){
        cout << "Checking " << i << "th " << gold[i] << endl;
        REQUIRE(gold[i] == head->val);
        head=head->next;
    } 
  }

  SECTION("test case 2") {
    
    
    vector<int> init_list1{};
    auto nodes1 = init_list(init_list1);
    vector<int> init_list2{};
    auto nodes2 = init_list(init_list2);

    auto ans = sol.mergeTwoLists(&nodes1[0], &nodes2[0]);

    
    REQUIRE(nullptr == ans);
   
  }
  SECTION("test case 3") {
    
    
    vector<int> init_list1{};
    auto nodes1 = init_list(init_list1);
    vector<int> init_list2{0};
    auto nodes2 = init_list(init_list2);

    auto ans = sol.mergeTwoLists(&nodes1[0], &nodes2[0]);

    vector<int> gold{0};
    auto head = ans;
    for (auto i=0; i<gold.size();i++){
        cout << "Checking " << i << "th " << gold[i] << endl;
        REQUIRE(gold[i] == head->val);
        head=head->next;
    } 
  }
}

TEST_CASE("my test cases 21", "[21 list]") {
  auto sol = Solution();
  SECTION("test case 1") {

  }
}