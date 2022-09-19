class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string ans;
        for(int i =0; i<s.size();i++ ){
            string w;
            if(s[i]==' ') continue;
            while(i<s.size() && s[i]!=' '){
                w +=s[i];
                i++;
            }
            words.push(w);
        }
        while(!words.empty()){
            ans+=words.top();
            if(words.size()!=1)
                ans+=' ';
            words.pop();
        }
        return ans;
    }

};
