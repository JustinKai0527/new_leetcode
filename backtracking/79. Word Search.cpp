#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int height;
    int width;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), true));
        vector<vector<bool>> tmp = check;
        height = board.size();
        width = board[0].size();

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {

                check[i][j] = false;
                if(board[i][j] == word[0] && backtrack(board, check, word, {i, j}, 0))  return true;
                check[i][j] = true;
                check = tmp;     //reset
            }
        }

        return false;
    }   

    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& check, string word, pair<int, int> index, int n) {
        
        // cout <<n;
        // cout <<endl;
        // for(int i = 0; i < check.size(); i++) {
        //     cout <<"| ";
        //     for(int j = 0; j < check[i].size(); j++) {
        //         cout <<check[i][j]<<" | ";
        //     }
        //     cout <<endl;
        // }
        //assert index.first index.second will not out of boundary
        if(word[n] != board[index.first][index.second])  return false;
        if(n == word.size() - 1)  return true;
        for(auto d: dir) {

            int y = index.first + d.first;
            int x = index.second + d.second;
            if(y < 0 || y >= height || x < 0 || x >= width)  continue;
            if(check[y][x]) {
                check[y][x] = false;
                if(backtrack(board, check, word, {y, x}, n + 1))  return true;
                check[y][x] = true;
            }
        }

        return false;
    }
};