#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //cost[0] == 0 floor cost[1] == 1 floor

        vector<int> dp(cost.size() + 1);
        //transition state dp[n] = min(dp[n - 1] + cost[n - 2], dp[n - 2] + cost[n - 3])
        //so initial state 
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= (cost.size()); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 1] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};