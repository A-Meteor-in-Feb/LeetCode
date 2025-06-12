#include <iostream>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0];});
        int target1 = points[0][0];
        int target2 = points[0][1];
        int arrow = 1;
        for(auto & p: points){
            target1 = max(target1, p[0]);
            target2 = min(target2, p[1]);
            if(target1 <= target2){
                continue;
            }else{
                target1 = p[0];
                target2 = p[1];
                ++arrow;
            }
        }
        return arrow;
    }
};