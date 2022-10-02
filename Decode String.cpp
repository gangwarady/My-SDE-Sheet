class Solution {
public:
    string solve(string &s, int &pos){
        string word = "";
        int nums=0;
        for(;pos<s.size();pos++){
            if(s[pos]=='['){
                string curr = solve(s, ++pos);
                while(nums){
                    word+=curr;
                    nums--;
                }
            }
            else if(s[pos]>='0' && s[pos]<='9'){
                nums = nums*10 + (s[pos]-'0');
            }
            else if(s[pos]==']'){
                return word;
            }
            else{
                word+=s[pos];
            }
        }
        return word;
    }
    string decodeString(string s) {
        int i =0;
        return solve(s, i);
    }
};
