//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	vector<vector<int>> dp;
	int solve(int arr[], int i,int prev,int n){
	   if(i==n-1){
	       if(prev==-1 || arr[prev]<arr[n-1]){
	           return arr[n-1];
	       }
	       return 0;
	   }
	   if(dp[i][prev+1]!=-1) return dp[i][prev+1];
	   int x = 0, y=0;
	   if(prev==-1 || arr[prev]<arr[i])
	    x=arr[i]+solve(arr,i+1, i,n);
	   y=solve(arr,i+1,prev,n);
	   
	   return dp[i][prev+1]=max(x,y);
	}
	int maxSumIS(int arr[], int n)  
	{   
	  dp.resize(n, vector<int>(n+1, -1));
	  return solve(arr, 0,-1,n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
