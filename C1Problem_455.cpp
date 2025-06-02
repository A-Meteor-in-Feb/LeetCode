#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children = g.size();
        int cookies = s.size();
        int i = 0, j = 0, content = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < children && j < cookies){
            if(g[i] <= s[j]){
                content += 1;
                i += 1;
                j += 1;
            }else{
                j += 1;
            }
        }
        return content;
    }
};

int main(){
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    Solution solution;

    int result = solution.findContentChildren(g, s);

    cout << "we can make content children as: " << result << endl;

    return 0;
}

/*
* Main idea: greedy algorithm. 
* Time complexity: O(n logn) -- the time compexity of sort()
* Space complexity: O(1) -- if you only calculate the explicitly defined variables.
*                   O(n logn) -- if you count the space occupied when do sorting.
*/