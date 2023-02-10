#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;    //larger group
    priority_queue<int> max_heap;                               //smaller group 

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(min_heap.size() == 0)  min_heap.push(num);
        else if(max_heap.size() == 0) {
            
            if(num > min_heap.top())  max_heap.push(num);
            else {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }

        if(max_heap.size() < min_heap.size()) {             //push to max_heap

            if(num < min_heap.top())  max_heap.push(num);
            else {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }  else {
            
            if(num > max_heap.top())  min_heap.push(num);
            else {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        
        if(max_heap.size() > min_heap.size())  return max_heap.top();
        else if(max_heap.size() < min_heap.size())  return min_heap.top();
        return double((max_heap.top() + min_heap.top()) / 2);
    }
};