#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
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
        if(b[row][column] != '0') return dfs(b, row, column + 1);
        for(char i = '1';i <= '9';i++){
            if(valid(b, row, column, i)){
                b[row][column] = i;
                if(dfs(b, row, column + 1)) return true;
                b[row][column] = '0';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};

int main(){
    IOS
    vector<vector<char>> board(100);
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            char a;
            cin >> a;
            board[i].push_back(a);
        }
    }
    Solution Sudoku;
    Sudoku.solveSudoku(board);
    cout << "=================" << '\n';
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}