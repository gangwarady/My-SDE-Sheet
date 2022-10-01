class Solution {
public:
    int mergesort(int s, int e, vector<int> &nums){
      if(s>=e) return 0; 
        int mid = s + (e-s)/2; 
        int cnt = mergesort( s, mid, nums) + mergesort(mid+1, e, nums); 
        for(int i = s, j = mid+1; i<=mid; i++){
            while(j<=e && nums[i]/2.0 > nums[j]) j++; 
            cnt += j-(mid+1); 
        }
        sort(nums.begin()+s, nums.begin() + e+1);
        return cnt; 
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0, nums.size()-1, nums);
    }
};
