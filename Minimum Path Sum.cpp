class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, int i , int j){
        if(i>=grid.size() || j>=grid[0].size()){
            return 1000;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return dp[i][j] = grid[i][j];
        }
        return dp[i][j] = grid[i][j] + min(solve(grid, i+1, j), solve(grid, i, j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0); 
    }
};
