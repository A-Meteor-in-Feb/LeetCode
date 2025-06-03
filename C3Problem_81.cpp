#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[l]){
                ++l;
            }else if(nums[mid] == nums[r]){
                --r;
            }else if(nums[mid] < nums[r]){
                if(target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else{
                if(target >= nums[l] && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};

int main(){

    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    Solution solution;

    bool result = solution.search(nums, target);

    cout << result << endl;

    return 0;
}

// 4,5,6,7,8,1,2,3
// 4,4,4,4,4,1,2,3,4,4
// 3,4,4,4,5,1,2