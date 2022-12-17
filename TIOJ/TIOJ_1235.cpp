// dfs sukodu
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int mat[10][10], ori[10][10];
char chlist[10] = {'R', 'O', 'Y', 'G', 'B', 'I', 'P', 'L', 'W'};
bool is_valid(int row, int column, int val){
    for(int i = 0;i < 9;i++){
        if(mat[row][i] == val || mat[i][column] == val) return false;
    }
    int r = row - row % 3, c = column - column % 3;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(mat[r + i][c + j] == val) return false;
        }
    }
    return true;
}
bool dfs(int row, int column){
    if(mat[row][column] != 0) return dfs(row, column + 1);
    if(column >= 9) return dfs(row + 1, 0);
    if(row >= 9) return true;
    for(int i = 0;i < 9;i++){
        if(is_valid(row, column, (int)chlist[i])){
            mat[row][column] = (int)chlist[i];
            if(dfs(row, column + 1)) return true;;
            mat[row][column] = 0;
        }
    }
    return false;
}
int main(){
    IOS
    memset(mat, 0, sizeof(mat));
    for(int i = 0;i < 9;i++){
        string str;
        cin >> str;
        for(int j = 0;j < 9;j++){
            if(str[j] == '*') mat[i][j] = 0;
            else mat[i][j] = (int)str[j];
            ori[i][j] = mat[i][j];
        }
    }
    dfs(0 ,0);
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            if(ori[i][j] == 0) cout << (char)mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}