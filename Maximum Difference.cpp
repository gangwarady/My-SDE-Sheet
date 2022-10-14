//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      //Your code here
      stack<int> st;
      int left[n];
      st.push(0);
      for(int i =0;i<n; i++){
          while(st.top()>=A[i]){
              st.pop();
          }
          left[i]=st.top();
          st.push(A[i]);
      }
      while(!st.empty()){
          st.pop();
      }
      int right[n];
      st.push(0);
      for(int i =n-1; i>=0;i--){
          while(st.top()>=A[i]){
              st.pop();
          }
          right[i]=st.top();
          st.push(A[i]);
      }
      int maxi =0;
      for(int i =0; i<n;i++){
          maxi = max(maxi, abs(left[i]-right[i]));
      }
      return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends
