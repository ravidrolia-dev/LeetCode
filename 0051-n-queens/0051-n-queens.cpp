class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n , string(n,'.'));
        vector<vector<string>> ans;
        nqueen(board,ans,0,n);
        return ans;
    }
    void nqueen(vector<string>& board,vector<vector<string>> &ans,int row,int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(issafe(board,row,i,n)){
                board[row][i] = 'Q';
                nqueen(board,ans,row + 1, n);
                board[row][i] = '.';
            }
        }
    }
    bool issafe(vector<string>& board,int row,int col,int n){
        for(int i = 0 ; i < n ; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        for(int j = 0 ; j < n ; j++){
            if(board[j][col] == 'Q'){
                return false;
            }
        }
        for(int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row , j = col ; i >= 0 && j < n ; i-- , j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
};