#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x, mid, x_div_mid;
        while(l <= r){
            mid = l + (r - l)/ 2;
            x_div_mid = x/mid;
            if(mid == x_div_mid){
                return mid;
            }
            if(mid < x_div_mid){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};

int main(){

    int x = 8;

    Solution solution;

    int result = solution.mySqrt(x);

    cout << result << endl;

    return 0;
}

/*
* The expression mid = (l + r) /2 can overflow because l + r might exceed the type's limit,
* so we instead write mid = l + (r - l)/2.
* likewise, directly computing mid*mid can overflow, so we compare mid with x / mid instead.
* 
* Time complexity: O(n)
* Space complexity: O(1)
*/