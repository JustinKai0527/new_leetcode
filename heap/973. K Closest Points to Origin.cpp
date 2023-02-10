#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> result;
        int size = points.size();
        int index = 0;

        //lambda [ captures ] ( params ) -> ret { body }
        //       [ captures ] ( params ) { body }
        //       [ captures ] { body }
        auto cmp = [] (pair<int, int> a, pair<int, int> b) -> bool { return (a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second); };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(int i = 0 ; i < size; i++) {

            pq.push({points[i][0], points[i][1]});
            if(pq.size() > k)  pq.pop();
        }


        for(int i = 0; i < k; i++) {
            result.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return result;
    }
};