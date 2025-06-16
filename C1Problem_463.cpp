#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    if(i == 0){
                        ++p;
                    }
                    if(i == m-1){
                        ++p;
                    }
                    if(j == 0){
                        ++p;
                    }
                    if(j == n-1){
                        ++p;
                    }
                    if(i+1 < m && grid[i+1][j] == 0){
                        ++p;
                    }
                    if(i-1 >=0 && grid[i-1][j] == 0){
                        ++p;
                    }
                    if(j+1 < n && grid[i][j+1] == 0){
                        ++p;
                    }
                    if(j-1 >= 0 && grid[i][j-1] == 0){
                        ++p;
                    }
                }
            }
        }

        return p;
    }
};

