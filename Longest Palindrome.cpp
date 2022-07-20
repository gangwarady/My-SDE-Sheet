class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i =0; i<s.size(); i++){
            m[s[i]]++;
        }
        if(m.size()==1){
            return s.size();
        }

        int count = 0;
        int oddy = 0;
        for(auto &it: m){
            if(it.second%2==0){
                count+=it.second;
            }
            else{
                oddy=1;
                count+=it.second-1;
            }
        }
        if(oddy)
            return count+1;
        else
            return count;
        
    }
};
