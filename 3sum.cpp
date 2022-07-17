class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        map<vector<int>,int> m;
        for(int i =0; i<nums.size(); i++){
            int target = 0 - nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                if(nums[start]+nums[end]>target){
                    end--;
                }
                else if(nums[start]+nums[end]<target){
                    start++;
                }
                else if(nums[start]+nums[end]==target){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[start]);
                    v.push_back(nums[end]);
                    ans.push_back(v);
                    start++;
                    end--;
                    while(start<end && nums[start]==v[1])
                        start++;
                    
                    while(start<end && nums[end]==v[2])
                        end--;
                    
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};
