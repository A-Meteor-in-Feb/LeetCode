#include <iostream>

using namespace std;

class Solution {
public:

    bool backtracing(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int pos){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[pos]){
            return false;
        }
        if(pos == word.size()-1){
            return true;
        }

        visited[i][j] = true;
        if(backtracing(board, word, visited, i + 1, j, pos + 1) ||
            backtracing(board, word, visited, i, j+1, pos + 1) ||
            backtracing(board, word, visited, i - 1, j, pos + 1) ||
            backtracing(board, word, visited, i, j - 1, pos + 1)){
                return true;
            }
        visited[i][j] = false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(backtracing(board, word, visited, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
