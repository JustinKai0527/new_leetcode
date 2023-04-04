#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        
        //define dp[i] is n-th maximum product
        vector<int> dp(n + 1);
        
        //notice that the 2 and 3 are not a good initial val
        if(n == 2 || n == 3)  return n - 1;

        //initial state
        dp[2] = 2;
        dp[3] = 3;

        //formula 
        for(int i = 4; i <= n; i++) {

            dp[i] = dp[i - 1] * 1;
            for(int j = 2; j <= i/2; j++) {

                if(dp[i] > dp[i - j] * dp[j])  break;
                dp[i] = dp[i - j] * dp[j];
            }
        }

        return dp[n];
    }
};


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n ; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};