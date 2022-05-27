// 37. Sudoku Solver
// Runtime: 28 ms, faster than 72.10% of C++ online submissions for Sudoku Solver.
class Solution {
public:
    bool valid(vector<vector<char>>& b, int row, int column, char value){
        for(int i = 0;i < 9;i++){
            if(b[row][i] == value || b[i][column] == value) return false; //check row and column
        }
        int r = row - row % 3, c = column - column % 3;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(b[r + i][c + j] == value) return false; // check grid
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& b, int row, int column){
        if(row == 9) return true;
        if(column == 9) return dfs(b, row + 1, 0);
        if(b[row][column] != '.') return dfs(b, row, column + 1);
        for(char i = '1';i <= '9';i++){
            if(valid(b, row, column, i)){
                b[row][column] = i;
                if(dfs(b, row, column + 1)) return true;
                b[row][column] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};