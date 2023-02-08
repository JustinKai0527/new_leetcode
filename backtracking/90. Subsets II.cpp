#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //write quick_sort
    //write merge_sort
    vector<vector<int>> result;
    vector<int> vec;
    int prev = RAND_MAX;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int>& nums, int n) {
        
        if(n == nums.size()) {
            result.push_back(vec);
            return;
        }

        if(prev != nums[n]) {
            vec.push_back(nums[n]);
            backtrack(nums, n + 1);
            vec.pop_back();
        }

        prev = nums[n];
        backtrack(nums, n + 1);
    }
    
};