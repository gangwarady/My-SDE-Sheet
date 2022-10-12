class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ind = nums.size()-1;
        while(ind>1){
            if(nums[ind]<nums[ind-1]+nums[ind-2]) return (nums[ind]+nums[ind-1]+nums[ind-2]);
            ind--;
        }
        return 0;
    }
};
