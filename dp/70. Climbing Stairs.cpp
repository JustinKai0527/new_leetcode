#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        if(n <= 1)  return n;
        vector<int> dp(n + 1);
        //initial state
        dp[1] = 1;
        dp[2] = 2;

        //due to we can climb stair 2 floor 1 floor
        //so the dp[n] = dp[n-1] climb 1 floor dp[n-2] climb 2 floor
        //formula dp[n] = dp[n-1] + dp[n-2]
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};