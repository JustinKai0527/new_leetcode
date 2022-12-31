from typing import List
import collections

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = collections.defaultdict(set)
        col = collections.defaultdict(set)
        squares = collections.defaultdict(set)

        for i in range(9):
            for j in range(9):

                c = board[i][j]
                if c == '.':  continue
                if c not in row[i]:
                    row[i].add(c)
                else:
                    return False
                
                if c not in col[j]:
                    col[j].add(c)
                else:
                    return False
                

                if c not in squares[i//3 + (j//3)*3]:
                    squares[i//3 + (j//3)*3].add(c)
                else:
                    return False
        
        return True