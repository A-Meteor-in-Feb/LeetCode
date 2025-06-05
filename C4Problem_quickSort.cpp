#include <iostream>

using namespace std;

void quickSort(vector<int> &nums, int l, int r){
    if(l >= r){
        return;
    }

    // randomly choose a position as the pivot
    int pivot = l + (rand() % (r-l+1));
    int pivot_val = nums[pivot];

    // exchange the pivot and l
    swap(nums[l], nums[pivot]);

    // traverse from [l+1, r]
    int i = l+1, j = r;
    while(true){
        while(i < j && nums[j] >= pivot_val){
            --j;
        }
        while(i < j && nums[i] <= pivot_val){
            ++i;
        }

        // until the left side of the pivot are values all smaller than pivot value.
        // And, the right side of the pivot are values all larger than pivot value.
        if(i == j){
            break;
        }

        // now i != j, 
        // and we know the value on i > pivot value, 
        // while the value on j < pivot value.
        // Therefore, we exchange nums[i] and nums[j].
        swap(nums[i], nums[j]);
    }

    // the place i==j is the new pivot, 
    int new_pivot = nums[i] <= nums[j] ? i : i - 1;
    swap(nums[l], nums[new_pivot]);
    quickSort(nums, l, new_pivot-1);
    quickSort(nums, new_pivot+1, r);

}

/*
* Time complexity: O(n logn) ~ O(n^2)
*/