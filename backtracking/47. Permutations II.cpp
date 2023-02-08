#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> vec;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<bool> check(nums.size(), false);
        backtrack(nums, check);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& check) {

        //termination
        if(vec.size() == nums.size()) {
            result.push_back(vec);
            return;
        }

        int prev = RAND_MAX;
        for(int i = 0; i < nums.size(); i++) {
            
            if(!check[i]) {
                if(prev != RAND_MAX && prev == nums[i])  continue;
                vec.push_back(nums[i]);
                check[i] = true;
                backtrack(nums, check);
                vec.pop_back();
                check[i] = false;
                prev = nums[i];
            }
        }

    }
};