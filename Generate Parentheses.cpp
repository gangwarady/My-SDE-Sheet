class Solution {
public:
    void solve(int n, vector<string> &ans, string s, int l, int r){
        if(s.size()==2*n && l==r){
            ans.push_back(s);
        }
        if(l<n){
            solve(n, ans, s+'(', l+1, r);
        }
        if(r<n && r<l){
            solve(n, ans, s+')', l, r+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,ans, "", 0,0);
        return ans;
    }
};
