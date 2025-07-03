#include <iostream>

using namespace std;

class Solution{
    int knapsack_01(vector<int> weights, vector<int> values, int n, int w){
        vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
        for(int i = 1; i <= n; ++i){
            int weight = weights[i-1], value = values[i-1];
            for(int j = 1; j <= w; ++j){
                if(j >= weight){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
    int knapsack_complete(vector<int> weights, vector<int> values, int n, int w){
        vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
        for(int i = 1; i <= n; ++i){
            int weight = weights[i-1], value = values[i-1];
            for(int j = 1; j <= w; ++j){
                if(j >= weight){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-weight] + value);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
};