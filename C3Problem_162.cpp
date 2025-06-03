#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //important
        if(n == 1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        int l = 0, r = n-1;
        int middle = l + (r - l)/2;
        while(l < r){
            if(nums[middle] > nums[middle-1] && nums[middle] > nums[middle+1]){
                break;
            }else if(nums[middle+1] > nums[middle]){
                l = middle + 1;
            }else if(nums[middle - 1] > nums[middle]){
                r = middle;
            }
            middle = l + (r - l)/2;
        }
        return middle;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 1};

    Solution solution;
    int result = solution.findPeakElement(nums);

    cout << result << endl;

    return 0;
}

/*
* key idea: binary search
* Time complexity: O(n)
* Space complexity: O(1)
*/