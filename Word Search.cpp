class Solution {
public:
    bool dfs(vector<vector<char>> &board, string word, int row, int col, int index){
        if(index==word.size())
            return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || word[index]!=board[row][col])
            return false;
        board[row][col]='1';
        bool sol = (dfs(board, word,row+1, col, index+1)
                   || dfs(board, word, row-1, col, index+1)
                   || dfs(board, word, row, col-1, index+1)
                   || dfs(board, word, row, col+1, index+1));
        board[row][col]=word[index];
        return sol;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0;i<board.size();i++){
            for(int j=0; j<board[0].size(); j++){
                if( dfs(board,word,i,j, 0))
                    return true;
            }
        }
        return false;
    }
};
