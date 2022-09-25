class Solution {
public:
    int row, col;
    int dp[200][200];
    int solve(vector<vector<int>>& matrix, int i, int j, int prev){
        if(i<0 || j<0 || i>=row || j>=col || matrix[i][j]<=prev)
            return 0;
        if(dp[i][j])    return dp[i][j];
        return dp[i][j] = 1 + max({solve(matrix,  i+1, j, matrix[i][j]),
                                 solve(matrix,  i-1, j, matrix[i][j]),
                                 solve(matrix,  i, j+1, matrix[i][j]),
                                 solve(matrix,  i, j-1, matrix[i][j])});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        int maxi = 0;
        int dp[200][200];
        for(int i =0; i<row; i++){
            for(int j=0; j<col; j++){
                maxi = max(maxi, solve(matrix,  i, j , -1));
            }
        }
        return maxi;
    }
};
