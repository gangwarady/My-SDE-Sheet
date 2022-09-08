class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int msf = INT_MAX;
        int ssf = 0;
        sort(nums.begin(), nums.end());
        for(int i =0; i<nums.size(); i++){
          
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
                int rem = nums[i];
               if(nums[low]+nums[high]==(target-rem)){
                   return target;
               }
                rem += nums[low];
                rem += nums[high];
                if(abs(target-rem)<msf){
                    msf = abs(target-rem);
                    ssf = rem;
                }
                if(nums[low]+nums[high]>(target-nums[i])){
                    high--;
                   
                }
                else{
                    low++;
                }
            }
            
        }
        return ssf;
    }
};
