#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};

    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2){
            return;
        }
        if(grid[i][j] == 0){
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        for(int k = 0; k < 4; ++k){
            dfs(points, grid, i + directions[k], j + directions[k+1]);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;

        bool flipped = false;
        for(int i = 0; i < m && !flipped; ++i){
            for(int j = 0; j < n && !flipped; ++j){
                if(grid[i][j] == 1){
                    dfs(points, grid, i, j);
                    flipped = true;
                }
            }
        }
        
        int level = 0;
        while(!points.empty()){
            ++level;
            int n_points = points.size();
            while(n_points--){
                auto [r, c] = points.front();
                points.pop();
                grid[r][c] = 2;
                for(int k = 0; k < 4; ++k){
                    int x = r + directions[k], y = c + directions[k+1];
                    if(x >=0 && x < m && y >=0 && y < n){
                        if(grid[x][y] == 2){
                            continue;
                        }
                        if(grid[x][y] == 1){
                            return level;
                        }
                        grid[x][y] = 2;
                        points.push({x, y});
                    }
                }
            }
        }
        return 0;
    }
};