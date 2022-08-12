class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int count = 0;
        unordered_map<char,int> st;
        for(int i = 0; i<s.size(); i++){
            if(st.find(s[i])==st.end()){
                st[s[i]] = i;
                count++;
                ans = max(ans, count);
            }
            else{
                i = st[s[i]] + 1;
                count = 1;
                st.clear();
                st[s[i]] = i;
            }
        }
        return ans;
    }
};
