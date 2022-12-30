#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i : nums) {
            mp[i]++;
        }      

        sort(mp.begin(),mp.end());
        for(auto it : mp) {
            cout << it.first <<" "<<it.second<<endl;
        }
        return ans;
    }
};