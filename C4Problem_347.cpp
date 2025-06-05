#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(int num: nums){
            ++counts[num];
        }
        unordered_map<int, vector<int>> buckets;
        for(auto [num, count]: counts){
            buckets[count].push_back(num);
        }
        vector<int> top_k;
        for(int count = nums.size(); count >= 0; --count){
            // in C++ 20 buckets.contains(count) if ok.
            if(buckets.contains(count)){
                for(int num: buckets[count]){
                    top_k.push_back(num);
                    if(top_k.size() == k){
                        return top_k;
                    }
                }
            }
        }
        return {0,0};
    }
};

int main(){

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution solution;

    vector<int> result = solution.topKFrequent(nums, k);

    for(int num: result){
        cout << num << endl;
    }
    
    return 0;
}