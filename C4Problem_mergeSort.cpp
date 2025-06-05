#include <iostream>

using namespace std;

void mergeSort(vector<int>& nums, vector<int>& cache, int l, int r){
    if(l >= r){
        return;
    }

    int mid = l + (r-l)/2;
    mergeSort(nums, cache, l, mid);
    mergeSort(nums, cache, mid+1, r);

    int i = l, j = mid+1;
    // l and r define the legal range
    // i and j are used for calcualtion
    // pos is for sorting
    // Two range [l(i), mid] & [j, r]
    for(int pos = l; pos <= r; ++pos){
        // j > r -> out of the range, we don't have any values from right side
        // or
        // there are elements smaller than nums[j] in the left range
        if(j > r || (i <= mid && nums[i] <= nums[j])){
            cache[pos] = nums[i++];
        }else{
            cache[pos] = nums[j++];
        }
    }
    // update the original vector
    for(int pos = l; pos <= r; ++pos){
        nums[pos] = cache[pos];
    }
}

/*
* Time complexity: O(n logn)
*/