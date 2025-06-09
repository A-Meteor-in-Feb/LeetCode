#include <iostream>

using namespace std;

/*
* Because the adjacency relation between cities is symmetric, 
* this two-dimensional array is a symmetric matrix. 
* And since each city belongs to its own city-circle, 
* all of the diagonal entries are 1. 
* In this problem, each row represents a node 
* and each column indicates whether there is an adjacent node. 
* Therefore, there are exactly n nodes in total; 
* each node can have at most n edges 
* (meaning it’s adjacent to every city) 
* and at least one edge 
* (meaning its city-circle contains only itself).
*/
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
        visited[i] = true;
        for(int j = 0; j < isConnected.size(); ++j){
            if(isConnected[i][j] == 1 && !visited[j]){
                dfs(isConnected, j, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                dfs(isConnected, i, visited);
                ++count;
            }
        }
        return count;
    }
};

