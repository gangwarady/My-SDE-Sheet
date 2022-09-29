class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int total, int i){
        if(total==0)
            return 1;
        if(i>=nums.size() || total <0)
            return 0;
        if(dp[i][total]!=-1)
            return dp[i][total];
        return dp[i][total]=solve(nums, total, i+1) + solve(nums, total-nums[i], i+1);
    }
    bool canPartition(vector<int>& nums) {
       int total = 0;
        for(int i =0; i<nums.size(); i++){
            total += nums[i];
        }
        if(total%2) return false;
        dp.resize(201, vector<int>(20001, -1));
        return solve(nums, total/2, 0);
    }
};
