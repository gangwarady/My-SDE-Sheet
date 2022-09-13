class Solution {
public:
    void solve(int ind, int target, vector<int>& candidates, vector<vector<int>> &ans, vector<int> &arr){
       if(target==0){
           ans.push_back(arr);
       }
        for(int i = ind; i<candidates.size(); i++){
            if(i!=ind && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            arr.push_back(candidates[i]);
            solve(i+1, target-candidates[i], candidates, ans,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ans, arr);
        return ans;
    }
};
