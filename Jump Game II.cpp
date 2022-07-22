class Solution {
public:
    int jump(vector<int>& nums) {
       int count =0, l=0, r=0;
        while(r<nums.size()-1){
            int msf=0;
            for(int i = l; i<=r; i++){
                msf=max(msf,i+nums[i]);
            }
            count++;
            l = r+1;
            r=msf;
        }
        return count;
    }
};
