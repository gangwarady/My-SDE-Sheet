class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.empty())
            return {};
        vector<string> res;
        res.push_back("");
        for(auto dig : digits){
            int indi = dig - '0';
            vector<string> temp;
            for(auto ch : pad[indi]){
                for(auto it: res){
                    temp.push_back(it + ch);
                }
            }
            res = temp;
        }
        return res;
    }
};
