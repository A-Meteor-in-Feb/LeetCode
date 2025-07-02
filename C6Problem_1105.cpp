#include <iostream>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; ++i){
            int w = books[i-1][0], h = books[i-1][1];
            dp[i] = dp[i-1] + h;
            for(int j = i-1; j > 0; --j){
                int prev_w = books[j-1][0], prev_h = books[j-1][1];
                w += prev_w;
                if(w <= shelfWidth){
                    h = max(h, prev_h);
                    dp[i] = min(dp[i], dp[j-1]+h);
                }else{
                    break;
                }
            }
        }
        return dp[n];
    }
};