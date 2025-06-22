#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindromeRange(const string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = (int)s.length() - 1;
        while (i < j && s[i] == s[j]) {
            ++i;
            --j;
        }
        // 要么整个串本来就是回文，要么跳过 s[i] 或 s[j] 后其中一个区间是回文
        return isPalindromeRange(s, i + 1, j) || isPalindromeRange(s, i, j - 1);
    }
};

int main(){
    string s = "aba";

    Solution solution;

    bool result;

    result = solution.validPalindrome(s);

    cout << result << endl;

    return 0;
}

/*
    你不一定删哪个，所以不可以用贪心算法遇到哪个删哪个。
    因为可能删不一样的位置就会有不一样的结果 例如 eceec
    时间复杂度：O(n)
*/