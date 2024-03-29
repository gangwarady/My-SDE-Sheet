//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string str, int i, int j){
        if(i>=j) return 0;
        if(isPalindrome(str, i, j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k<j; k++){
            if(isPalindrome(str, i, k)){
                int temp = 1 + solve(str, k+1, j);
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        dp.resize(str.size(), vector<int>(str.size(), -1));
        return solve(str, 0, str.size()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
