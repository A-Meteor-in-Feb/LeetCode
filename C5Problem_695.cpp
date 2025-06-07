#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> directions = {0, -1, 0, 1, 0}; // left, up, right, down

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        return(1 + dfs(grid, r+1, c) + dfs(grid, r-1, c) + dfs(grid, r, c+1) + dfs(grid, r, c-1));
    }
};

/*
* Time complexity:
*   In the worst case, dfs will be called on every cell and each DFS explores all
*   connected land cells exactly once.
*   Thus, overall work is proportional to the total number of cells in the grid.
*   O(mn).
*
* Space Complexity:
*   We use the call stack for recursion.
*   In the worst case, the depth of the recursive calls can be as alrge as the area
*   of that island, which is O(mn).
*   O(mn). 
*/