#include <iostream>

using namespace std;

class Solution {
public:

    void backtracing(vector<vector<string>>& solutions, vector<string>& board, vector<bool>&column, vector<bool>& ldiag, vector<bool>& rdiag, int row){
        int n = board.size();
        if(row == n){
            solutions.push_back(board);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(column[i] || ldiag[n-row+i-1] || rdiag[row+i]){
                continue;
            }
            board[row][i] = 'Q';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;
            backtracing(solutions, board, column, ldiag, rdiag, row+1);
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false);
        vector<bool> ldiag(2*n-1, false);
        vector<bool> rdiag(2*n-1, false);
        backtracing(solutions, board, column, ldiag, rdiag, 0);
        return solutions;
    }
};