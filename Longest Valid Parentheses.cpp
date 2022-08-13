class Solution {
public:
    int longestValidParentheses(string s) {
        int c1=0,c2=0,len = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(')
                c1++;
            else
                c2++;
            if(c1==c2)
                len = max(len, c1+c2);
            else if(c2>c1){
                c1=0;
                c2=0;
            }
        }
        c1=c2=0;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i]=='(')
                c1++;
            else
                c2++;
            if(c1==c2)
                len = max(len, c1+c2);
            else if(c1>c2){
                c1=c2=0;
            }
        }
        return len;
    }
};
