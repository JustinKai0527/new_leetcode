#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int row, column;
    int count = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea;
        column = grid.size();
        row = grid[0].size();

        for(int i = 0; i < column; i++) {
            for(int j = 0; j < row; j++) {
                if(grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, i, j);
                    maxArea = max(maxArea, count);
                }
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {

        if(i < 0 || i >= column || j < 0 || j >= row || grid[i][j] == 0)  return;
        grid[i][j] = 0;
        count++;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};