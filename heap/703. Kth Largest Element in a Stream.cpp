#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        
        size = k;
        for(int i: nums) {
            pq.push(i);
        }

        while(pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        
        pq.push(val);
        while(pq.size() > size) {
            pq.pop();
        }
        return pq.top();
    }
};