class Solution {
public:
    bool check(string s,int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int index, string &s, vector<string> &arr, vector<vector<string>> &ans){
        if(index==s.size()){
            ans.push_back(arr);
        }
        for(int i = index; i<s.size();i++){
            if(check(s, index, i)){
                arr.push_back(s.substr(index, i-index+1));
                solve(i+1,s,arr,ans);
                arr.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        solve(0, s, arr,ans);
        return ans;
        
    }
};
