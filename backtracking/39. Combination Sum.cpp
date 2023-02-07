#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> vec;

    void backtrack(vector<int>& candidates, int sum, int target) {

        if(sum == target) {
            result.push_back(vec);
            return;
        }  else if(sum > target)  return;

        for(int i: candidates) {
            
            vec.push_back(i);
            backtrack(candidates, sum + i, target);
            vec.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        backtrack(candidates, 0, target);

        return result;
    }
};