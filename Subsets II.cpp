class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> &res,int index){
    
        ans.push_back(res);
        for(int i=index; i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1])
                continue;
            res.push_back(nums[i]);
            //cout<<i<<endl;
            solve(nums,ans,res,i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(),nums.end());
        solve(nums,ans,res,0);
        return ans;
    }
};
