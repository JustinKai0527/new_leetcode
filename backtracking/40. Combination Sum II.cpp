#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




// 5% faster  sooooo shy
class Solution {
public:

    vector<vector<int>> result;
    vector<int> vec;
    int prev = RAND_MAX;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, 0);
        return result;
    }

    void backtrack(vector<int> candidates, int sum, int target, int index) {

        if(sum == target) {
            result.push_back(vec);
            return;
        }
        if(index == candidates.size() || sum > target)  return;

    
        if(prev != candidates[index]) {
            vec.push_back(candidates[index]);
            backtrack(candidates, sum + candidates[index], target, index + 1);
            vec.pop_back();
        }

        prev = candidates[index];
        backtrack(candidates, sum, target, index + 1);
    }
};