class Solution {
public:
    vector<vector<int>> dp;
    int f(string s1, string s2, int i, int j){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=f(s1, s2, i-1, j-1);
        return dp[i][j]=1+min({f(s1, s2, i-1, j), f(s1, s2, i, j-1), f(s1, s2, i-1, j-1)});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        f(word1, word2, n, m);
        return dp[n][m];
    }
};
