#include <iostream>

using namespace std;

class Solution {
public:
    void backtracing(vector<vector<int>>& combination, vector<int>& pick, int pos, int n , int k){
        if(pick.size() == k){
            combination.push_back(pick);
            return;
        }
        for(int i = pos; i <= n; ++i){
            pick.push_back(i);
            backtracing(combination, pick, i+1, n, k);
            pick.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combination;
        vector<int> pick;
        backtracing(combination, pick, 1, n, k);
        return combination;
    }
};