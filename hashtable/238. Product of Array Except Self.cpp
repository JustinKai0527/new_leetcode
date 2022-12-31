#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> right(size,1);
        vector<int> left(size,1);
        vector<int> ans(size);

        for(int i = 1; i < size; i++) {
            right[i] = nums[i-1] * right[i-1];
            // cout <<right[i]<<" ";
        }
        // cout <<endl;
        for(int i = size - 2; i >= 0; i--) {
            left[i] = nums[i+1] * left[i+1];
            // cout <<left[i]<<" ";
        }
        // cout <<endl;
        for(int i = 0; i < size; i++) {
            ans[i] = right[i] * left[i];
        }

        return ans;
    }
};