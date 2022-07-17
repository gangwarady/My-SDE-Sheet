class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i<nums.size(); i++){
            long long int val2 = target - nums[i];
            for(int j = i+1; j<nums.size(); j++){
                int start = j+1;
                int end = nums.size()-1;
                long long int val = val2 - nums[j];
                while(start<end){
                    if(nums[start]+nums[end]<val){
                        start++;
                    }
                    else if(nums[start]+nums[end]>val){
                        end--;
                    }
                    else{
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[start]);
                        v.push_back(nums[end]);
                        ans.push_back(v);
                        while(start<end && nums[start]==v[2])
                            start++;
                        while(start<end && nums[end]==v[3])
                            end--;
                    }
                }
                while(j+1<nums.size() && nums[j]==nums[j+1])
                    j++;
            }
            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};
