#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};

    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& can_reach, int r, int c){
        if(can_reach[r][c]){
            return;
        }
        can_reach[r][c] = true;
        for(int i = 0; i < 4; ++i){
            int x = r + directions[i], y = c + directions[i+1];
            if(x >= 0 && x < heights.size() && y >=0 && y < heights[0].size() && heights[r][c] <= heights[x][y]){
                dfs(heights, can_reach, x, y);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        vector<vector<int>> can_reach_p_and_a;
        for(int i = 0; i < m; ++i){
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n-1);
        }
        for(int i = 0; i < n; ++i){
            dfs(heights, can_reach_p, 0, i);
            dfs(heights, can_reach_a, m-1, i);
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(can_reach_p[i][j] && can_reach_a[i][j]){
                    can_reach_p_and_a.push_back({i, j});
                }
            }
        }
        return can_reach_p_and_a;
    }
};

