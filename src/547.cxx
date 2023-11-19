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

//https://leetcode.com/problems/number-of-provinces/?envType=study-plan-v2&envId=graph-theory


class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjList) {
        visited[node] = 1;
        for(int i=0; i<adjList[node].size(); i++) {
            if(!visited[adjList[node][i]]) {
                dfs(adjList[node][i], visited, adjList);
            }
        }
    }

    void bfs(int start, vector<int>& visited, vector<vector<int>>& adjList) {
        deque<int> dq;
        dq.push_back(start);
        visited[start] = 1;

        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();

            for (int i = 0; i < adjList[node].size(); ++i) {
                if (!visited[adjList[node][i]]) {
                    visited[adjList[node][i]] = 1;
                    dq.push_back(adjList[node][i]);
                }
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected, bool useDFS = true) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        vector<int> visited(n, 0);
        int count = 0;

        // Build the adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (useDFS) {
                    dfs(i, visited, adjList);
                } else {
                    bfs(i, visited, adjList);
                }
                count++;
            }
        }
        return count;
    }
};

// int run() {
//     Solution s;
//     cout << "test" << endl;
//     return 0;
// }

#include <catch2/catch_test_macros.hpp>

TEST_CASE("A dummy test") {
    SECTION("test case 1") {
        
        
        Solution sol;
        int rtn;

        // Test example 1
        vector<vector<int>> isConnected1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        rtn = sol.findCircleNum(isConnected1);
        cout << "Number of provinces (Example 1): " << rtn << endl;
        REQUIRE(rtn == 2);

        // Test example 2
        vector<vector<int>> isConnected2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        rtn = sol.findCircleNum(isConnected2);
        cout << "Number of provinces (Example 2): " << rtn << endl;
        REQUIRE(rtn == 3);

        // Test example 3
        vector<vector<int>> isConnected3 = {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
        rtn = sol.findCircleNum(isConnected3);
        cout << "Number of provinces (new test case #3): " << rtn << endl;
        REQUIRE(rtn == 2);
    
    
        
   
    }
}

