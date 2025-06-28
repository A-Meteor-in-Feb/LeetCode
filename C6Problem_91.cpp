#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int prev = s[0]-'0';
        if(prev == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        vector<int> dp(n+1, 1);
        for(int i = 2; i <= n; ++i){
            int cur = s[i-1] - '0';
            if((prev == 0 || prev > 2) && cur == 0){
                return 0;
            }
            if((prev < 2 && prev > 0) || (prev == 2 && cur <= 6)){
                if(cur == 0){
                    dp[i] = dp[i-2];
                }else{
                    dp[i] = dp[i-2] + dp[i-1];
                }
            }else{
                dp[i] = dp[i-1];
            }
            prev = cur;
        }
        return dp[n];
    }
};