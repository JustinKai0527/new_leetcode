#include <iostream>
#include <vector>

using namespace std;


class SoGlution {
public:

    vector<vector<int>> result;
    vector<int> vec;
    vector<bool> check;

    void backtrack(vector<int> nums) {

        if(vec.size() == nums.size()) {
            result.push_back(vec);
            return;
        }        

        for(int i = 0; i < nums.size(); i++) {

            if(!check[i]) {
                check[i] = true;
                vec.push_back(nums[i]);
                backtrack(nums);
                vec.pop_back();
            }
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {

        check.resize(nums.size(), false);
        backtrack(nums);
        return result;    
    }
};


class Solution {
public:

    vector<vector<int>> result;
    vector<int> vec;

    void backtrack(vector<int> remain) {

        if(remain.size() == 0) {
            result.push_back(vec);
            return;
        }        

        for(int i = 0; i < remain.size(); i++) {

            vec.push_back(remain[i]);
            remain.erase(remain.begin() + i);
            backtrack(remain);
            remain.insert(remain.begin() + i, vec.back());
            vec.pop_back();
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> remain = nums;
        backtrack(remain);
        return result;    
    }
};