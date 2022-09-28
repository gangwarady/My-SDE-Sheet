class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amount, int ind){
        if(amount<=0 || ind>=coins.size()){
            if(amount==0)
                return 0;
            else
                return INT_MAX-1;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int total = -1;
        if(coins[ind]>amount){
            total = solve(coins, amount, ind+1);
        }
        else{
            total = min(1 + solve(coins,amount-coins[ind],ind), solve(coins,amount, ind+1));
        }
        return dp[ind][amount] = total;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(),vector<int>(10000+1, -1));
        int total = solve(coins, amount, 0);
        return (total==INT_MAX-1)?-1:total;
    }
};
