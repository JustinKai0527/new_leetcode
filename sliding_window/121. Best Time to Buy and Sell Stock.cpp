#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int size = prices.size();
        int max_profit = 0;
        int min_index = 0;
        for(int i = 0; i < size; i++) {
            
            min_index = min(min_index, i);
            max_profit = max(max_profit, (prices[i] - prices[min_index]));
        }
        return max_profit;
    }
};