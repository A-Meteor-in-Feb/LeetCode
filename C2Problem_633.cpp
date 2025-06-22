#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = static_cast<long long>(std::floor(std::sqrt(c)));
        long long outcome = a * a + b * b;

        while(a < b){
            if(outcome > c){
                --b;
            }else if(outcome < c){
                ++a;
            }else{
                return true;
            }
            outcome = a * a + b * b;
        }
        return false;
    }
};

int main(){
    int c = 5;

    Solution solution;

    bool result;

    result = solution.judgeSquareSum(5);

    cout << result << endl;

    return 0;
}

/*
    这个题目需要注意的事是，当数值很大时，相乘可能会导致结果溢出(overflow)。
    所以需要long long 
    同时注意 类型转换的方法 static_cast。
    还有就是向下取整 std::floor()
    还有就是开方函数 std::sqrt()。
    时间复杂度：O(N) n is eauql to sqrt of c.
*/