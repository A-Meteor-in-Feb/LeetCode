#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int climbStairs_2(int n){
        int prev_prev = 1, prev = 1, cur = 1;
        for(int i = 2; i <= n; ++i){
            cur = prev_prev + prev;
            prev_prev = prev;
            prev = cur;
        }
        return cur;
    }
};