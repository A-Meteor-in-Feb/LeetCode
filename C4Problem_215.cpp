#include <iostream>

using namespace std;

class Solution {
public:
    // store the values rather than swap. 
    // in order to save time.
    int findKthLargest(vector<int>& nums, int k){
        int pivot = rand() % nums.size();
        int pivot_val = nums[pivot];
        vector<int> larger, equal, smaller;
        for(int num: nums){
            if(num > pivot_val){
                larger.push_back(num);  
            }else if(num < pivot_val){
                smaller.push_back(num);
            }else{
                equal.push_back(num);
            }
        }
        if(k <= larger.size()){
            return findKthLargest(larger, k);
        }
        if(k > larger.size() + equal.size()){
            return findKthLargest(smaller, k - larger.size() - equal.size());
        }
        return pivot_val;
    }


    int findKthLargest_1(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        int pos = nums.size() - k;
        return nums[pos];
    }

private:
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }

        int pivot = l + (rand() % (r-l+1));
        int pivot_val = nums[pivot];

        swap(nums[l], nums[pivot]);
        int i = l+1, j = r;

        while(true){
            while(i < j && nums[j] >= pivot_val){
                j--;
            }
            while(i < j && nums[i] <= pivot_val){
                i++;
            }
            if(i == j){
                break;
            }

            swap(nums[i], nums[j]);
        }

        int new_pivot = nums[i] <= nums[j] ? i : i - 1;
        swap(nums[l], nums[new_pivot]);
        quickSort(nums, l, new_pivot-1);
        quickSort(nums, new_pivot+1, r);
    }
};

int main(){

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution solution;

    int result = solution.findKthLargest(nums, k);
    cout << result << endl;

    return 0;
}