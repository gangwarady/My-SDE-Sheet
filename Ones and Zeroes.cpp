class Solution {
public:
    vector<vector<vector<int>>> dp;
    int find(vector<string>& strs, int m, int n, int index){
        if(index==strs.size() || m<0 || n<0){
            return 0;
        }
        if(dp[m][n][index]!=-1) return dp[m][n][index];
        int zeroes = count(strs[index].begin(), strs[index].end(),'0');
        int ones = strs[index].size()-zeroes;
        if(m-zeroes>=0 && n-ones>=0)
            return dp[m][n][index] = max(1+find(strs, m-zeroes,n-ones,index+1), 
                                        find(strs, m,n,index+1));
        return dp[m][n][index] =  find(strs, m,n,index+1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(strs.size(),-1)));
        return find(strs,m,n,0);
    }
};
