class Solution {
public:
    string longestPalindrome(string s) {
        int l,h,st,maxlen = 0;
        for(int i = 0; i<s.size(); i++){
            l = i;
            h = i;
            while(l>=0 && h<s.size() && s[l]==s[h]){
                if(h-l+1 > maxlen){
                    maxlen = h-l+1;
                    st = l;
                }
                l--;
                h++;
            }
            l = i;
            h = i+1;
            while(l>=0 && h<s.size() && s[l]==s[h]){
                if(h-l+1 > maxlen){
                    maxlen = h-l+1;
                    st = l;
                }
                l--;
                h++;
            }
        }
        return s.substr(st,maxlen);
    }
};
