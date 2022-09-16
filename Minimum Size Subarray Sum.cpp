class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0;
        int r = 0;
        int sum =0;
        int len = INT_MAX;
        while(r<nums.size() ){
             sum = sum+ nums[r];
                
               
           //cout<<sum<<endl;
              if(sum>=target){
                  while(sum>=target){
                len = min(len, r-l+1);
                sum -= nums[l];
                l++;
                  }
                }
            r++;
            
        }
          
        if(len==INT_MAX)
            return 0;
        return len;
    }
};
