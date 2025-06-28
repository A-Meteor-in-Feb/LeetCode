#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int max_side = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side * max_side;
    }
};

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0', '0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    Solution solution;

    int result = solution.maximalSquare(matrix);

    cout << result << endl;

    return 0;
}