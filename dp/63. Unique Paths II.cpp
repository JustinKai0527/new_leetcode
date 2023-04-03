#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        //define dp[i][j] is the possible line to (i, j)
        vector<vector<int>> dp(row, vector<int>(col, 0));

        //initial state
        //notcie that if touch to obstacle the dp[i to row][0] is 0
        for(int i = 0; i < row; i++) {  
            if(obstacleGrid[i][0] == 1)  break;
            dp[i][0] = 1;
        }
        //notcie that if touch to obstacle the dp[0][j to col] is 0
        for(int j = 0; j < col; j++) {  
            if(obstacleGrid[0][j] == 1)  break;
            dp[0][j] = 1;
        }            

        //formula dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        //when touch to obstacle the dp[i][j] = 0 
        //because it can't there is no possible way to go to there so dp[i][j] is 0
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {

                if(obstacleGrid[i][j] == 1)  dp[i][j] = 0;
                else  dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[row - 1][col - 1];
    }
};