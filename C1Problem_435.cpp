#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){return a[1]< b[1];});
        int removed = 0, prev_end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] < prev_end){
                ++removed;
            }else{
                prev_end = intervals[i][1];
            }
        }
        return removed;
    }
};

int main(){
    vector<vector<int>> intervals = {{1, 2}, {2, 4}, {1, 3}};
    Solution solution;
    int result = solution.eraseOverlapIntervals(intervals);
    cout << result << endl;

    return 0;
}