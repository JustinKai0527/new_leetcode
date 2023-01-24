#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


//max_heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i : nums) {
            mp[i]++;
        }      

        auto comp = [&mp] (int n1, int n2)->bool { return mp[n1] > mp[n2];};
        priority_queue<int, vector<int>, decltype(comp)> max_heap(comp);

        for(auto it: mp) {
            max_heap.push(it.first);
            if(max_heap.size() > k)  max_heap.pop();
        }

        while(!max_heap.empty()) {
            ans.push_back(max_heap.top());
            max_heap.pop();
        }

        return ans;
    }
};

//quick_sort
