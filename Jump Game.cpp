class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=0,r=0;
        while(l<=r && r<nums.size()-1){
            int msf = 0;
            for(int i = l; i<=r; i++){
                msf = max(msf, i+nums[i]);
            }
            l= r+1;
            r=msf;
        }
        if(l>r){
            return false;
        }
        return true;
    }
};
