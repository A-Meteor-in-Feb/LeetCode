#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), sum = 0;
        vector<int> candies = vector<int>(n, 1);
        // From left to right, compare the right one with the left one
        // Cause you can only see the left one, rather than the right one.
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        // From right to left, compare the left one wtih the right one
        // Because you can see the left one now. 
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        sum = accumulate(candies.begin(), candies.end(), 0);
        return sum;
    }
};

int main(){
    vector<int> ratings = {1, 0, 2};
    Solution solution;
    int result = solution.candy(ratings);
    cout << "yes" << result << endl;
    return result;
}

/*
* Key idea: greedy algorithm
* Time complexity: O(n^2)
* Space complexity: O(n)
*/