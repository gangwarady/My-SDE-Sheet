class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()|| board[i][j]!='O'){
            return ;
        }
        board[i][j]='#';
        dfs(i+1, j, board);
        dfs(i,j+1, board);
        dfs(i-1, j, board);
        dfs(i, j-1, board);
    }
    void solve(vector<vector<char>>& board) {
        for(int i =0; i<board.size();i++){
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
            if(board[i][board[0].size()-1]=='O'){
                dfs(i, board[0].size()-1, board);
            }
        }
        for(int i =0; i<board[0].size();i++){
            if(board[0][i]=='O'){
                dfs(0,i,board);
            }
            if(board[board.size()-1][i]=='O'){
                dfs(board.size()-1, i, board);
            }
        }
        for(int i =0; i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
