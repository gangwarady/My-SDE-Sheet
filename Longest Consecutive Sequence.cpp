class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> vals(nums.begin(), nums.end()); 
     
        int count = 1, ans = 0; 
        
        
        long long prev = -100000000000; // number out of bounds. 
        
        for (auto &it : vals){
            if (it - 1 == prev) count++; 
            else{
                ans = max(count, ans);
                count = 1; 
            }
            prev = it; 
        }
        
        return max(count, ans); 
    }
};
