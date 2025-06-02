#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] < target){
                l += 1;
            }else if(numbers[l] + numbers[r] > target){
                r -= 1;
            }else{
                break;
            }
        }
        return vector<int>{l+1, r+1};
    }
};

int main(){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution solution;

    vector<int> result = solution.twoSum(numbers, target);

    cout << result[0] << result[1] << endl;

    return 0;
}

/*
* Key idea: double pointers.
* Time complexity: O(n)
* Space complexity: O(1)
*/