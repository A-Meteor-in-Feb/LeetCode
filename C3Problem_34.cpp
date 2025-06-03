#include <iostream>

using namespace std;

class Solution {
public:
    // Time Complexity O(n) -- worst situation
    vector<int> searchRange_0(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return vector<int>{-1, -1};
        }
        int r = 0, l = nums.size()-1, middle = 0;
        middle = r + (l - r)/2;
        while(nums[middle] != target){
            if(nums[middle] < target){
                r = middle + 1;
            }else{
                l = middle;
            }
            middle = r + (l - r) / 2;
        }
        int start = middle, end = middle;
        while(nums[start] == nums[middle]){
            start--;
        }
        while(nums[end] == nums[middle]){
            end++;
        }
        return vector<int>{start+1, end-1};
    }


    vector<int> searchRange(vector<int>& nums, int target){
        int n = nums.size();

        if(n == 0){
            return {-1, -1};
        }

        int left = findTarget(nums, target);
        if(left == n || nums[left] != target){
            return {-1, -1};
        }

        int right = findTarget(nums, target+1) - 1;
        return {left, right};

    }

private:
    int findTarget(const vector<int>& nums, int x){
        int l = 0, r = nums.size(); //[l, r)
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] < x){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};

int main(){
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution solution;

    vector<int> result = solution.searchRange(nums, target);

    cout << result[0] << " & " << result[1] << endl;

    return 0;
}


/*
* Main idea: use binary search to find upper and lower bound respectively.
* Time complexity: O(n logn)
* Space complexity: O(1)
*/