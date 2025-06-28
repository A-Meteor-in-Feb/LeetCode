#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            for(const string& word: wordDict){
                int m = word.length();
                if(i >= m && s.substr(i-m, m) == word){
                    dp[i] = dp[i] || dp[i-m];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[n];
    }
};