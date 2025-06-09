#include <iostream>

using namespace std;

class Solution {
public:
    void backtracing(vector<int>& nums, int level, vector<vector<int>>& permutations){
        if(level == nums.size() - 1){
            permutations.push_back(nums);
            return;
        }
        for(int i = level; i < nums.size(); ++i){
            swap(nums[i], nums[level]);
            backtracing(nums, level+1, permutations);
            swap(nums[i], nums[level]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtracing(nums, 0, permutations);
        return permutations;
    }
};