//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>dp;
    int solve(int arr[], int N, int i, int j){
        int mn = INT_MAX;
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i; k<j; k++){
            int temp = solve(arr, N, i,k) + solve(arr, N, k+1,j) + arr[i-1]*arr[k]*arr[j];
            mn = min(mn, temp);
        }
        return dp[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        dp.resize(N,vector<int>(N,-1));
        return solve(arr, N, 1, N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
