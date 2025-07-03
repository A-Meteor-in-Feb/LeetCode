#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        int target = sum / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i){
            int num = nums[i-1];
            for(int j = 1; j <= target; ++j){
                if(j >= num){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-num];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};