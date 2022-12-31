#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
        vector<unordered_map<char, int>> col(size), row(size);
        vector<vector<unordered_map<char, int>>> block(3, vector<unordered_map<char, int>>(3));

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {

                char c = board[i][j];
                if(c == '.')  continue;
                else{
                    if(row[i][c]++ > 0 | col[j][c]++ > 0 | block[i/3][j/3][c]++ > 0)  return false;
                }
            }
        }
    }
};
/*
[".",".","4",".",".",".","6","3","."],
[".",".",".",".",".",".",".",".","."],
["5",".",".",".",".",".",".","9","."],
[".",".",".","5","6",".",".",".","."],
["4",".","3",".",".",".",".",".","1"],
[".",".",".","7",".",".",".",".","."],
[".",".",".","5",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."]*/