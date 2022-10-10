class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int mp[1<<16] ={};
        for(int i =0; i<n; i++){
            for(int j =0;j<n;j++){
                mp[(nums[i]&nums[j])]++;
            }
        }
        //long range = 1<<16;
        for(int j =0;j<n;j++){
            for(int i = 0; i<(1<<16);i++){
                if((nums[j]&i)==0 ) count+=mp[i];
            }
        }    
        return count;
    }
};
