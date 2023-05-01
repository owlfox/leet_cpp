#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

//https://leetcode.com/problems/graph-valid-tree/
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, -1);
        unordered_map<int, set<int> > adj_list;
        for(auto i=0; i<n; i++) {
            set<int> s;
            adj_list[i] = s;
        }
        for(auto e: edges) {
            auto& l0 = adj_list[e[0]];
            auto& l1 = adj_list[e[1]];
            //insert node to neighbor set
            if (l0.find(e[1]) == l0.end() ) {
                
                l0.insert(e[1]);
                //cout <<"insert " << e[1] << "to "<<e[0] <<" len:" <<l0.size() <<endl;
            } else {
                //cout <<"dup in " << e[0] << ": "<<e[1] << endl;
                return false;//duplicate edge
            }
            if (l1.find(e[0]) == l1.end() ) {
                
                l1.insert(e[0]);
                //cout <<"insert " << e[0] << "to "<<e[1] << " len: " << l1.size() << endl;
            } else {
                //cout <<"dup in " << e[1] << ": "<<e[0] << endl;
                return false;//duplicate edge
            }
            //cout << e[0] <<"," <<e[1] << "(end of loop1)" << endl;
        }
        deque<vector<int>> bfs;
        vector<int> root = {0, 0};//next, source
        bfs.push_front(root);
        parent[0] = 0;
        while(!bfs.empty()) {
            int node = bfs.back()[0]; int from = bfs.back()[1]; bfs.pop_back();
            //cout << "bfs: " << node << endl;
            for(auto itr=adj_list[node].begin();itr != adj_list[node].end(); itr++) {
                
                //cout << "current: " << node <<": (adj):" << (*itr) <<" from:" <<from << " parent:" <<parent[*itr] << endl;
                //update unvisited nodes only, and add to bfs queue
                if(parent[*itr] == -1) {
                    parent[*itr] = node;
                    vector<int> next;
                    next.push_back(*itr);
                    next.push_back(node);
                    //cout << "next: " << *itr <<"from: " << node << endl;
                    bfs.push_front(next);

                // if there are more edges that is not from parent && not unvisited, something wrong
                } else if ( *itr != from) {
                    //cout <<*itr<<"BYE: from: "<<from << "parent:" <<parent[*itr]<<endl;
                    return false;
                }
                
            }
            
        } 
        auto count = 0;
        for(auto p: parent) {
            //cout << p << endl;
            if(p != -1) count++;
        }
        //cout << count << endl;
        if(count == n) return true;
        return false;
    }
};
// int run() {
//     Solution s;
//     cout << "test" << endl;
//     return 0;
// }

// #include <catch2/catch_test_macros.hpp>

// TEST_CASE("A dummy test") {
//     SECTION("test case 1") {
        
//         // auto n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
//         // auto i = 0;
//         // for (auto& n : nodes) {
//         //     n.val = i++;
//         // }
//         // auto& root = nodes[0];
//         // root.left = &nodes[1];
//         // root.right = &nodes[5];
//         // nodes[1].left = &nodes[2];
//         // nodes[2].left = &nodes[3];
//         // nodes[2].right = &nodes[4];
//         // Solution sol;
//         // auto rtn = sol.invertTree(&root);
//         // REQUIRE(rtn->right->val == 1);
//         // REQUIRE(rtn->left->val == 5);
//         // REQUIRE(rtn->right->right->right->val == 3);
//     }
// }

