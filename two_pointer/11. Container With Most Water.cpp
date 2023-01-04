#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size();
        int Max = 0;

        int left = 0, right = size - 1;
        while(left < right) { 
            
            int Area = min(height[left], height[right]) * (right - left);
            Max = max(Max, Area);

            if(height[left] > height[right]) right--;
            else if(height[left] < height[right]) left++;
            else  left++;
        }

        return Max;
    }
};