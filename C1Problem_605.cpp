#include <iostream>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        
        if(m == 1 && n == 1){
            if(flowerbed[0] == 0){
                return true;
            }
        }
        
        if(n > (m+1)/2){
            return false;
        }else{
            if(m == 2 && n == 1){
                if(flowerbed[0] == 0 && flowerbed[1] == 0){
                    return true;
                }else{
                    return false;
                }
            }
        }

        int i = 0;

        while(i < m && n != 0){
            if(i == 0){
                if(flowerbed[0] == 0 && flowerbed[1] == 0){
                    flowerbed[0] = 1;
                    n -= 1;
                    i += 1;
                }
                i += 1;
            }else if(i+1 <= m -1){
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    n -= 1;
                    i += 1;
                }
                i += 1;
            }else if(i == m-1){
                if(flowerbed[m-1] == 0 && flowerbed[m-2] == 0){
                    flowerbed[m-1] = 1;
                    n -= 1;
                }
                i += 1;
            }
        }

        return n == 0;
        
    }
};