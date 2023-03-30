#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        
        vector<int> dp(n + 1);
        //initial state
        dp[0] = 1;
        dp[1] = 1;
        //formula dp[n] = dp[n-1] + dp[n-2]
        for(int i = 2; i < n; i++) {

            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};