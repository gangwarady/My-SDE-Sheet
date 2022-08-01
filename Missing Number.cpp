class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int high = nums.size()-1;
        int low = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==nums[mid])
                low = mid + 1;
            else if(mid<nums[mid])
                high = mid - 1;
        }
        return low;
    }
};
