#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> vec;

    void backtrack(vector<int>& nums, int n) {

        if(n == nums.size()) {
            result.push_back(vec);
            return;
        }

        vec.push_back(nums[n]);
        backtrack(nums, n + 1);                 //got index i elem
        vec.pop_back();

        backtrack(nums, n + 1);                 //not got index i elem
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int size = n;
        backtrack(nums, 0);
        return result;
    }
};