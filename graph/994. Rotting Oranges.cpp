#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int column = grid.size(), row = grid[0].size();
        queue<pair<int, int>> bfs;
        int phase = -1;
        int count = 0;
        
        for(int i = 0; i < column; i++) {
            for(int j = 0; j < row; j++) {

                if(grid[i][j] == 2)  bfs.push({i, j});
                else if(grid[i][j] == 1)  count++;
            }
        }

        if(count == 0)  return 0;

        while(!bfs.empty()) {
            int size = bfs.size();
            queue<pair<int, int>> tmp;
            // cout <<size<<endl;
            for(int i = 0; i < size; i++) {
                
                pair<int, int> cur = bfs.front();
                bfs.pop();
                // cout <<cur.first<<cur.second;
                for(int j = 0; j < 4; j++) {

                    int y = cur.first + dir[j].first;
                    int x = cur.second + dir[j].second;

                    if(y >= 0 && y < column && x >= 0 && x < row) {
                        if(grid[y][x] == 1) {  
                            tmp.push({y, x});
                            grid[y][x] = 2;
                            count --;
                        }
                    }
                }
            }
            phase++;
            bfs = tmp;
        }
        
        return (count != 0)? -1: phase; 
    }
};