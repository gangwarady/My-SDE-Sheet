class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& cuts, int i, int j){
        if(i+1==j)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k =i+1; k<j; k++){
            int curr = cuts[j]-cuts[i]+solve(cuts, i, k)+solve(cuts, k,j);
            ans = min(ans, curr);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        dp.resize(102, vector<int>(102,-1));
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size()-1);
    }
};
