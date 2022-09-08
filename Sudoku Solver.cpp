class Solution {
public:
    bool f(vector<vector<char>>& board){
        for(int i =0 ; i<board.size(); i++){
            for(int j =0; j<board[0].size(); j++){
                if(board[i][j]=='.'){
                    for(int c = '1'; c<='9'; c++){
                        if(valid(i,j,board,c)){
                            board[i][j]=c;
                        if(f(board))
                            return true;
                        else
                            board[i][j]='.';
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
    
    bool valid(int i, int j, vector<vector<char>>& board, int c){
        for(int k = 0; k<board.size(); k++){
            if(board[i][k]==c)
                return false;
            if(board[k][j]==c)
                return false;
            if(board[3*(i/3) + k/3][3*(j/3)+ k%3]==c)
                return false;
        }
        
        return true;
    }
};
